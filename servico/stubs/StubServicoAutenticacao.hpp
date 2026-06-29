#pragma once

#include "../../interfaces/IServicoAutenticacao.hpp"

#include "../../dominios/Email.hpp"
#include "../../dominios/Senha.hpp"
#include "../../dominios/Nome.hpp"

/**
 * @class StubServicoAutenticacao
 * @brief Classe stub para simular o serviço de autenticação.
 */
class StubServicoAutenticacao : public IServicoAutenticacao {
private:
  bool resultado = true;

public:
  /// @copydoc IServicoAutenticacao::autenticar
  bool autenticar(const Email &email, const Senha &senha, Nome &nome, Papel &papel) override {
      (void)email;
      (void)senha;
      (void)papel;
      if (this->resultado) {
          nome.setNome("Stub");
      }
      return this->resultado;
  }
};
