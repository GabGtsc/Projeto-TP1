#pragma once

#include "Sessao.hpp"

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
   * @return Um struct Sessao contendo o status de sucesso e os dados da pessoa autenticada.
   */
  virtual Sessao executar() = 0;
};
