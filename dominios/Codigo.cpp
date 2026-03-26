#include "Codigo.hpp"
#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

void Codigo::setCodigo(const string &texto) {
  if (texto.length() != 5) {
    throw invalid_argument("Codigo deve ter exatamente 5 dígitos");
  }
  if (!isupper(texto[0]) || !isupper(texto[1]) || !isdigit(texto[2]) ||
      !isdigit(texto[3]) || !isdigit(texto[4])) {
    throw invalid_argument("Codigo deve seguir formato AA123");
  }

  this->valor = texto;
}

string Codigo::getCodigo() const { return valor; }

Codigo::Codigo(const string &texto) { setCodigo(texto); }
