#pragma once
#include <string>
#include <stdio.h>

/**
 * @class Nome
 * @brief Domínio que representa um nome válido no sistema.
 *
 * A classe Nome é responsável por armazenar uma string e garantir que ela cumpra
 * as regras de negócio: até 10 caracteres, contendo apenas letras (A-Z, a-z) ou
 * espaços em branco. Também garante que espaços não apareçam no início ou no fim,
 * e que todo espaço seja obrigatoriamente seguido por uma letra.
 */
class Nome {
private:
    std::string nome_;

public:
    /**
     * @brief Construtor padrão (default).
     * * Inicializa a instância da classe de forma vazia, permitindo que o valor
     * seja preenchido posteriormente através do método setNome. Essencial para
     * a criação de instâncias dentro das classes de Entidade.
     */
    Nome() = default;

    /**
     * @brief Construtor com parâmetro.
     * * Inicializa o objeto já com uma string. Internamente, invoca o método 
     * setNome para garantir que a string fornecida passe pela validação.
     * * @param nome String contendo o nome a ser armazenado.
     * @throw std::invalid_argument Se a string não respeitar as regras de formatação.
     */
    Nome(const std::string& nome) { setNome(nome); }

    /**
     * @brief Retorna o nome atualmente armazenado.
     * * @return std::string correspondente ao nome válido da instância.
     */
    std::string getNome() const { return nome_; }

    /**
     * @brief Atribui um novo valor ao nome.
     * * Valida a string fornecida antes de armazená-la no atributo privado.
     * * @param nome String com o nome que se deseja atribuir.
     * @throw std::invalid_argument Se o formato do nome for inválido.
     */
    void setNome(const std::string& nome);
};