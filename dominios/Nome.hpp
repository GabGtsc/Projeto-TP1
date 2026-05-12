#pragma once
#include <string>
#include <stdio.h>

class Nome {
private:
    std::string nome_;
public:
    Nome(const std::string& nome) { setNome(nome); }
    std::string getNome() const { return nome_; }
    void setNome(const std::string& nome);
};
