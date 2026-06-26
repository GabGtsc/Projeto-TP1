#pragma once
#include <string>
#include <stdexcept>

/**
 * @brief Classe de dominio que representa uma Senha de acesso.
 * Possui regras restritas de formatacao de caracteres e numeros.
 */
class Senha {
private:
    /// String que armazena a senha
    std::string senha_;

    /**
     * @brief Metodo auxiliar para validar a formatacao da senha
     * @param senha String a ser validada
     * @throw std::invalid_argument Se a formatacao da senha for invalida
     */
    void validar(const std::string &senha);

public:
    /**
     * @brief setter da senha, define um valor
     *
     * A senha deve conter apenas letras e numeros.
     * Um numero nao pode ser seguido imediatamente por outro numero.
     *
     * @param senha String representando a nova senha
     * @throw std::invalid_argument Se as regras de formatacao nao forem cumpridas
     */
    void setSenha(const std::string &senha);

    /**
     * @brief Construtor da classe Senha
     *
     * Inicializa o objeto com uma senha valida, internamente chama
     * setSenha() para definir o valor inicial.
     *
     * @param senha String com valor inicial da senha
     */
    Senha() = default;
    Senha(const std::string &senha) { setSenha(senha); };

    /**
     * @brief Retorna o valor atual da senha
     *
     * @return std::string contendo a senha no objeto
     */
    std::string getSenha() const { return this->senha_; };
};