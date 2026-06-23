#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Papel.hpp"

/**
 * @class Pessoa
 * @brief Entidade que representa um usuário no sistema.
 *
 * A classe Pessoa é responsável por agrupar as informações básicas de um usuário.
 * Ela é composta por instâncias das classes de domínio Email, Nome, Senha e Papel.
 * O e-mail funciona como a chave primária (identificador único) desta entidade.
 */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:
    /**
     * @brief Armazena o e-mail da pessoa.
     * @param email Instância da classe de domínio Email.
     */
    void setEmail(const Email& email);

    /**
     * @brief Retorna o e-mail da pessoa.
     * @return Instância da classe de domínio Email.
     */
    Email getEmail() const;

    /**
     * @brief Armazena o nome da pessoa.
     * @param nome Instância da classe de domínio Nome.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Instância da classe de domínio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Armazena a senha da pessoa.
     * @param senha Instância da classe de domínio Senha.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Retorna a senha da pessoa.
     * @return Instância da classe de domínio Senha.
     */
    Senha getSenha() const;

    /**
     * @brief Armazena o papel da pessoa no projeto.
     * @param papel Instância da classe de domínio Papel.
     */
    void setPapel(const Papel& papel);

    /**
     * @brief Retorna o papel da pessoa no projeto.
     * @return Instância da classe de domínio Papel.
     */
    Papel getPapel() const;
};

#endif // PESSOA_HPP