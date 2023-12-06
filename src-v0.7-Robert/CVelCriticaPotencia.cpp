#include <iostream>
#include <cmath>

#include "CVelCriticaPotencia.h"

/**
@class CVelCriticaPotencia
@file CVelCriticaPotencia.cpp
*/

using namespace std;

/// Metodo para o calculo da Velocidade Critica para Fluidos de Potencia, no interior de tubos e unidades no Sistema Internacional
double CVelCriticaPotencia::Vel_critica_Potencia_it_SI() {

	vel_critica_Potencia_it_SI = (pow((((3470 - 1370 * pindice->n_it) * pindice->k_it) / (8 * ppoco->rho)), (1 / (2 - pindice->n_it))) * pow((((6 * pindice->n_it) + 2) / (ppoco->d * pindice->n_it)), (pindice->n_it / (2 - pindice->n_it))));

	return vel_critica_Potencia_it_SI;
}

/// Metodo para o calculo da Velocidade Critica para Fluidos de Potencia, no interior de tubos e unidades de Campo
double CVelCriticaPotencia::Vel_critica_Potencia_it_UC() {

	vel_critica_Potencia_it_UC = (1.969 * pow(((5 * (3470 - 1370 * pindice->n_it) * pindice->k_it) / (ppoco->rho)), (1 / (2 - pindice->n_it))) * pow((((3 * pindice->n_it) + 1) / (1.27 * ppoco->d * pindice->n_it)), (pindice->n_it / (2 - pindice->n_it))));

	return vel_critica_Potencia_it_UC;
}

/// Metodo para o calculo da Velocidade Critica para Fluidos de Potencia, no espaço anular e unidades no Sistema Internacional
double CVelCriticaPotencia::Vel_critica_Potencia_ea_SI() {

	vel_critica_Potencia_ea_SI = (pow((((3470 - 1370 * pindice->n_ea) * pindice->k_ea) / (9.788 * ppoco->rho)), (1 / (2 - pindice->n_ea))) * pow((((8 * pindice->n_ea) + 4) / ((ppoco->df - ppoco->di)* pindice->n_ea)), (pindice->n_ea / (2 - pindice->n_ea))));

	return vel_critica_Potencia_ea_SI;
}

/// Metodo para o calculo da Velocidade Critica para Fluidos de Potencia, no espaço anular e unidades de Campo
double CVelCriticaPotencia::Vel_critica_Potencia_ea_UC() {

	vel_critica_Potencia_ea_UC = (1.969 * pow(((4.08 * (3470 - 1370 * pindice->n_ea) * pindice->k_ea) / (ppoco->rho)), (1 / (2 - pindice->n_ea))) * pow((((2 * pindice->n_ea) + 1) / (0.64 * (ppoco->df - ppoco->di) * pindice->n_ea)), (pindice->n_ea / (2 - pindice->n_ea))));

	return vel_critica_Potencia_ea_UC;
}
