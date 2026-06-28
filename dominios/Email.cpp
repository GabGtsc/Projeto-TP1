#include "Email.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

bool Email::AlfabetoMinusculoOuDigito(char c) const { return (isalpha(c) and islower(c)) or isdigit(c); }

void Email::ValidarEmail(const std::string &email) {
  if (email.empty()) {
    throw std::invalid_argument("O email digitado esta vazio!");
  }
  /*VERIFICAR PARTE LOCAL DO EMAIL*/
  /*
    Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-);
    não pode iniciar ou terminar com ponto ou hífen;
    ponto ou hífen deve ser seguido por letra(s) ou dígito(s); comprimento máximo é 64 caracteres. */

  size_t arroba = email.find('@');
  if (arroba == std::string::npos or arroba == 0 or arroba > 64) {
    throw std::invalid_argument("Parte local do email invalida!");
  }

  std::string ParteLocal = email.substr(0, arroba);
  size_t TamanhoParteLocal = ParteLocal.length();

  if ((ParteLocal.front() == '-' or ParteLocal.back() == '-') or
      (ParteLocal.front() == '.' or ParteLocal.back() == '.')) {
    throw std::invalid_argument("Ponto ou Hifen no inicio ou no fim do codigo");
  }

  for (size_t i = 0; i < TamanhoParteLocal; i++) {
    if (ParteLocal[i] == '-' || ParteLocal[i] == '.') {
      continue;
    }
    if (!AlfabetoMinusculoOuDigito(ParteLocal[i])) {
      throw std::invalid_argument(
          "Parte local do seu email possui caracteres diferentes de letras minusculas do alfabeto ou digito!");
    }
  }

  /*PARTE LOCAL VERIFICADA*/
  /*VERIFICAR PARTE DO DOMINIO*/
  /*
    Domínio é composto por uma ou mais partes separadas por ponto (.);
    cada parte pode conter letra (a-z), dígito (0-9) ou hífen (-);
    não pode iniciar ou terminar com hífen; comprimento máximo é 255 caracteres. */

  std::string ParteDominio = email.substr(arroba + 1);
  size_t TamanhoDominio = ParteDominio.length();

  if (ParteDominio.length() > 255 or ParteDominio.length() < 1) {
    throw std::invalid_argument("Dominio do seu email tem tamanho invalido!");
  }
  if (ParteDominio.front() == '-' or ParteDominio.back() == '-') {
    throw std::invalid_argument("Dominio do seu email inicia ou acaba em hifen!");
  }
  if (ParteDominio.find('.') == std::string::npos) {
    throw std::invalid_argument("Dominio sem nenhum '.'");
  }

  for (size_t i = 0; i < TamanhoDominio - 1; i++) {
    char c = ParteDominio[i];
    if (c == '.' and ParteDominio[i + 1] == '.') {
      throw std::invalid_argument("Parte em Dominio do email esta vazio!");
    }
    if (!AlfabetoMinusculoOuDigito(c) and c != '-' and c != '.') {
      throw std::invalid_argument("Em Dominio o seu email possui caracteres invalidos!");
    }
  }
}

void Email::setEmail(const std::string &email) {
  ValidarEmail(email);
  email_ = email;
}