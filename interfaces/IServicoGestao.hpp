#pragma once

#include "../dominios/Codigo.cpp"
#include "../entidades/HistoriaDeUsuario.hpp"
#include "../entidades/PlanoDeSprint.hpp"
#include "../entidades/Projeto.hpp"

class IServicoGestao {
public:
  virtual ~IServicoGestao() = default;

  // servicos de projeto ID 5 - 8
  virtual bool criarProjeto(const Projeto &projeto) = 0;
  virtual bool lerProjeto(const Codigo &codigo, const Projeto &projeto) = 0;
  virtual bool atualizarProjeto(const Projeto &projeto) = 0;
  virtual bool excluirProjeto(const Codigo &codigo) = 0;

  // servicos de plano de sprint ID 9 - 12
  virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool lerPlanoDeSprint(const Codigo &codigo, const PlanoDeSprint &plano) = 0;
  virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;

  // servicos de historia de usuario ID 13 - 16
  virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool lerHistoriaDeUsuario(const Codigo &codigo, const HistoriaDeUsuario &historia) = 0;
  virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;
};
