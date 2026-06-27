#pragma once

#include "../../interfaces/IServicoAutenticacao.hpp"

#include "../../dominios/Email.hpp"
#include "../../dominios/Senha.hpp"

class StubServicoAutenticacao : public IServicoAutenticacao {
private:
  bool resultado = true;

public:
  bool autenticar(const Email &email, const Senha &senha) override { return this->resultado; }
};
