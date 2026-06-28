#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/PlanoDeSprint.hpp"

class ContPlanos {
private:
    std::map<std::string, PlanoDeSprint> planos;
    // Maps sprint code -> project code
    std::map<std::string, std::string> relacaoProjeto;

public:
    bool inserir(const PlanoDeSprint &plano);
    bool buscar(const std::string &codigo, PlanoDeSprint &plano);
    bool atualizar(const PlanoDeSprint &plano);
    bool remover(const std::string &codigo);
    
    bool associarProjeto(const std::string &codigoSprint, const std::string &codigoProjeto);
    std::vector<std::string> listarSprintsDeProjeto(const std::string &codigoProjeto);
};
