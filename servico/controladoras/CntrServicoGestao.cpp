#include "CntrServicoGestao.hpp"

// PROJETO
bool CntrServicoGestao::criarProjeto(const Projeto &projeto, const Email &emailPO, const Email &emailSM) {
    if (armazenamento->criarProjeto(projeto)) {
        armazenamento->associarProjetoPessoa(projeto.getCodigo(), emailPO);
        armazenamento->associarProjetoPessoa(projeto.getCodigo(), emailSM);
        return true;
    }
    return false;
}
bool CntrServicoGestao::lerProjeto(const Codigo &codigo, Projeto &projeto) {
    return armazenamento->lerProjeto(codigo, projeto);
}
bool CntrServicoGestao::atualizarProjeto(const Projeto &projeto) {
    return armazenamento->atualizarProjeto(projeto);
}
bool CntrServicoGestao::excluirProjeto(const Codigo &codigo) {
    return armazenamento->excluirProjeto(codigo);
}

// SPRINT
int diasEntreDatas(const std::string& d1, const std::string& d2) {
    // Calculo simples para a validação. Apenas exibe o uso de tempo no projeto.
    // Em C++, o ideal seria usar <chrono>, mas dadas as simplificações de Data (1..31, 1..12), 
    // um cálculo aproximado bastaria para a lógica, ou algo mais sofisticado se exigido.
    // Como a data é DD/MM/AAAA.
    int dia1 = std::stoi(d1.substr(0, 2));
    int mes1 = std::stoi(d1.substr(3, 2));
    int ano1 = std::stoi(d1.substr(6, 4));
    
    int dia2 = std::stoi(d2.substr(0, 2));
    int mes2 = std::stoi(d2.substr(3, 2));
    int ano2 = std::stoi(d2.substr(6, 4));
    
    int t1 = ano1 * 365 + mes1 * 30 + dia1;
    int t2 = ano2 * 365 + mes2 * 30 + dia2;
    return (t2 - t1);
}

bool CntrServicoGestao::criarPlanoDeSprint(const PlanoDeSprint &plano, const Codigo &codigoProjeto) {
    Projeto p;
    if (!armazenamento->lerProjeto(codigoProjeto, p)) return false;
    
    // Regra: A soma das capacidades dos planos de sprint deve ser menor ou igual 
    // ao número de dias entre as datas de início e término do projeto.
    int diasTotais = diasEntreDatas(p.getInicio().getData(), p.getTermino().getData());
    
    std::vector<Codigo> sprints = armazenamento->listarSprintsDeProjeto(codigoProjeto);
    int somaCapacidade = 0;
    for (const auto &c : sprints) {
        PlanoDeSprint s;
        if (armazenamento->lerPlanoDeSprint(c, s)) {
            somaCapacidade += s.getCapacidade().getTempo();
        }
    }
    
    if (somaCapacidade + plano.getCapacidade().getTempo() > diasTotais) {
        return false; // Violacao da regra
    }
    
    if (armazenamento->criarPlanoDeSprint(plano)) {
        return armazenamento->associarSprintProjeto(plano.getCodigo(), codigoProjeto);
    }
    return false;
}
bool CntrServicoGestao::lerPlanoDeSprint(const Codigo &codigo, PlanoDeSprint &plano) {
    return armazenamento->lerPlanoDeSprint(codigo, plano);
}
bool CntrServicoGestao::atualizarPlanoDeSprint(const PlanoDeSprint &plano) {
    return armazenamento->atualizarPlanoDeSprint(plano);
}
bool CntrServicoGestao::excluirPlanoDeSprint(const Codigo &codigo) {
    return armazenamento->excluirPlanoDeSprint(codigo);
}

// HISTORIA
bool CntrServicoGestao::criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) {
    // A historia deve ter o estado inicial "A FAZER" (ja vem setada ou o sistema pode forcar)
    if (armazenamento->criarHistoriaDeUsuario(historia)) {
        return armazenamento->associarHistoriaProjeto(historia.getCodigo(), codigoProjeto);
    }
    return false;
}
bool CntrServicoGestao::lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) {
    return armazenamento->lerHistoriaDeUsuario(codigo, historia);
}
bool CntrServicoGestao::atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    return armazenamento->atualizarHistoriaDeUsuario(historia);
}
bool CntrServicoGestao::excluirHistoriaDeUsuario(const Codigo &codigo) {
    return armazenamento->excluirHistoriaDeUsuario(codigo);
}

// ASSOCIACOES
bool CntrServicoGestao::associarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    return armazenamento->associarHistoriaPessoa(codigoHistoria, emailPessoa);
}
bool CntrServicoGestao::desassociarHistoriaPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    return armazenamento->desassociarHistoriaPessoa(codigoHistoria, emailPessoa);
}

std::vector<Codigo> CntrServicoGestao::listarProjetosDePessoa(const Email &emailPessoa) {
    return armazenamento->listarProjetosDePessoa(emailPessoa);
}
std::vector<Codigo> CntrServicoGestao::listarTodosProjetos() {
    return armazenamento->listarTodosProjetos();
}
std::vector<Codigo> CntrServicoGestao::listarHistoriasDeProjeto(const Codigo &codigoProjeto) {
    return armazenamento->listarHistoriasDeProjeto(codigoProjeto);
}
std::vector<Codigo> CntrServicoGestao::listarSprintsDeProjeto(const Codigo &codigoProjeto) {
    return armazenamento->listarSprintsDeProjeto(codigoProjeto);
}
std::vector<Codigo> CntrServicoGestao::listarHistoriasDeSprint(const Codigo &codigoSprint) {
    return armazenamento->listarHistoriasDeSprint(codigoSprint);
}
std::vector<Codigo> CntrServicoGestao::listarHistoriasDePessoa(const Email &emailPessoa) {
    return armazenamento->listarHistoriasDePessoa(emailPessoa);
}

bool CntrServicoGestao::moverHistoriaParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,
                               const Codigo &codigoSprint) {
    // Regra: A soma das estimativas das histórias de usuário associadas a um plano de sprint, 
    // deve ser menor ou igual à capacidade do plano de sprint.
    PlanoDeSprint p;
    if (!armazenamento->lerPlanoDeSprint(codigoSprint, p)) return false;
    
    std::vector<Codigo> hists = armazenamento->listarHistoriasDeSprint(codigoSprint);
    int somaEstimativas = 0;
    for (const auto& hc : hists) {
        HistoriaDeUsuario h;
        if (armazenamento->lerHistoriaDeUsuario(hc, h)) {
            somaEstimativas += h.getEstimativa().getTempo();
        }
    }
    
    HistoriaDeUsuario novaH;
    if (!armazenamento->lerHistoriaDeUsuario(codigoHistoria, novaH)) return false;
    
    if (somaEstimativas + novaH.getEstimativa().getTempo() > p.getCapacidade().getTempo()) {
        return false;
    }
    
    return armazenamento->associarHistoriaSprint(codigoHistoria, codigoSprint);
}

bool CntrServicoGestao::alterarEstadoHistoria(const Codigo &codigoHistoria, const Estado &novoEstado) {
    HistoriaDeUsuario h;
    if (armazenamento->lerHistoriaDeUsuario(codigoHistoria, h)) {
        h.setEstado(novoEstado);
        return armazenamento->atualizarHistoriaDeUsuario(h);
    }
    return false;
}
