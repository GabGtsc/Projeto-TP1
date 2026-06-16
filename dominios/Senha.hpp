#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
#include <stdexcept>

class Senha {
private:
    std::string valor;
    void validar(std::string valor);

public:
    void setValor(std::string valor);
    std::string getValor() const;
};

#endif