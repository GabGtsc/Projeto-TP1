#include "apresentacao/controladoras/CntrApresentacaoAutenticacao.hpp"
#include "apresentacao/controladoras/CntrApresentacaoCadastro.hpp"
#include "apresentacao/controladoras/CntrApresentacaoGestao.hpp"
#include "servico/controladoras/CntrServicoAutenticacao.hpp"
#include "servico/controladoras/CntrServicoCadastro.hpp"
#include "servico/stubs/StubServicoGestao.hpp"
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
  
  // Stubs temporarios para Gestão
  StubServicoGestao *servicoGestao = new StubServicoGestao();

  // Instancia as controladoras de apresentação injetando os serviços
  CntrApresentacaoAutenticacao ctrlAuth(servicoAuth);
  CntrApresentacaoCadastro ctrlCad(servicoCad);
  CntrApresentacaoGestao ctrlGestao(servicoGestao);

  bool rodando = true;
  std::string escolha;
  Sessao sessaoAtiva;

  while (rodando) {
    limparTelaPrincipal();
    std::cout << "===============================\n";
    std::cout << "    SISTEMA DE GERENCIAMENTO   \n";
    std::cout << "===============================\n";
    if (sessaoAtiva.logado) {
        std::cout << "Ola, " << sessaoAtiva.nome.getNome() << " (" << sessaoAtiva.papel.getPapel() << ")!\n\n";
    }
    
    std::cout << (sessaoAtiva.logado ? "1 - Logout\n" : "1 - Login\n");
    std::cout << "2 - Cadastro / Gerenciar Pessoas\n";
    if (sessaoAtiva.logado) {
        std::cout << "3 - Modulo de Gestao (Projetos, Sprints, Historias)\n";
    }
    std::cout << "4 - Sair\n";
    std::cout << "Escolha uma opcao: ";
    
    std::cin >> std::ws;
    std::getline(std::cin, escolha);

    if (escolha == "1") {
      if (sessaoAtiva.logado) {
          sessaoAtiva.logado = false;
          std::cout << "\n[SISTEMA] Logout realizado com sucesso.\n";
          std::cout << "Pressione ENTER para continuar...";
          std::getline(std::cin, escolha);
      } else {
          sessaoAtiva = ctrlAuth.executar();
          limparTelaPrincipal();
          if (sessaoAtiva.logado) {
            std::cout << "\n[SISTEMA] Bem-vindo(a)! Usuario autenticado com sucesso: " << sessaoAtiva.email.getEmail() << "\n";
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
    } else if (escolha == "3" && sessaoAtiva.logado) {
      ctrlGestao.executar(sessaoAtiva);
    } else if (escolha == "4") {
      rodando = false;
    }
  }

  std::cout << "\n[SISTEMA] Encerrando aplicacao...\n";

  // Libera a memória alocada dinamicamente
  delete servicoAuth;
  delete servicoCad;
  delete servicoGestao;
  delete cntrDados;

  return 0;
}
