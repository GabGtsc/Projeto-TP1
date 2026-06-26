#pragma once

#include "../dominios/Codigo.hpp"
#include "../dominios/Estado.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Tempo.hpp"
#include "../dominios/Texto.hpp"

/**
 * @class HistoriaDeUsuario
 * @brief Entidade que representa uma história de usuário no sistema.
 *
 * A classe HistoriaDeUsuario armazena as informações relativas a uma história
 * de usuário. Ela é composta pelas classes de domínio Codigo, Texto (para
 * título, papel, ação e valor), Tempo (para estimativa), Prioridade e Estado.
 * O código atua como a chave primária (identificador único) desta entidade.
 */
class HistoriaDeUsuario {
private:
  Codigo codigo;
  Texto titulo;
  Texto papel;
  Texto acao;
  Texto valor;
  Tempo estimativa;
  Prioridade prioridade;
  Estado estado;

public:
  /**
   * @brief Armazena o código da história de usuário.
   * @param codigo Instância da classe de domínio Codigo.
   */
  void setCodigo(const Codigo &codigo) { this->codigo = codigo; }

  /**
   * @brief Retorna o código da história de usuário.
   * @return Instância da classe de domínio Codigo.
   */
  const Codigo &getCodigo() const { return codigo; }

  /**
   * @brief Armazena o título da história de usuário.
   * @param titulo Instância da classe de domínio Texto.
   */
  void setTitulo(const Texto &titulo) { this->titulo = titulo; }

  /**
   * @brief Retorna o título da história de usuário.
   * @return Instância da classe de domínio Texto.
   */
  const Texto &getTitulo() const { return titulo; }

  /**
   * @brief Armazena o papel da história de usuário.
   * @param papel Instância da classe de domínio Texto.
   */
  void setPapel(const Texto &papel) { this->papel = papel; }

  /**
   * @brief Retorna o papel da história de usuário.
   * @return Instância da classe de domínio Texto.
   */
  const Texto &getPapel() const { return papel; }

  /**
   * @brief Armazena a ação da história de usuário.
   * @param acao Instância da classe de domínio Texto.
   */
  void setAcao(const Texto &acao) { this->acao = acao; }

  /**
   * @brief Retorna a ação da história de usuário.
   * @return Instância da classe de domínio Texto.
   */
  const Texto &getAcao() const { return acao; }

  /**
   * @brief Armazena o valor da história de usuário.
   * @param valor Instância da classe de domínio Texto.
   */
  void setValor(const Texto &valor) { this->valor = valor; }

  /**
   * @brief Retorna o valor da história de usuário.
   * @return Instância da classe de domínio Texto.
   */
  const Texto &getValor() const { return valor; }

  /**
   * @brief Armazena a estimativa da história de usuário.
   * @param estimativa Instância da classe de domínio Tempo.
   */
  void setEstimativa(const Tempo &estimativa) { this->estimativa = estimativa; }

  /**
   * @brief Retorna a estimativa da história de usuário.
   * @return Instância da classe de domínio Tempo.
   */
  const Tempo &getEstimativa() const { return estimativa; }

  /**
   * @brief Armazena a prioridade da história de usuário.
   * @param prioridade Instância da classe de domínio Prioridade.
   */
  void setPrioridade(const Prioridade &prioridade) { this->prioridade = prioridade; }

  /**
   * @brief Retorna a prioridade da história de usuário.
   * @return Instância da classe de domínio Prioridade.
   */
  const Prioridade &getPrioridade() const { return prioridade; }

  /**
   * @brief Armazena o estado da história de usuário.
   * @param estado Instância da classe de domínio Estado.
   */
  void setEstado(const Estado &estado) { this->estado = estado; }

  /**
   * @brief Retorna o estado da história de usuário.
   * @return Instância da classe de domínio Estado.
   */
  const Estado &getEstado() const { return estado; }
};
