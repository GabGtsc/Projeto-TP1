#pragma once

class IApresentacaoGestao {
public:
  virtual ~IApresentacaoGestao() = default;
  virtual void executar() = 0;
};
