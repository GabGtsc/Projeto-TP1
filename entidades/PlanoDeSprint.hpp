#pragma once

#include "../dominios/Codigo.hpp"
#include "../dominios/Tempo.hpp"
#include "../dominios/Texto.hpp"

/**
 * @class PlanoDeSprint
 * @brief Entidade que representa um plano de sprint no sistema.
 *
 * A classe PlanoDeSprint é responsável por agrupar as informações de um plano
 * de sprint. Ela é composta por instâncias das classes de domínio Codigo, Texto
 * (para objetivo) e Tempo (para capacidade). O código funciona como a chave
 * primária (identificador único) desta entidade.
 */
class PlanoDeSprint {
private:
  Codigo codigo;
  Texto objetivo;
  Tempo capacidade;

public:
  /**
   * @brief Armazena o código do plano de sprint.
   * @param codigo Instância da classe de domínio Codigo.
   */
  void setCodigo(const Codigo &codigo) { this->codigo = codigo; }

  /**
   * @brief Retorna o código do plano de sprint.
   * @return Instância da classe de domínio Codigo.
   */
  const Codigo &getCodigo() const { return codigo; }

  /**
   * @brief Armazena o objetivo do plano de sprint.
   * @param objetivo Instância da classe de domínio Texto.
   */
  void setObjetivo(const Texto &objetivo) { this->objetivo = objetivo; }

  /**
   * @brief Retorna o objetivo do plano de sprint.
   * @return Instância da classe de domínio Texto.
   */
  const Texto &getObjetivo() const { return objetivo; }

  /**
   * @brief Armazena a capacidade do plano de sprint.
   * @param capacidade Instância da classe de domínio Tempo.
   */
  void setCapacidade(const Tempo &capacidade) { this->capacidade = capacidade; }

  /**
   * @brief Retorna a capacidade do plano de sprint.
   * @return Instância da classe de domínio Tempo.
   */
  const Tempo &getCapacidade() const { return capacidade; }
};
