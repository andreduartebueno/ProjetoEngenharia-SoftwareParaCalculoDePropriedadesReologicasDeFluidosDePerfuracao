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
    std::shared_ptr<CAmostraFluido> amostra;
    /// Objeto CExperimentoViscosimetroFan35A.
    std::shared_ptr<CExperimentoViscosimetroFan35A> eviscosimetro;
	/// Objeto modelo de escoamento.
	std::shared_ptr<CIModeloEscoamentoFluido> modeloEscoamento;
    /// Objeto CPoco.
    std::shared_ptr<CPoco> poco;

 public:
	CSimuladorPerdaCargaCirculacaoFluidos() = default;
	void Cabecalho(std::ostream& out);
    void CriarAmostra();
    void CriarExperimentoViscosimetro();
    void CriarPoco();
    void SelecaoTipoFluido();
    void CriarModeloEscoamento();
    void SelecaoTipoCirculacao();
	void SelecaoTipoUnidade();
    void SelecaoTipoFluxo();
    void PrepararSimulacao();
    void VisualizarDadosSimulacao();
	bool ExecutarSimulacao();

	bool Menu();
	//  Tarefa get/set,  operadores,  E/S
};
# endif
