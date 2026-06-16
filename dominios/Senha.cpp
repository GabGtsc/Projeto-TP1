#include "Senha.hpp"
#include <cctype> // Biblioteca necessária para usar isalnum() e isdigit()

void Senha::validar(std::string valor) {

    if (valor.length() != 6) {
        throw std::invalid_argument("A senha deve ter exatamente 6 caracteres.");
    }

    for (size_t i = 0; i < valor.length(); i++) {
        char c = valor[i];

        if (!isalnum(c)) {
            throw std::invalid_argument("Formato invalido: A senha deve conter apenas letras e numeros.");
        }

        // Verifica a regra de não ter dois números seguidos
        if (isdigit(c)) {
            if (i < valor.length() - 1) {
                if (isdigit(valor[i + 1])) {
                    throw std::invalid_argument("Formato invalido: Um numero nao pode ser seguido por outro numero.");
                }
            }
        }
    }
}

void Senha::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Senha::getValor() const {
    return valor;
}