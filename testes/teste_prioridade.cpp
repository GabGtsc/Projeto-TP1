#include "../dominios/Prioridade.hpp"
#include "doctest.h"

TEST_CASE("Testando o Dominio Prioridade") {
  SUBCASE("Valores validos") {
    CHECK_NOTHROW(Prioridade p("ALTA"));
    CHECK_NOTHROW(Prioridade p("MEDIA"));
    CHECK_NOTHROW(Prioridade p("BAIXA"));
  }

  SUBCASE("Valores invalidos") {
    CHECK_THROWS(Prioridade("URGENTE")); // Nao existe na lista
    CHECK_THROWS(Prioridade("alta"));    // Minusculo
    CHECK_THROWS(Prioridade(""));        // Vazio
  }
}