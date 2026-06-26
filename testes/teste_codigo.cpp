#include "../dominios/Codigo.hpp"
#include "doctest.h"
#include <stdexcept>

TEST_CASE("Codigo - Valido") {
  Codigo c("AB123");
  CHECK(c.getCodigo() == "AB123");
}

TEST_CASE("Codigo - Invalido (Tamanho)") {
  CHECK_THROWS_AS(Codigo("A123"), std::invalid_argument);
  CHECK_THROWS_AS(Codigo("ABC123"), std::invalid_argument);
}

TEST_CASE("Codigo - Invalido (Formato)") {
  CHECK_THROWS_AS(Codigo("aB123"), std::invalid_argument);
  CHECK_THROWS_AS(Codigo("AB12A"), std::invalid_argument);
  CHECK_THROWS_AS(Codigo("12123"), std::invalid_argument);
}
