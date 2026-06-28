#include "CntrDados.hpp"

CntrDados::CntrDados() {
#ifdef DEBUG
    try {
        Pessoa po;
        Nome n1; n1.setNome("Prop"); po.setNome(n1);
        Email e1; e1.setEmail("po@a.com"); po.setEmail(e1);
        Senha s1; s1.setSenha("A1a2B3"); po.setSenha(s1);
        Papel p1; p1.setPapel("PROPRIETARIO DE PRODUTO"); po.setPapel(p1);
        this->criar(po);

        Pessoa sm;
        Nome n2; n2.setNome("Scrum"); sm.setNome(n2);
        Email e2; e2.setEmail("sm@a.com"); sm.setEmail(e2);
        Senha s2; s2.setSenha("A1a2B3"); sm.setSenha(s2);
        Papel p2; p2.setPapel("MESTRE SCRUM"); sm.setPapel(p2);
        this->criar(sm);

        Pessoa dev;
        Nome n3; n3.setNome("Dev"); dev.setNome(n3);
        Email e3; e3.setEmail("dv@a.com"); dev.setEmail(e3);
        // ==========================================
        // DADOS FALSOS DE GESTAO
        // ==========================================
        
        // --- PROJETO 1 ---
        Projeto mockProj1;
        Codigo cMockP1; cMockP1.setCodigo("PRJ001"); mockProj1.setCodigo(cMockP1);
        Nome nMockP1; nMockP1.setNome("Projeto Alfa"); mockProj1.setNome(nMockP1);
        Data dInicio1; dInicio1.setData("01/01/2026"); mockProj1.setInicio(dInicio1);
        Data dTermino1; dTermino1.setData("31/12/2026"); mockProj1.setTermino(dTermino1);
        this->criarProjeto(mockProj1);
        this->associarProjetoPessoa(cMockP1, e1); // e1 = po@a.com
        this->associarProjetoPessoa(cMockP1, e2); // e2 = sm@a.com
        
        PlanoDeSprint mockSpr1;
        Codigo cMockS1; cMockS1.setCodigo("SPR001"); mockSpr1.setCodigo(cMockS1);
        Texto txMockS1; txMockS1.setTexto("Entrega do MVP"); mockSpr1.setObjetivo(txMockS1);
        Tempo tmMockS1; tmMockS1.setTempo(30); mockSpr1.setCapacidade(tmMockS1);
        this->criarPlanoDeSprint(mockSpr1);
        this->associarSprintProjeto(cMockS1, cMockP1);
        
        // 3 Historias para o PRJ001 e SPR001
        for (int i=1; i<=3; ++i) {
            HistoriaDeUsuario hMock;
            Codigo cHMock; cHMock.setCodigo("HST00" + std::to_string(i)); hMock.setCodigo(cHMock);
            
            Texto tTi; tTi.setTexto("Titulo alfa " + std::to_string(i)); hMock.setTitulo(tTi);
            Texto tPa; tPa.setTexto("Usuario do sistema"); hMock.setPapel(tPa);
            Texto tAc; tAc.setTexto("Poder executar acao " + std::to_string(i)); hMock.setAcao(tAc);
            Texto tVa; tVa.setTexto("Alcancando o valor " + std::to_string(i)); hMock.setValor(tVa);
            
            Prioridade prHMock; prHMock.setPrioridade("ALTA"); hMock.setPrioridade(prHMock);
            Estado esHMock; esHMock.setEstado("A FAZER"); hMock.setEstado(esHMock);
            Tempo tmHMock; tmHMock.setTempo(5); hMock.setEstimativa(tmHMock);
            
            this->criarHistoriaDeUsuario(hMock);
            this->associarHistoriaProjeto(cHMock, cMockP1);
            this->associarHistoriaSprint(cHMock, cMockS1);
            this->associarHistoriaPessoa(cHMock, e3); // dv@a.com
        }
        
        // --- PROJETO 2 ---
        Projeto mockProj2;
        Codigo cMockP2; cMockP2.setCodigo("PRJ002"); mockProj2.setCodigo(cMockP2);
        Nome nMockP2; nMockP2.setNome("Projeto Beta"); mockProj2.setNome(nMockP2);
        Data dInicio2; dInicio2.setData("15/05/2026"); mockProj2.setInicio(dInicio2);
        Data dTermino2; dTermino2.setData("15/10/2026"); mockProj2.setTermino(dTermino2);
        this->criarProjeto(mockProj2);
        this->associarProjetoPessoa(cMockP2, e1); // e1 = po@a.com
        this->associarProjetoPessoa(cMockP2, e2); // e2 = sm@a.com
        
        PlanoDeSprint mockSpr2;
        Codigo cMockS2; cMockS2.setCodigo("SPR002"); mockSpr2.setCodigo(cMockS2);
        Texto txMockS2; txMockS2.setTexto("Funcionalidade Core"); mockSpr2.setObjetivo(txMockS2);
        Tempo tmMockS2; tmMockS2.setTempo(20); mockSpr2.setCapacidade(tmMockS2);
        this->criarPlanoDeSprint(mockSpr2);
        this->associarSprintProjeto(cMockS2, cMockP2);
        
        // 3 Historias para o PRJ002 e SPR002
        for (int i=4; i<=6; ++i) {
            HistoriaDeUsuario hMock;
            Codigo cHMock; cHMock.setCodigo("HST00" + std::to_string(i)); hMock.setCodigo(cHMock);
            
            Texto tTi; tTi.setTexto("Titulo beta " + std::to_string(i)); hMock.setTitulo(tTi);
            Texto tPa; tPa.setTexto("Visitante comum"); hMock.setPapel(tPa);
            Texto tAc; tAc.setTexto("Acessar pagina " + std::to_string(i)); hMock.setAcao(tAc);
            Texto tVa; tVa.setTexto("Ter mais velocidade na aba " + std::to_string(i)); hMock.setValor(tVa);
            
            Prioridade prHMock; prHMock.setPrioridade("MEDIA"); hMock.setPrioridade(prHMock);
            Estado esHMock; esHMock.setEstado("A FAZER"); hMock.setEstado(esHMock);
            Tempo tmHMock; tmHMock.setTempo(2); hMock.setEstimativa(tmHMock);
            
            this->criarHistoriaDeUsuario(hMock);
            this->associarHistoriaProjeto(cHMock, cMockP2);
            this->associarHistoriaSprint(cHMock, cMockS2);
            this->associarHistoriaPessoa(cHMock, e3); // dv@a.com
        }
        
    } catch (...) {
        // Falhas silenciosas ao criar mocks
    }
#endif
}

bool CntrDados::obterPessoa(const Email &email, Pessoa &pessoa) {
  if (!contPessoas.buscar(email.getEmail(), pessoa)) {
    throw std::invalid_argument("Pessoa nao encontrada (autenticacao).");
  }
  return true;
}

bool CntrDados::criar(const Pessoa &pessoa) {
  if (!contPessoas.inserir(pessoa)) {
    throw std::invalid_argument("Nao foi possivel criar: E-mail ja cadastrado.");
  }
  return true;
}

bool CntrDados::ler(const Email &email, Pessoa &pessoa) {
  if (!contPessoas.buscar(email.getEmail(), pessoa)) {
    throw std::invalid_argument("Pessoa nao encontrada para leitura.");
  }
  return true;
}

bool CntrDados::atualizar(const Pessoa &pessoa) {
  if (!contPessoas.atualizar(pessoa)) {
    throw std::invalid_argument("Nao foi possivel atualizar: Pessoa nao encontrada.");
  }
  return true;
}

bool CntrDados::excluir(const Email &email) {
  if (!contPessoas.remover(email.getEmail())) {
    throw std::invalid_argument("Nao foi possivel excluir: Pessoa nao encontrada.");
  }
  return true;
}

// ================= GESTAO =================

// PROJETO
bool CntrDados::criarProjeto(const Projeto &projeto) {
    return contProjetos.inserir(projeto);
}
bool CntrDados::lerProjeto(const Codigo &codigo, Projeto &projeto) {
    return contProjetos.buscar(codigo.getCodigo(), projeto);
}
bool CntrDados::atualizarProjeto(const Projeto &projeto) {
    return contProjetos.atualizar(projeto);
}
bool CntrDados::excluirProjeto(const Codigo &codigo) {
    return contProjetos.remover(codigo.getCodigo());
}
bool CntrDados::associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa) {
    // Para simplificar, consideramos que a camada de Serviço vai especificar se é PO ou SM.
    // Mas na interface base, a associação poderia ser abstrata.
    // Como a regra de negócio do Projeto pede um PO e um SM, vamos assumir que o CntrServicoGestao
    // fará a lógica de associarPO e associarSM. Mas como na interface IArmazenamentoGestao temos apenas associarProjetoPessoa...
    // Na verdade, no Serviço eu preciso associar 2 pessoas diferentes!
    // Vou usar os 2 métodos diretamente daqui para ContProjetos.
    // Espera, a interface do CntrDados expõe apenas associarProjetoPessoa? 
    // Vamos verificar o papel da pessoa no BD.
    Pessoa p;
    if (contPessoas.buscar(emailPessoa.getEmail(), p)) {
        if (p.getPapel().getPapel() == "PROPRIETARIO DE PRODUTO") {
            return contProjetos.associarPO(codigoProjeto.getCodigo(), emailPessoa.getEmail());
        } else if (p.getPapel().getPapel() == "MESTRE SCRUM") {
            return contProjetos.associarSM(codigoProjeto.getCodigo(), emailPessoa.getEmail());
        }
    }
    return false;
}
std::vector<Codigo> CntrDados::listarProjetosDePessoa(const Email &emailPessoa) {
    std::vector<std::string> listaStr = contProjetos.listarProjetosDePessoa(emailPessoa.getEmail());
    std::vector<Codigo> listaCod;
    for (const auto &str : listaStr) {
        Codigo c; c.setCodigo(str);
        listaCod.push_back(c);
    }
    return listaCod;
}

// PLANO DE SPRINT
bool CntrDados::criarPlanoDeSprint(const PlanoDeSprint &plano) {
    return contPlanos.inserir(plano);
}
bool CntrDados::lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) {
    return contPlanos.buscar(codigo.getCodigo(), plano);
}
bool CntrDados::atualizarPlanoDeSprint(const PlanoDeSprint &plano) {
    return contPlanos.atualizar(plano);
}
bool CntrDados::excluirPlanoDeSprint(const Codigo &codigo) {
    return contPlanos.remover(codigo.getCodigo());
}
bool CntrDados::associarSprintProjeto(const Codigo &codigoSprint, const Codigo &codigoProjeto) {
    return contPlanos.associarProjeto(codigoSprint.getCodigo(), codigoProjeto.getCodigo());
}
std::vector<Codigo> CntrDados::listarSprintsDeProjeto(const Codigo &codigoProjeto) {
    std::vector<std::string> listaStr = contPlanos.listarSprintsDeProjeto(codigoProjeto.getCodigo());
    std::vector<Codigo> listaCod;
    for (const auto &str : listaStr) {
        Codigo c; c.setCodigo(str);
        listaCod.push_back(c);
    }
    return listaCod;
}

// HISTORIA DE USUARIO
bool CntrDados::criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    return contHistorias.inserir(historia);
}
bool CntrDados::lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) {
    return contHistorias.buscar(codigo.getCodigo(), historia);
}
bool CntrDados::atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    return contHistorias.atualizar(historia);
}
bool CntrDados::excluirHistoriaDeUsuario(const Codigo &codigo) {
    return contHistorias.remover(codigo.getCodigo());
}
bool CntrDados::associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto) {
    return contHistorias.associarProjeto(codigoHistoria.getCodigo(), codigoProjeto.getCodigo());
}
std::vector<Codigo> CntrDados::listarHistoriasDeProjeto(const Codigo &codigoProjeto) {
    std::vector<std::string> listaStr = contHistorias.listarHistoriasDeProjeto(codigoProjeto.getCodigo());
    std::vector<Codigo> listaCod;
    for (const auto &str : listaStr) {
        Codigo c; c.setCodigo(str);
        listaCod.push_back(c);
    }
    return listaCod;
}
bool CntrDados::associarHistoriaSprint(const Codigo &codigoHistoria, const Codigo &codigoSprint) {
    return contHistorias.associarSprint(codigoHistoria.getCodigo(), codigoSprint.getCodigo());
}
std::vector<Codigo> CntrDados::listarHistoriasDeSprint(const Codigo &codigoSprint) {
    std::vector<std::string> listaStr = contHistorias.listarHistoriasDeSprint(codigoSprint.getCodigo());
    std::vector<Codigo> listaCod;
    for (const auto &str : listaStr) {
        Codigo c; c.setCodigo(str);
        listaCod.push_back(c);
    }
    return listaCod;
}
bool CntrDados::associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    return contHistorias.associarPessoa(codigoHistoria.getCodigo(), emailPessoa.getEmail());
}
bool CntrDados::desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    return contHistorias.desassociarPessoa(codigoHistoria.getCodigo(), emailPessoa.getEmail());
}
std::vector<Codigo> CntrDados::listarHistoriasDePessoa(const Email &emailPessoa) {
    std::vector<std::string> listaStr = contHistorias.listarHistoriasDePessoa(emailPessoa.getEmail());
    std::vector<Codigo> listaCod;
    for (const auto &str : listaStr) {
        Codigo c; c.setCodigo(str);
        listaCod.push_back(c);
    }
    return listaCod;
}

