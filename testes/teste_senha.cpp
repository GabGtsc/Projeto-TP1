#include "../dominios/Senha.hpp"
#include "doctest.h"

TEST_CASE("Testando o Dominio Senha") {
  SUBCASE("Valores validos") {
    CHECK_NOTHROW(Senha s("A1b2C3"));
  }

  SUBCASE("Valores invalidos") {
    CHECK_THROWS(Senha("Senha@"));
    CHECK_THROWS(Senha("A1b23C")); // numeros seguidos
    CHECK_THROWS(Senha("ab1C2d")); // letras seguidas
    CHECK_THROWS(Senha("A1B2C3")); // sem minuscula
    CHECK_THROWS(Senha("a1b2c3")); // sem maiuscula
    CHECK_THROWS(Senha("AbCdEf")); // sem numero
    CHECK_THROWS(Senha("A1b2C")); // < 6
    CHECK_THROWS(Senha("A1b2C3d")); // > 6
  }
}