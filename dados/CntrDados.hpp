#pragma once

#include "../interfaces/IArmazenamentoAutenticacao.hpp"
#include "../interfaces/IArmazenamentoCadastro.hpp"
#include "ContPessoas.hpp"
#include <stdexcept>

/**
 * @class CntrDados
 * @brief Controladora de dados do sistema.
 *
 * Responsável por gerenciar os contêineres de dados (como ContPessoas) e
 * fornecer a implementação real para as interfaces de acesso a dados usadas
 * pelos serviços (IArmazenamentoAutenticacao, IArmazenamentoCadastro).
 */
class CntrDados : public IArmazenamentoAutenticacao, public IArmazenamentoCadastro {
private:
  ContPessoas contPessoas;

public:
  // Implementação de IArmazenamentoAutenticacao
  /**
   * @brief Obtém os dados de uma pessoa para autenticação.
   * @param email E-mail da pessoa a buscar.
   * @param pessoa Referência para preencher os dados.
   * @return true se encontrada com sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada.
   */
  bool obterPessoa(const Email &email, Pessoa &pessoa) override;

  // Implementação de IArmazenamentoCadastro
  /**
   * @brief Cria um novo registro de Pessoa.
   * @param pessoa Objeto a ser inserido.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se o e-mail já existir.
   */
  bool criar(const Pessoa &pessoa) override;

  /**
   * @brief Lê os dados de uma Pessoa pelo e-mail.
   * @param email Chave primária.
   * @param pessoa Objeto para preencher os dados.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada.
   */
  bool ler(const Email &email, Pessoa &pessoa) override;

  /**
   * @brief Atualiza um registro existente de Pessoa.
   * @param pessoa Objeto com os novos dados.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não existir para atualizar.
   */
  bool atualizar(const Pessoa &pessoa) override;

  /**
   * @brief Exclui um registro de Pessoa pelo e-mail.
   * @param email Chave primária.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada para exclusão.
   */
  bool excluir(const Email &email) override;
};
