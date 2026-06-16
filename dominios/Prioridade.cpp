#include "Prioridade.hpp"

void Prioridade::validar(const std::string &prioridade) {
    if (prioridade != "ALTA" && prioridade != "MEDIA" && prioridade != "BAIXA") {
        throw std::invalid_argument("Formato de prioridade invalido.");
    }
}

void Prioridade::setPrioridade(const std::string &prioridade) {
    validar(prioridade);
    this->prioridade_ = prioridade;
}