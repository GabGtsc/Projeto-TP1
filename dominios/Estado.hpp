#pragma once
#include <string>

/**
 * @brief Classe de dominio que representa estado de complitude.
 * podendo assumar apenas um conjunto restrito de valores predefinidos
 * */
class Estado {
private:
  /// String que armazena o valor do estado
  std::string estado_;

public:
  /**
   * @brief setter do estado, define um valor
   *
   * O valor passado precisa ser um da seguinte lista:
   * "A FAZER", "FAZENDO" ou "FEITO"
   *
   * @param estado String representando o novo estado a ser definido
   * @throw std::invalid_argument Se o valor passado nao for um dos estados
   * validos
   */
  void setEstado(const std::string &estado);

  /**
   * @brief Constructor da classe estado
   *
   * Inicializa o objeto com um valor de estado valido, internamente chama
   * setEstado() para definir valor inicial.
   *
   * @param estado String com valor inicial para estado
   */
  Estado(const std::string estado) { setEstado(estado); };

  /**
   * @brief Retorna o valor atual do estado
   *
   * @return std::string contendo o valor do estado no objeto
   */
  std::string getEstado() const { return this->estado_; };
};
