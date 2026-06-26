#include "Data.hpp"
#include <format>
#include <stdexcept>
#include <string>
#include <vector>

void Data::setData(const std::string &data) {
  if (data.empty())
    throw std::invalid_argument("Data não deve ser vazia!");

  if (data.length() != 10)
    throw std::invalid_argument("Data deve ter 10 char");

  if (!isdigit(data[0]) || !isdigit(data[1]) || data[2] != '/' || !isdigit(data[3]) || !isdigit(data[4]) ||
      data[5] != '/' || !isdigit(data[6]) || !isdigit(data[7]) || !isdigit(data[8]) || !isdigit(data[9]))
    throw std::invalid_argument("Formato errado: Data deve seguir dd/mm/aaaa");

  int dia = ((data[0] - '0') * 10) + (data[1] - '0');
  int mes = ((data[3] - '0') * 10) + (data[4] - '0');
  int ano = std::stoi(std::string{data[6], data[7], data[8], data[9]});

  if (ano < 2000 || ano > 2099)
    throw std::invalid_argument("Ano deve ser valor entre 2000 e 2099");
  if (mes < 1 || mes > 12)
    throw std::invalid_argument("Mês deve ser entre 1 e 12");
  if (dia < 1)
    throw std::invalid_argument("Dia não pode ser menor que 1");

  const std::vector<int> dias_por_mes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool bissexto = (ano % 4 == 0);

  if (mes == 2) {
    if ((bissexto && dia > dias_por_mes[mes - 1] + 1) || (!bissexto && dia > dias_por_mes[mes - 1]))
      throw std::invalid_argument("Dias demais para o mês dado");
  } else {
    if (dia > dias_por_mes[mes - 1])
      throw std::invalid_argument("Dias demais para o mês dado");
  }

  this->dia_ = dia;
  this->mes_ = mes;
  this->ano_ = ano;
}

Data::Data(const std::string &data) { setData(data); }

std::string Data::getData() const { return std::format("{:02}/{:02}/{}", this->dia_, this->mes_, this->ano_); }
