#include "CntrApresentacaoAutenticacao.hpp"
#include <cstdlib>

namespace {
    void limparTela() {
#if defined _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }
}

ResultadoAutenticacao CntrApresentacaoAutenticacao::executar() {
    std::string entradaEmail, entradaSenha;
    Email emailInstancia;
    Senha senhaInstancia;
    ResultadoAutenticacao resultado = {false, Email()};
    std::string mensagemErro = "";

    while (true) {
        limparTela();
        std::cout << "\n===============================\n";
        std::cout << "        TELA DE LOGIN          \n";
        std::cout << "===============================\n";
        
        if (!mensagemErro.empty()) {
            std::cout << "[ERRO] " << mensagemErro << "\n\n";
            mensagemErro = ""; // Limpa a mensagem após exibir
        }
        
        std::cout << "Digite seu Email (ou 'sair' para voltar): ";
        std::cin >> entradaEmail;
        
        if (entradaEmail == "sair") {
            return resultado;
        }

        std::cout << "Digite sua Senha: ";
        std::cin >> entradaSenha;

        try {
            emailInstancia.setEmail(entradaEmail);
            senhaInstancia.setSenha(entradaSenha);

            Nome nomeInstancia;
            if (servico->autenticar(emailInstancia, senhaInstancia, nomeInstancia)) {
                // Sucesso na autenticação
                resultado.sucesso = true;
                resultado.email = emailInstancia;
                resultado.nome = nomeInstancia;
                return resultado; // Sai da tela retornando sucesso (a main cuidará de avisar o login)
            } else {
                mensagemErro = "Email ou senha incorretos.";
            }
        } 
        catch (const std::invalid_argument &exp) {
            mensagemErro = exp.what();
        }
    }
}