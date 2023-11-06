#include <iostream>
#include <cmath>

#include "CIndice.h"

/**
@class CIndice
@file CIndice.cpp
*/

using namespace std;

/// Definicao dos metodos set e get

void CIndice::Teta600(double _teta600){teta600=_teta600;}

double CIndice::Teta600() {return teta600;}

void CIndice::Teta300(double _teta300){teta300=_teta300;}

double CIndice::Teta300(){return teta300;}

void CIndice::Teta003(double _teta003){teta003=_teta003;}

double CIndice::Teta003(){return teta003;}


/// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
double CIndice::N_it(const CAmostraFluido& indice) {

    double x = (indice.teta600/indice.teta300);
	n_it = (3.32 * log10(x));

	return n_it;
}

/// Metodo que calcula o Indice de Comportamento para o Espaço Anular
double CIndice::N_ea(const CAmostraFluido& indice) {

    double y = (indice.teta300/indice.teta003);
	n_ea = (0.5 * log10(y));

	return n_ea;
}

/// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
double CIndice::K_it(const CAmostraFluido& indice) {

	k_it = 1.067 * (indice.teta600 / (1022 * n_it));

	return k_it;
}

/// Metodo que calcula o Indice de Consistencia o Espaço Anular
double CIndice::K_ea(const CAmostraFluido& indice) {

	k_ea = 1.067 * (indice.teta300 / (511 * n_ea));

	return k_ea;

}
