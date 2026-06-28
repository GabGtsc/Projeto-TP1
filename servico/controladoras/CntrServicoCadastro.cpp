#include "CntrServicoCadastro.hpp"
#include <stdexcept>

bool CntrServicoCadastro::ler(const Email &email, Pessoa &pessoa) {
  try {
    return armazenamento->ler(email, pessoa);
  } catch (const std::invalid_argument &) {
    return false;
  }
}

bool CntrServicoCadastro::criar(const Pessoa &pessoa) {
  try {
    return armazenamento->criar(pessoa);
  } catch (const std::invalid_argument &) {
    return false;
  }
}

bool CntrServicoCadastro::atualizar(const Pessoa &pessoa) {
  try {
    return armazenamento->atualizar(pessoa);
  } catch (const std::invalid_argument &) {
    return false;
  }
}

bool CntrServicoCadastro::excluir(const Email &email) {
  try {
    return armazenamento->excluir(email);
  } catch (const std::invalid_argument &) {
    return false;
  }
}
