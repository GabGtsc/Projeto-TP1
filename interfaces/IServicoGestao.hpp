#pragma once

#include <vector>

#include "../dominios/Codigo.hpp"
#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"

#include "../entidades/HistoriaDeUsuario.hpp"
#include "../entidades/PlanoDeSprint.hpp"
#include "../entidades/Projeto.hpp"

class IServicoGestao {
public:
  virtual ~IServicoGestao() = default;

  // servicos de projeto ID 5 - 8
  virtual bool criarProjeto(const Projeto &projeto) = 0;
  virtual bool lerProjeto(const Codigo &codigo, const Projeto *projeto) = 0;
  virtual bool atualizarProjeto(const Projeto &projeto) = 0;
  virtual bool excluirProjeto(const Codigo &codigo) = 0;

  // servicos de plano de sprint ID 9 - 12
  virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool lerPlanoDeSprint(const Codigo &codigo, const PlanoDeSprint *plano) = 0;
  virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;

  // servicos de historia de usuario ID 13 - 16
  virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool lerHistoriaDeUsuario(const Codigo &codigo, const HistoriaDeUsuario *historia) = 0;
  virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;

  // ID 17: Estabelecer Associação entre História de Usuário e Pessoa
  virtual bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

  // ID 18: Remover Associação entre História de Usuário e Pessoa
  virtual bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

  // ID 19: Listar Projetos associados a Pessoa
  virtual std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) = 0;

  // ID 20: Listar Histórias de Usuário associadas a Projeto
  virtual std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) = 0;

  // ID 21: Listar Planos de Sprint associados a Projeto
  virtual std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) = 0;

  // ID 22: Listar Histórias de Usuário associadas a Plano de Sprint
  virtual std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) = 0;

  // ID 23: Listar Histórias de Usuário associadas a Pessoa
  virtual std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) = 0;

  // ID 24: Mover História de Usuário de Projeto para Plano de Sprint
  virtual bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                                       const Codigo &codigoSprint) = 0;

  // ID 25: Alterar Estado de História de Usuário (A Fazer -> Fazendo -> Feito)
  virtual bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) = 0;
};
