#pragma once
#include <map>
#include <string>
#include <vector>
#include "../entidades/PlanoDeSprint.hpp"

/**
 * @brief Contêiner em memória para gerenciamento de Planos de Sprint.
 */
class ContPlanos {
private:
    std::map<std::string, PlanoDeSprint> planos;
    // Maps sprint code -> project code
    std::map<std::string, std::string> relacaoProjeto;

public:
    /**
     * @brief Insere um novo Plano de Sprint no contêiner.
     * @param plano Objeto PlanoDeSprint a ser inserido.
     * @return true se sucesso.
     */
    bool inserir(const PlanoDeSprint &plano);

    /**
     * @brief Busca um plano de sprint pelo seu código.
     * @param codigo Código do plano.
     * @param plano Referência para armazenar o plano encontrado.
     * @return true se encontrado.
     */
    bool buscar(const std::string &codigo, PlanoDeSprint &plano);

    /**
     * @brief Atualiza os dados de um plano existente.
     * @param plano Plano de sprint com os novos dados.
     * @return true se sucesso.
     */
    bool atualizar(const PlanoDeSprint &plano);

    /**
     * @brief Remove um plano de sprint pelo seu código.
     * @param codigo Código do plano a ser removido.
     * @return true se sucesso.
     */
    bool remover(const std::string &codigo);
    
    /**
     * @brief Associa um plano de sprint a um projeto.
     * @param codigoSprint Código do plano de sprint.
     * @param codigoProjeto Código do projeto.
     * @return true se sucesso.
     */
    bool associarProjeto(const std::string &codigoSprint, const std::string &codigoProjeto);

    /**
     * @brief Lista todos os planos de sprint de um determinado projeto.
     * @param codigoProjeto Código do projeto.
     * @return std::vector<std::string> com os códigos dos planos.
     */
    std::vector<std::string> listarSprintsDeProjeto(const std::string &codigoProjeto);
};
