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

Sessao CntrApresentacaoAutenticacao::executar() {
    std::string entradaEmail, entradaSenha;
    Email emailInstancia;
    Senha senhaInstancia;
    Sessao resultado = {false, Email(), Nome(), Papel()};
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
            Papel papelInstancia;
            if (servico->autenticar(emailInstancia, senhaInstancia, nomeInstancia, papelInstancia)) {
                // Sucesso na autenticação
                resultado.logado = true;
                resultado.email = emailInstancia;
                resultado.nome = nomeInstancia;
                resultado.papel = papelInstancia;
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