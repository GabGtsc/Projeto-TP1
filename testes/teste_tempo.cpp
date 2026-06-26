#include "doctest.h"
#include "../dominios/Tempo.hpp"

TEST_CASE("Testando o Dominio Tempo") {
    SUBCASE("Valores validos (Dentro dos limites)") {
        CHECK_NOTHROW(Tempo t(1));   // Limite inferior
        CHECK_NOTHROW(Tempo t(180)); // Meio
        CHECK_NOTHROW(Tempo t(365)); // Limite superior
    }

    SUBCASE("Valores invalidos (Fora dos limites)") {
        CHECK_THROWS(Tempo(0));   // Abaixo do limite
        CHECK_THROWS(Tempo(-10)); // Negativo
        CHECK_THROWS(Tempo(366)); // Acima do limite
    }
}