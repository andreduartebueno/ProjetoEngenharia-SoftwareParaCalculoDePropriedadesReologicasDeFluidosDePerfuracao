#include <iostream>
#include "CPropriedadesReologicas.h"

/**
@class CPropriedadesReologicas
@file CPropriedadesReologicas.cpp
 */

using namespace std;

/// Metodo que calcula a viscosidade aparente
double CPropriedadesReologicas::Visco_aparente() {

    visco_aparente = l600 / 2.0;

    return visco_aparente;
}
    
/// Metodo que calcula a viscosidade plastica
double CPropriedadesReologicas::Visco_plastica() {

    visco_plastica = l600 / l300;

    return visco_plastica;
 }

/// Metodo que calcula o limite de escoamento
double CPropriedadesReologicas::Limite_escoamento() {

    limite_escoamento = l300 - visco_plastica;

    return visco_aparente;
}