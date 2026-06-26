#include "Texto.hpp"
#include <cctype>

void Texto::validar(const std::string &texto) {
  if (texto.length() < 10 || texto.length() > 40) {
    throw std::invalid_argument("Formato invalido: O texto deve ter entre 10 e 40 caracteres.");
  }

  for (size_t i = 0; i < texto.length() - 1; i++) {
    if (texto[i] == ' ' && texto[i + 1] == ' ') {
      throw std::invalid_argument("Formato invalido: Nao podem existir espacos em branco em sequencia.");
    }

    if (ispunct(texto[i]) && ispunct(texto[i + 1])) {
      throw std::invalid_argument("Formato invalido: Nao podem existir sinais de pontuacao em sequencia.");
    }
  }
}

void Texto::setTexto(const std::string &texto) {
  validar(texto);
  this->texto_ = texto;
}