#include "CntrApresentacaoGestao.hpp"
#include <cstdlib>

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
        std::cout << "===============================\n";
        std::cout << "       MODULO DE GESTAO        \n";
        std::cout << "===============================\n";
        std::cout << "Usuario logado: " << sessao.nome.getNome() 
                  << " (" << sessao.papel.getPapel() << ")\n\n";

        if (!mensagem.empty()) {
            std::cout << "[INFO] " << mensagem << "\n\n";
            mensagem = "";
        }

        std::cout << "1 - Projetos\n";
        std::cout << "2 - Planos de Sprint\n";
        std::cout << "3 - Historias de Usuario\n";
        std::cout << "4 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        std::cin >> std::ws;
        std::getline(std::cin, escolha);

        if (escolha == "1") {
            mensagem = "Modulo de Projetos ainda nao implementado visualmente.";
        } else if (escolha == "2") {
            mensagem = "Modulo de Planos de Sprint ainda nao implementado visualmente.";
        } else if (escolha == "3") {
            mensagem = "Modulo de Historias ainda nao implementado visualmente.";
        } else if (escolha == "4") {
            rodando = false;
        } else {
            mensagem = "Opcao invalida.";
        }
    }
}
