#include "Estado.hpp"

void Estado::validar(std::string valor) {
    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO") {
        throw std::invalid_argument("Formato de estado invalido.");
    }
}

void Estado::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Estado::getValor() const {
    return valor;
}