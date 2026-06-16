#ifndef TEMPO_HPP
#define TEMPO_HPP

#include <stdexcept>

class Tempo {
private:
    int valor;
    void validar(int valor);

public:
    void setValor(int valor);
    int getValor() const;
};

#endif 