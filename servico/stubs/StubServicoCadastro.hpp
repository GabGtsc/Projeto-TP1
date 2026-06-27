#pragma once

#include "../../interfaces/IServicoCadastro.hpp"

#include "../../dominios/Email.hpp"
#include "../../entidades/Pessoa.hpp"

class StubServicoCadastro : public IServicoCadastro {
private:
  bool resultado = true;

public:
  bool ler(const Email &email, const Pessoa &pessoa) override { return this->resultado; };
  bool criar(const Pessoa &pessoa) override { return this->resultado; }
  bool atualizar(const Pessoa &pessoa) override { return this->resultado; }
  bool excluir(const Email &email) override { return this->resultado; };
};
