#include <iostream>
#include <cmath>
#include "CVelCritica.h"

/**
@class CVelCritica
@file CVelCritica.cpp
 */

using namespace std;

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
double Vel_critica_Bighamiano_it_SI(CPropiedadesReologicas& propriedade) {

	vel_critica_Bighamiano_it_SI = ((1050 / (D * ro)) * (propriedade.visco_plastica + (sqrt((pow(propriedade.visco_plastica, 2)) + ((propriedade.limite_escoamento * (pow(D, 2) * ro)) / (4200)), 2))));

	return vel_critica_Bighamiano_it_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
double Vel_critica_Bighamiano_it_UC(CPropiedadesReologicas& propriedade) {

	vel_critica_Bighamiano_it_UC = ((67.91 / (D * ro)) * (propriedade.visco_plastica + (sqrt((pow(propriedade.visco_plastica, 2)) + (8.816 * propriedade.limite_escoamento * (pow(D, 2) * ro))), 2)));

	return vel_critica_Bighamiano_it_UC;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
double Vel_critica_Bighamiano_ea_SI(CPropiedadesReologicas& propriedade) {

	vel_critica_Bighamiano_ea_SI = ((1286 / ((Do-Di)* ro)) * (propriedade.visco_plastica + (sqrt((pow(propriedade.visco_plastica, 2)) + ((propriedade.limite_escoamento * (Do-Di) * ro)) / (7716)), 2)));

	return vel_critica_Bighamiano_ea_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades de Campo
double Vel_critica_Bighamiano_ea_UC(CPropiedadesReologicas& propriedade) {

	vel_critica_Bighamiano_ea_UC = ((93.17 / ((Do-Di)* ro)) * (propriedade.visco_plastica + (sqrt((pow(propriedade.visco_plastica, 2)) + (4.8 * propriedade.limite_escoamento * (Do-Di) * ro)), 2)));

	return vel_critica_Bighamiano_ea_UC;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
double Vel_critica_Potencia_it_SI(CIndice& indice) {

	vel_critica_Potencia_it_SI = ((pow(((3470 - 1370 * indice.n_it) * indice.k_it) / (8 * ro)), (1 / (2 - indice.n_it))) * (pow((((6 * indice.n_it) + 2) / (D * indice.n_it)), (indice.n_it / (2 - indice.n_it)))));

	return vel_critica_Potencia_it_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
double Vel_critica_Potencia_it_UC(CIndice& indice) {

	vel_critica_Potencia_it_UC = (1.969 * (pow((5 * (3470 - 1370 * indice.n_it) * indice.k_it) / (ro)), (1 / (2 - indice.n_it))) * (pow((((3 * indice.n_it) + 1) / (1.27 * D * indice.n_it)), (indice.n_it / (2 - indice.n_it)))));

	return vel_critica_Potencia_it_UC;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
double Vel_critica_Potencia_ea_SI(CIndice& indice) {

	vel_critica_Potencia_ea_SI = ((pow(((3470 - 1370 * indice.n_it) * indice.k_it) / (9.788 * ro)), (1 / (2 - indice.n_it))) * (pow((((8 * indice.n_it) + 4) / ((Do-Di)* indice.n_it)), (indice.n_it / (2 - indice.n_it)))));

	return vel_critica_Potencia_ea_SI;
}

/// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
double Vel_critica_Potencia_ea_UC(CIndice& indice) {

	vel_critica_Potencia_ea_UC = (1.969 * (pow((4.08 * (3470 - 1370 * indice.n_it) * indice.k_it) / (ro)), (1 / (2 - indice.n_it))) * (pow((((2 * indice.n_it) + 1) / (0.64 * (Do-Di) * indice.n_it)), (indice.n_it / (2 - indice.n_it)))));

	return vel_critica_Potencia_ea_UC;
}