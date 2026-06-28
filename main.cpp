#include "apresentacao/controladoras/CntrApresentacaoAutenticacao.hpp"
#include "apresentacao/controladoras/CntrApresentacaoCadastro.hpp"
#include "servico/stubs/StubServicoAutenticacao.hpp"
#include "servico/stubs/StubServicoCadastro.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

void limparTelaPrincipal() {
#if defined _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main() {
  // Instancia os stubs de serviço
  StubServicoAutenticacao *servicoAuth = new StubServicoAutenticacao();
  StubServicoCadastro *servicoCad = new StubServicoCadastro();

  // Instancia as controladoras de apresentação injetando os stubs
  CntrApresentacaoAutenticacao ctrlAuth(servicoAuth);
  CntrApresentacaoCadastro ctrlCad(servicoCad);

  bool rodando = true;
  std::string escolha;

  while (rodando) {
    limparTelaPrincipal();
    std::cout << "===============================\n";
    std::cout << "    SISTEMA DE GERENCIAMENTO   \n";
    std::cout << "===============================\n";
    std::cout << "1 - Login\n";
    std::cout << "2 - Cadastro\n";
    std::cout << "3 - Sair\n";
    std::cout << "Escolha uma opcao: ";
    
    std::cin >> std::ws;
    std::getline(std::cin, escolha);

    if (escolha == "1") {
      ResultadoAutenticacao sessao = ctrlAuth.executar();
      limparTelaPrincipal();
      if (sessao.sucesso) {
        std::cout << "\n[SISTEMA] Bem-vindo(a)! Usuario autenticado com sucesso: " << sessao.email.getEmail() << "\n";
        std::cout << "Pressione ENTER para continuar...";
        std::getline(std::cin, escolha);
      } else {
        std::cout << "\n[SISTEMA] Autenticacao cancelada ou falhou.\n";
        std::cout << "Pressione ENTER para voltar ao menu...";
        std::getline(std::cin, escolha);
      }
    } else if (escolha == "2") {
      ctrlCad.executar();
    } else if (escolha == "3") {
      rodando = false;
    }
  }

  std::cout << "\n[SISTEMA] Encerrando aplicacao...\n";

  // Libera a memória alocada dinamicamente
  delete servicoAuth;
  delete servicoCad;

  return 0;
}
