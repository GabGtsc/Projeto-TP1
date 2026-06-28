#include "../dominios/Texto.hpp"
#include "doctest.h"

TEST_CASE("Testando o Dominio Texto") {
  SUBCASE("Valores validos") {
    CHECK_NOTHROW(Texto t("Texto valido"));
    CHECK_NOTHROW(Texto t("Isto eh um teste com 30 letras"));
  }

  SUBCASE("Valores invalidos - Tamanho") {
    CHECK_THROWS(Texto(""));
    CHECK_THROWS(Texto("Este texto eh muito longo e vai ultrapassar o limite de 40 caracteres permitido."));
  }

  SUBCASE("Valores invalidos - Formatacao") {
    CHECK_THROWS(Texto("Dois  espacos juntos"));
    CHECK_THROWS(Texto("Duas pontuacoes.."));
    CHECK_THROWS(Texto("Pontuacoes mistas.,"));
    CHECK_THROWS(Texto("Texto com ponto."));
  }
}