#pragma once
#include <string>

/**
 * @brief Domínio que representa uma Data.
 * 
 * Armazena e valida uma data fornecida como string (ex: DD/MM/AAAA).
 */
class Data {
private:
  int dia_, mes_, ano_;

public:
  /**
   * @brief Construtor padrão.
   */
  Data() = default;

  /**
   * @brief Construtor que inicializa a data.
   * @param data String representando a data a ser definida.
   * @throw std::invalid_argument Se a data for inválida.
   */
  Data(const std::string &data);

  /**
   * @brief Define um novo valor para a data.
   * @param data String no formato DD/MM/AAAA.
   * @throw std::invalid_argument Se a data for inválida.
   */
  void setData(const std::string &data);

  /**
   * @brief Retorna o valor da data.
   * @return std::string contendo a data formatada.
   */
  [[nodiscard]] std::string getData() const;
};
