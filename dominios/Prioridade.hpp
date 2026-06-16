#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

#include <string>
#include <stdexcept>

class Prioridade {
private:
    std::string valor;

    void validar(std::string valor); 

public:
    void setValor(std::string valor);
    std::string getValor() const;
};

#endif 