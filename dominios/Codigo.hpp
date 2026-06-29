#pragma once

#include <string>

/**
 * @brief Domínio que representa um Código.
 * 
 * Um código válido tem 5 caracteres, sendo os dois primeiros letras maiúsculas
 * e os três últimos dígitos numéricos (formato AA123).
 */
class Codigo {
private:
  std::string valor;

public:
  /**
   * @brief Construtor padrão.
   */
  Codigo() = default;

  /**
   * @brief Construtor que inicializa o código com um valor.
   * @param texto String representando o código a ser definido.
   * @throw std::invalid_argument Se o código for inválido.
   */
  Codigo(const std::string &texto);

  /**
   * @brief Define um novo valor para o código.
   * @param texto String representando o código.
   * @throw std::invalid_argument Se o código não estiver no formato AA123.
   */
  void setCodigo(const std::string &texto);

  /**
   * @brief Retorna o valor do código.
   * @return std::string contendo o código.
   */
  [[nodiscard]] std::string getCodigo() const;
};
