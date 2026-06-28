#include "CntrDados.hpp"

bool CntrDados::obterPessoa(const Email &email, Pessoa &pessoa) {
  if (!contPessoas.buscar(email.getEmail(), pessoa)) {
    throw std::invalid_argument("Pessoa nao encontrada (autenticacao).");
  }
  return true;
}

bool CntrDados::criar(const Pessoa &pessoa) {
  if (!contPessoas.inserir(pessoa)) {
    throw std::invalid_argument("Nao foi possivel criar: E-mail ja cadastrado.");
  }
  return true;
}

bool CntrDados::ler(const Email &email, Pessoa &pessoa) {
  if (!contPessoas.buscar(email.getEmail(), pessoa)) {
    throw std::invalid_argument("Pessoa nao encontrada para leitura.");
  }
  return true;
}

bool CntrDados::atualizar(const Pessoa &pessoa) {
  if (!contPessoas.atualizar(pessoa)) {
    throw std::invalid_argument("Nao foi possivel atualizar: Pessoa nao encontrada.");
  }
  return true;
}

bool CntrDados::excluir(const Email &email) {
  if (!contPessoas.remover(email.getEmail())) {
    throw std::invalid_argument("Nao foi possivel excluir: Pessoa nao encontrada.");
  }
  return true;
}
