#include "Senha.hpp"
#include <cctype>

void Senha::validar(const std::string &senha) {
  if (senha.length() != 6) {
    throw std::invalid_argument("Formato invalido: A senha deve conter exatamente 6 caracteres.");
  }

  bool hasLower = false, hasUpper = false, hasDigit = false;

  for (size_t i = 0; i < senha.length(); i++) {
    char c = senha[i];

    if (!isalnum(c)) {
      throw std::invalid_argument("Formato invalido: A senha deve conter apenas letras e numeros.");
    }

    if (islower(c)) hasLower = true;
    if (isupper(c)) hasUpper = true;
    if (isdigit(c)) hasDigit = true;

    if (i < senha.length() - 1) {
      if (isdigit(c) && isdigit(senha[i + 1])) {
        throw std::invalid_argument("Formato invalido: Um numero nao pode ser seguido por outro numero.");
      }
      if (isalpha(c) && isalpha(senha[i + 1])) {
        throw std::invalid_argument("Formato invalido: Uma letra nao pode ser seguida por outra letra.");
      }
    }
  }

  if (!hasLower || !hasUpper || !hasDigit) {
    throw std::invalid_argument("Formato invalido: A senha deve conter pelo menos uma letra minuscula, uma maiuscula e um digito.");
  }
}

void Senha::setSenha(const std::string &senha) {
  validar(senha);
  this->senha_ = senha;
}