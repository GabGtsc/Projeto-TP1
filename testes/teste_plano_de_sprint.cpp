#include "doctest.h"
#include "../entidades/PlanoDeSprint.hpp"

TEST_CASE("PlanoDeSprint - Armazenamento de Atributos") {
    PlanoDeSprint plano;
    
    Codigo codigo("AB123");
    Texto objetivo("Texto valido.");
    Tempo capacidade(180);
    
    plano.setCodigo(codigo);
    plano.setObjetivo(objetivo);
    plano.setCapacidade(capacidade);
    
    CHECK(plano.getCodigo().getCodigo() == "AB123");
    CHECK(plano.getObjetivo().getTexto() == "Texto valido.");
    CHECK(plano.getCapacidade().getTempo() == 180);
}
