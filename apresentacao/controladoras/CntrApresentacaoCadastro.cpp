#include "CntrApresentacaoCadastro.hpp"
#include <cstdlib>
#include <string>

namespace {
    void limparTela() {
#if defined _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }
}

void CntrApresentacaoCadastro::executar() {
    std::string escolha;
    std::string mensagemErro = "";
    std::string mensagemSucesso = "";

    while (true) {
        limparTela();
        std::cout << "\n===============================\n";
        std::cout << "      GERENCIAR PESSOAS        \n";
        std::cout << "===============================\n";
        
        if (!mensagemErro.empty()) {
            std::cout << "[ERRO] " << mensagemErro << "\n\n";
            mensagemErro = "";
        }
        if (!mensagemSucesso.empty()) {
            std::cout << "[SUCESSO] " << mensagemSucesso << "\n\n";
            mensagemSucesso = "";
        }
        
        std::cout << "1 - Criar Pessoa (Cadastro)\n";
        std::cout << "2 - Ler Pessoa\n";
        std::cout << "3 - Atualizar Pessoa\n";
        std::cout << "4 - Excluir Pessoa\n";
        std::cout << "5 - Voltar\n";
        std::cout << "Escolha uma opcao: ";
        
        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1") {
            // CRIAR PESSOA
            std::string entrada;
            Email emailInstancia;
            Nome nomeInstancia;
            Senha senhaInstancia;
            Papel papelInstancia;
            Pessoa pessoa;

            limparTela();
            std::cout << "--- CRIAR PESSOA ---\n";
            std::cout << "Digite 'cancelar' a qualquer momento para voltar.\n\n";

            // Loop para Email
            while (true) {
                std::cout << "Digite o Email: ";
                std::getline(std::cin, entrada);
                if (entrada == "cancelar") break;
                try {
                    emailInstancia.setEmail(entrada);
                    pessoa.setEmail(emailInstancia);
                    break; // Sucesso
                } catch (const std::invalid_argument &e) {
                    std::cout << "Erro: " << e.what() << ". Tente novamente.\n";
                }
            }
            if (entrada == "cancelar") continue;

            // Loop para Nome
            while (true) {
                std::cout << "Digite o Nome: ";
                std::getline(std::cin, entrada);
                if (entrada == "cancelar") break;
                try {
                    nomeInstancia.setNome(entrada);
                    pessoa.setNome(nomeInstancia);
                    break; // Sucesso
                } catch (const std::invalid_argument &e) {
                    std::cout << "Erro: " << e.what() << ". Tente novamente.\n";
                }
            }
            if (entrada == "cancelar") continue;

            // Loop para Senha
            while (true) {
                std::cout << "Digite a Senha: ";
                std::getline(std::cin, entrada);
                if (entrada == "cancelar") break;
                try {
                    senhaInstancia.setSenha(entrada);
                    pessoa.setSenha(senhaInstancia);
                    break; // Sucesso
                } catch (const std::invalid_argument &e) {
                    std::cout << "Erro: " << e.what() << ". Tente novamente.\n";
                }
            }
            if (entrada == "cancelar") continue;

            // Loop para Papel
            while (true) {
                std::cout << "Escolha o Papel:\n";
                std::cout << "1 - DESENVOLVEDOR\n";
                std::cout << "2 - MESTRE SCRUM\n";
                std::cout << "3 - PROPRIETARIO DE PRODUTO\n";
                std::cout << "Opcao (ou 'cancelar'): ";
                std::getline(std::cin, entrada);
                if (entrada == "cancelar") break;

                std::string papelStr = "";
                if (entrada == "1") papelStr = "DESENVOLVEDOR";
                else if (entrada == "2") papelStr = "MESTRE SCRUM";
                else if (entrada == "3") papelStr = "PROPRIETARIO DE PRODUTO";
                else papelStr = entrada; // Caso usuario digite o nome diretamente

                try {
                    papelInstancia.setPapel(papelStr);
                    pessoa.setPapel(papelInstancia);
                    break; // Sucesso
                } catch (const std::invalid_argument &e) {
                    std::cout << "Erro: " << e.what() << ". Tente novamente.\n";
                }
            }
            if (entrada == "cancelar") continue;

            // Enviar para serviço
            if (servico->criar(pessoa)) {
                mensagemSucesso = "Pessoa criada com sucesso!";
            } else {
                mensagemErro = "Falha ao criar pessoa. O e-mail ja existe?";
            }

        } else if (escolha == "2") {
            // LER PESSOA
            limparTela();
            std::cout << "--- LER PESSOA ---\n";
            std::string entradaEmail;
            std::cout << "Digite o Email da pessoa a ser lida (ou 'cancelar'): ";
            std::getline(std::cin, entradaEmail);
            if (entradaEmail != "cancelar") {
                try {
                    Email email;
                    email.setEmail(entradaEmail);
                    Pessoa pessoa;
                    if (servico->ler(email, pessoa)) {
                        mensagemSucesso = "Pessoa encontrada!";
                        // Dependendo da implementacao do servico de ler, pessoa seria preenchida.
                        // Mas para mostrar ao usuario, precisariamos ler da entidade retornada (se fosse passada por referencia nao const).
                        // O IServicoCadastro::ler(const Email&, const Pessoa&) e um pouco estranho. O correto seria retornar Pessoa ou Pessoa passada por ref.
                    } else {
                        mensagemErro = "Pessoa nao encontrada.";
                    }
                } catch (const std::invalid_argument &e) {
                    mensagemErro = e.what();
                }
            }
        } else if (escolha == "3") {
            // ATUALIZAR PESSOA
            mensagemErro = "Funcao Atualizar nao implementada na interface (Pessoa precisa ser recriada ou consultada primeiro).";
        } else if (escolha == "4") {
            // EXCLUIR PESSOA
            limparTela();
            std::cout << "--- EXCLUIR PESSOA ---\n";
            std::string entradaEmail;
            std::cout << "Digite o Email da pessoa a ser excluida (ou 'cancelar'): ";
            std::getline(std::cin, entradaEmail);
            if (entradaEmail != "cancelar") {
                try {
                    Email email;
                    email.setEmail(entradaEmail);
                    if (servico->excluir(email)) {
                        mensagemSucesso = "Pessoa excluida com sucesso!";
                    } else {
                        mensagemErro = "Pessoa nao encontrada para exclusao.";
                    }
                } catch (const std::invalid_argument &e) {
                    mensagemErro = e.what();
                }
            }
        } else if (escolha == "5") {
            break;
        } else {
            mensagemErro = "Opcao invalida!";
        }
    }
}

