#include "Tempo.hpp"
#include <stdexcept>

void Tempo::validar(int tempo) {
    if (tempo < 1 || tempo > 365) {
        throw std::invalid_argument("Formato de tempo invalido. Deve ser entre 1 e 365.");
    }
}

void Tempo::setTempo(int tempo) {
    validar(tempo);
    this->tempo_ = tempo;
}