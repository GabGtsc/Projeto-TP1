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
  void setArmazenamento(IArmazenamentoGestao *arm) { this->armazenamento = arm; }

  // servicos de projeto ID 5 - 8
  bool criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) override;
  bool lerProjeto(const Codigo &codigo, Projeto &projeto) override;
  bool atualizarProjeto(const Projeto &projeto) override;
  bool excluirProjeto(const Codigo &codigo) override;

  // servicos de plano de sprint ID 9 - 12
  bool criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) override;
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override;
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override;
  bool excluirPlanoDeSprint(const Codigo &codigo) override;

  // servicos de historia de usuario ID 13 - 16
  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) override;
  bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) override;
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override;

  // Associações
  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  
  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override;
  std::vector<Codigo> listarTodosProjetos() override;
  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override;
  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override;
  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override;
  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override;
  
  bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                               const Codigo &codigoSprint) override;
  bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) override;
};
