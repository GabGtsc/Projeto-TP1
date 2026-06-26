#include "../dominios/Papel.hpp"
#include "doctest.h"

TEST_CASE("Testando o Dominio Papel") {
  SUBCASE("Valores validos") {
    CHECK_NOTHROW(Papel p("DESENVOLVEDOR"));
    CHECK_NOTHROW(Papel p("MESTRE SCRUM"));
    CHECK_NOTHROW(Papel p("PROPRIETARIO DE PRODUTO"));
  }

  SUBCASE("Valores invalidos") {
    CHECK_THROWS(Papel("PROGRAMADOR"));  // Nao existe na lista
    CHECK_THROWS(Papel("SCRUM MASTER")); // Escrito de forma diferente da tabela
    CHECK_THROWS(Papel(""));             // Vazio
  }
}