#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/Projeto.hpp"

class ContProjetos {
private:
    std::map<std::string, Projeto> projetos;
    // Maps project code -> email of the associated PO
    std::map<std::string, std::string> relacaoPO;
    // Maps project code -> email of the associated SM
    std::map<std::string, std::string> relacaoSM;

public:
    bool inserir(const Projeto &projeto);
    bool buscar(const std::string &codigo, Projeto &projeto);
    bool atualizar(const Projeto &projeto);
    bool remover(const std::string &codigo);
    
    bool associarPO(const std::string &codigo, const std::string &email);
    bool associarSM(const std::string &codigo, const std::string &email);
    
    std::vector<std::string> listarProjetosDePessoa(const std::string &email);
};
