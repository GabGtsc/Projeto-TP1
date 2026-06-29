#pragma once

#include "../../interfaces/IServicoGestao.hpp"
#include <vector>

/**
 * @class StubServicoGestao
 * @brief Classe stub para simular o serviço de gestão.
 */
class StubServicoGestao : public IServicoGestao {
private:
  bool resultado = true;

public:
  /// @copydoc IServicoGestao::criarProjeto
  bool criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) override { return this->resultado; }
  
  /// @copydoc IServicoGestao::lerProjeto
  bool lerProjeto(const Codigo &codigo, Projeto &projeto) override {
      projeto.setCodigo(codigo);
      Nome n; n.setNome("Proj Teste");
      projeto.setNome(n);
      Data d1; d1.setData("01/01/2024");
      projeto.setInicio(d1);
      Data d2; d2.setData("31/12/2024");
      projeto.setTermino(d2);
      return this->resultado;
  }
  
  /// @copydoc IServicoGestao::atualizarProjeto
  bool atualizarProjeto(const Projeto &projeto) override { return this->resultado; }
  /// @copydoc IServicoGestao::excluirProjeto
  bool excluirProjeto(const Codigo &codigo) override { return this->resultado; }

  /// @copydoc IServicoGestao::criarPlanoDeSprint
  bool criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) override { return this->resultado; }
  
  /// @copydoc IServicoGestao::lerPlanoDeSprint
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override {
      plano.setCodigo(codigo);
      Texto t; t.setTexto("Sprint Dummy");
      plano.setObjetivo(t);
      Tempo cap; cap.setTempo(10);
      plano.setCapacidade(cap);
      return this->resultado;
  }
  
  /// @copydoc IServicoGestao::atualizarPlanoDeSprint
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override { return this->resultado; }
  /// @copydoc IServicoGestao::excluirPlanoDeSprint
  bool excluirPlanoDeSprint(const Codigo &codigo) override { return this->resultado; }

  /// @copydoc IServicoGestao::criarHistoriaDeUsuario
  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) override { return this->resultado; }
  
  /// @copydoc IServicoGestao::lerHistoriaDeUsuario
  bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) override {
      historia.setCodigo(codigo);
      Texto titulo; titulo.setTexto("Titulo Hist");
      historia.setTitulo(titulo);
      Texto papel; papel.setTexto("Desenvolvedor");
      historia.setPapel(papel);
      Texto acao; acao.setTexto("Acao Hist");
      historia.setAcao(acao);
      Texto valor; valor.setTexto("Valor Hist");
      historia.setValor(valor);
      Tempo est; est.setTempo(5);
      historia.setEstimativa(est);
      Prioridade p; p.setPrioridade("MEDIA");
      historia.setPrioridade(p);
      Estado e; e.setEstado("A FAZER");
      historia.setEstado(e);
      return this->resultado;
  }
  
  /// @copydoc IServicoGestao::atualizarHistoriaDeUsuario
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override { return this->resultado; }
  /// @copydoc IServicoGestao::excluirHistoriaDeUsuario
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override { return this->resultado; }

  /// @copydoc IServicoGestao::associarHistoriaPessoa
  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override { return this->resultado; }
  /// @copydoc IServicoGestao::desassociarHistoriaPessoa
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override { return this->resultado; }

  /// @copydoc IServicoGestao::listarProjetosDePessoa
  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("PR001");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::listarTodosProjetos
  std::vector<Codigo> listarTodosProjetos() override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("PR001");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::listarHistoriasDeProjeto
  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS001");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::listarSprintsDeProjeto
  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("SP001");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::listarHistoriasDeSprint
  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS002");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::listarHistoriasDePessoa
  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS003");
      lista.push_back(c);
      return lista;
  }

  /// @copydoc IServicoGestao::moverHistoriaParaSprint
  bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto, const Codigo &codigoSprint) override {
    return this->resultado;
  }

  /// @copydoc IServicoGestao::alterarEstadoHistoria
  bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) override {
    return this->resultado;
  }
};
