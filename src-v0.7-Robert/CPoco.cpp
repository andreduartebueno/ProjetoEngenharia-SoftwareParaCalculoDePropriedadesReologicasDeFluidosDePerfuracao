#include <iostream>

#include "CPoco.h"

/**
@class CPoco
@file CPoco.cpp
*/

using  namespace std;

/// Definicao dos metodos set e get

void CPoco::D(double _d){d=_d;}

double CPoco::D() {return d;}

void CPoco::Di(double _di){di=_di;}

double CPoco::Di(){return di;}

void CPoco::Df(double _df){df=_df;}

double CPoco::Df(){return df;}

void CPoco::L(double _l){l=_l;}

double CPoco::L(){return l;}

void CPoco::V(double _v){v=_v;}

double CPoco::V(){return v;}

void CPoco::Rho(double _rho){rho=_rho;}

double CPoco::Rho(){return rho;}


string static linha = "_______________________________________________________________________________________ \n";


///Sobrecarga do operador >>, entrada de dados pelo teclado
istream& operator >> (istream& in, CPoco& poco){

    cout << "Entre com os valores das variaveis conforme sequencia:\n";
    cout << "Caso a variavel nao seja necessaria para o calculo, digitar 0 \n";
    cout << linha;
    cout << "1 - [d] Diametro de tubo (unidade: m ou in): \n";
    in >> poco.d; in.get();
    cout << "\n2 - [di] Diametro externo de tubo interno para anular (unidade: m ou in): \n";
    in >> poco.di; in.get();
    cout << "\n3 - [de] Diametro interno de tubo externo para anular (unidade: m ou in): \n";
    in >> poco.df; in.get();
    cout << "\n4 - [l] Comprimento (unidade: m ou ft): \n";
    in >> poco.l; in.get();
    cout << "\n5 - [v] Velocidade de fluxo (unidade: m/s ou ft/min): \n";
    in >> poco.v; in.get();
    cout << "\n6 - [rho] Massa especifica ou densidade absoluta do fluido (unidade: kg/m^3 ou lbm/gal): \n";
    in >> poco.rho; in.get();
    cout << linha;

    return in;
}
