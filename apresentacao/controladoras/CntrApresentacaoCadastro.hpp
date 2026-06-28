#pragma once

#include "../../interfaces/IApresentacaoCadastro.hpp"
#include "../../interfaces/IServicoCadastro.hpp"
#include "../../entidades/Pessoa.hpp"
#include "../../dominios/Email.hpp"
#include "../../dominios/Nome.hpp"
#include "../../dominios/Senha.hpp"
#include "../../dominios/Papel.hpp"
#include <iostream>

/**
 * @class CntrApresentacaoCadastro
 * @brief Classe controladora de apresentação para o módulo de Cadastro.
 *
 * Esta classe é responsável por gerenciar a interface com o usuário durante
 * o processo de cadastro no sistema. Ela coleta as entradas de texto (via terminal), 
 * instancia e valida os domínios necessários para criar a entidade Pessoa, e delega a
 * persistência/criação para a camada de serviço.
 */
class CntrApresentacaoCadastro : public IApresentacaoCadastro {
private:
    /// Ponteiro para a interface da camada de serviço de cadastro
    IServicoCadastro* servico;

public:
    /**
     * @brief Construtor da controladora de apresentação com injeção de dependência.
     * @param servico Ponteiro para um objeto que implemente IServicoCadastro.
     */
    CntrApresentacaoCadastro(IServicoCadastro* servico) : servico(servico) {}

    /**
     * @brief Executa o fluxo de interação com o usuário para cadastro.
     * Exibe a tela no terminal, solicita os dados (email, nome, senha, papel),
     * trata possíveis exceções de formatação incorreta lançadas pelos domínios
     * e informa o resultado da tentativa de cadastro.
     */
    void executar() override;
};
