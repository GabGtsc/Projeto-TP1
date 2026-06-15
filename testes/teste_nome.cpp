#include "doctest.h"
#include "../dominios/Nome.hpp"
#include <stdexcept>

TEST_CASE("Nome - Valido") {
    Nome n("Ana Maria");
    CHECK(n.getNome() == "Ana Maria");
}

TEST_CASE("Nome - Invalido") {
    CHECK_THROWS_AS(Nome(""), std::invalid_argument);
    CHECK_THROWS_AS(Nome("Nome Grande"), std::invalid_argument); // 11 caracteres
    CHECK_THROWS_AS(Nome(" Ana"), std::invalid_argument);
    CHECK_THROWS_AS(Nome("Ana "), std::invalid_argument);
    CHECK_THROWS_AS(Nome("Ana1"), std::invalid_argument);
}
