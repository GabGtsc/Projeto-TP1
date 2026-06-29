#pragma once

#include "../interfaces/IArmazenamentoAutenticacao.hpp"
#include "../interfaces/IArmazenamentoCadastro.hpp"
#include "../interfaces/IArmazenamentoGestao.hpp"
#include "ContPessoas.hpp"
#include "ContProjetos.hpp"
#include "ContPlanos.hpp"
#include "ContHistorias.hpp"
#include <stdexcept>

/**
 * @class CntrDados
 * @brief Controladora de dados do sistema.
 *
 * Responsável por gerenciar os contêineres de dados (como ContPessoas) e
 * fornecer a implementação real para as interfaces de acesso a dados usadas
 * pelos serviços (IArmazenamentoAutenticacao, IArmazenamentoCadastro e IArmazenamentoGestao).
 */
class CntrDados : public IArmazenamentoAutenticacao, public IArmazenamentoCadastro, public IArmazenamentoGestao {
private:
  ContPessoas contPessoas;
  ContProjetos contProjetos;
  ContPlanos contPlanos;
  ContHistorias contHistorias;

public:
  /**
   * @brief Construtor padrão de CntrDados.
   */
  CntrDados();

  // Implementação de IArmazenamentoAutenticacao
  /// @copydoc IArmazenamentoAutenticacao::obterPessoa
  bool obterPessoa(const Email &email, Pessoa &pessoa) override;

  // Implementação de IArmazenamentoCadastro
  /// @copydoc IArmazenamentoCadastro::criar
  bool criar(const Pessoa &pessoa) override;
  /// @copydoc IArmazenamentoCadastro::ler
  bool ler(const Email &email, Pessoa &pessoa) override;
  /// @copydoc IArmazenamentoCadastro::atualizar
  bool atualizar(const Pessoa &pessoa) override;
  /// @copydoc IArmazenamentoCadastro::excluir
  bool excluir(const Email &email) override;

  // ================= GESTAO =================

  // PROJETO
  /// @copydoc IArmazenamentoGestao::criarProjeto
  bool criarProjeto(const Projeto &projeto) override;
  /// @copydoc IArmazenamentoGestao::lerProjeto
  bool lerProjeto(const Codigo &codigo, Projeto &projeto) override;
  /// @copydoc IArmazenamentoGestao::atualizarProjeto
  bool atualizarProjeto(const Projeto &projeto) override;
  /// @copydoc IArmazenamentoGestao::excluirProjeto
  bool excluirProjeto(const Codigo &codigo) override;
  /// @copydoc IArmazenamentoGestao::associarProjetoPessoa
  bool associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa) override;
  /// @copydoc IArmazenamentoGestao::listarProjetosDePessoa
  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override;
  /// @copydoc IArmazenamentoGestao::listarTodosProjetos
  std::vector<Codigo> listarTodosProjetos() override;

  // PLANO DE SPRINT
  /// @copydoc IArmazenamentoGestao::criarPlanoDeSprint
  bool criarPlanoDeSprint(const PlanoDeSprint &plano) override;
  /// @copydoc IArmazenamentoGestao::lerPlanoDeSprint
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override;
  /// @copydoc IArmazenamentoGestao::atualizarPlanoDeSprint
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override;
  /// @copydoc IArmazenamentoGestao::excluirPlanoDeSprint
  bool excluirPlanoDeSprint(const Codigo &codigo) override;
  /// @copydoc IArmazenamentoGestao::associarSprintProjeto
  bool associarSprintProjeto(const Codigo &codigoSprint, const Codigo &codigoProjeto) override;
  /// @copydoc IArmazenamentoGestao::listarSprintsDeProjeto
  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override;

  // HISTORIA DE USUARIO
  /// @copydoc IArmazenamentoGestao::criarHistoriaDeUsuario
  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  /// @copydoc IArmazenamentoGestao::lerHistoriaDeUsuario
  bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) override;
  /// @copydoc IArmazenamentoGestao::atualizarHistoriaDeUsuario
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  /// @copydoc IArmazenamentoGestao::excluirHistoriaDeUsuario
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override;
  
  /// @copydoc IArmazenamentoGestao::associarHistoriaProjeto
  bool associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto) override;
  /// @copydoc IArmazenamentoGestao::listarHistoriasDeProjeto
  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override;
  
  /// @copydoc IArmazenamentoGestao::associarHistoriaSprint
  bool associarHistoriaSprint(const Codigo &codigoHistoria, const Codigo &codigoSprint) override;
  /// @copydoc IArmazenamentoGestao::listarHistoriasDeSprint
  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override;
  
  /// @copydoc IArmazenamentoGestao::associarHistoriaPessoa
  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  /// @copydoc IArmazenamentoGestao::desassociarHistoriaPessoa
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  /// @copydoc IArmazenamentoGestao::listarHistoriasDePessoa
  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override;
};
