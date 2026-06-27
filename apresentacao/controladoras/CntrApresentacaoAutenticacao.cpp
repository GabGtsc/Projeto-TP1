#include "CntrApresentacaoAutenticacao.hpp"

void CntrApresentacaoAutenticacao::setServico(IServicoAutenticacao* servico) {
    this->servico = servico;
}

void CntrApresentacaoAutenticacao::executar() {
    std::string entradaEmail, entradaSenha;
    Email emailInstancia;
    Senha senhaInstancia;

    while (true) {
        std::cout << "\n===============================\n";
        std::cout << "        TELA DE LOGIN          \n";
        std::cout << "===============================\n";
        
        std::cout << "Digite seu Email (ou 'sair' para voltar): ";
        std::cin >> entradaEmail;
        
        if (entradaEmail == "sair") {
            return;
        }

        std::cout << "Digite sua Senha: ";
        std::cin >> entradaSenha;

        try {
            // Usando os setters exatos dos seus domínios
            emailInstancia.setEmail(entradaEmail);
            senhaInstancia.setSenha(entradaSenha);

            // Chama o serviço (Stub)
            if (servico->autenticar(emailInstancia, senhaInstancia)) {
                std::cout << "\n[SUCESSO] Autenticacao realizada com sucesso!\n";
                this->emailLogado = emailInstancia;
                this->autenticado = true;
                return; // Sai da tela de login
            } else {
                std::cout << "\n[FALHA] Email ou senha incorretos.\n";
            }
        } 
        catch (const std::invalid_argument &exp) {
            std::cout << "\n[ERRO] Formato invalido. Verifique os dados digitados e tente novamente.\n";
        }
    }
}