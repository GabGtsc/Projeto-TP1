#pragma once

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

/**
 * @brief Interface para o serviço de Cadastro.
 * 
 * Define o contrato para gerenciamento de cadastros de usuários.
 */
class IServicoCadastro {
public:
  virtual ~IServicoCadastro() = default;

  /**
   * @brief Lê os dados de uma pessoa.
   * @param email E-mail da pessoa a ser lida.
   * @param pessoa Objeto preenchido com os dados lidos.
   * @return true se sucesso.
   */
  virtual bool ler(const Email &email, Pessoa &pessoa) = 0;

  /**
   * @brief Cria um novo registro de pessoa.
   * @param pessoa Objeto pessoa com os dados a serem criados.
   * @return true se sucesso.
   */
  virtual bool criar(const Pessoa &pessoa) = 0;

  /**
   * @brief Atualiza os dados de uma pessoa.
   * @param pessoa Objeto pessoa com os novos dados.
   * @return true se sucesso.
   */
  virtual bool atualizar(const Pessoa &pessoa) = 0;

  /**
   * @brief Exclui uma pessoa do sistema.
   * @param email E-mail da pessoa a ser excluída.
   * @return true se sucesso.
   */
  virtual bool excluir(const Email &email) = 0;
};
