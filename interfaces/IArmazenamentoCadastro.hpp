#pragma once

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

/**
 * @class IArmazenamentoCadastro
 * @brief Interface de acesso aos dados para o módulo de Cadastro.
 *
 * Define o contrato de CRUD (Criar, Ler, Atualizar, Excluir) que a camada 
 * de serviço de cadastro utilizará para persistir as entidades no armazenamento.
 */
class IArmazenamentoCadastro {
public:
  /**
   * @brief Cria um registro de pessoa no armazenamento.
   * @param pessoa Objeto pessoa contendo os dados a serem salvos.
   * @return true em caso de sucesso, false caso contrário (ex: e-mail já existe).
   */
  virtual bool criar(const Pessoa &pessoa) = 0;

  /**
   * @brief Lê os dados de uma pessoa através do seu e-mail.
   * @param email Chave primária (e-mail) da pessoa a ser lida.
   * @param pessoa Referência que será populada com os dados recuperados.
   * @return true se encontrada, false caso não exista.
   */
  virtual bool ler(const Email &email, Pessoa &pessoa) = 0;

  /**
   * @brief Atualiza os dados de uma pessoa existente.
   * @param pessoa Objeto contendo o e-mail da pessoa a atualizar e os novos dados.
   * @return true se sucesso, false caso a pessoa não seja encontrada.
   */
  virtual bool atualizar(const Pessoa &pessoa) = 0;

  /**
   * @brief Exclui o registro de uma pessoa pelo seu e-mail.
   * @param email E-mail da pessoa a ser removida.
   * @return true se sucesso, false caso não seja encontrada.
   */
  virtual bool excluir(const Email &email) = 0;

  /**
   * @brief Destrutor virtual padrão.
   */
  virtual ~IArmazenamentoCadastro() = default;
};
