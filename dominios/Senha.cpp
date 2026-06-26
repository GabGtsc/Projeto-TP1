#include "Senha.hpp"
#include <cctype>

void Senha::validar(const std::string &senha) {
  for (size_t i = 0; i < senha.length(); i++) {
    char c = senha[i];

    if (!isalnum(c)) {
      throw std::invalid_argument("Formato invalido: A senha deve conter apenas letras e numeros.");
    }

    if (isdigit(c)) {
      if (i < senha.length() - 1) {
        if (isdigit(senha[i + 1])) {
          throw std::invalid_argument("Formato invalido: Um numero nao pode ser seguido por outro numero.");
        }
      }
    }
  }
}

void Senha::setSenha(const std::string &senha) {
  validar(senha);
  this->senha_ = senha;
}