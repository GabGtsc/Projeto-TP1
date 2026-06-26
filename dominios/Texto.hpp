#pragma once
#include <stdexcept>
#include <string>

/**
 * @brief Classe de dominio que representa blocos de Texto no sistema.
 * Restringe tamanho e a utilizacao de espacos e pontuacoes repetidas.
 */
class Texto {
private:
  /// String que armazena o texto
  std::string texto_;

  /**
   * @brief Metodo auxiliar para validar o texto
   * @param texto String a ser validada
   * @throw std::invalid_argument Se as regras de limite e formatacao nao forem cumpridas
   */
  void validar(const std::string &texto);

public:
  /**
   * @brief setter do texto, define um valor
   *
   * Regras aplicadas:
   * - Tamanho entre 10 e 40 caracteres.
   * - Nao pode conter espacos em branco em sequencia.
   * - Nao pode conter sinais de pontuacao em sequencia.
   *
   * @param texto String representando o novo texto
   * @throw std::invalid_argument Se o formato for invalido
   */
  void setTexto(const std::string &texto);

  /**
   * @brief Construtor da classe Texto
   *
   * Inicializa o objeto com um texto valido, internamente chama
   * setTexto() para definir o valor inicial.
   *
   * @param texto String com valor inicial
   */
  Texto() = default;
  Texto(const std::string &texto) { setTexto(texto); };

  /**
   * @brief Retorna o valor atual do texto
   *
   * @return std::string contendo o texto no objeto
   */
  std::string getTexto() const { return this->texto_; };
};