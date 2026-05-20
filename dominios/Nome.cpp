#include <stdexcept>
#include <cctype>
#include <string>
#include "Nome.hpp"

void Nome::setNome(const std::string& nome) {
    if (nome.empty()) { throw std::invalid_argument("Nome vazio!"); }
    if (nome.length() > 10) { throw std::invalid_argument("Tamanho do nome maior que 10!"); }
    if (nome.front() == ' ' || nome.back() == ' ') {throw std::invalid_argument("Primeira ou ultima letra invalida!"); }

    for(int i = 0 ; i < nome.length() ; i++){
        if( !( isalpha(nome[i]) || isspace(nome[i]) )) {
            throw std::invalid_argument("Nome invalido!");
        }

    nome_ = nome;
    }
}
