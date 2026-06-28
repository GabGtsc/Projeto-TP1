#include "ContHistorias.hpp"

bool ContHistorias::inserir(const HistoriaDeUsuario &historia) {
    std::string key = historia.getCodigo().getCodigo();
    if (historias.find(key) != historias.end()) {
        return false;
    }
    historias[key] = historia;
    return true;
}

bool ContHistorias::buscar(const std::string &codigo, HistoriaDeUsuario &historia) {
    auto it = historias.find(codigo);
    if (it != historias.end()) {
        historia = it->second;
        return true;
    }
    return false;
}

bool ContHistorias::atualizar(const HistoriaDeUsuario &historia) {
    std::string key = historia.getCodigo().getCodigo();
    if (historias.find(key) != historias.end()) {
        historias[key] = historia;
        return true;
    }
    return false;
}

bool ContHistorias::remover(const std::string &codigo) {
    if (historias.find(codigo) != historias.end()) {
        historias.erase(codigo);
        relacaoProjeto.erase(codigo);
        relacaoSprint.erase(codigo);
        relacaoPessoa.erase(codigo);
        return true;
    }
    return false;
}

bool ContHistorias::associarProjeto(const std::string &codigoHistoria, const std::string &codigoProjeto) {
    if (historias.find(codigoHistoria) == historias.end()) return false;
    relacaoProjeto[codigoHistoria] = codigoProjeto;
    return true;
}

std::vector<std::string> ContHistorias::listarHistoriasDeProjeto(const std::string &codigoProjeto) {
    std::vector<std::string> lista;
    for (const auto& pair : relacaoProjeto) {
        if (pair.second == codigoProjeto) {
            lista.push_back(pair.first);
        }
    }
    return lista;
}

bool ContHistorias::associarSprint(const std::string &codigoHistoria, const std::string &codigoSprint) {
    if (historias.find(codigoHistoria) == historias.end()) return false;
    relacaoSprint[codigoHistoria] = codigoSprint;
    return true;
}

std::vector<std::string> ContHistorias::listarHistoriasDeSprint(const std::string &codigoSprint) {
    std::vector<std::string> lista;
    for (const auto& pair : relacaoSprint) {
        if (pair.second == codigoSprint) {
            lista.push_back(pair.first);
        }
    }
    return lista;
}

bool ContHistorias::associarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa) {
    if (historias.find(codigoHistoria) == historias.end()) return false;
    relacaoPessoa[codigoHistoria] = emailPessoa;
    return true;
}

bool ContHistorias::desassociarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa) {
    auto it = relacaoPessoa.find(codigoHistoria);
    if (it != relacaoPessoa.end() && it->second == emailPessoa) {
        relacaoPessoa.erase(it);
        return true;
    }
    return false;
}

std::vector<std::string> ContHistorias::listarHistoriasDePessoa(const std::string &emailPessoa) {
    std::vector<std::string> lista;
    for (const auto& pair : relacaoPessoa) {
        if (pair.second == emailPessoa) {
            lista.push_back(pair.first);
        }
    }
    return lista;
}
