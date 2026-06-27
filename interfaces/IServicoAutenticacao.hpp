#pragma once

#include "../dominios/Email.hpp"
#include "../dominios/Senha.hpp"

class IServicoAutenticacao {

public:
  virtual bool autenticar(const Email &email, const Senha &senha) = 0;
  virtual ~IServicoAutenticacao() = default;
};
