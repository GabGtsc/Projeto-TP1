#include "Papel.hpp"

void Papel::validar(std::string valor) {
    if (valor != "DESENVOLVEDOR" && valor != "MESTRE SCRUM" && valor != "PROPRIETARIO DE PRODUTO") {
        throw std::invalid_argument("Formato de papel invalido.");
    }
}

void Papel::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Papel::getValor() const {
    return valor;
}