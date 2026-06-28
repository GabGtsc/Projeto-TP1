#pragma once

#include "../../interfaces/IServicoAutenticacao.hpp"

#include "../../dominios/Email.hpp"
#include "../../dominios/Senha.hpp"
#include "../../dominios/Nome.hpp"

class StubServicoAutenticacao : public IServicoAutenticacao {
private:
  bool resultado = true;

public:
  bool autenticar(const Email &email, const Senha &senha, Nome &nome) override {
      (void)email;
      (void)senha;
      if (this->resultado) {
          nome.setNome("Stub");
      }
      return this->resultado;
  }
};
