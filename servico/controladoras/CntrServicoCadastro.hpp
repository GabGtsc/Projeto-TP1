#pragma once

#include "../../interfaces/IServicoCadastro.hpp"
#include "../../interfaces/IArmazenamentoCadastro.hpp"

/**
 * @class CntrServicoCadastro
 * @brief Controladora de serviço responsável pela lógica de negócio do cadastro (CRUD).
 *
 * Implementa a interface IServicoCadastro. Delega as operações de persistência
 * para a camada de armazenamento, capturando exceções (como std::invalid_argument)
 * e convertendo em retornos booleanos.
 */
class CntrServicoCadastro : public IServicoCadastro {
private:
  IArmazenamentoCadastro *armazenamento;

public:
  /**
   * @brief Construtor da controladora com injeção de dependência.
   * @param armazenamento Ponteiro para o armazenamento de dados.
   */
  CntrServicoCadastro(IArmazenamentoCadastro *armazenamento) : armazenamento(armazenamento) {}

  bool ler(const Email &email, Pessoa &pessoa) override;
  bool criar(const Pessoa &pessoa) override;
  bool atualizar(const Pessoa &pessoa) override;
  bool excluir(const Email &email) override;
};
