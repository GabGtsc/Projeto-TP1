#include "Nome.hpp"
#include <cctype>
#include <stdexcept>
#include <string>

void Nome::setNome(const std::string &nome) {
  if (nome.empty()) {
    throw std::invalid_argument("Nome vazio!");
  }
  if (nome.length() > 10) {
    throw std::invalid_argument("Tamanho do nome maior que 10!");
  }
  if (nome.front() == ' ' || nome.back() == ' ') {
    throw std::invalid_argument("Primeira ou ultima letra invalida!");
  }

  for (size_t i = 0; i < nome.length(); i++) {
    if (isspace(nome[i])) {
      if (i + 1 < nome.length() && !isalpha(nome[i + 1])) {
        throw std::invalid_argument("Espaco em branco deve ser seguido por letra!");
      }
    } else if (!isalpha(nome[i])) {
      throw std::invalid_argument("Nome invalido!");
    }
  }
  
  nome_ = nome;
}
