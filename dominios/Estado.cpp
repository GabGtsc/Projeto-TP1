#include "Estado.hpp"
#include <stdexcept>

void Estado::setEstado(const std::string &estado) {
  if (estado == "A FAZER" || estado == "FAZENDO" || estado == "FEITO") {
    this->estado_ = estado;
  } else {
    throw std::invalid_argument(
        "Estado dever ser um de: A FAZER, FAZENDO, FEITO");
  }
}
