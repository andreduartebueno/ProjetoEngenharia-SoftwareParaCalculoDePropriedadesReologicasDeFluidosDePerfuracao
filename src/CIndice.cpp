#include <iostream>
#include "CIndice.h"

/**
@class CIndice
@file CIndice.cpp
 */

using namespace std;

/// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
int CIndice::N_it() {

	n_it = 3.32 * log(l600 / l300);

	return n_it;
}

/// Metodo que calcula o Indice de Comportamento para o Espaço Anular
int CIndice::N_ea() {

	n_ea = 0.5 * log(l300 / l003);

	return n_ea;
}

/// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
int CIndice::K_it() {

	K_it = 1.067 * (l600 / (1022 * n_it));

	return K_it;
}

/// Metodo que calcula o Indice de Consistencia o Espaço Anular
int CIndice::K_ea() {

	K_ea = 1.067 * (l300 / (511 * n_ea));

	return K_ea;
}