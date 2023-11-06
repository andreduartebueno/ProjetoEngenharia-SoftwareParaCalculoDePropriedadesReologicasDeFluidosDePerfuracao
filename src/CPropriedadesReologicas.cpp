#include <iostream>

#include "CPropriedadesReologicas.h"

/**
@class CPropriedadesReologicas
@file CPropriedadesReologicas.cpp
*/

using namespace std;

/// Definicao dos metodos set e get

void CPropriedadesReologicas::Teta600(double _teta600){teta600=_teta600;}

double CPropriedadesReologicas::Teta600() {return teta600;}

void CPropriedadesReologicas::Teta300(double _teta300){teta300=_teta300;}

double CPropriedadesReologicas::Teta300(){return teta300;}


/// Metodo que calcula a viscosidade aparente
double CPropriedadesReologicas::Visco_aparente(const CAmostraFluido& amostra) {

    visco_aparente = (amostra.teta600 / 2.0);

    return visco_aparente;
}

/// Metodo que calcula a viscosidade plastica
double CPropriedadesReologicas::Visco_plastica(const CAmostraFluido& amostra) {

    visco_plastica = (amostra.teta600 - amostra.teta300);

    return visco_plastica;
 }

/// Metodo que calcula o limite de escoamento
double CPropriedadesReologicas::Limite_escoamento(const CAmostraFluido& amostra) {

    limite_escoamento = (amostra.teta300 - visco_plastica);

    return limite_escoamento;
}
