#pragma once

/**
 * @brief Classe de dominio que representa uma quantidade de tempo em dias.
 * Deve estar estritamente dentro de um intervalo numerico permitido.
 */
class Tempo {
private:
  /// Inteiro que armazena o valor do tempo
  int tempo_;

  /**
   * @brief Metodo auxiliar para validar o tempo
   * @param tempo Inteiro a ser validado
   * @throw std::invalid_argument Se o tempo estiver fora do limite
   */
  void validar(int tempo);

public:
  /**
   * @brief setter do tempo, define um valor
   *
   * O valor passado precisa estar no intervalo de 1 a 365.
   *
   * @param tempo Inteiro representando o novo tempo a ser definido
   * @throw std::invalid_argument Se o valor passado nao for valido
   */
  void setTempo(int tempo);

  /**
   * @brief Construtor da classe Tempo
   *
   * Inicializa o objeto com um valor valido, internamente chama
   * setTempo() para definir o valor inicial.
   *
   * @param tempo Inteiro com valor inicial
   */
  Tempo() = default;
  Tempo(int tempo) { setTempo(tempo); };

  /**
   * @brief Retorna o valor atual do tempo
   *
   * @return int contendo o valor do tempo no objeto
   */
  int getTempo() const { return this->tempo_; };
};
