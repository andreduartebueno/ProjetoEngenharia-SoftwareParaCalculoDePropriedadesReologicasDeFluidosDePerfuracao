#include <iostream>
#include <cmath>

#include "CPerdaCargaPotencia.h"

/**
@class CPerdaCargaPotencia
@file CPerdaCargaPotencia.cpp
*/

using namespace std;

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades SI
double CPerdaCargaPotencia::Perda_carga_Potencia_fl_it_SI() {

    perda_carga_Potencia_fl_it_SI = (((4 * pindice->k_it * ppoco->l) / (ppoco->d)) * pow(((ppoco->v / ppoco->d) * (((6 * pindice->n_it) + 2) / pindice->n_it)), pindice->n_it));

    return perda_carga_Potencia_fl_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades de Campo
double CPerdaCargaPotencia::Perda_carga_Potencia_fl_it_UC() {

    perda_carga_Potencia_fl_it_UC = (((pindice->k_it * ppoco->l) / (300 * ppoco->d)) * pow((((0.4 * ppoco->v) / ppoco->d) * (((3 * pindice->n_it) + 1) / pindice->n_it)), pindice->n_it));

    return perda_carga_Potencia_fl_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades SI
double CPerdaCargaPotencia::Perda_carga_Potencia_fl_ea_SI() {

    perda_carga_Potencia_fl_ea_SI = (((4 * pindice->k_ea * ppoco->l) / (ppoco->df - ppoco->di)) * pow(((ppoco->v / (ppoco->df - ppoco->di)) * ((pindice->n_ea + 4) / pindice->n_ea)), pindice->n_ea));

    return perda_carga_Potencia_fl_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades de Campo
double CPerdaCargaPotencia::Perda_carga_Potencia_fl_ea_UC() {

    perda_carga_Potencia_fl_ea_UC = (((pindice->k_ea * ppoco->l) / (300 * (ppoco->df - ppoco->di))) * pow((((0.8 * ppoco->v) / (ppoco->df - ppoco->di)) * (((2 * pindice->n_ea) + 1) / pindice->n_ea)), pindice->n_ea));

    return perda_carga_Potencia_fl_ea_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades SI
double CPerdaCargaPotencia::Perda_carga_Potencia_ft_it_SI() {

    perda_carga_Potencia_ft_it_SI = ((((log10(pindice->n_it) + 2.5) * ppoco->rho * pow(ppoco->v, 2) * ppoco->l) / (25 * ppoco->d)) * pow(((pindice->k_it * ((ppoco->v / ppoco->d) * (((6 * pindice->n_it) + 2) / pindice->n_it))) / (8 * ppoco->rho * pow(ppoco->v , 2))), ((1.4 - log10(pindice->n_it)) / 7)));

    return perda_carga_Potencia_ft_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CPerdaCargaPotencia::Perda_carga_Potencia_ft_it_UC() {

    perda_carga_Potencia_ft_it_UC = ((((log10(pindice->n_it) + 2.5) * ppoco->rho * pow(ppoco->v, 2) * ppoco->l) / (4645029 * ppoco->d)) * pow((((19.36 * pindice->k_it) * (((0.4 * ppoco->v) / ppoco->d) * (((3 * pindice->n_it) + 1) / pindice->n_it))) / (ppoco->rho * pow(ppoco->v , 2))), ((1.4 - log10(pindice->n_it)) / 7)));

    return perda_carga_Potencia_ft_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades SI
double CPerdaCargaPotencia::Perda_carga_Potencia_ft_ea_SI() {

    perda_carga_Potencia_ft_ea_SI = ((((log10(pindice->n_ea) + 2.5) * ppoco->rho * pow(ppoco->v, 2) * ppoco->l) / (20.4125 * (ppoco->df - ppoco->di))) * pow((pindice->k_ea * pow(((ppoco->v / (ppoco->df - ppoco->di)) * (((8 * pindice->n_ea) + 4) / pindice->n_ea)), pindice->n_ea) / (9.798 * ppoco->rho * pow(ppoco->v , 2))), ((1.4 - log10(pindice->n_ea)) / 7)));



    return perda_carga_Potencia_ft_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades de Campo
double CPerdaCargaPotencia::Perda_carga_Potencia_ft_ea_UC() {

    perda_carga_Potencia_ft_ea_UC = ((((log10(pindice->n_ea) + 2.5) * ppoco->rho * pow(ppoco->v, 2) * ppoco->l) / (3792669 * (ppoco->df - ppoco->di))) * pow(((15.81 * pindice->k_ea) * pow((((0.8 * ppoco->v) / (ppoco->df - ppoco->di)) * (((2 * pindice->n_ea) + 1) / pindice->n_ea)), pindice->n_ea) / (ppoco->rho * pow(ppoco->v , 2))), ((1.4 - log10(pindice->n_ea)) / 7)));

    return perda_carga_Potencia_ft_ea_UC;
}
