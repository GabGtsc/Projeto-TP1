#include "CntrApresentacaoGestao.hpp"

using namespace std;

void CntrApresentacaoGestao::executar() {
    int opcao;
    bool executando = true;

    while (executando) {
        cout << "\n===============================\n";
        cout << "      PAINEL DE GESTAO SCRUM   \n";
        cout << "===============================\n";
        cout << "1 - Gestao de Projetos\n";
        cout << "2 - Gestao de Planos de Sprint\n";
        cout << "3 - Gestao de Historias de Usuario\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); opcao = 0; 
        }

        switch (opcao) {
            case 1: menuProjetos(); break;
            case 2: menuSprints(); break;
            case 3: menuHistorias(); break;
            case 4: executando = false; break;
            default: cout << "[ERRO] Opcao invalida.\n"; break;
        }
    }
}

void CntrApresentacaoGestao::menuProjetos() {
    int opcao;
    bool executando = true;
    while (executando) {
        cout << "\n--- SUBMENU: PROJETOS ---\n";
        cout << "1 - Criar Projeto\n2 - Ler Projeto\n3 - Atualizar Projeto\n4 - Excluir Projeto\n5 - Listar Projetos de uma Pessoa\n6 - Voltar\nEscolha: ";
        cin >> opcao;

        string entradaCodigo;
        Codigo codigo;
        Projeto projeto;

        switch (opcao) {
            case 1: { // CRIAR PROJETO (Simplificado para focar na arquitetura)
                cout << "Digite o Codigo do novo projeto (Ex: PR123): ";
                cin >> entradaCodigo;
                try {
                    codigo.setCodigo(entradaCodigo);
                    projeto.setCodigo(codigo);
                    if (servico->criarProjeto(projeto)) cout << "[SUCESSO] Projeto criado!\n";
                    else cout << "[FALHA] Nao foi possivel criar.\n";
                } catch (invalid_argument &e) { cout << "[ERRO] Formato invalido: " << e.what() << "\n"; }
                break;
            }
            case 2: { // LER PROJETO
                cout << "Digite o Codigo do projeto para buscar: ";
                cin >> entradaCodigo;
                try {
                    codigo.setCodigo(entradaCodigo);
                    if (servico->lerProjeto(codigo, &projeto)) {
                        cout << "\n--- DADOS DO PROJETO ---\nCodigo: " << projeto.getCodigo().getCodigo() << "\n";
                    } else cout << "[FALHA] Projeto nao encontrado.\n";
                } catch (invalid_argument &e) { cout << "[ERRO] " << e.what() << "\n"; }
                break;
            }
            case 5: { // LISTAR PROJETOS DA PESSOA
                string entradaEmail;
                cout << "Digite o Email da pessoa: ";
                cin >> entradaEmail;
                try {
                    Email email; email.setEmail(entradaEmail);
                    vector<Codigo> lista = servico->listarProjetosDePessoa(email);
                    cout << "\n--- PROJETOS ENCONTRADOS ---\n";
                    for (Codigo c : lista) { cout << "- " << c.getCodigo() << "\n"; }
                    if(lista.empty()) cout << "Nenhum projeto associado.\n";
                } catch (invalid_argument &e) { cout << "[ERRO] " << e.what() << "\n"; }
                break;
            }
            case 6: executando = false; break;
            default: break;
        }
    }
}

void CntrApresentacaoGestao::menuSprints() {
    cout << "\n[Aviso] Submenu de Sprints em construcao. Retornando...\n";
    // A logica aqui e identica ao menuProjetos, chamando os metodos criarPlanoDeSprint, etc.
}

void CntrApresentacaoGestao::menuHistorias() {
    cout << "\n[Aviso] Submenu de Historias em construcao. Retornando...\n";
    // A logica aqui e identica ao menuProjetos, mas com 12 opcoes em vez de 6.
}