#pragma once

#include "../../interfaces/IServicoGestao.hpp"
#include "../../interfaces/IArmazenamentoGestao.hpp"
#include <stdexcept>

/**
 * @class CntrServicoGestao
 * @brief Controladora de Serviço de Gestão.
 *
 * Implementa a interface IServicoGestao aplicando as regras de negócio
 * e orquestrando as chamadas para a camada de armazenamento (IArmazenamentoGestao).
 */
class CntrServicoGestao : public IServicoGestao {
private:
  IArmazenamentoGestao *armazenamento;

public:
  /**
   * @brief Define o armazenamento a ser utilizado pela controladora.
   * @param arm Ponteiro para o armazenamento de gestão.
   */
  void setArmazenamento(IArmazenamentoGestao *arm) { this->armazenamento = arm; }

  // servicos de projeto ID 5 - 8
  /// @copydoc IServicoGestao::criarProjeto
  bool criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) override;
  /// @copydoc IServicoGestao::lerProjeto
  bool lerProjeto(const Codigo &codigo, Projeto &projeto) override;
  /// @copydoc IServicoGestao::atualizarProjeto
  bool atualizarProjeto(const Projeto &projeto) override;
  /// @copydoc IServicoGestao::excluirProjeto
  bool excluirProjeto(const Codigo &codigo) override;

  // servicos de plano de sprint ID 9 - 12
  /// @copydoc IServicoGestao::criarPlanoDeSprint
  bool criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) override;
  /// @copydoc IServicoGestao::lerPlanoDeSprint
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override;
  /// @copydoc IServicoGestao::atualizarPlanoDeSprint
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override;
  /// @copydoc IServicoGestao::excluirPlanoDeSprint
  bool excluirPlanoDeSprint(const Codigo &codigo) override;

  // servicos de historia de usuario ID 13 - 16
  /// @copydoc IServicoGestao::criarHistoriaDeUsuario
  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) override;
  /// @copydoc IServicoGestao::lerHistoriaDeUsuario
  bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) override;
  /// @copydoc IServicoGestao::atualizarHistoriaDeUsuario
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  /// @copydoc IServicoGestao::excluirHistoriaDeUsuario
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override;

  // Associações
  /// @copydoc IServicoGestao::associarHistoriaPessoa
  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  /// @copydoc IServicoGestao::desassociarHistoriaPessoa
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  
  /// @copydoc IServicoGestao::listarProjetosDePessoa
  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override;
  /// @copydoc IServicoGestao::listarTodosProjetos
  std::vector<Codigo> listarTodosProjetos() override;
  /// @copydoc IServicoGestao::listarHistoriasDeProjeto
  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override;
  /// @copydoc IServicoGestao::listarSprintsDeProjeto
  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override;
  /// @copydoc IServicoGestao::listarHistoriasDeSprint
  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override;
  /// @copydoc IServicoGestao::listarHistoriasDePessoa
  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override;
  
  /// @copydoc IServicoGestao::moverHistoriaParaSprint
  bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                               const Codigo &codigoSprint) override;
  /// @copydoc IServicoGestao::alterarEstadoHistoria
  bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) override;
};
