#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/Projeto.hpp"

/**
 * @brief Contêiner em memória para gerenciamento de Projetos.
 */
class ContProjetos {
private:
    std::map<std::string, Projeto> projetos;
    // Maps project code -> email of the associated PO
    std::map<std::string, std::string> relacaoPO;
    // Maps project code -> email of the associated SM
    std::map<std::string, std::string> relacaoSM;

public:
    /**
     * @brief Insere um novo Projeto no contêiner.
     * @param projeto Objeto Projeto a ser inserido.
     * @return true se sucesso.
     */
    bool inserir(const Projeto &projeto);

    /**
     * @brief Busca um projeto pelo seu código.
     * @param codigo Código do projeto.
     * @param projeto Referência para armazenar o projeto encontrado.
     * @return true se encontrado.
     */
    bool buscar(const std::string &codigo, Projeto &projeto);

    /**
     * @brief Atualiza os dados de um projeto existente.
     * @param projeto Projeto com os novos dados.
     * @return true se sucesso.
     */
    bool atualizar(const Projeto &projeto);

    /**
     * @brief Remove um projeto pelo seu código.
     * @param codigo Código do projeto a ser removido.
     * @return true se sucesso.
     */
    bool remover(const std::string &codigo);
    
    /**
     * @brief Associa um Product Owner (PO) a um projeto.
     * @param codigo Código do projeto.
     * @param email Email do PO.
     * @return true se sucesso.
     */
    bool associarPO(const std::string &codigo, const std::string &email);

    /**
     * @brief Associa um Scrum Master (SM) a um projeto.
     * @param codigo Código do projeto.
     * @param email Email do SM.
     * @return true se sucesso.
     */
    bool associarSM(const std::string &codigo, const std::string &email);
    
    /**
     * @brief Lista projetos associados a uma pessoa (PO ou SM).
     * @param email Email da pessoa.
     * @return std::vector<std::string> com os códigos dos projetos.
     */
    std::vector<std::string> listarProjetosDePessoa(const std::string &email);

    /**
     * @brief Lista todos os projetos armazenados.
     * @return std::vector<std::string> com os códigos de todos os projetos.
     */
    std::vector<std::string> listarTodosProjetos();
};
