#pragma once

#include "../../interfaces/IServicoGestao.hpp"
#include <vector>

class StubServicoGestao : public IServicoGestao {
private:
  bool resultado = true;

public:
  bool criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) override { return this->resultado; }
  
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
  
  bool atualizarProjeto(const Projeto &projeto) override { return this->resultado; }
  bool excluirProjeto(const Codigo &codigo) override { return this->resultado; }

  bool criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) override { return this->resultado; }
  
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override {
      plano.setCodigo(codigo);
      Texto t; t.setTexto("Sprint Dummy");
      plano.setObjetivo(t);
      Tempo cap; cap.setTempo(10);
      plano.setCapacidade(cap);
      return this->resultado;
  }
  
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override { return this->resultado; }
  bool excluirPlanoDeSprint(const Codigo &codigo) override { return this->resultado; }

  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) override { return this->resultado; }
  
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
  
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override { return this->resultado; }
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override { return this->resultado; }

  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override { return this->resultado; }
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override { return this->resultado; }

  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("PR001");
      lista.push_back(c);
      return lista;
  }

  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS001");
      lista.push_back(c);
      return lista;
  }

  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("SP001");
      lista.push_back(c);
      return lista;
  }

  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS002");
      lista.push_back(c);
      return lista;
  }

  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override {
      std::vector<Codigo> lista;
      Codigo c; c.setCodigo("HS003");
      lista.push_back(c);
      return lista;
  }

  bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto, const Codigo &codigoSprint) override {
    return this->resultado;
  }

  bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) override {
    return this->resultado;
  }
};
