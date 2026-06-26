#include "doctest.h"
#include "../entidades/Projeto.hpp"

TEST_CASE("Projeto - Armazenamento de Atributos") {
    Projeto projeto;
    
    Codigo codigo("AB123");
    Nome nome("Proj Alfa");
    Data inicio("29/02/2004");
    Data termino("31/12/2099");
    
    projeto.setCodigo(codigo);
    projeto.setNome(nome);
    projeto.setInicio(inicio);
    projeto.setTermino(termino);
    
    CHECK(projeto.getCodigo().getCodigo() == "AB123");
    CHECK(projeto.getNome().getNome() == "Proj Alfa");
    CHECK(projeto.getInicio().getData() == "29/02/2004");
    CHECK(projeto.getTermino().getData() == "31/12/2099");
}
