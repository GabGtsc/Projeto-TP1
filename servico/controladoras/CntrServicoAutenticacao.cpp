#include "CntrServicoAutenticacao.hpp"
#include <stdexcept>

bool CntrServicoAutenticacao::autenticar(const Email &email, const Senha &senha) {
  Pessoa pessoa;
  try {
    // Tenta obter a pessoa do armazenamento
    armazenamento->obterPessoa(email, pessoa);
    
    // Verifica se a senha armazenada é igual à fornecida
    if (pessoa.getSenha().getSenha() == senha.getSenha()) {
      return true; // Autenticado com sucesso
    }
  } catch (const std::invalid_argument &) {
    // Pessoa não encontrada, cai aqui
    return false;
  }
  
  return false; // Senha incorreta ou erro
}
