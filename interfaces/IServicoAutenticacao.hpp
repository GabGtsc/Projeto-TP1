#pragma once

#include "../dominios/Email.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"

class IServicoAutenticacao {

public:
  virtual bool autenticar(const Email &email, const Senha &senha, Nome &nome, Papel &papel) = 0;
  virtual ~IServicoAutenticacao() = default;
};
