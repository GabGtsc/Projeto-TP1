#pragma once

#include "../../interfaces/IApresentacaoGestao.hpp"
#include "../../interfaces/IServicoGestao.hpp"
#include <iostream>
#include <limits>

/**
 * @class CntrApresentacaoGestao
 * @brief Classe controladora de apresentação para o módulo de Gestão Scrum.
 *
 * Responsável por gerir os menus interativos do utilizador para operações
 * de CRUD e regras de negócio envolvendo Projetos, Planos de Sprint e 
 * Histórias de Utilizador.
 */
class CntrApresentacaoGestao : public IApresentacaoGestao {
private:
    IServicoGestao* servico;

    // Métodos auxiliares privados para organizar os submenus
    void menuProjetos();
    void menuSprints();
    void menuHistorias();

public:
    void executar() override;
    void setServico(IServicoGestao* servico) { this->servico = servico; }
};