#include "Tempo.hpp"

void Tempo::validar(int valor) {
    if (valor < 1 || valor > 365) {
        throw std::invalid_argument("Formato de tempo invalido. Deve ser entre 1 e 365.");
    }
}

void Tempo::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

int Tempo::getValor() const {
    return valor;
}