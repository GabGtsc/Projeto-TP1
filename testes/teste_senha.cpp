#include "doctest.h"
#include "../dominios/Senha.hpp"

TEST_CASE("Testando o Dominio Senha") {
    SUBCASE("Valores validos") {
        // Letras e numeros alternados (sem numeros seguidos)
        CHECK_NOTHROW(Senha s("Senha1A2b3"));
        // Apenas letras
        CHECK_NOTHROW(Senha s("SenhaSegura"));
    }

    SUBCASE("Valores invalidos") {
        // Contem caractere especial
        CHECK_THROWS(Senha("Senha@123"));
        // Contem numeros em sequencia
        CHECK_THROWS(Senha("Senha12"));
        // Espacos em branco nao sao permitidos por causa do isalnum
        CHECK_THROWS(Senha("Senha 1"));
    }
}