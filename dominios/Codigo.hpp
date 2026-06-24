#pragma once

#include <string>

class Codigo {
private:
  std::string valor;

public:
  Codigo() = default;
  Codigo(const std::string &texto);
  void setCodigo(const std::string &texto);
  [[nodiscard]] std::string getCodigo() const;
};
