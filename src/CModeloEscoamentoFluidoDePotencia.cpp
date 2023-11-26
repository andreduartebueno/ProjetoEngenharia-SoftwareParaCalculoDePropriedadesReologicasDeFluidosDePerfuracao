#include <iostream>
#include <cmath>

#include <string_view>

#include "CModeloEscoamentoFluidoDePotencia.h"
static std::string_view linha = "\n_______________________________________________________________________________________ \n";

using namespace std;

/// Realiza procedimento de pré-processamento,  calculando variaveis necessárias.
void CModeloEscoamentoFluidoDePotencia::PreProcessamento(){
    do {
        cout << linha << "Propriedades para Fluidos de Potencia:\n" << linha;

        /// Circulacao pelo Interior de Tubos
        if (tipoCirculacao == TipoCirculacao::InteriorDeTubos) {
        cout << linha;
        N_it();
        cout << "Indice de Comportamento para o Interior de Tubos: "  << n_it  <<  "  adimensional\n" ;
        K_it();
        cout << "Indice de Consistencia para o Interior de Tubos:  "  << k_it  <<  "  lbf.s^n/100 ft^2\n";
        cout << linha;

        /// Circulacao pelo Espaco Anular
        } else if (tipoCirculacao == TipoCirculacao::EspacoAnular){
        cout << linha;
        N_ea();
        cout << "Indice de Comportamento para o Espaco Anular:     "  << n_ea  <<  " adimensional\n";
        K_ea();
        cout << "Indice de Consistencia para o Espaco Anular:      "  << k_ea  <<  " lbf.s^n/100 ft^2\n";
        cout << linha;
        }

        /// Mensagem de erro se a selecao for errada
        if ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao != TipoCirculacao::EspacoAnular)){cout << linha << "Opcao Invalida\n" ;}

    } while ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao != TipoCirculacao::EspacoAnular));

}

/// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
double CModeloEscoamentoFluidoDePotencia::N_it() {
    double x = (eviscosimetro->Teta600()/eviscosimetro->Teta300());
	n_it = (3.32 * log10(x));
	return n_it;
}

/// Metodo que calcula o Indice de Comportamento para o Espaço Anular
double CModeloEscoamentoFluidoDePotencia::N_ea() {
    double y = (eviscosimetro->Teta300()/eviscosimetro->Teta003());
	n_ea = (0.5 * log10(y));
	return n_ea;
}

/// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
double CModeloEscoamentoFluidoDePotencia::K_it() {
	k_it = 1.067 * (eviscosimetro->Teta600() / (1022 * n_it));
	return k_it;
}

/// Metodo que calcula o Indice de Consistencia o Espaço Anular
double CModeloEscoamentoFluidoDePotencia::K_ea() {
	k_ea = 1.067 * (eviscosimetro->Teta300() / (511 * n_ea));
	return k_ea;

}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades SI
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_fl_it_SI() {
    perdaDeCargaInterior = (((4 * k_it * poco->l) / (poco->d)) * pow(((poco->v / poco->d) * (((6 * n_it) + 2) / n_it)), n_it));
    return perdaDeCargaInterior;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades de Campo
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_fl_it_UC() {
    perdaDeCargaInterior = (((k_it * poco->l) / (300 * poco->d)) * pow((((0.4 * poco->v) / poco->d) * (((3 * n_it) + 1) / n_it)), n_it));
    return perdaDeCargaInterior;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades SI
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_fl_ea_SI() {
    perdaDeCargaAnular = (((4 * k_ea * poco->l) / (poco->df - poco->di)) * pow(((poco->v / (poco->df - poco->di)) * ((n_ea + 4) / n_ea)), n_ea));
    return perdaDeCargaAnular;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades de Campo
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_fl_ea_UC() {
    perdaDeCargaAnular = (((k_ea * poco->l) / (300 * (poco->df - poco->di))) * pow((((0.8 * poco->v) / (poco->df - poco->di)) * (((2 * n_ea) + 1) / n_ea)), n_ea));
    return perdaDeCargaAnular;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades SI
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_ft_it_SI() {
    perdaDeCargaInterior = ((((log10(n_it) + 2.5) * poco->rho * pow(poco->v, 2) * poco->l) / (25 * poco->d)) * pow(((k_it * ((poco->v / poco->d) * (((6 * n_it) + 2) / n_it))) / (8 * poco->rho * pow(poco->v , 2))), ((1.4 - log10(n_it)) / 7)));
    return perdaDeCargaInterior;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_ft_it_UC() {
    perdaDeCargaInterior = ((((log10(n_it) + 2.5) * poco->rho * pow(poco->v, 2) * poco->l) / (4645029 * poco->d)) * pow((((19.36 * k_it) * (((0.4 * poco->v) / poco->d) * (((3 * n_it) + 1) / n_it))) / (poco->rho * pow(poco->v , 2))), ((1.4 - log10(n_it)) / 7)));
    return perdaDeCargaInterior;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades SI
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_ft_ea_SI() {
    perdaDeCargaAnular = ((((log10(n_ea) + 2.5) * poco->rho * pow(poco->v, 2) * poco->l) / (20.4125 * (poco->df - poco->di))) * pow((k_ea * pow(((poco->v / (poco->df - poco->di)) * (((8 * n_ea) + 4) / n_ea)), n_ea) / (9.798 * poco->rho * pow(poco->v , 2))), ((1.4 - log10(n_ea)) / 7)));
    return perdaDeCargaAnular;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades de Campo
double CModeloEscoamentoFluidoDePotencia::PerdaDeCarga_ft_ea_UC() {
    perdaDeCargaAnular = ((((log10(n_ea) + 2.5) * poco->rho * pow(poco->v, 2) * poco->l) / (3792669 * (poco->df - poco->di))) * pow(((15.81 * k_ea) * pow((((0.8 * poco->v) / (poco->df - poco->di)) * (((2 * n_ea) + 1) / n_ea)), n_ea) / (poco->rho * pow(poco->v , 2))), ((1.4 - log10(n_ea)) / 7)));
    return perdaDeCargaAnular;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
double CModeloEscoamentoFluidoDePotencia::VelocidadeCritica_it_SI() {
	velocidadeCriticaInterior = (pow((((3470 - 1370 * n_it) * k_it) / (8 * poco->rho)), (1 / (2 - n_it))) * pow((((6 * n_it) + 2) / (poco->d * n_it)), (n_it / (2 - n_it))));
	return velocidadeCriticaInterior;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
double CModeloEscoamentoFluidoDePotencia::VelocidadeCritica_it_UC() {
	velocidadeCriticaInterior = (1.969 * pow(((5 * (3470 - 1370 * n_it) * k_it) / (poco->rho)), (1 / (2 - n_it))) * pow((((3 * n_it) + 1) / (1.27 * poco->d * n_it)), (n_it / (2 - n_it))));
	return velocidadeCriticaInterior;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
double CModeloEscoamentoFluidoDePotencia::VelocidadeCritica_ea_SI() {
	velocidadeCriticaAnular = (pow((((3470 - 1370 * n_ea) * k_ea) / (9.788 * poco->rho)), (1 / (2 - n_ea))) * pow((((8 * n_ea) + 4) / ((poco->df - poco->di)* n_ea)), (n_ea / (2 - n_ea))));
	return velocidadeCriticaAnular;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
double CModeloEscoamentoFluidoDePotencia::VelocidadeCritica_ea_UC() {
	velocidadeCriticaAnular = (1.969 * pow(((4.08 * (3470 - 1370 * n_ea) * k_ea) / (poco->rho)), (1 / (2 - n_ea))) * pow((((2 * n_ea) + 1) / (0.64 * (poco->df - poco->di) * n_ea)), (n_ea / (2 - n_ea))));
	return velocidadeCriticaAnular;
}
