#include "ContPessoas.hpp"

bool ContPessoas::inserir(const Pessoa &pessoa) {
  std::string chave = pessoa.getEmail().getEmail();
  // Se já existe, retorna false
  if (container.find(chave) != container.end()) {
    return false;
  }
  container[chave] = pessoa;
  return true;
}

bool ContPessoas::buscar(const std::string &email, Pessoa &pessoa) const {
  auto it = container.find(email);
  if (it != container.end()) {
    pessoa = it->second;
    return true;
  }
  return false;
}

bool ContPessoas::atualizar(const Pessoa &pessoa) {
  std::string chave = pessoa.getEmail().getEmail();
  auto it = container.find(chave);
  if (it != container.end()) {
    container[chave] = pessoa;
    return true;
  }
  return false;
}

bool ContPessoas::remover(const std::string &email) {
  auto it = container.find(email);
  if (it != container.end()) {
    container.erase(it);
    return true;
  }
  return false;
}
