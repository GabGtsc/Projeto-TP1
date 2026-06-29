#pragma once

#include "Sessao.hpp"

/**
 * @brief Interface para a camada de apresentação de Gestão.
 * 
 * Define o contrato para a execução da tela/menu de gestão do sistema.
 */
class IApresentacaoGestao {
public:
  virtual ~IApresentacaoGestao() = default;

  /**
   * @brief Executa o fluxo de apresentação de Gestão.
   * @param sessao Sessão atual do usuário autenticado.
   */
  virtual void executar(const Sessao &sessao) = 0;
};
