#pragma once

#include "../dominios/Email.hpp"
#include "../dominios/Senha.hpp"

class IServicoAutenticacao {
  virtual bool autenticar(const Email &email, const Senha &senha) = 0;

public:
  virtual ~IServicoAutenticacao() = default;
};
