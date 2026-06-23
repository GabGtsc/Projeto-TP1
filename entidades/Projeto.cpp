#include "Projeto.hpp"

void Projeto::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Projeto::getCodigo() const {
    return codigo;
}

void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Projeto::getNome() const {
    return nome;
}

void Projeto::setInicio(const Data& inicio) {
    this->inicio = inicio;
}

Data Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(const Data& termino) {
    this->termino = termino;
}

Data Projeto::getTermino() const {
    return termino;
}