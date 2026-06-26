#include "../dominios/Email.hpp"
#include "doctest.h"
#include <stdexcept>

TEST_CASE("Email - Valido") {
  Email e("teste-123@dominio.com");
  CHECK(e.getEmail() == "teste-123@dominio.com");
}

TEST_CASE("Email - ValidarEmail Lanca Excecao em Invalido") {
  Email e("valido@dominio.com"); // Instancia com um válido para não printar erro no construtor

  CHECK_THROWS_AS(e.ValidarEmail(""), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("teste@"), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("@dominio.com"), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("-teste@dominio.com"), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("teste-@dominio.com"), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("teste.@dominio.com"), std::invalid_argument);
  CHECK_THROWS_AS(e.ValidarEmail("Teste@dominio.com"), std::invalid_argument);  // Maiuscula na parte local
  CHECK_THROWS_AS(e.ValidarEmail("teste@Dominio.com"), std::invalid_argument);  // Maiuscula no dominio
  CHECK_THROWS_AS(e.ValidarEmail("teste@dominio..com"), std::invalid_argument); // .. no dominio
  CHECK_THROWS_AS(e.ValidarEmail("teste@-dominio.com"), std::invalid_argument); // hifen no dominio
}
