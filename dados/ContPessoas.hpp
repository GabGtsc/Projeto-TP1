#pragma once

#include "../dominios/Email.hpp"
#include "../entidades/Pessoa.hpp"
#include <map>
#include <string>

/**
 * @class ContPessoas
 * @brief Contêiner em memória para armazenar objetos do tipo Pessoa.
 *
 * Utiliza um std::map cuja chave é a std::string representando o e-mail,
 * e o valor é o próprio objeto Pessoa. Responsável puramente pelas
 * operações de coleção na memória.
 */
class ContPessoas {
private:
  std::map<std::string, Pessoa> container;

public:
  /**
   * @brief Tenta inserir uma nova Pessoa no contêiner.
   * @param pessoa Objeto pessoa a ser inserido.
   * @return true se inseriu com sucesso, false se o e-mail já existir.
   */
  bool inserir(const Pessoa &pessoa);

  /**
   * @brief Tenta buscar uma Pessoa no contêiner.
   * @param email String com o e-mail (chave primária).
   * @param pessoa Referência para retornar a pessoa encontrada.
   * @return true se encontrada, false caso contrário.
   */
  bool buscar(const std::string &email, Pessoa &pessoa) const;

  /**
   * @brief Tenta atualizar uma Pessoa já existente.
   * @param pessoa Objeto pessoa com as novas informações.
   * @return true se atualizado, false se não existia.
   */
  bool atualizar(const Pessoa &pessoa);

  /**
   * @brief Tenta remover uma Pessoa do contêiner.
   * @param email String com o e-mail (chave primária).
   * @return true se removida, false se não encontrada.
   */
  bool remover(const std::string &email);
};
