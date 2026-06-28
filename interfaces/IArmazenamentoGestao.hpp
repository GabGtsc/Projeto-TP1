#pragma once

#include <vector>

#include "../dominios/Codigo.hpp"
#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"
#include "../entidades/HistoriaDeUsuario.hpp"
#include "../entidades/PlanoDeSprint.hpp"
#include "../entidades/Projeto.hpp"

class IArmazenamentoGestao {
public:
  virtual ~IArmazenamentoGestao() = default;

  // PROJETO
  virtual bool criarProjeto(const Projeto &projeto) = 0;
  virtual bool lerProjeto(const Codigo &codigo, Projeto &projeto) = 0;
  virtual bool atualizarProjeto(const Projeto &projeto) = 0;
  virtual bool excluirProjeto(const Codigo &codigo) = 0;
  virtual bool associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa) = 0;
  virtual std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) = 0;
  virtual std::vector<Codigo> listarTodosProjetos() = 0;

  // PLANO DE SPRINT
  virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) = 0;
  virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;
  virtual bool associarSprintProjeto(const Codigo &codigoSprint, const Codigo &codigoProjeto) = 0;
  virtual std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) = 0;

  // HISTORIA DE USUARIO
  virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) = 0;
  virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;
  
  // Associacoes de Historia
  virtual bool associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto) = 0;
  virtual std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) = 0;
  
  virtual bool associarHistoriaSprint(const Codigo &codigoHistoria, const Codigo &codigoSprint) = 0;
  virtual std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) = 0;
  
  virtual bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
  virtual bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
  virtual std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) = 0;
};
