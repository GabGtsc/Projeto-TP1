#pragma once

#include <string>
#include "Codigo.hpp"
#include "Tempo.hpp"
#include "Texto.hpp"

/// @brief Entidade que representa um plano de sprint associado a um projeto.
class PlanoSprint{
    private:
        Codigo codigo;
        Tempo duracao;
        Texto objetivo;

    public:
        // --- Codigo (chave primaria) ---

        /// @brief Inicializa o codigo do plano de sprint (apenas na criacao).
        /// @param cod Codigo no formato valido (2 letras maiusculas + 3 digitos).
        void inicializarCodigo(const std::string& cod){
            codigo.setCodigo(cod);
        }

        /// @brief Retorna o codigo do plano de sprint.
        Codigo getCodigo() const{
            return codigo.getCodigo();
        }

        // --- Objetivo ---

        /// @brief Define o objetivo do plano de sprint.
        /// @param obj Texto com ate 40 caracteres validos.
        void setObjetivo(const std::string& obj){
            objetivo.setTexto(obj);
        }

        /// @brief Retorna o objetivo do plano de sprint.
        Texto getObjetivo() const{
            return objetivo.getTexto();
        }

        // --- Capacidade ---

        /// @brief Define a capacidade do plano de sprint em dias.
        /// @param cap Valor entre 1 e 365.
        void setDuracao(int dur){
            duracao.setTempo(dur);
        }

        /// @brief Retorna a capacidade do plano de sprint.
        Tempo getDuracao() const{
            return duracao.getTempo();
        }
};
