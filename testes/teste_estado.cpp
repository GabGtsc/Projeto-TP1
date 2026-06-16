#include "doctest.h"
#include "../dominios/Estado.hpp"
#include <stdexcept>

TEST_CASE("Estado - Valido") {
    Estado e1("A FAZER");
    CHECK(e1.getEstado() == "A FAZER");

    Estado e2("FAZENDO");
    CHECK(e2.getEstado() == "FAZENDO");

    Estado e3("FEITO");
    CHECK(e3.getEstado() == "FEITO");
}

TEST_CASE("Estado - Invalido") {
    CHECK_THROWS_AS(Estado("a fazer"), std::invalid_argument);
    CHECK_THROWS_AS(Estado("Fazendo"), std::invalid_argument);
    CHECK_THROWS_AS(Estado("Feito"), std::invalid_argument);
    CHECK_THROWS_AS(Estado(""), std::invalid_argument);
    CHECK_THROWS_AS(Estado("OUTRO ESTADO"), std::invalid_argument);
}
