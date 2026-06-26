#include "doctest.h"
#include "../entidades/HistoriaDeUsuario.hpp"

TEST_CASE("HistoriaDeUsuario - Armazenamento de Atributos") {
    HistoriaDeUsuario historia;
    
    Codigo codigo("AB123");
    Texto titulo("Texto valido.");
    Texto papel("Texto valido.");
    Texto acao("Texto valido.");
    Texto valor("Texto valido.");
    Tempo estimativa(180);
    Prioridade prioridade("ALTA");
    Estado estado("A FAZER");
    
    historia.setCodigo(codigo);
    historia.setTitulo(titulo);
    historia.setPapel(papel);
    historia.setAcao(acao);
    historia.setValor(valor);
    historia.setEstimativa(estimativa);
    historia.setPrioridade(prioridade);
    historia.setEstado(estado);
    
    CHECK(historia.getCodigo().getCodigo() == "AB123");
    CHECK(historia.getTitulo().getTexto() == "Texto valido.");
    CHECK(historia.getPapel().getTexto() == "Texto valido.");
    CHECK(historia.getAcao().getTexto() == "Texto valido.");
    CHECK(historia.getValor().getTexto() == "Texto valido.");
    CHECK(historia.getEstimativa().getTempo() == 180);
    CHECK(historia.getPrioridade().getPrioridade() == "ALTA");
    CHECK(historia.getEstado().getEstado() == "A FAZER");
}
