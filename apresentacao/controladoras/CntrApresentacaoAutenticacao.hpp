#pragma once

#include "../../interfaces/IApresentacaoAutenticacao.hpp"
#include "../../interfaces/IServicoAutenticacao.hpp"
#include "../../dominios/Email.hpp"
#include "../../dominios/Senha.hpp"
#include <iostream>

/**
 * @class CntrApresentacaoAutenticacao
 * @brief Classe controladora de apresentação para o módulo de Autenticação.
 *
 * Esta classe é responsável por gerenciar a interface com o usuário durante
 * o processo de login. Ela coleta as entradas de texto (via terminal), 
 * instancia e valida os domínios de Email e Senha, e delega a verificação 
 * das credenciais para a camada de serviço.
 */
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    /// Ponteiro para a interface da camada de serviço de autenticação
    IServicoAutenticacao* servico;
    
    /// Armazena o email do usuário caso a autenticação seja bem-sucedida
    Email emailLogado;
    
    /// Flag que indica se o usuário atual está autenticado no sistema
    bool autenticado = false;

public:
    /**
     * @brief Executa o fluxo de interação com o usuário para login.
     * * Exibe os menus no terminal, solicita os dados, trata possíveis exceções 
     * de formatação incorreta lançadas pelos domínios e informa o resultado 
     * da tentativa de autenticação.
     */
    void executar() override;

    /**
     * @brief Estabelece a ligação entre a controladora de apresentação e o serviço.
     * * @param servico Ponteiro para um objeto que implemente IServicoAutenticacao.
     */
    void setServico(IServicoAutenticacao* servico);

    /**
     * @brief Retorna o e-mail do usuário logado.
     * * @return Objeto da classe Email contendo o e-mail validado e autenticado.
     */
    Email getEmailLogado() const { return emailLogado; }

    /**
     * @brief Verifica o estado de autenticação do usuário.
     * * @return true Se o usuário logou com sucesso.
     * @return false Caso o usuário não esteja logado.
     */
    bool isAutenticado() const { return autenticado; }
};