#pragma once

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

/**
 * @class IArmazenamentoAutenticacao
 * @brief Interface de acesso aos dados para o módulo de Autenticação.
 *
 * Define o contrato para que o serviço de autenticação possa recuperar
 * os dados necessários da camada de armazenamento para validar as credenciais.
 */
class IArmazenamentoAutenticacao {
public:
  /**
   * @brief Obtém os dados de uma pessoa a partir de seu e-mail.
   *
   * @param email E-mail da pessoa a ser consultada.
   * @param pessoa Referência onde a pessoa encontrada será populada.
   * @return true se a pessoa foi encontrada.
   * @throw std::invalid_argument se a pessoa não for encontrada.
   */
  virtual bool obterPessoa(const Email &email, Pessoa &pessoa) = 0;

  /**
   * @brief Destrutor virtual padrão.
   */
  virtual ~IArmazenamentoAutenticacao() = default;
};
