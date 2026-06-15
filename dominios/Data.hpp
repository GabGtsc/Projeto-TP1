#pragma once
#include <string>

class Data {
private:
  int dia, mes, ano;

public:
  Data(const std::string &data);
  void setData(const std::string &data);
  [[nodiscard]] std::string getData() const;
};
