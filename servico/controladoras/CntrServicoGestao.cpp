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
bool ehBissexto(int ano) {
    return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));
}

int diasNoMes(int mes, int ano) {
    if (mes == 2) return ehBissexto(ano) ? 29 : 28;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    return 31;
}

int contarDiasAte(int dia, int mes, int ano) {
    int dias = ano * 365 + ano / 4 - ano / 100 + ano / 400;
    for (int m = 1; m < mes; m++) {
        dias += diasNoMes(m, ano);
    }
    dias += dia;
    return dias;
}

int diasEntreDatas(const std::string& d1, const std::string& d2) {
    int dia1 = std::stoi(d1.substr(0, 2));
    int mes1 = std::stoi(d1.substr(3, 2));
    int ano1 = std::stoi(d1.substr(6, 4));
    
    int dia2 = std::stoi(d2.substr(0, 2));
    int mes2 = std::stoi(d2.substr(3, 2));
    int ano2 = std::stoi(d2.substr(6, 4));
    
    int t1 = contarDiasAte(dia1, mes1, ano1);
    int t2 = contarDiasAte(dia2, mes2, ano2);
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
    std::vector<Codigo> projetos = armazenamento->listarTodosProjetos();
    Codigo projCodigo;
    bool found = false;
    for (const auto& pc : projetos) {
        std::vector<Codigo> sprints = armazenamento->listarSprintsDeProjeto(pc);
        for (const auto& sc : sprints) {
            if (sc.getCodigo() == plano.getCodigo().getCodigo()) {
                projCodigo = pc;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        Projeto p;
        if (armazenamento->lerProjeto(projCodigo, p)) {
            int diasTotais = diasEntreDatas(p.getInicio().getData(), p.getTermino().getData());
            std::vector<Codigo> sprints = armazenamento->listarSprintsDeProjeto(projCodigo);
            int somaCapacidade = 0;
            for (const auto &c : sprints) {
                if (c.getCodigo() != plano.getCodigo().getCodigo()) {
                    PlanoDeSprint s;
                    if (armazenamento->lerPlanoDeSprint(c, s)) {
                        somaCapacidade += s.getCapacidade().getTempo();
                    }
                }
            }
            if (somaCapacidade + plano.getCapacidade().getTempo() > diasTotais) {
                return false;
            }
        }
    }
    return armazenamento->atualizarPlanoDeSprint(plano);
}
bool CntrServicoGestao::excluirPlanoDeSprint(const Codigo &codigo) {
    return armazenamento->excluirPlanoDeSprint(codigo);
}

// HISTORIA
bool CntrServicoGestao::criarHistoriaDeUsuario(const HistoriaDeUsuario &historia, const Codigo &codigoProjeto) {
    HistoriaDeUsuario h = historia;
    Estado est; est.setEstado("A FAZER");
    h.setEstado(est);
    if (armazenamento->criarHistoriaDeUsuario(h)) {
        return armazenamento->associarHistoriaProjeto(h.getCodigo(), codigoProjeto);
    }
    return false;
}
bool CntrServicoGestao::lerHistoriaDeUsuario(const Codigo &codigo, HistoriaDeUsuario &historia) {
    return armazenamento->lerHistoriaDeUsuario(codigo, historia);
}
bool CntrServicoGestao::atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    std::vector<Codigo> projetos = armazenamento->listarTodosProjetos();
    Codigo sprintCodigo;
    bool foundSprint = false;
    for (const auto& pc : projetos) {
        std::vector<Codigo> sprints = armazenamento->listarSprintsDeProjeto(pc);
        for (const auto& sc : sprints) {
            std::vector<Codigo> historias = armazenamento->listarHistoriasDeSprint(sc);
            for (const auto& hc : historias) {
                if (hc.getCodigo() == historia.getCodigo().getCodigo()) {
                    sprintCodigo = sc;
                    foundSprint = true;
                    break;
                }
            }
            if (foundSprint) break;
        }
        if (foundSprint) break;
    }

    if (foundSprint) {
        PlanoDeSprint p;
        if (armazenamento->lerPlanoDeSprint(sprintCodigo, p)) {
            std::vector<Codigo> hists = armazenamento->listarHistoriasDeSprint(sprintCodigo);
            int somaEstimativas = 0;
            for (const auto& hc : hists) {
                if (hc.getCodigo() != historia.getCodigo().getCodigo()) {
                    HistoriaDeUsuario h;
                    if (armazenamento->lerHistoriaDeUsuario(hc, h)) {
                        somaEstimativas += h.getEstimativa().getTempo();
                    }
                }
            }
            if (somaEstimativas + historia.getEstimativa().getTempo() > p.getCapacidade().getTempo()) {
                return false;
            }
        }
    }
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
