#include "doctest.h"
#include "Texto.hpp"

TEST_CASE("Testando o Dominio Texto") {
    SUBCASE("Valores validos") {
        // 10 a 40 caracteres com formatacao correta
        CHECK_NOTHROW(Texto t("Texto valido.")); 
        CHECK_NOTHROW(Texto t("Isto eh um teste com 30 letras."));
    }

    SUBCASE("Valores invalidos - Tamanho") {
        // Menos de 10 caracteres
        CHECK_THROWS(Texto("Curto"));
        // Mais de 40 caracteres
        CHECK_THROWS(Texto("Este texto eh muito longo e vai ultrapassar o limite de 40 caracteres permitido."));
    }

    SUBCASE("Valores invalidos - Formatacao") {
        // Dois espacos seguidos
        CHECK_THROWS(Texto("Dois  espacos juntos."));
        // Duas pontuacoes seguidas
        CHECK_THROWS(Texto("Duas pontuacoes!!"));
        CHECK_THROWS(Texto("Pontuacoes mistas.,"));
    }
}