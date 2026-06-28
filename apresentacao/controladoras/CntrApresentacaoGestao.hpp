#pragma once

#include "../../interfaces/IApresentacaoGestao.hpp"
#include "../../interfaces/IServicoGestao.hpp"
#include <iostream>
#include <string>

/**
 * @class CntrApresentacaoGestao
 * @brief Classe controladora de apresentação para o módulo de Gestão.
 *
 * Esta classe é responsável por gerenciar a interface com o usuário autenticado
 * e oferecer menus e opções baseadas no seu Papel (Proprietário de Produto,
 * Mestre Scrum, Desenvolvedor). Ela delega a execução das regras de negócio
 * para a camada de serviço.
 */
class CntrApresentacaoGestao : public IApresentacaoGestao {
private:
    /// Ponteiro para a interface da camada de serviço de gestão
    IServicoGestao* servico;

public:
    /**
     * @brief Construtor da controladora de apresentação com injeção de dependência.
     * @param servico Ponteiro para um objeto que implemente IServicoGestao.
     */
    CntrApresentacaoGestao(IServicoGestao* servico) : servico(servico) {}

    /**
     * @brief Executa o fluxo de interação com o usuário para a gestão de entidades.
     * Exibe o menu principal condicional ao papel do usuário (Sessao).
     * Solicita entradas para operações CRUD e de listagem.
     * 
     * @param sessao DTO de Sessão contendo Email, Nome e Papel do usuário logado.
     */
    void executar(const Sessao &sessao) override;
};
