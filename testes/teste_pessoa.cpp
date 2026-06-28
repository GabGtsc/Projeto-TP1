#include "../entidades/Pessoa.hpp"
#include "doctest.h"

TEST_CASE("Pessoa - Armazenamento de Atributos") {
  Pessoa pessoa;

  Email email("teste-123@dominio.com");
  Nome nome("Ana Maria");
  Senha senha("A1b2C3");
  Papel papel("DESENVOLVEDOR");

  pessoa.setEmail(email);
  pessoa.setNome(nome);
  pessoa.setSenha(senha);
  pessoa.setPapel(papel);

  CHECK(pessoa.getEmail().getEmail() == "teste-123@dominio.com");
  CHECK(pessoa.getNome().getNome() == "Ana Maria");
  CHECK(pessoa.getSenha().getSenha() == "A1b2C3");
  CHECK(pessoa.getPapel().getPapel() == "DESENVOLVEDOR");
}
