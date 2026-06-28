#pragma once

#include "Sessao.hpp"

class IApresentacaoGestao {
public:
  virtual ~IApresentacaoGestao() = default;
  virtual void executar(const Sessao &sessao) = 0;
};
