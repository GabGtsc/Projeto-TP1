#include "CntrServicoAutenticacao.hpp"
#include <stdexcept>

bool CntrServicoAutenticacao::autenticar(const Email &email, const Senha &senha, Nome &nome) {
  Pessoa pessoa;
  try {
    // Tenta obter a pessoa do armazenamento
    armazenamento->obterPessoa(email, pessoa);
  } catch (const std::invalid_argument &) {
    // Pessoa não encontrada
    throw std::invalid_argument("Usuario nao existe.");
  }
  
  // Verifica se a senha armazenada é igual à fornecida
  if (pessoa.getSenha().getSenha() == senha.getSenha()) {
    nome = pessoa.getNome();
    return true; // Autenticado com sucesso
  }
  
  return false; // Senha incorreta
}
