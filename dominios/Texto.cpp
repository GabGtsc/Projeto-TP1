#include "Texto.hpp"
#include <cctype> 

void Texto::validar(std::string valor) {
    if (valor.length() < 10 || valor.length() > 40) {
        throw std::invalid_argument("Formato invalido: O texto deve ter entre 10 e 40 caracteres.");
    }

    for (size_t i = 0; i < valor.length() - 1; i++) {
        
        if (valor[i] == ' ' && valor[i + 1] == ' ') {
            throw std::invalid_argument("Formato invalido: Nao podem existir espacos em branco em sequencia.");
        }

        if (ispunct(valor[i]) && ispunct(valor[i + 1])) {
            throw std::invalid_argument("Formato invalido: Nao podem existir sinais de pontuacao em sequencia.");
        }
    }
}

void Texto::setValor(std::string valor) {
    validar(valor);
    this->valor = valor; 
}

std::string Texto::getValor() const {
    return valor;
}