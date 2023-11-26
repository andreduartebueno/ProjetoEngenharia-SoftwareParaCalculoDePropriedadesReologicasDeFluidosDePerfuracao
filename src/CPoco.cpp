#include <iostream>
#include <string_view>

#include "CPoco.h"

/**
@class CPoco
@file CPoco.h
*/

using  namespace std;

#ifndef linha_
#define linha_
std::string_view linha = "\n_______________________________________________________________________________________ \n";
#endif

/// Metodo que solicita a entrada de dados do objeto.
void CPoco::EntradaDeDados(std::ostream& out, std::istream& in) {
    out << "Entre com os valores das variaveis conforme sequencia:\n";
    out << "Caso a variavel nao seja necessaria para o calculo, digitar 0 \n" << linha;
    out << "1 - [d] Diametro de tubo (unidade: m ou in): \n";
    in >> d; in.get();
    out << "\n2 - [di] Diametro externo de tubo interno para anular (unidade: m ou in): \n";
    in >> di; in.get();
    out << "\n3 - [de] Diametro interno de tubo externo para anular (unidade: m ou in): \n";
    in >> df; in.get();
    out << "\n4 - [l] Comprimento (unidade: m ou ft): \n";
    in >> l; in.get();
    out << "\n5 - [v] Velocidade de fluxo (unidade: m/s ou ft/min): \n";
    in >> v; in.get();
    out << "\n6 - [rho] Massa especifica ou densidade absoluta do fluido (unidade: kg/m^3 ou lbm/gal): \n";
    in >> rho; in.get();
    out << linha;
}

/// Método que mostra dados do objeto.
void CPoco::SaidaDeDados(std::ostream& out) {
    out <<  "\nDiametro de tubo (unidade: m ou in): " <<  d;
    out <<  "\nDiametro externo de tubo interno para anular (unidade: m ou in): " <<  di;
    out <<  "\nDiametro interno de tubo externo para anular (unidade: m ou in): " <<  df;
    out <<  "\nComprimento (unidade: m ou ft): " <<  l;
    out <<  "\nVelocidade de fluxo (unidade: m/s ou ft/min): " <<  v;
    out <<  "\nMassa especifica ou densidade absoluta do fluido (unidade: kg/m^3 ou lbm/gal): " <<  rho;
}

/// Método que salva dados do objeto em disco.
void CPoco::SaidaDeDadosDisco(std::ostream& out) {
    out << d << ' ' << di << ' ' << df << ' ' << l << ' ' << v << ' ' << rho << ' ';
}

