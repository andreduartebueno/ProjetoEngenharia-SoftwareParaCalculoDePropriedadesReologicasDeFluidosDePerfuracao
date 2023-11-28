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
std::string_view linha = "_______________________________________________________________________________________ \n";
#endif

/// Metodo que solicita a entrada de dados do objeto.
void CPoco::EntradaDeDados(std::ostream& out, std::istream& in) {
    out <<  linha
		<<  "Entrada atributos CAmostraFluido:\n"
        << " Entre com os valores das variaveis conforme sequencia:\n"
        << " Caso a variavel nao seja necessaria para o calculo, digitar 0\n"
        << " Entre com o diametro do tubo (d)(unidade: m ou in) : ";
    in >> d; in.get();
    out << " Entre com o diametro externo de tubo (di) interno para anular, unidade: [m ou in]: ";
    in >> di; in.get();
    out << " Entre com o diametro interno de tubo externo (df) para anular, unidade: [m ou in]: ";
    in >> df; in.get();
    out << " Entre com o diametro comprimento (l),  unidade: [m ou ft]: ";
    in >> l; in.get();
    out << " Entre com a velocidade de fluxo (v),  unidade: [m/s ou ft/min]: ";
    in >> v; in.get();
    out << " Entre com a massa especifica ou densidade absoluta do fluido (rho),  unidade: [kg/m^3 ou lbm/gal]: ";
    in >> rho; in.get();
    out << linha;
}

/// Método que mostra dados do objeto.
void CPoco::SaidaDeDados(std::ostream& out) {
    out <<  "Atributos CPoco:"
        <<  "\nDiametro de tubo (d), unidade: [m ou in]: " <<  d
        <<  "\nDiametro externo de tubo interno para anular (di), unidade: [m ou in]: " <<  di
        <<  "\nDiametro interno de tubo externo para anular (df), unidade: [m ou in]: " <<  df
        <<  "\nComprimento (l), unidade: [m ou ft]: " <<  l
        <<  "\nVelocidade de fluxo (v), unidade: [m/s ou ft/min]: " <<  v
        <<  "\nMassa especifica ou densidade absoluta do fluido (rho), unidade: [kg/m^3 ou lbm/gal]: " <<  rho <<  std::endl;
}

/// Método que salva dados do objeto em disco.
void CPoco::SaidaDeDadosDisco(std::ostream& out) {
    out << d << ' ' << di << ' ' << df << ' ' << l << ' ' << v << ' ' << rho << ' ';
}

