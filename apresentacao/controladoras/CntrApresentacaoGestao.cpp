#include "CntrApresentacaoGestao.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

namespace {
    void limparTelaGestao() {
#if defined _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }
}

void CntrApresentacaoGestao::executar(const Sessao &sessao) {
    bool rodando = true;
    std::string escolha;
    std::string mensagem = "";

    while (rodando) {
        limparTelaGestao();
        std::cout << "=======================================\n";
        std::cout << "           MODULO DE GESTAO            \n";
        std::cout << "=======================================\n";
        std::cout << "Usuario: " << sessao.nome.getNome() 
                  << " (" << sessao.papel.getPapel() << ")\n\n";

        if (!mensagem.empty()) {
            std::cout << "[INFO] " << mensagem << "\n\n";
            mensagem = "";
        }

        std::cout << "1 - Gerenciar Projetos\n";
        std::cout << "2 - Gerenciar Planos de Sprint\n";
        std::cout << "3 - Gerenciar Historias de Usuario\n";
        std::cout << "4 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1") {
            gerenciarProjetos(sessao);
        } else if (escolha == "2") {
            gerenciarSprints(sessao);
        } else if (escolha == "3") {
            gerenciarHistorias(sessao);
        } else if (escolha == "4") {
            rodando = false;
        } else {
            mensagem = "Opcao invalida.";
        }
    }
}

// =================== PROJETOS ===================
void CntrApresentacaoGestao::gerenciarProjetos(const Sessao &sessao) {
    bool rodando = true;
    std::string escolha;
    std::string mensagem = "";
    std::string papel = sessao.papel.getPapel();

    while (rodando) {
        limparTelaGestao();
        std::cout << "--- PROJETOS ---\n\n";
        if (!mensagem.empty()) {
            std::cout << "[INFO] " << mensagem << "\n\n";
            mensagem = "";
        }

        if (papel == "PROPRIETARIO DE PRODUTO") {
            std::cout << "1 - Criar Projeto\n";
            std::cout << "2 - Atualizar Projeto\n";
            std::cout << "3 - Excluir Projeto\n";
        }
        std::cout << "4 - Listar e Visualizar Projetos\n";
        std::cout << "5 - Listar Projetos por Pessoa\n";
        std::cout << "6 - Voltar\n";
        std::cout << "Escolha: ";

        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1" && papel == "PROPRIETARIO DE PRODUTO") {
            criarProjeto(sessao);
        } else if (escolha == "2" && papel == "PROPRIETARIO DE PRODUTO") {
            atualizarProjeto(sessao);
        } else if (escolha == "3" && papel == "PROPRIETARIO DE PRODUTO") {
            excluirProjeto(sessao);
        } else if (escolha == "4") {
            listarEVisualizarProjetos(sessao);
        } else if (escolha == "5") {
            listarProjetosPorPessoa(sessao);
        } else if (escolha == "6") {
            rodando = false;
        } else {
            mensagem = "Opcao invalida ou sem permissao.";
        }
    }
}

void CntrApresentacaoGestao::criarProjeto(const Sessao &sessao) {
    std::string entrada;
    Projeto projeto;
    Email eSM;
    
    std::cout << "\n--- CRIAR PROJETO ---\n";
    std::cout << "Digite 'cancelar' a qualquer momento para voltar.\n\n";

    while (true) {
        std::cout << "Codigo (5 caracteres, 2 letras maiusculas + 3 numeros): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Codigo c; c.setCodigo(entrada); projeto.setCodigo(c); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Nome (ate 10 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Nome n; n.setNome(entrada); projeto.setNome(n); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Data de Inicio (DD/MM/AAAA): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Data d; d.setData(entrada); projeto.setInicio(d); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Data de Termino (DD/MM/AAAA): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Data d; d.setData(entrada); projeto.setTermino(d); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Email do Mestre Scrum associado: ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { eSM.setEmail(entrada); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    if (servico->criarProjeto(projeto, sessao.email, eSM)) {
        std::cout << "[SUCESSO] Projeto criado com sucesso!\n";
    } else {
        std::cout << "[ERRO] Nao foi possivel criar o projeto.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

void CntrApresentacaoGestao::atualizarProjeto(const Sessao &sessao) {
    std::string entrada, codigoStr;
    std::cout << "\n--- ATUALIZAR PROJETO ---\n";
    std::cout << "Digite o Codigo do Projeto a atualizar (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        Projeto projeto;
        
        if (!servico->lerProjeto(codigo, projeto)) {
            std::cout << "[ERRO] Projeto nao encontrado.\n";
        } else {
            std::cout << "\n--- DADOS ATUAIS ---\n";
            std::cout << "Nome: " << projeto.getNome().getNome() << "\n";
            std::cout << "Inicio: " << projeto.getInicio().getData() << "\n";
            std::cout << "Termino: " << projeto.getTermino().getData() << "\n";
            std::cout << "--------------------\n";
            std::cout << "Deixe em branco para manter o dado atual.\n\n";

            // Nome
            std::cout << "Novo Nome [" << projeto.getNome().getNome() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                Nome n; n.setNome(entrada);
                projeto.setNome(n);
            }

            // Inicio
            std::cout << "Novo Inicio [" << projeto.getInicio().getData() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                Data d; d.setData(entrada);
                projeto.setInicio(d);
            }

            // Termino
            std::cout << "Novo Termino [" << projeto.getTermino().getData() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                Data d; d.setData(entrada);
                projeto.setTermino(d);
            }

            if (servico->atualizarProjeto(projeto)) {
                std::cout << "[SUCESSO] Projeto atualizado!\n";
            } else {
                std::cout << "[ERRO] Falha ao atualizar projeto.\n";
            }
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }
    
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

void CntrApresentacaoGestao::excluirProjeto(const Sessao &sessao) {
    std::string codigoStr;
    std::cout << "\n--- EXCLUIR PROJETO ---\n";
    std::cout << "Digite o Codigo do Projeto a excluir (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        Projeto projeto;
        
        if (servico->lerProjeto(codigo, projeto)) {
            std::cout << "\nProjeto Encontrado: " << projeto.getNome().getNome() << "\n";
            std::cout << "Deseja realmente exclui-lo? (s/n): ";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (confirm == "s" || confirm == "S") {
                if (servico->excluirProjeto(codigo)) {
                    std::cout << "[SUCESSO] Projeto excluido com sucesso.\n";
                } else {
                    std::cout << "[ERRO] Falha ao excluir o projeto.\n";
                }
            } else {
                std::cout << "[INFO] Exclusao cancelada.\n";
            }
        } else {
            std::cout << "[ERRO] Projeto nao encontrado.\n";
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

void CntrApresentacaoGestao::listarEVisualizarProjetos(const Sessao &sessao) {
    std::cout << "\n--- PROJETOS ---\n";
    std::vector<Codigo> projetos = servico->listarTodosProjetos();
    
    if (projetos.empty()) {
        std::cout << "Nenhum projeto encontrado.\n";
    } else {
        for (const auto &codigo : projetos) {
            std::cout << "- Codigo do Projeto: " << codigo.getCodigo() << "\n";
            Projeto p;
            if (servico->lerProjeto(codigo, p)) {
                std::cout << "  Nome: " << p.getNome().getNome() << "\n";
                std::cout << "  Inicio: " << p.getInicio().getData() << "\n";
                std::cout << "  Termino: " << p.getTermino().getData() << "\n\n";
            }
        }
    }
    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

void CntrApresentacaoGestao::listarProjetosPorPessoa(const Sessao &sessao) {
    std::cout << "\n--- LISTAR PROJETOS POR PESSOA ---\n";
    std::string emailStr;
    std::cout << "Digite o Email da Pessoa: ";
    std::getline(std::cin, emailStr);
    if (emailStr.empty()) return;

    try {
        Email email;
        email.setEmail(emailStr);
        std::vector<Codigo> projetos = servico->listarProjetosDePessoa(email);
        
        if (projetos.empty()) {
            std::cout << "Nenhum projeto encontrado para esta pessoa.\n";
        } else {
            for (const auto &codigo : projetos) {
                std::cout << "- Codigo do Projeto: " << codigo.getCodigo() << "\n";
                Projeto p;
                if (servico->lerProjeto(codigo, p)) {
                    std::cout << "  Nome: " << p.getNome().getNome() << "\n";
                    std::cout << "  Inicio: " << p.getInicio().getData() << "\n";
                    std::cout << "  Termino: " << p.getTermino().getData() << "\n\n";
                }
            }
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

// =================== PLANOS DE SPRINT ===================
void CntrApresentacaoGestao::gerenciarSprints(const Sessao &sessao) {
    bool rodando = true;
    std::string escolha;
    std::string mensagem = "";
    std::string papel = sessao.papel.getPapel();

    while (rodando) {
        limparTelaGestao();
        std::cout << "--- PLANOS DE SPRINT ---\n\n";
        if (!mensagem.empty()) {
            std::cout << "[INFO] " << mensagem << "\n\n";
            mensagem = "";
        }

        if (papel == "MESTRE SCRUM") {
            std::cout << "1 - Criar Plano de Sprint\n";
            std::cout << "2 - Atualizar Sprint\n";
            std::cout << "3 - Excluir Sprint\n";
        }
        std::cout << "4 - Listar e Visualizar Sprints de um Projeto\n";
        std::cout << "5 - Voltar\n";
        std::cout << "Escolha: ";

        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1" && papel == "MESTRE SCRUM") {
            criarSprint(sessao);
        } else if (escolha == "2" && papel == "MESTRE SCRUM") {
            atualizarSprint(sessao);
        } else if (escolha == "3" && papel == "MESTRE SCRUM") {
            excluirSprint(sessao);
        } else if (escolha == "4") {
            listarEVisualizarSprints(sessao);
        } else if (escolha == "5") {
            rodando = false;
        } else {
            mensagem = "Opcao invalida ou sem permissao.";
        }
    }
}

void CntrApresentacaoGestao::criarSprint(const Sessao &sessao) {
    std::string entrada;
    Codigo cp;
    PlanoDeSprint plano;
    
    std::cout << "\n--- CRIAR PLANO DE SPRINT ---\n";
    std::cout << "Digite 'cancelar' a qualquer momento para voltar.\n\n";

    while (true) {
        std::cout << "Codigo do Projeto vinculado: ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { cp.setCodigo(entrada); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Codigo do Sprint (5 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Codigo c; c.setCodigo(entrada); plano.setCodigo(c); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Objetivo (ate 40 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Texto t; t.setTexto(entrada); plano.setObjetivo(t); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Capacidade (em dias, 1 a 365): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Tempo t; t.setTempo(std::stoi(entrada)); plano.setCapacidade(t); break; }
        catch (const std::exception &e) { std::cout << "Erro: Entrada invalida. Certifique-se de digitar um numero.\n"; }
    }

    if (servico->criarPlanoDeSprint(plano, cp)) {
        std::cout << "[SUCESSO] Plano de Sprint criado!\n";
    } else {
        std::cout << "[ERRO] Nao foi possivel criar o Sprint (verifique a capacidade do projeto).\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

void CntrApresentacaoGestao::listarEVisualizarSprints(const Sessao &sessao) {
    std::string entProj;
    std::cout << "\nDigite o codigo do Projeto: ";
    std::cin >> std::ws;
    std::getline(std::cin, entProj);

    try {
        Codigo cp; cp.setCodigo(entProj);
        std::vector<Codigo> sprints = servico->listarSprintsDeProjeto(cp);
        
        if (sprints.empty()) {
            std::cout << "Nenhum Sprint encontrado para este projeto.\n";
        } else {
            for (const auto &codigo : sprints) {
                std::cout << "- Codigo do Sprint: " << codigo.getCodigo() << "\n";
                PlanoDeSprint p;
                if (servico->lerPlanoDeSprint(codigo, p)) {
                    std::cout << "  Objetivo: " << p.getObjetivo().getTexto() << "\n";
                    std::cout << "  Capacidade: " << p.getCapacidade().getTempo() << " dias\n\n";
                }
            }
        }
    } catch(std::invalid_argument &e) {
        std::cout << "[ERRO] Codigo de projeto invalido.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}


// ------------------- AUXILIARES SPRINT -------------------

void CntrApresentacaoGestao::atualizarSprint(const Sessao &sessao) {
    std::string entrada, codigoStr;
    std::cout << "\n--- ATUALIZAR SPRINT ---\n";
    std::cout << "Digite o Codigo do Sprint a atualizar (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        PlanoDeSprint plano;
        
        if (!servico->lerPlanoDeSprint(codigo, plano)) {
            std::cout << "[ERRO] Sprint nao encontrado.\n";
        } else {
            std::cout << "\n--- DADOS ATUAIS ---\n";
            std::cout << "Objetivo: " << plano.getObjetivo().getTexto() << "\n";
            std::cout << "Capacidade: " << plano.getCapacidade().getTempo() << "\n";
            std::cout << "--------------------\n";
            std::cout << "Deixe em branco para manter o dado atual.\n\n";

            std::cout << "Novo Objetivo [" << plano.getObjetivo().getTexto() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                Texto o; o.setTexto(entrada);
                plano.setObjetivo(o);
            }

            std::cout << "Nova Capacidade [" << plano.getCapacidade().getTempo() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                Tempo c; c.setTempo(std::stoi(entrada));
                plano.setCapacidade(c);
            }

            if (servico->atualizarPlanoDeSprint(plano)) {
                std::cout << "[SUCESSO] Sprint atualizado!\n";
            } else {
                std::cout << "[ERRO] Falha ao atualizar sprint.\n";
            }
        }
    } catch (const std::exception &e) {
        std::cout << "[ERRO] Entrada invalida: " << e.what() << "\n";
    }
    
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

void CntrApresentacaoGestao::excluirSprint(const Sessao &sessao) {
    std::string codigoStr;
    std::cout << "\n--- EXCLUIR SPRINT ---\n";
    std::cout << "Digite o Codigo do Sprint a excluir (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        PlanoDeSprint plano;
        
        if (servico->lerPlanoDeSprint(codigo, plano)) {
            std::cout << "\nSprint Encontrado: " << plano.getObjetivo().getTexto() << "\n";
            std::cout << "Deseja realmente exclui-lo? (s/n): ";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (confirm == "s" || confirm == "S") {
                if (servico->excluirPlanoDeSprint(codigo)) {
                    std::cout << "[SUCESSO] Sprint excluido com sucesso.\n";
                } else {
                    std::cout << "[ERRO] Falha ao excluir o sprint.\n";
                }
            } else {
                std::cout << "[INFO] Exclusao cancelada.\n";
            }
        } else {
            std::cout << "[ERRO] Sprint nao encontrado.\n";
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

// =================== HISTORIAS DE USUARIO ===================
void CntrApresentacaoGestao::gerenciarHistorias(const Sessao &sessao) {
    bool rodando = true;
    std::string escolha;
    std::string mensagem = "";
    std::string papel = sessao.papel.getPapel();

    while (rodando) {
        limparTelaGestao();
        std::cout << "--- HISTORIAS DE USUARIO ---\n\n";
        if (!mensagem.empty()) {
            std::cout << "[INFO] " << mensagem << "\n\n";
            mensagem = "";
        }

        if (papel == "PROPRIETARIO DE PRODUTO") {
            std::cout << "1 - Criar Historia de Usuario\n";
            std::cout << "2 - Atualizar Historia\n";
            std::cout << "3 - Excluir Historia\n";
        }
        if (papel == "MESTRE SCRUM") {
            std::cout << "4 - Associar Historia a Pessoa\n";
            std::cout << "5 - Desassociar Historia de Pessoa\n";
            std::cout << "6 - Mover Historia para Sprint\n";
        }
        if (papel == "PROPRIETARIO DE PRODUTO" || papel == "MESTRE SCRUM") {
            std::cout << "7 - Alterar Estado da Historia\n";
        }
        std::cout << "8 - Listar Historias de um Projeto\n";
        std::cout << "9 - Listar Historias de um Sprint\n";
        std::cout << "10 - Listar Historias de uma Pessoa\n";
        std::cout << "11 - Voltar\n";
        std::cout << "Escolha: ";

        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1" && papel == "PROPRIETARIO DE PRODUTO") {
            criarHistoria(sessao);
        } else if (escolha == "2" && papel == "PROPRIETARIO DE PRODUTO") {
            atualizarHistoria(sessao);
        } else if (escolha == "3" && papel == "PROPRIETARIO DE PRODUTO") {
            excluirHistoria(sessao);
        } else if (escolha == "4" && papel == "MESTRE SCRUM") {
            associarHistoriaPessoa(sessao);
        } else if (escolha == "5" && papel == "MESTRE SCRUM") {
            desassociarHistoriaPessoa(sessao);
        } else if (escolha == "6" && papel == "MESTRE SCRUM") {
            moverHistoriaParaSprint(sessao);
        } else if (escolha == "7" && (papel == "PROPRIETARIO DE PRODUTO" || papel == "MESTRE SCRUM")) {
            alterarEstadoHistoria(sessao);
        } else if (escolha == "8") {
            listarEVisualizarHistorias(sessao); // Listar de Projeto
        } else if (escolha == "9") {
            listarHistoriasDeSprint(sessao);
        } else if (escolha == "10") {
            listarHistoriasDePessoa(sessao);
        } else if (escolha == "11") {
            rodando = false;
        } else {
            mensagem = "Opcao invalida ou sem permissao.";
        }
    }
}

void CntrApresentacaoGestao::criarHistoria(const Sessao &sessao) {
    std::string entrada;
    Codigo cp;
    HistoriaDeUsuario historia;
    
    std::cout << "\n--- CRIAR HISTORIA ---\n";
    std::cout << "Digite 'cancelar' a qualquer momento para voltar.\n\n";

    while (true) {
        std::cout << "Codigo do Projeto vinculado: ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { cp.setCodigo(entrada); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Codigo da Historia (5 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Codigo ch; ch.setCodigo(entrada); historia.setCodigo(ch); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Titulo (ate 40 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Texto t; t.setTexto(entrada); historia.setTitulo(t); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Papel alvo (ate 40 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Texto t; t.setTexto(entrada); historia.setPapel(t); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Acao (ate 40 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Texto t; t.setTexto(entrada); historia.setAcao(t); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Valor (ate 40 char): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Texto t; t.setTexto(entrada); historia.setValor(t); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    while (true) {
        std::cout << "Estimativa (1 a 365): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Tempo t; t.setTempo(std::stoi(entrada)); historia.setEstimativa(t); break; }
        catch (const std::exception &e) { std::cout << "Erro: Entrada invalida.\n"; }
    }

    while (true) {
        std::cout << "Prioridade (BAIXA, MEDIA, ALTA): ";
        std::getline(std::cin, entrada);
        if (entrada == "cancelar") return;
        try { Prioridade p; p.setPrioridade(entrada); historia.setPrioridade(p); break; }
        catch (const std::invalid_argument &e) { std::cout << "Erro: " << e.what() << "\n"; }
    }

    Estado estInic; estInic.setEstado("A FAZER"); // Definido pelo negócio
    historia.setEstado(estInic);

    if (servico->criarHistoriaDeUsuario(historia, cp)) {
        std::cout << "[SUCESSO] Historia criada (Estado inicial: A FAZER)!\n";
    } else {
        std::cout << "[ERRO] Nao foi possivel criar a historia.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

// ------------------- AUXILIARES HISTORIA -------------------

void CntrApresentacaoGestao::atualizarHistoria(const Sessao &sessao) {
    std::string entrada, codigoStr;
    std::cout << "\n--- ATUALIZAR HISTORIA ---\n";
    std::cout << "Digite o Codigo da Historia a atualizar (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        HistoriaDeUsuario historia;
        
        if (!servico->lerHistoriaDeUsuario(codigo, historia)) {
            std::cout << "[ERRO] Historia nao encontrada.\n";
        } else {
            std::cout << "\n--- DADOS ATUAIS ---\n";
            std::cout << "Titulo: " << historia.getTitulo().getTexto() << "\n";
            std::cout << "Papel: " << historia.getPapel().getTexto() << "\n";
            std::cout << "Acao: " << historia.getAcao().getTexto() << "\n";
            std::cout << "Valor: " << historia.getValor().getTexto() << "\n";
            std::cout << "Estimativa: " << historia.getEstimativa().getTempo() << "\n";
            std::cout << "Prioridade: " << historia.getPrioridade().getPrioridade() << "\n";
            std::cout << "--------------------\n";
            std::cout << "Deixe em branco para manter o dado atual.\n\n";

            std::cout << "Novo Titulo [" << historia.getTitulo().getTexto() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Texto t; t.setTexto(entrada); historia.setTitulo(t); }

            std::cout << "Novo Papel [" << historia.getPapel().getTexto() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Texto t; t.setTexto(entrada); historia.setPapel(t); }

            std::cout << "Nova Acao [" << historia.getAcao().getTexto() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Texto t; t.setTexto(entrada); historia.setAcao(t); }

            std::cout << "Novo Valor [" << historia.getValor().getTexto() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Texto t; t.setTexto(entrada); historia.setValor(t); }

            std::cout << "Nova Estimativa [" << historia.getEstimativa().getTempo() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Tempo t; t.setTempo(std::stoi(entrada)); historia.setEstimativa(t); }

            std::cout << "Nova Prioridade (BAIXA, MEDIA, ALTA) [" << historia.getPrioridade().getPrioridade() << "]: ";
            std::getline(std::cin, entrada);
            if (!entrada.empty()) { Prioridade p; p.setPrioridade(entrada); historia.setPrioridade(p); }

            if (servico->atualizarHistoriaDeUsuario(historia)) {
                std::cout << "[SUCESSO] Historia atualizada!\n";
            } else {
                std::cout << "[ERRO] Falha ao atualizar historia.\n";
            }
        }
    } catch (const std::exception &e) {
        std::cout << "[ERRO] Entrada invalida: " << e.what() << "\n";
    }
    
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entrada);
}

void CntrApresentacaoGestao::excluirHistoria(const Sessao &sessao) {
    std::string codigoStr;
    std::cout << "\n--- EXCLUIR HISTORIA ---\n";
    std::cout << "Digite o Codigo da Historia a excluir (ou 'cancelar'): ";
    std::getline(std::cin, codigoStr);
    if (codigoStr == "cancelar" || codigoStr.empty()) return;

    try {
        Codigo codigo;
        codigo.setCodigo(codigoStr);
        HistoriaDeUsuario historia;
        
        if (servico->lerHistoriaDeUsuario(codigo, historia)) {
            std::cout << "\nHistoria Encontrada: " << historia.getTitulo().getTexto() << "\n";
            std::cout << "Deseja realmente exclui-la? (s/n): ";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (confirm == "s" || confirm == "S") {
                if (servico->excluirHistoriaDeUsuario(codigo)) {
                    std::cout << "[SUCESSO] Historia excluida com sucesso.\n";
                } else {
                    std::cout << "[ERRO] Falha ao excluir a historia.\n";
                }
            } else {
                std::cout << "[INFO] Exclusao cancelada.\n";
            }
        } else {
            std::cout << "[ERRO] Historia nao encontrada.\n";
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

void CntrApresentacaoGestao::associarHistoriaPessoa(const Sessao &sessao) {
    std::string entHist, entEmail;
    std::cout << "\n--- ASSOCIAR HISTORIA A PESSOA ---\n";
    std::cout << "Codigo da Historia: ";
    std::cin >> std::ws;
    std::getline(std::cin, entHist);
    std::cout << "Email da Pessoa: ";
    std::getline(std::cin, entEmail);
    
    try {
        Codigo ch; ch.setCodigo(entHist);
        Email em; em.setEmail(entEmail);
        if (servico->associarHistoriaPessoa(ch, em)) {
            std::cout << "[SUCESSO] Associacao efetuada.\n";
        } else {
            std::cout << "[ERRO] Nao foi possivel efetuar a associacao.\n";
        }
    } catch (std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entHist);
}

void CntrApresentacaoGestao::desassociarHistoriaPessoa(const Sessao &sessao) {
    std::string entHist, entEmail;
    std::cout << "\n--- DESASSOCIAR HISTORIA DE PESSOA ---\n";
    std::cout << "Codigo da Historia: ";
    std::cin >> std::ws;
    std::getline(std::cin, entHist);
    std::cout << "Email da Pessoa: ";
    std::getline(std::cin, entEmail);
    
    try {
        Codigo ch; ch.setCodigo(entHist);
        Email em; em.setEmail(entEmail);
        if (servico->desassociarHistoriaPessoa(ch, em)) {
            std::cout << "[SUCESSO] Desassociacao efetuada.\n";
        } else {
            std::cout << "[ERRO] Nao foi possivel remover a associacao.\n";
        }
    } catch (std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entHist);
}

void CntrApresentacaoGestao::moverHistoriaParaSprint(const Sessao &sessao) {
    std::string entHist, entProj, entSprint;
    std::cout << "\n--- MOVER HISTORIA PARA SPRINT ---\n";
    std::cout << "Codigo da Historia: ";
    std::cin >> std::ws;
    std::getline(std::cin, entHist);
    std::cout << "Codigo do Projeto Atual: ";
    std::getline(std::cin, entProj);
    std::cout << "Codigo do Plano de Sprint Destino: ";
    std::getline(std::cin, entSprint);
    
    try {
        Codigo ch; ch.setCodigo(entHist);
        Codigo cp; cp.setCodigo(entProj);
        Codigo cs; cs.setCodigo(entSprint);
        if (servico->moverHistoriaParaSprint(ch, cp, cs)) {
            std::cout << "[SUCESSO] Historia movida para sprint.\n";
        } else {
            std::cout << "[ERRO] Nao foi possivel mover a historia.\n";
        }
    } catch (std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entHist);
}

void CntrApresentacaoGestao::alterarEstadoHistoria(const Sessao &sessao) {
    std::string entHist, entEstado;
    std::cout << "\n--- ALTERAR ESTADO DA HISTORIA ---\n";
    std::cout << "Codigo da Historia: ";
    std::cin >> std::ws;
    std::getline(std::cin, entHist);
    std::cout << "Novo Estado (A FAZER, FAZENDO, FEITO): ";
    std::getline(std::cin, entEstado);
    
    try {
        Codigo ch; ch.setCodigo(entHist);
        Estado es; es.setEstado(entEstado);
        if (servico->alterarEstadoHistoria(ch, es)) {
            std::cout << "[SUCESSO] Estado da historia alterado.\n";
        } else {
            std::cout << "[ERRO] Falha ao alterar estado.\n";
        }
    } catch (std::invalid_argument &e) {
        std::cout << "[ERRO] " << e.what() << "\n";
    }
    std::cout << "Pressione ENTER para continuar...";
    std::getline(std::cin, entHist);
}

void CntrApresentacaoGestao::listarEVisualizarHistorias(const Sessao &sessao) {
    std::string entProj;
    std::cout << "\n--- LISTAR HISTORIAS DE PROJETO ---\n";
    std::cout << "Digite o codigo do Projeto para listar historias: ";
    std::cin >> std::ws;
    std::getline(std::cin, entProj);

    try {
        Codigo cp; cp.setCodigo(entProj);
        std::vector<Codigo> hist = servico->listarHistoriasDeProjeto(cp);
        
        if (hist.empty()) {
            std::cout << "Nenhuma Historia encontrada para este projeto.\n";
        } else {
            for (const auto &codigo : hist) {
                std::cout << "- Codigo da Historia: " << codigo.getCodigo() << "\n";
                HistoriaDeUsuario h;
                if (servico->lerHistoriaDeUsuario(codigo, h)) {
                    std::cout << "  Titulo: " << h.getTitulo().getTexto() << "\n";
                    std::cout << "  Estado: " << h.getEstado().getEstado() << "\n";
                    std::cout << "  Prioridade: " << h.getPrioridade().getPrioridade() << "\n";
                    std::cout << "  Estimativa: " << h.getEstimativa().getTempo() << " dias\n\n";
                }
            }
        }
    } catch(std::invalid_argument &e) {
        std::cout << "[ERRO] Codigo invalido.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

void CntrApresentacaoGestao::listarHistoriasDeSprint(const Sessao &sessao) {
    std::string entSprint;
    std::cout << "\n--- LISTAR HISTORIAS DE SPRINT ---\n";
    std::cout << "Digite o codigo do Sprint para listar historias: ";
    std::cin >> std::ws;
    std::getline(std::cin, entSprint);

    try {
        Codigo cs; cs.setCodigo(entSprint);
        std::vector<Codigo> hist = servico->listarHistoriasDeSprint(cs);
        
        if (hist.empty()) {
            std::cout << "Nenhuma Historia encontrada para este sprint.\n";
        } else {
            for (const auto &codigo : hist) {
                std::cout << "- Codigo da Historia: " << codigo.getCodigo() << "\n";
                HistoriaDeUsuario h;
                if (servico->lerHistoriaDeUsuario(codigo, h)) {
                    std::cout << "  Titulo: " << h.getTitulo().getTexto() << "\n";
                    std::cout << "  Estado: " << h.getEstado().getEstado() << "\n";
                }
            }
        }
    } catch(std::invalid_argument &e) {
        std::cout << "[ERRO] Codigo invalido.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}

void CntrApresentacaoGestao::listarHistoriasDePessoa(const Sessao &sessao) {
    std::string entEmail;
    std::cout << "\n--- LISTAR HISTORIAS DE PESSOA ---\n";
    std::cout << "Digite o Email da pessoa (deixe em branco para seu proprio usuario): ";
    std::cin >> std::ws;
    std::getline(std::cin, entEmail);
    if (entEmail.empty()) entEmail = sessao.email.getEmail();

    try {
        Email email; email.setEmail(entEmail);
        std::vector<Codigo> hist = servico->listarHistoriasDePessoa(email);
        
        if (hist.empty()) {
            std::cout << "Nenhuma Historia encontrada para esta pessoa.\n";
        } else {
            for (const auto &codigo : hist) {
                std::cout << "- Codigo da Historia: " << codigo.getCodigo() << "\n";
                HistoriaDeUsuario h;
                if (servico->lerHistoriaDeUsuario(codigo, h)) {
                    std::cout << "  Titulo: " << h.getTitulo().getTexto() << "\n";
                    std::cout << "  Estado: " << h.getEstado().getEstado() << "\n";
                }
            }
        }
    } catch(std::invalid_argument &e) {
        std::cout << "[ERRO] Email invalido.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::string lixo;
    std::getline(std::cin, lixo);
}
