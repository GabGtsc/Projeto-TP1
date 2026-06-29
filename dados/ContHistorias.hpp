#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/HistoriaDeUsuario.hpp"

/**
 * @brief Contêiner em memória para gerenciamento de Histórias de Usuário.
 */
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
    /**
     * @brief Insere uma nova história no contêiner.
     * @param historia Objeto HistoriaDeUsuario a ser inserido.
     * @return true se sucesso.
     */
    bool inserir(const HistoriaDeUsuario &historia);

    /**
     * @brief Busca uma história pelo seu código.
     * @param codigo Código da história.
     * @param historia Referência para armazenar a história encontrada.
     * @return true se encontrado.
     */
    bool buscar(const std::string &codigo, HistoriaDeUsuario &historia);

    /**
     * @brief Atualiza os dados de uma história existente.
     * @param historia História com os novos dados.
     * @return true se sucesso.
     */
    bool atualizar(const HistoriaDeUsuario &historia);

    /**
     * @brief Remove uma história pelo seu código.
     * @param codigo Código da história a ser removida.
     * @return true se sucesso.
     */
    bool remover(const std::string &codigo);
    
    /**
     * @brief Associa uma história a um projeto.
     * @param codigoHistoria Código da história.
     * @param codigoProjeto Código do projeto.
     * @return true se sucesso.
     */
    bool associarProjeto(const std::string &codigoHistoria, const std::string &codigoProjeto);

    /**
     * @brief Lista as histórias associadas a um projeto.
     * @param codigoProjeto Código do projeto.
     * @return std::vector<std::string> com os códigos das histórias.
     */
    std::vector<std::string> listarHistoriasDeProjeto(const std::string &codigoProjeto);

    /**
     * @brief Associa uma história a um plano de sprint.
     * @param codigoHistoria Código da história.
     * @param codigoSprint Código do plano de sprint.
     * @return true se sucesso.
     */
    bool associarSprint(const std::string &codigoHistoria, const std::string &codigoSprint);

    /**
     * @brief Lista as histórias associadas a um plano de sprint.
     * @param codigoSprint Código do plano de sprint.
     * @return std::vector<std::string> com os códigos das histórias.
     */
    std::vector<std::string> listarHistoriasDeSprint(const std::string &codigoSprint);

    /**
     * @brief Associa uma história a uma pessoa (Desenvolvedor).
     * @param codigoHistoria Código da história.
     * @param emailPessoa Email da pessoa.
     * @return true se sucesso.
     */
    bool associarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa);

    /**
     * @brief Desassocia uma história de uma pessoa.
     * @param codigoHistoria Código da história.
     * @param emailPessoa Email da pessoa.
     * @return true se sucesso.
     */
    bool desassociarPessoa(const std::string &codigoHistoria, const std::string &emailPessoa);

    /**
     * @brief Lista as histórias associadas a uma pessoa.
     * @param emailPessoa Email da pessoa.
     * @return std::vector<std::string> com os códigos das histórias.
     */
    std::vector<std::string> listarHistoriasDePessoa(const std::string &emailPessoa);
};
