#include "../dominios/Data.hpp"
#include "doctest.h"
#include <stdexcept>

TEST_CASE("Data - Valida") {
  Data d("29/02/2004"); // bissexto
  CHECK(d.getData() == "29/02/2004");

  Data d2("31/12/2099");
  CHECK(d2.getData() == "31/12/2099");
}

TEST_CASE("Data - Invalida (Formato e Tamanho)") {
  CHECK_THROWS_AS(Data(""), std::invalid_argument);
  CHECK_THROWS_AS(Data("1/1/2000"), std::invalid_argument);
  CHECK_THROWS_AS(Data("12-12-2000"), std::invalid_argument);
}

TEST_CASE("Data - Invalida (Limites e Anos Bissextos)") {
  CHECK_THROWS_AS(Data("29/02/2001"), std::invalid_argument); // não bissexto
  CHECK_THROWS_AS(Data("31/04/2000"), std::invalid_argument);
  CHECK_THROWS_AS(Data("00/12/2000"), std::invalid_argument);
  CHECK_THROWS_AS(Data("12/13/2000"), std::invalid_argument);
  CHECK_THROWS_AS(Data("12/12/1999"), std::invalid_argument);
  CHECK_THROWS_AS(Data("12/12/2100"), std::invalid_argument);
}
