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

public:
    /**
     * @brief Construtor da controladora de apresentação com injeção de dependência.
     * @param servico Ponteiro para um objeto que implemente IServicoAutenticacao.
     */
    CntrApresentacaoAutenticacao(IServicoAutenticacao* servico) : servico(servico) {}

    /**
     * @brief Executa o fluxo de interação com o usuário para login.
     * Exibe os menus no terminal, solicita os dados, trata possíveis exceções 
     * de formatação incorreta lançadas pelos domínios e informa o resultado 
     * da tentativa de autenticação.
     * @return Um struct ResultadoAutenticacao contendo o status de sucesso e o Email logado (se houver).
     */
    ResultadoAutenticacao executar() override;
};