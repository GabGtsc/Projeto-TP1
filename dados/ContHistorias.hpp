#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/HistoriaDeUsuario.hpp"

class ContHistorias {
private:
    std::map<std::string, HistoriaDeUsuario> historias;
    // Maps historia code -> project code
    std::map<std::string, std::string> relacaoProjeto;
    // Maps historia code -> sprint code
    std::map<std::string, std::string> relacaoSprint;
    // Maps historia code -> email pessoa
    std::map<std::string, std::string> relacaoPessoa;

public:
    bool inserir(const HistoriaDeUsuario &historia);
    bool buscar(const std::string &codigo, HistoriaDeUsuario &historia);
    bool atualizar(const HistoriaDeUsuario &historia);
    bool remover(const std::string &codigo);
    
    bool associarProjeto(const std::string &codigoHistoria, const std::string &codigoProjeto);
    std::vector<std::string> listarHistoriasDeProjeto(const std::string &codigoProjeto);

    bool associarSprint(const std::string &codigoHistoria, const std::string &codigoSprint);
    std::vector<std::string> listarHistoriasDeSprint(const std::string &codigoSprint);

    bool associarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa);
    bool desassociarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa);
    std::vector<std::string> listarHistoriasDePessoa(const std::string &emailPessoa);
};
