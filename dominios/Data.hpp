#pragma once

#include <string>

/**
 * @class Email
 * @brief Domínio que representa um endereço de correio eletrónico válido.
 *
 * A classe Email é responsável por armazenar e validar o formato de um e-mail.
 * De acordo com as regras de negócio, um e-mail válido é composto por uma 
 * parte local e um domínio, separados pelo carácter '@', devendo respeitar 
 * regras rigorosas quanto aos caracteres permitidos e comprimentos máximos.
 */
class Email {
private:
    std::string email_;

public:
    /**
     * @brief Construtor por omissão (padrão).
     * * Inicializa a instância da classe sem um valor atribuído, 
     * permitindo que este seja definido posteriormente através do método setEmail.
     */
    Email() = default;

    /**
     * @brief Construtor com parâmetro.
     * * Inicializa o objeto já com uma string de e-mail. Este construtor invoca
     * internamente o método setEmail para garantir que o valor fornecido é validado.
     * * @param email String que contém o e-mail a ser armazenado.
     * @throw std::invalid_argument Se a string fornecida não respeitar o formato válido.
     */
    Email(const std::string& email) { setEmail(email); }

    /**
     * @brief Valida o formato do e-mail passado como argumento.
     * * Verifica se a string cumpre todas as regras sintáticas exigidas para um 
     * e-mail (comprimento da parte local, do domínio, utilização de pontos, etc.).
     * * @param email String a ser submetida à validação.
     * @throw std::invalid_argument Se a string fornecida for um e-mail inválido.
     */
    void ValidarEmail(const std::string& email);

    /**
     * @brief Atribui um novo valor ao e-mail.
     * * Antes de armazenar o valor no atributo privado, este método chama 
     * ValidarEmail() para garantir a integridade dos dados.
     * * @param email String com o e-mail que se deseja atribuir.
     * @throw std::invalid_argument Se a string fornecida for inválida.
     */
    void setEmail(const std::string& email);

    /**
     * @brief Recupera o e-mail atualmente armazenado.
     * * @return std::string correspondente ao e-mail válido da instância.
     */
    std::string const getEmail() { return email_; }

    /**
     * @brief Método auxiliar para validação de caracteres.
     * * Verifica se o carácter passado por parâmetro corresponde a uma letra 
     * minúscula do alfabeto (a-z) ou a um dígito numérico (0-9).
     * * @param c Carácter a ser avaliado.
     * @return true Se o carácter for uma letra minúscula ou dígito.
     * @return false Caso contrário.
     */
    bool AlfabetoMinusculoOuDigito(char c) const;
};