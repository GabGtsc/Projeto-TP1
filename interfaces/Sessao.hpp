#pragma once

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Papel.hpp"

/**
 * @struct Sessao
 * @brief Estrutura que encapsula os dados da sessão do usuário autenticado.
 * 
 * Contém o status de logado e os dados essenciais da Pessoa logada (Email, Nome, Papel)
 * para serem repassados aos outros módulos do sistema.
 */
struct Sessao {
    bool logado = false; ///< Indica se a sessão atual pertence a um usuário logado (true) ou não (false).
    Email email;         ///< E-mail da pessoa logada.
    Nome nome;           ///< Nome da pessoa logada.
    Papel papel;         ///< Papel (Proprietário de Produto, Mestre Scrum, Desenvolvedor) da pessoa logada.
};
