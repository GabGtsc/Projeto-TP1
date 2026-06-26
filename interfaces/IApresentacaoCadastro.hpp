#pragma once

class IApresentacaoCadastro {
public:
  virtual void executar() = 0;
  virtual ~IApresentacaoCadastro() = default;
};
