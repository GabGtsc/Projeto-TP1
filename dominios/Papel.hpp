#pragma once
#include <string>
#include <stdexcept>

/**
 * @brief Classe de dominio que representa o papel de um usuario no sistema.
 * Podendo assumir apenas valores especificos relacionados ao Scrum.
 */
class Papel {
private:
    /// String que armazena o valor do papel
    std::string papel_;

    /**
     * @brief Metodo auxiliar para validar o papel
     * @param papel String a ser validada
     * @throw std::invalid_argument Se o papel nao for valido
     */
    void validar(const std::string &papel);

public:
    /**
     * @brief setter do papel, define um valor
     *
     * O valor passado precisa ser um da seguinte lista:
     * "DESENVOLVEDOR", "MESTRE SCRUM" ou "PROPRIETARIO DE PRODUTO"
     *
     * @param papel String representando o novo papel a ser definido
     * @throw std::invalid_argument Se o valor passado nao for valido
     */
    void setPapel(const std::string &papel);

    /**
     * @brief Construtor da classe Papel
     *
     * Inicializa o objeto com um valor valido, internamente chama
     * setPapel() para definir o valor inicial.
     *
     * @param papel String com valor inicial para o papel
     */
    Papel(const std::string &papel) { setPapel(papel); };

    /**
     * @brief Retorna o valor atual do papel
     *
     * @return std::string contendo o valor do papel no objeto
     */
    std::string getPapel() const { return this->papel_; };
};