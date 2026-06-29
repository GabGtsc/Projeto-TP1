#pragma once

#include <vector>

#include "../dominios/Codigo.hpp"
#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"

#include "../entidades/HistoriaDeUsuario.hpp"
#include "../entidades/PlanoDeSprint.hpp"
#include "../entidades/Projeto.hpp"

/**
 * @brief Interface para o Serviço de Gestão.
 *
 * Define o contrato para serviços de gestão de projetos, planos de sprint
 * e histórias de usuário, bem como as associações entre eles e as pessoas.
 */
class IServicoGestao {
public:
  virtual ~IServicoGestao() = default;

  // servicos de projeto ID 5 - 8
  
  /**
   * @brief Cria um projeto.
   * @param projeto Objeto projeto a ser criado.
   * @param emailPO Email do Product Owner.
   * @param emailSM Email do Scrum Master.
   * @return true se sucesso.
   */
  virtual bool criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) = 0;
  
  /**
   * @brief Lê os dados de um projeto.
   * @param codigo Código do projeto.
   * @param projeto Referência para retorno dos dados.
   * @return true se sucesso.
   */
  virtual bool lerProjeto(const Codigo &codigo, Projeto &projeto) = 0;
  
  /**
   * @brief Atualiza os dados de um projeto.
   * @param projeto Objeto projeto com novos dados.
   * @return true se sucesso.
   */
  virtual bool atualizarProjeto(const Projeto &projeto) = 0;
  
  /**
   * @brief Exclui um projeto.
   * @param codigo Código do projeto.
   * @return true se sucesso.
   */
  virtual bool excluirProjeto(const Codigo &codigo) = 0;

  // servicos de plano de sprint ID 9 - 12
  
  /**
   * @brief Cria um plano de sprint.
   * @param plano Objeto plano a ser criado.
   * @param codigoProjeto Código do projeto associado.
   * @return true se sucesso.
   */
  virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) = 0;
  
  /**
   * @brief Lê os dados de um plano de sprint.
   * @param codigo Código do plano.
   * @param plano Referência para retorno dos dados.
   * @return true se sucesso.
   */
  virtual bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) = 0;
  
  /**
   * @brief Atualiza um plano de sprint.
   * @param plano Objeto plano com novos dados.
   * @return true se sucesso.
   */
  virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;
  
  /**
   * @brief Exclui um plano de sprint.
   * @param codigo Código do plano.
   * @return true se sucesso.
   */
  virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;

  // servicos de historia de usuario ID 13 - 16
  
  /**
   * @brief Cria uma história de usuário.
   * @param historia Objeto história a ser criado.
   * @param codigoProjeto Código do projeto associado.
   * @return true se sucesso.
   */
  virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) = 0;
  
  /**
   * @brief Lê os dados de uma história de usuário.
   * @param codigo Código da história.
   * @param historia Referência para retorno dos dados.
   * @return true se sucesso.
   */
  virtual bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) = 0;
  
  /**
   * @brief Atualiza uma história de usuário.
   * @param historia Objeto história com novos dados.
   * @return true se sucesso.
   */
  virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;
  
  /**
   * @brief Exclui uma história de usuário.
   * @param codigo Código da história.
   * @return true se sucesso.
   */
  virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;

  // ID 17: Estabelecer Associação entre História de Usuário e Pessoa
  /**
   * @brief Associa uma história a uma pessoa (Desenvolvedor).
   * @param codigoHistoria Código da história.
   * @param emailPessoa Email do desenvolvedor.
   * @return true se sucesso.
   */
  virtual bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

  // ID 18: Remover Associação entre História de Usuário e Pessoa
  /**
   * @brief Desassocia uma história de uma pessoa.
   * @param codigoHistoria Código da história.
   * @param emailPessoa Email da pessoa.
   * @return true se sucesso.
   */
  virtual bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

  // ID 19: Listar Projetos associados a Pessoa
  /**
   * @brief Lista projetos de uma determinada pessoa.
   * @param emailPessoa Email da pessoa.
   * @return Vetor de códigos de projetos.
   */
  virtual std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) = 0;
  
  // Extra: Listar TODOS os Projetos registrados
  /**
   * @brief Lista todos os projetos registrados no sistema.
   * @return Vetor de códigos de todos os projetos.
   */
  virtual std::vector<Codigo> listarTodosProjetos() = 0;

  // ID 20: Listar Histórias de Usuário associadas a Projeto
  /**
   * @brief Lista as histórias de usuário de um projeto.
   * @param codigoProjeto Código do projeto.
   * @return Vetor de códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) = 0;

  // ID 21: Listar Planos de Sprint associados a Projeto
  /**
   * @brief Lista os planos de sprint de um projeto.
   * @param codigoProjeto Código do projeto.
   * @return Vetor de códigos dos planos.
   */
  virtual std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) = 0;

  // ID 22: Listar Histórias de Usuário associadas a Plano de Sprint
  /**
   * @brief Lista as histórias de usuário de um plano de sprint.
   * @param codigoSprint Código do plano.
   * @return Vetor de códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) = 0;

  // ID 23: Listar Histórias de Usuário associadas a Pessoa
  /**
   * @brief Lista as histórias de usuário de uma pessoa.
   * @param emailPessoa Email da pessoa.
   * @return Vetor de códigos das histórias.
   */
  virtual std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) = 0;

  // ID 24: Mover História de Usuário de Projeto para Plano de Sprint
  /**
   * @brief Move uma história de usuário de um projeto para um plano de sprint.
   * @param codigoHistoria Código da história.
   * @param codigoProjeto Código do projeto atual.
   * @param codigoSprint Código do sprint de destino.
   * @return true se sucesso.
   */
  virtual bool moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                                       const Codigo &codigoSprint) = 0;

  // ID 25: Alterar Estado de História de Usuário (A Fazer -> Fazendo -> Feito)
  /**
   * @brief Altera o estado de uma história de usuário.
   * @param codigoHistoria Código da história.
   * @param novoEstado Novo estado a ser aplicado.
   * @return true se sucesso.
   */
  virtual bool alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) = 0;
};
