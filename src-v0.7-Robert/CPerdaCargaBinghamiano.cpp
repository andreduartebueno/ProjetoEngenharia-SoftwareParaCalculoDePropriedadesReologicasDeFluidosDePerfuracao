#include <iostream>
#include <cmath>

#include "CPerdaCargaBinghamiano.h"

/**
@class CPerdaCargaBinghamiano
@file CPerdaCargaBinghamiano.cpp
*/

using namespace std;


/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades SI
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_fl_it_SI() {

    perda_carga_Binghamiano_fl_it_SI = (((32 * ppropriedade->visco_plastica * ppoco->l * ppoco->v) / (pow(ppoco->d, 2))) + ((4 * ppropriedade->limite_escoamento * ppoco->l) / (ppoco->d)));

    return perda_carga_Binghamiano_fl_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades de Campo
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_fl_it_UC() {

    perda_carga_Binghamiano_fl_it_UC = (((ppropriedade->visco_plastica * ppoco->l * ppoco->v) / (89775 * (pow(ppoco->d, 2)))) + ((ppropriedade->limite_escoamento * ppoco->l) / (300 * ppoco->d)));

    return perda_carga_Binghamiano_fl_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades SI
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_fl_ea_SI() {

    perda_carga_Binghamiano_fl_ea_SI = (((48 * ppropriedade->visco_plastica * ppoco->l * ppoco->v) / (pow((ppoco->df - ppoco->di), 2))) + ((4 * ppropriedade->limite_escoamento * ppoco->l) / (ppoco->df - ppoco->di)));

    return perda_carga_Binghamiano_fl_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades de Campo
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_fl_ea_UC() {

    perda_carga_Binghamiano_fl_ea_UC = (((ppropriedade->visco_plastica * ppoco->l * ppoco->v) / (59851 * (pow((ppoco->df - ppoco->di), 2)))) + ((ppropriedade->limite_escoamento * ppoco->l) / 300 * (ppoco->df - ppoco->di)));

    return perda_carga_Binghamiano_fl_ea_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades SI
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_ft_it_SI() {

    perda_carga_Binghamiano_ft_it_SI = ((0.1 * ppoco->l * pow(ppoco->rho, 0.8) * pow(ppoco->v, 1.8) * pow(ppropriedade->visco_plastica, 0.2)) / pow(ppoco->d, 1.2));

    return perda_carga_Binghamiano_ft_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_ft_it_UC() {

    perda_carga_Binghamiano_ft_it_UC = ((ppoco->l * pow(ppoco->rho, 0.8) * pow(ppoco->v, 1.8) * pow(ppropriedade->visco_plastica, 0.2)) / (3212923 * pow(ppoco->d, 1.2)));

    return perda_carga_Binghamiano_ft_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades SI
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_ft_ea_SI() {

    perda_carga_Binghamiano_ft_ea_SI = ((0.1275 * ppoco->l * pow(ppoco->rho, 0.8) * pow(ppoco->v, 1.8) * pow(ppropriedade->visco_plastica, 0.2)) / pow((ppoco->df - ppoco->di), 1.2));

    return perda_carga_Binghamiano_ft_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades de Campo
double CPerdaCargaBinghamiano::Perda_carga_Binghamiano_ft_ea_UC() {

    perda_carga_Binghamiano_ft_ea_UC = ((ppoco->l * pow(ppoco->rho, 0.8) * pow(ppoco->v, 1.8) * pow(ppropriedade->visco_plastica, 0.2)) / (2519939 * pow((ppoco->df - ppoco->di), 1.2)));

    return perda_carga_Binghamiano_ft_ea_UC;
}
