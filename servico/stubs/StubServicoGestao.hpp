#pragma once

#include "../../interfaces/IServicoGestao.hpp"

#include <vector>

#include "../../dominios/Codigo.hpp"
#include "../../dominios/Email.hpp"
#include "../../dominios/Estado.hpp"
#include "../../entidades/HistoriaDeUsuario.hpp"
#include "../../entidades/PlanoDeSprint.hpp"
#include "../../entidades/Projeto.hpp"

class StubServicoGestao : public IServicoGestao {
private:
  bool resultado = true;

public:
  bool criarProjeto(const Projeto &projeto) override { return this->resultado; }
  bool lerProjeto(const Codigo &codigo, const Projeto &projeto) override { return this->resultado; }
  bool atualizarProjeto(const Projeto &projeto) override { return this->resultado; }
  bool excluirProjeto(const Codigo &codigo) override { return this->resultado; }

  bool criarPlanoDeSprint(const PlanoDeSprint &plano) override { return this->resultado; }
  bool lerPlanoDeSprint(const Codigo &codigo, const PlanoDeSprint &plano) override { return this->resultado; }
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override { return this->resultado; }
  bool excluirPlanoDeSprint(const Codigo &codigo) override { return this->resultado; }

  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override { return this->resultado; }
  bool lerHistoriaDeUsuario(const Codigo &codigo, const HistoriaDeUsuario &historia) override {
    return this->resultado;
  }
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override { return this->resultado; }
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override { return this->resultado; }

  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override {
    return this->resultado;
  }

  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override {
    return this->resultado;
  }

  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override { return std::vector<Codigo>(); }

  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override { return std::vector<Codigo>(); }

  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override { return std::vector<Codigo>(); }

  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override { return std::vector<Codigo>(); }

  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override { return std::vector<Codigo>(); }

  bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                               const Codigo &codigoSprint) override {
    return this->resultado;
  }

  bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) override {
    return this->resultado;
  }
};
