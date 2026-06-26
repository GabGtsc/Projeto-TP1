#pragma once

class IServicoAutenticacao {
public:
  virtual bool autenticar() = 0;
  virtual ~IServicoAutenticacao() = default;
};
