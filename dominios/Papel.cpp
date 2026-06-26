#include "Papel.hpp"

void Papel::validar(const std::string &papel) {
  if (papel != "DESENVOLVEDOR" && papel != "MESTRE SCRUM" && papel != "PROPRIETARIO DE PRODUTO") {
    throw std::invalid_argument("Formato de papel invalido.");
  }
}

void Papel::setPapel(const std::string &papel) {
  validar(papel);
  this->papel_ = papel;
}