#pragma once

#include "../dominios/Email.hpp"

/**
 * @struct ResultadoAutenticacao
 * @brief Estrutura que encapsula o resultado de uma tentativa de autenticação.
 * 
 * Contém o status de sucesso da operação e, caso o login tenha sido bem-sucedido, 
 * armazena o objeto Email correspondente ao usuário autenticado.
 */
struct ResultadoAutenticacao {
    bool sucesso; ///< Indica se a autenticação foi realizada com sucesso (true) ou não (false).
    Email email;  ///< Instância do domínio Email contendo o e-mail validado do usuário (se sucesso == true).
};

/**
 * @class IApresentacaoAutenticacao
 * @brief Interface para a camada de apresentação do módulo de Autenticação.
 *
 * Define o contrato para as classes controladoras responsáveis por gerenciar a 
 * interação com o usuário (via terminal ou GUI) durante o fluxo de login no sistema.
 */
class IApresentacaoAutenticacao {
public:
  /**
   * @brief Destrutor virtual padrão.
   */
  virtual ~IApresentacaoAutenticacao() = default;

  /**
   * @brief Executa o fluxo de apresentação para autenticação do usuário.
   * 
   * Método responsável por coletar os dados do usuário, interagir com a camada 
   * de serviço para verificar as credenciais e tratar as saídas/erros para o usuário.
   * 
   * @return Um struct ResultadoAutenticacao contendo o status de sucesso e o e-mail autenticado.
   */
  virtual ResultadoAutenticacao executar() = 0;
};
