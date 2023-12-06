#include <iostream>

#include "CFluidoBinghamiano.h"

/**
@class CFluidoBinghamiano
@file CFluidoBinghamiano.cpp
*/

using namespace std;

/// Definicao dos metodos set e get

void CFluidoBinghamiano::Teta600(double _teta600){teta600=_teta600;}

double CFluidoBinghamiano::Teta600() {return teta600;}

void CFluidoBinghamiano::Teta300(double _teta300){teta300=_teta300;}

double CFluidoBinghamiano::Teta300(){return teta300;}


/// Metodo que calcula a viscosidade aparente
double CFluidoBinghamiano::Visco_aparente(const CAmostraFluido& amostra) {

    visco_aparente = (amostra.teta600 / 2.0);

    return visco_aparente;
}

/// Metodo que calcula a viscosidade plastica
double CFluidoBinghamiano::Visco_plastica(const CAmostraFluido& amostra) {

    visco_plastica = (amostra.teta600 - amostra.teta300);

    return visco_plastica;
 }

/// Metodo que calcula o limite de escoamento
double CFluidoBinghamiano::Limite_escoamento(const CAmostraFluido& amostra) {

    limite_escoamento = (amostra.teta300 - visco_plastica);

    return limite_escoamento;
}
