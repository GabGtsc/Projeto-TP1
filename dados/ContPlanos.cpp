#include "ContPlanos.hpp"

bool ContPlanos::inserir(const PlanoDeSprint &plano) {
    std::string key = plano.getCodigo().getCodigo();
    if (planos.find(key) != planos.end()) {
        return false;
    }
    planos[key] = plano;
    return true;
}

bool ContPlanos::buscar(const std::string &codigo, PlanoDeSprint &plano) {
    auto it = planos.find(codigo);
    if (it != planos.end()) {
        plano = it->second;
        return true;
    }
    return false;
}

bool ContPlanos::atualizar(const PlanoDeSprint &plano) {
    std::string key = plano.getCodigo().getCodigo();
    if (planos.find(key) != planos.end()) {
        planos[key] = plano;
        return true;
    }
    return false;
}

bool ContPlanos::remover(const std::string &codigo) {
    if (planos.find(codigo) != planos.end()) {
        planos.erase(codigo);
        relacaoProjeto.erase(codigo);
        return true;
    }
    return false;
}

bool ContPlanos::associarProjeto(const std::string &codigoSprint, const std::string &codigoProjeto) {
    if (planos.find(codigoSprint) == planos.end()) return false;
    relacaoProjeto[codigoSprint] = codigoProjeto;
    return true;
}

std::vector<std::string> ContPlanos::listarSprintsDeProjeto(const std::string &codigoProjeto) {
    std::vector<std::string> lista;
    for (const auto& pair : relacaoProjeto) {
        if (pair.second == codigoProjeto) {
            lista.push_back(pair.first);
        }
    }
    return lista;
}
