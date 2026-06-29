#pragma once

#include "../dominios/Email.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"

/**
 * @brief Interface para o serviço de Autenticação.
 * 
 * Define o contrato para autenticação de usuários no sistema.
 */
class IServicoAutenticacao {

public:
  /**
   * @brief Autentica um usuário com base no e-mail e senha.
   * @param email E-mail do usuário.
   * @param senha Senha do usuário.
   * @param nome Parâmetro de saída preenchido com o nome do usuário autenticado.
   * @param papel Parâmetro de saída preenchido com o papel do usuário autenticado.
   * @return true se a autenticação for bem-sucedida, false caso contrário.
   */
  virtual bool autenticar(const Email &email, const Senha &senha, Nome &nome, Papel &papel) = 0;
  
  virtual ~IServicoAutenticacao() = default;
};
