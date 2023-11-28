#ifndef CSimuladorPerdaCargaCirculacaoFluidos_h
#define CSimuladorPerdaCargaCirculacaoFluidos_h

#include <iostream>

#include "CEquipamento.h"
#include "CExperimentoViscosimetroFan35A.h"
#include "CAmostra.h"
#include "CAmostraFluido.h"
#include "CPoco.h"
#include "CIModeloEscoamentoFluido.h"
#include "CModeloEscoamentoFluidoBinghamiano.h"
#include "CModeloEscoamentoFluidoDePotencia.h"
#include "CGnuplot.h"


class CSimuladorPerdaCargaCirculacaoFluidos {

 private:
	TipoFluido 		tipoFluido;
	TipoUnidade 	tipoUnidade;
	TipoCirculacao 	tipoCirculacao;
	TipoFluxo 		tipoFluxo;

    /// Objeto CAmostraFluido.
    std::shared_ptr<CAmostraFluido> amostraFluido;
    /// Objeto CExperimentoViscosimetroFan35A.
    std::shared_ptr<CExperimentoViscosimetroFan35A> eviscosimetro;
	/// Objeto modelo de escoamento.
	std::shared_ptr<CIModeloEscoamentoFluido> modeloEscoamento;
    /// Objeto CPoco.
    std::shared_ptr<CPoco> poco;

 public:
	CSimuladorPerdaCargaCirculacaoFluidos() = default;
    bool Menu();
 private:
	void Cabecalho(std::ostream& out);
    //  Simulacao reologia
    void CriarAmostraFluido();
    void CriarExperimentoViscosimetro();
    void PrepararSimulacaoReologia();
    void VisualizarDadosSimulacaoReologia();
	bool ExecutarSimulacaoReologia();
    void VisualizarResultadosSimulacaoReologia();

    //  Simulacao fluxo
    void CriarPoco();
    void SelecaoTipoFluido();
    void SelecaoTipoCirculacao();
	void SelecaoTipoUnidade();
    void SelecaoTipoFluxo();
    void CriarModeloEscoamento();
    void PrepararSimulacaoFluxo();
    void VisualizarDadosSimulacaoFluxo();
	bool ExecutarSimulacaoFluxo();
    void VisualizarResultadosSimulacaoFluxo();
};
# endif
