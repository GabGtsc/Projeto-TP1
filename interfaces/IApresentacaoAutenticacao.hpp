#pragma once

class IApresentacaoAutenticacao {
public:
  virtual ~IApresentacaoAutenticacao() = default;
  virtual void executar() = 0;
};
