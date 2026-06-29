#pragma once

#include <vector>

#include "../dominios/Codigo.hpp"
#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"
#include "../entidades/HistoriaDeUsuario.hpp"
#include "../entidades/PlanoDeSprint.hpp"
#include "../entidades/Projeto.hpp"

/**
 * @brief Interface para Armazenamento de Gestão.
 *
 * Define o contrato para acesso e persistência de dados de projetos,
 * planos de sprint e histórias de usuário.
 */
class IArmazenamentoGestao {
public:
  virtual ~IArmazenamentoGestao() = default;

  // PROJETO
  /**
   * @brief Cria um registro de projeto.
   * @param projeto Objeto projeto.
   * @return true se sucesso.
   */
  virtual bool criarProjeto(const Projeto &projeto) = 0;
  
  /**
   * @brief Lê os dados de um projeto.
   * @param codigo Código do projeto.
   * @param projeto Objeto para preencher os dados.
   * @return true se sucesso.
   */
  virtual bool lerProjeto(const Codigo &codigo, Projeto &projeto) = 0;
  
  /**
   * @brief Atualiza um projeto.
   * @param projeto Objeto projeto.
   * @return true se sucesso.
   */
  virtual bool atualizarProjeto(const Projeto &projeto) = 0;
  
  /**
   * @brief Exclui um projeto.
   * @param codigo Código do projeto.
   * @return true se sucesso.
   */
  virtual bool excluirProjeto(const Codigo &codigo) = 0;
  
  /**
   * @brief Associa um projeto a uma pessoa.
   * @param codigoProjeto Código do projeto.
   * @param emailPessoa Email da pessoa.
   * @return true se sucesso.
   */
  virtual bool associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa) = 0;
  
  /**
   * @brief Lista projetos associados a uma pessoa.
   * @param emailPessoa Email da pessoa.
   * @return Vetor com códigos dos projetos.
   */
  virtual std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) = 0;
  
  /**
   * @brief Lista todos os projetos do sistema.
   * @return Vetor com códigos dos projetos.
   */
  virtual std::vector<Codigo> listarTodosProjetos() = 0;

  // PLANO DE SPRINT
  /**
   * @brief Cria um registro de plano de sprint.
   * @param plano Objeto plano.
   * @return true se sucesso.
   */
  virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  
  /**
   * @brief Lê os dados de um plano.
   * @param codigo Código do plano.
   * @param plano Objeto para preencher os dados.
   * @return true se sucesso.
   */
  virtual bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) = 0;
  
  /**
   * @brief Atualiza um plano de sprint.
   * @param plano Objeto plano.
   * @return true se sucesso.
   */
  virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  
  /**
   * @brief Exclui um plano de sprint.
   * @param codigo Código do plano.
   * @return true se sucesso.
   */
  virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;
  
  /**
   * @brief Associa um sprint a um projeto.
   * @param codigoSprint Código do sprint.
   * @param codigoProjeto Código do projeto.
   * @return true se sucesso.
   */
  virtual bool associarSprintProjeto(const Codigo &codigoSprint, const Codigo &codigoProjeto) = 0;
  
  /**
   * @brief Lista sprints associados a um projeto.
   * @param codigoProjeto Código do projeto.
   * @return Vetor com códigos dos sprints.
   */
  virtual std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) = 0;

  // HISTORIA DE USUARIO
  /**
   * @brief Cria uma história de usuário.
   * @param historia Objeto história.
   * @return true se sucesso.
   */
  virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  
  /**
   * @brief Lê uma história de usuário.
   * @param codigo Código da história.
   * @param historia Objeto para preencher.
   * @return true se sucesso.
   */
  virtual bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) = 0;
  
  /**
   * @brief Atualiza uma história de usuário.
   * @param historia Objeto história.
   * @return true se sucesso.
   */
  virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  
  /**
   * @brief Exclui uma história de usuário.
   * @param codigo Código da história.
   * @return true se sucesso.
   */
  virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;
  
  // Associacoes de Historia
  /**
   * @brief Associa uma história a um projeto.
   * @param codigoHistoria Código da história.
   * @param codigoProjeto Código do projeto.
   * @return true se sucesso.
   */
  virtual bool associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto) = 0;
  
  /**
   * @brief Lista histórias de um projeto.
   * @param codigoProjeto Código do projeto.
   * @return Vetor com códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) = 0;
  
  /**
   * @brief Associa uma história a um sprint.
   * @param codigoHistoria Código da história.
   * @param codigoSprint Código do sprint.
   * @return true se sucesso.
   */
  virtual bool associarHistoriaSprint(const Codigo &codigoHistoria, const Codigo &codigoSprint) = 0;
  
  /**
   * @brief Lista histórias de um sprint.
   * @param codigoSprint Código do sprint.
   * @return Vetor com códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) = 0;
  
  /**
   * @brief Associa uma história a uma pessoa.
   * @param codigoHistoria Código da história.
   * @param emailPessoa Email da pessoa.
   * @return true se sucesso.
   */
  virtual bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
  
  /**
   * @brief Desassocia uma história de uma pessoa.
   * @param codigoHistoria Código da história.
   * @param emailPessoa Email da pessoa.
   * @return true se sucesso.
   */
  virtual bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
  
  /**
   * @brief Lista histórias de uma pessoa.
   * @param emailPessoa Email da pessoa.
   * @return Vetor com códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) = 0;
};
