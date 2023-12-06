#include <iostream>
#include <cmath>

#include "CVelCriticaBinghamiano.h"

/**
@class CVelCriticaBinghamiano
@file CVelCriticaBinghamiano.cpp
*/

using namespace std;

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
double CVelCriticaBinghamiano::Vel_critica_Binghamiano_it_SI() {

	vel_critica_Binghamiano_it_SI = ((1050 / (ppoco->d * ppoco->rho)) * (ppropriedade->visco_plastica + (sqrt((pow(ppropriedade->visco_plastica, 2)) + ((ppropriedade->limite_escoamento * (pow(ppoco->d, 2) * ppoco->rho)) / (4200))))));

	return vel_critica_Binghamiano_it_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
double CVelCriticaBinghamiano::Vel_critica_Binghamiano_it_UC() {

	vel_critica_Binghamiano_it_UC = ((67.91 / (ppoco->d * ppoco->rho)) * (ppropriedade->visco_plastica + (sqrt((pow(ppropriedade->visco_plastica, 2)) + (8.816 * ppropriedade->limite_escoamento * (pow(ppoco->d, 2) * ppoco->rho))))));

	return vel_critica_Binghamiano_it_UC;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
double CVelCriticaBinghamiano::Vel_critica_Binghamiano_ea_SI() {

	vel_critica_Binghamiano_ea_SI = ((1286 / ((ppoco->df - ppoco->di)* ppoco->rho)) * (ppropriedade->visco_plastica + (sqrt((pow(ppropriedade->visco_plastica, 2)) + ((ppropriedade->limite_escoamento * (ppoco->df - ppoco->di) * ppoco->rho)) / (7716)))));

	return vel_critica_Binghamiano_ea_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades de Campo
double CVelCriticaBinghamiano::Vel_critica_Binghamiano_ea_UC() {

	vel_critica_Binghamiano_ea_UC = ((93.17 / ((ppoco->df - ppoco->di)* ppoco->rho)) * (ppropriedade->visco_plastica + (sqrt((pow(ppropriedade->visco_plastica, 2)) + (4.8 * ppropriedade->limite_escoamento * (ppoco->df - ppoco->di) * ppoco->rho)))));

	return vel_critica_Binghamiano_ea_UC;
}
