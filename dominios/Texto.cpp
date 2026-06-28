#include "Texto.hpp"
#include <cctype>

void Texto::validar(const std::string &texto) {
  if (texto.length() == 0 || texto.length() > 40) {
    throw std::invalid_argument("Formato invalido: O texto deve ter entre 1 e 40 caracteres.");
  }

  char front = texto.front();
  char back = texto.back();
  if (front == ',' || front == '.' || front == ' ' || back == ',' || back == '.' || back == ' ') {
    throw std::invalid_argument("Formato invalido: O texto nao pode iniciar ou terminar com ponto, virgula ou espaco.");
  }

  for (size_t i = 0; i < texto.length(); i++) {
    char c = texto[i];
    if (!isalnum(c) && c != ' ' && c != '.' && c != ',') {
      throw std::invalid_argument("Formato invalido: O texto possui caracteres nao permitidos.");
    }

    if (i < texto.length() - 1) {
      if (c == ' ' && !isalnum(texto[i + 1])) {
        throw std::invalid_argument("Formato invalido: Espaco em branco deve ser seguido por letra ou digito.");
      }
      if ((c == ',' || c == '.') && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
        throw std::invalid_argument("Formato invalido: Ponto ou virgula nao pode ser seguido por ponto ou virgula.");
      }
    }
  }
}

void Texto::setTexto(const std::string &texto) {
  validar(texto);
  this->texto_ = texto;
}