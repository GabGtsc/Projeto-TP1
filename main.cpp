#include "apresentacao/controladoras/CntrApresentacaoAutenticacao.hpp"
#include "servico/stubs/StubServicoAutenticacao.hpp"
#include <iostream>

int main() {
  // Instancia o stub do serviço de autenticação
  StubServicoAutenticacao *servicoAuth = new StubServicoAutenticacao();

  // Instancia a controladora de apresentação injetando o stub pelo construtor
  CntrApresentacaoAutenticacao ctrlAuth(servicoAuth);

  // Executa a controladora e obtém a sessão
  ResultadoAutenticacao sessao = ctrlAuth.executar();

  if (sessao.sucesso) {
    std::cout << "\n[MAIN] Usuario logado no sistema com o e-mail: " << sessao.email.getEmail() << "\n";
  } else {
    std::cout << "\n[MAIN] Usuario decidiu sair ou a autenticacao falhou.\n";
  }

  // Libera a memória alocada dinamicamente
  delete servicoAuth;

  return 0;
}
