#include "ContProjetos.hpp"

bool ContProjetos::inserir(const Projeto &projeto) {
    std::string key = projeto.getCodigo().getCodigo();
    if (projetos.find(key) != projetos.end()) {
        return false;
    }
    projetos[key] = projeto;
    return true;
}

bool ContProjetos::buscar(const std::string &codigo, Projeto &projeto) {
    auto it = projetos.find(codigo);
    if (it != projetos.end()) {
        projeto = it->second;
        return true;
    }
    return false;
}

bool ContProjetos::atualizar(const Projeto &projeto) {
    std::string key = projeto.getCodigo().getCodigo();
    if (projetos.find(key) != projetos.end()) {
        projetos[key] = projeto;
        return true;
    }
    return false;
}

bool ContProjetos::remover(const std::string &codigo) {
    if (projetos.find(codigo) != projetos.end()) {
        projetos.erase(codigo);
        relacaoPO.erase(codigo);
        relacaoSM.erase(codigo);
        return true;
    }
    return false;
}

bool ContProjetos::associarPO(const std::string &codigo, const std::string &email) {
    if (projetos.find(codigo) == projetos.end()) return false;
    relacaoPO[codigo] = email;
    return true;
}

bool ContProjetos::associarSM(const std::string &codigo, const std::string &email) {
    if (projetos.find(codigo) == projetos.end()) return false;
    relacaoSM[codigo] = email;
    return true;
}

std::vector<std::string> ContProjetos::listarProjetosDePessoa(const std::string &email) {
    std::vector<std::string> lista;
    for (const auto& pair : relacaoPO) {
        if (pair.second == email) {
            lista.push_back(pair.first);
        }
    }
    for (const auto& pair : relacaoSM) {
        if (pair.second == email) {
            // Evitar duplicatas caso a mesma pessoa seja PO e SM (apesar de a regra impedir)
            bool found = false;
            for (const auto& l : lista) {
                if (l == pair.first) { found = true; break; }
            }
            if (!found) lista.push_back(pair.first);
        }
    }
    return lista;
}

std::vector<std::string> ContProjetos::listarTodosProjetos() {
    std::vector<std::string> lista;
    for (const auto& pair : projetos) {
        lista.push_back(pair.first);
    }
    return lista;
}
