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
 * pelos serviços (IArmazenamentoAutenticacao, IArmazenamentoCadastro).
 */
class CntrDados : public IArmazenamentoAutenticacao, public IArmazenamentoCadastro, public IArmazenamentoGestao {
private:
  ContPessoas contPessoas;
  ContProjetos contProjetos;
  ContPlanos contPlanos;
  ContHistorias contHistorias;

public:
  CntrDados();

  // Implementação de IArmazenamentoAutenticacao
  /**
   * @brief Obtém os dados de uma pessoa para autenticação.
   * @param email E-mail da pessoa a buscar.
   * @param pessoa Referência para preencher os dados.
   * @return true se encontrada com sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada.
   */
  bool obterPessoa(const Email &email, Pessoa &pessoa) override;

  // Implementação de IArmazenamentoCadastro
  /**
   * @brief Cria um novo registro de Pessoa.
   * @param pessoa Objeto a ser inserido.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se o e-mail já existir.
   */
  bool criar(const Pessoa &pessoa) override;

  /**
   * @brief Lê os dados de uma Pessoa pelo e-mail.
   * @param email Chave primária.
   * @param pessoa Objeto para preencher os dados.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada.
   */
  bool ler(const Email &email, Pessoa &pessoa) override;

  /**
   * @brief Atualiza um registro existente de Pessoa.
   * @param pessoa Objeto com os novos dados.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não existir para atualizar.
   */
  bool atualizar(const Pessoa &pessoa) override;

  /**
   * @brief Exclui um registro de Pessoa pelo e-mail.
   * @param email Chave primária.
   * @return true em caso de sucesso.
   * @throw std::invalid_argument se a pessoa não for encontrada para exclusão.
   */
  bool excluir(const Email &email) override;

  // ================= GESTAO =================

  // PROJETO
  bool criarProjeto(const Projeto &projeto) override;
  bool lerProjeto(const Codigo &codigo, Projeto &projeto) override;
  bool atualizarProjeto(const Projeto &projeto) override;
  bool excluirProjeto(const Codigo &codigo) override;
  bool associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa) override;
  std::vector<Codigo> listarProjetosDePessoa(const Email &emailPessoa) override;
  std::vector<Codigo> listarTodosProjetos() override;

  // PLANO DE SPRINT
  bool criarPlanoDeSprint(const PlanoDeSprint &plano) override;
  bool lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) override;
  bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override;
  bool excluirPlanoDeSprint(const Codigo &codigo) override;
  bool associarSprintProjeto(const Codigo &codigoSprint, const Codigo &codigoProjeto) override;
  std::vector<Codigo> listarSprintsDeProjeto(const Codigo &codigoProjeto) override;

  // HISTORIA DE USUARIO
  bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  bool lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) override;
  bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;
  bool excluirHistoriaDeUsuario(const Codigo &codigo) override;
  
  bool associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto) override;
  std::vector<Codigo> listarHistoriasDeProjeto(const Codigo &codigoProjeto) override;
  
  bool associarHistoriaSprint(const Codigo &codigoHistoria, const Codigo &codigoSprint) override;
  std::vector<Codigo> listarHistoriasDeSprint(const Codigo &codigoSprint) override;
  
  bool associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  bool desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
  std::vector<Codigo> listarHistoriasDePessoa(const Email &emailPessoa) override;
};
