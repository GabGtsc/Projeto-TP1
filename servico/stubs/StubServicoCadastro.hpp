#pragma once

#include "../../interfaces/IServicoCadastro.hpp"

#include "../../dominios/Email.hpp"
#include "../../entidades/Pessoa.hpp"

/**
 * @class StubServicoCadastro
 * @brief Classe stub para simular o serviço de cadastro.
 */
class StubServicoCadastro : public IServicoCadastro {
private:
  bool resultado = true;

public:
  /// @copydoc IServicoCadastro::ler
  bool ler(const Email &email, Pessoa &pessoa) override { (void)email; (void)pessoa; return this->resultado; };
  /// @copydoc IServicoCadastro::criar
  bool criar(const Pessoa &pessoa) override { return this->resultado; }
  /// @copydoc IServicoCadastro::atualizar
  bool atualizar(const Pessoa &pessoa) override { return this->resultado; }
  /// @copydoc IServicoCadastro::excluir
  bool excluir(const Email &email) override { return this->resultado; };
};
