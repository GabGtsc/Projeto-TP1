#pragma once

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"

class IServicoCadastro {
public:
  virtual ~IServicoCadastro() = default;
  virtual bool ler(const Email &email, const Pessoa &pessoa) = 0;
  virtual bool criar(const Pessoa &pessoa) = 0;
  virtual bool atualizar(const Pessoa &pessoa) = 0;
  virtual bool excluir(const Email &email) = 0;
};
