#include "apresentacao/controladoras/CntrApresentacaoAutenticacao.hpp"
#include "apresentacao/controladoras/CntrApresentacaoCadastro.hpp"
#include "servico/controladoras/CntrServicoAutenticacao.hpp"
#include "servico/controladoras/CntrServicoCadastro.hpp"
#include "dados/CntrDados.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

void limparTelaPrincipal() {
    std::cout << "\x1B[2J\x1B[H";
    std::cout.flush();
}

int main() {
  // Instancia a controladora de dados
  CntrDados *cntrDados = new CntrDados();

  // Instancia os serviços injetando as interfaces de armazenamento implementadas pela controladora de dados
  CntrServicoAutenticacao *servicoAuth = new CntrServicoAutenticacao(cntrDados);
  CntrServicoCadastro *servicoCad = new CntrServicoCadastro(cntrDados);

  // Instancia as controladoras de apresentação injetando os serviços
  CntrApresentacaoAutenticacao ctrlAuth(servicoAuth);
  CntrApresentacaoCadastro ctrlCad(servicoCad);

  bool rodando = true;
  std::string escolha;
  bool logado = false;
  std::string nomeLogado = "";

  while (rodando) {
    limparTelaPrincipal();
    std::cout << "===============================\n";
    std::cout << "    SISTEMA DE GERENCIAMENTO   \n";
    std::cout << "===============================\n";
    if (logado) {
        std::cout << "Ola, " << nomeLogado << "!\n\n";
    }
    
    std::cout << (logado ? "1 - Logout\n" : "1 - Login\n");
    std::cout << "2 - Cadastro / Gerenciar Pessoas\n";
    std::cout << "3 - Sair\n";
    std::cout << "Escolha uma opcao: ";
    
    std::cin >> std::ws;
    std::getline(std::cin, escolha);

    if (escolha == "1") {
      if (logado) {
          logado = false;
          nomeLogado = "";
          std::cout << "\n[SISTEMA] Logout realizado com sucesso.\n";
          std::cout << "Pressione ENTER para continuar...";
          std::getline(std::cin, escolha);
      } else {
          ResultadoAutenticacao sessao = ctrlAuth.executar();
          limparTelaPrincipal();
          if (sessao.sucesso) {
            logado = true;
            nomeLogado = sessao.nome.getNome();
            std::cout << "\n[SISTEMA] Bem-vindo(a)! Usuario autenticado com sucesso: " << sessao.email.getEmail() << "\n";
            std::cout << "Pressione ENTER para continuar...";
            std::getline(std::cin, escolha);
          } else {
            std::cout << "\n[SISTEMA] Autenticacao cancelada ou falhou.\n";
            std::cout << "Pressione ENTER para voltar ao menu...";
            std::getline(std::cin, escolha);
          }
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
  delete cntrDados;

  return 0;
}
