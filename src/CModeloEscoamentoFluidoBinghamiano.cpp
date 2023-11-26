#include <iostream>
#include <cmath>
#include <string_view>

#include "CModeloEscoamentoFluidoBinghamiano.h"

static std::string_view linha = "\n_______________________________________________________________________________________ \n";

using namespace std;

/// Realiza procedimento de pré-processamento,  calculando variaveis necessárias.
void CModeloEscoamentoFluidoBinghamiano::PreProcessamento(){
    cout << linha <<  "Propriedades para Fluidos Binghamianos:\n" << linha;
    ViscosidadeAparente();
    cout << "Viscosidade aparente: "  << viscosidadeAparente    << " cP\n";
    ViscosidadePlastica();
    cout << "Viscosidade plastica: "  << viscosidadePlastica    << " cP\n";
    LimiteEscoamento();
    cout << "Limite de escoamento: "  << limiteEscoamento << " lbf/100 ft^2\n" << linha;
}

/// Metodo que calcula a viscosidade aparente
double CModeloEscoamentoFluidoBinghamiano::ViscosidadeAparente() {
    viscosidadeAparente = (eviscosimetro->Teta600() / 2.0);
    return viscosidadeAparente;
}

/// Metodo que calcula a viscosidade plastica
double CModeloEscoamentoFluidoBinghamiano::ViscosidadePlastica() {
    viscosidadePlastica = (eviscosimetro->Teta600() - eviscosimetro->Teta300());
    return viscosidadePlastica;
 }

/// Metodo que calcula o limite de escoamento
double CModeloEscoamentoFluidoBinghamiano::LimiteEscoamento() {
    limiteEscoamento = (eviscosimetro->Teta300() - viscosidadePlastica);
    return limiteEscoamento;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades SI
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_fl_it_SI() {
    perdaDeCargaInterior = (((32 * viscosidadePlastica * poco->l * poco->v) / (pow(poco->d, 2))) + ((4 * limiteEscoamento * poco->l) / (poco->d)));
    return perdaDeCargaInterior;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_fl_it_UC() {
    perdaDeCargaInterior = (((viscosidadePlastica * poco->l * poco->v) / (89775 * (pow(poco->d, 2)))) + ((limiteEscoamento * poco->l) / (300 * poco->d)));
    return perdaDeCargaInterior;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades SI
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_fl_ea_SI() {
    perdaDeCargaAnular = (((48 * viscosidadePlastica * poco->l * poco->v) / (pow((poco->df - poco->di), 2))) + ((4 * limiteEscoamento * poco->l) / (poco->df - poco->di)));
    return perdaDeCargaAnular;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_fl_ea_UC() {
    perdaDeCargaAnular = (((viscosidadePlastica * poco->l * poco->v) / (59851 * (pow((poco->df - poco->di), 2)))) + ((limiteEscoamento * poco->l) / 300 * (poco->df - poco->di)));
    return perdaDeCargaAnular;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades SI
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_ft_it_SI() {
    perdaDeCargaInterior = ((0.1 * poco->l * pow(poco->rho, 0.8) * pow(poco->v, 1.8) * pow(viscosidadePlastica, 0.2)) / pow(poco->d, 1.2));
    return perdaDeCargaInterior;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_ft_it_UC() {
    perdaDeCargaInterior = ((poco->l * pow(poco->rho, 0.8) * pow(poco->v, 1.8) * pow(viscosidadePlastica, 0.2)) / (3212923 * pow(poco->d, 1.2)));
    return perdaDeCargaInterior;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades SI
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_ft_ea_SI() {
    perdaDeCargaAnular = ((0.1275 * poco->l * pow(poco->rho, 0.8) * pow(poco->v, 1.8) * pow(viscosidadePlastica, 0.2)) / pow((poco->df - poco->di), 1.2));
    return perdaDeCargaAnular;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::PerdaDeCarga_ft_ea_UC() {
    perdaDeCargaAnular = ((poco->l * pow(poco->rho, 0.8) * pow(poco->v, 1.8) * pow(viscosidadePlastica, 0.2)) / (2519939 * pow((poco->df - poco->di), 1.2)));
    return perdaDeCargaAnular;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
double CModeloEscoamentoFluidoBinghamiano::VelocidadeCritica_it_SI() {
	velocidadeCriticaInterior = ((1050 / (poco->d * poco->rho)) * (viscosidadePlastica + (sqrt((pow(viscosidadePlastica, 2)) + ((limiteEscoamento * (pow(poco->d, 2) * poco->rho)) / (4200))))));
	return velocidadeCriticaInterior;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::VelocidadeCritica_it_UC() {
	velocidadeCriticaInterior = ((67.91 / (poco->d * poco->rho)) * (viscosidadePlastica + (sqrt((pow(viscosidadePlastica, 2)) + (8.816 * limiteEscoamento * (pow(poco->d, 2) * poco->rho))))));
	return velocidadeCriticaInterior;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
double CModeloEscoamentoFluidoBinghamiano::VelocidadeCritica_ea_SI() {
	velocidadeCriticaAnular = ((1286 / ((poco->df - poco->di)* poco->rho)) * (viscosidadePlastica + (sqrt((pow(viscosidadePlastica, 2)) + ((limiteEscoamento * (poco->df - poco->di) * poco->rho)) / (7716)))));
	return velocidadeCriticaAnular;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades de Campo
double CModeloEscoamentoFluidoBinghamiano::VelocidadeCritica_ea_UC() {
	velocidadeCriticaAnular = ((93.17 / ((poco->df - poco->di)* poco->rho)) * (viscosidadePlastica + (sqrt((pow(viscosidadePlastica, 2)) + (4.8 * limiteEscoamento * (poco->df - poco->di) * poco->rho)))));
	return velocidadeCriticaAnular;
}
