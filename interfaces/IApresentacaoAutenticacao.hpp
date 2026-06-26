#pragma once

class IApresentacaoAutenticacao {
public:
  ~IApresentacaoAutenticacao() = default;
  virtual void executar() = 0;
};
