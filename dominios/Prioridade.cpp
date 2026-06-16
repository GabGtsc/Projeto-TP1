#include "Prioridade.hpp"

void Prioridade::validar(std::string valor) {
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw std::invalid_argument("Formato de prioridade invalido.");
    }
}

void Prioridade::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Prioridade::getValor() const {
    return valor;
}