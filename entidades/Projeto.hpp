#pragma once

#include "../dominios/Codigo.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Data.hpp"

/**
 * @class Projeto
 * @brief Entidade que representa um projeto no sistema.
 *
 * A classe Projeto armazena as informações principais de um projeto ágil.
 * Ela é composta pelas classes de domínio Codigo, Nome e Data (para representar
 * as datas de início e término).
 * O código do projeto atua como a chave primária (identificador único).
 */
class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;

public:
    /**
     * @brief Armazena o código identificador do projeto.
     * @param codigo Instância da classe de domínio Codigo.
     */
    void setCodigo(const Codigo& codigo) { this->codigo = codigo; }

    /**
     * @brief Retorna o código identificador do projeto.
     * @return Instância da classe de domínio Codigo.
     */
    const Codigo& getCodigo() const { return codigo; }

    /**
     * @brief Armazena o nome do projeto.
     * @param nome Instância da classe de domínio Nome.
     */
    void setNome(const Nome& nome) { this->nome = nome; }

    /**
     * @brief Retorna o nome do projeto.
     * @return Instância da classe de domínio Nome.
     */
    const Nome& getNome() const { return nome; }

    /**
     * @brief Armazena a data de início do projeto.
     * @param inicio Instância da classe de domínio Data.
     */
    void setInicio(const Data& inicio) { this->inicio = inicio; }

    /**
     * @brief Retorna a data de início do projeto.
     * @return Instância da classe de domínio Data.
     */
    const Data& getInicio() const { return inicio; }

    /**
     * @brief Armazena a data de término do projeto.
     * @param termino Instância da classe de domínio Data.
     */
    void setTermino(const Data& termino) { this->termino = termino; }

    /**
     * @brief Retorna a data de término do projeto.
     * @return Instância da classe de domínio Data.
     */
    const Data& getTermino() const { return termino; }
};