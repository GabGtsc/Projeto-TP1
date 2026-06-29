#pragma once

#include "../../interfaces/IServicoAutenticacao.hpp"
#include "../../interfaces/IArmazenamentoAutenticacao.hpp"

/**
 * @class CntrServicoAutenticacao
 * @brief Controladora de serviço responsável pela lógica de autenticação.
 *
 * Implementa a interface IServicoAutenticacao. Utiliza a camada de dados 
 * (via IArmazenamentoAutenticacao) para buscar o registro e comparar credenciais.
 */
class CntrServicoAutenticacao : public IServicoAutenticacao {
private:
  IArmazenamentoAutenticacao *armazenamento;

public:
  /**
   * @brief Construtor da controladora com injeção de dependência.
   * @param armazenamento Ponteiro para o armazenamento de dados.
   */
  CntrServicoAutenticacao(IArmazenamentoAutenticacao *armazenamento) : armazenamento(armazenamento) {}

  /// @copydoc IServicoAutenticacao::autenticar
  bool autenticar(const Email &email, const Senha &senha, Nome &nome, Papel &papel) override;
};
