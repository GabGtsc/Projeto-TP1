#pragma once
#include <string>
#include <stdexcept>

/**
 * @brief Classe de dominio que representa a prioridade de uma tarefa ou projeto.
 * Podendo assumir apenas um conjunto restrito de valores predefinidos.
 */
class Prioridade {
private:
    /// String que armazena o valor da prioridade
    std::string prioridade_;

    /**
     * @brief Metodo auxiliar para validar a prioridade
     * @param prioridade String a ser validada
     * @throw std::invalid_argument Se a prioridade nao for valida
     */
    void validar(const std::string &prioridade);

public:
    /**
     * @brief setter da prioridade, define um valor
     *
     * O valor passado precisa ser um da seguinte lista:
     * "ALTA", "MEDIA" ou "BAIXA"
     *
     * @param prioridade String representando a nova prioridade a ser definida
     * @throw std::invalid_argument Se o valor passado nao for valido
     */
    void setPrioridade(const std::string &prioridade);

    /**
     * @brief Construtor da classe Prioridade
     *
     * Inicializa o objeto com um valor valido, internamente chama
     * setPrioridade() para definir o valor inicial.
     *
     * @param prioridade String com valor inicial para prioridade
     */
    Prioridade() = default;
    Prioridade(const std::string &prioridade) { setPrioridade(prioridade); };

    /**
     * @brief Retorna o valor atual da prioridade
     *
     * @return std::string contendo o valor da prioridade no objeto
     */
    std::string getPrioridade() const { return this->prioridade_; };
};