#pragma once

/**
 * @class IApresentacaoCadastro
 * @brief Interface para a camada de apresentação do módulo de Cadastro e Gerenciamento de Pessoas.
 *
 * Esta interface define o contrato para as classes controladoras responsáveis 
 * por interagir com o usuário (via terminal, GUI, etc) para realizar as 
 * operações de criar, ler, atualizar e excluir cadastros de Pessoa no sistema.
 */
class IApresentacaoCadastro {
public:
  /**
   * @brief Executa o fluxo principal da apresentação de cadastro.
   * 
   * Método responsável por apresentar o menu ou interface inicial ao usuário, 
   * coletar entradas, validar dados utilizando as classes de domínio e delegar 
   * a lógica de persistência e negócio para a camada de serviço.
   */
  virtual void executar() = 0;

  /**
   * @brief Destrutor virtual padrão.
   * 
   * Garante a destruição correta das classes derivadas.
   */
  virtual ~IApresentacaoCadastro() = default;
};
