#ifndef CPoco_h
#define CPoco_h

#include <iostream>
#include <fstream>
#include <string>

/**
@brief Classe responsavel pela entrada de dados necessarios ao calculo de perda de carga e velocidade critica
@class CPoco
@file CPoco.h
*/

class CPoco{
/// Atributos
public:
    /// Diametro de tubo (unidade: m ou in)
    double d;
    /// Diametro externo de tubo interno para anular (unidade: m ou in)
    double di;
    /// Diametro interno de tubo externo para anular (unidade: m ou in)
    double df;
    /// Comprimento (unidade: m ou ft)
    double l;
    /// Velocidade de fluxo (unidade: m/s ou ft/min)
    double v;
    /// Massa especifica ou densidade absoluta do fluido (unidade: kg/m^3 ou lbm/gal)
    double rho;

/// Metodos
public:
    /// Construtor default
    CPoco (){};
    /// Destrutor
    ~CPoco(){};

    /// Metodos set e get
    void D(double _d);           ///Set
    double D();                  ///Get

    void Di(double _di);         ///Set
    double Di();                 ///Get

    void Df(double _df);         ///Set
    double Df();                 ///Get

    void L(double _l);           ///Set
    double L();                  ///Get

    void V(double _v);           ///Set
    double V();                  ///Get

    void Rho(double _rho);       ///Set
    double Rho();                ///Get


    /// Sobrecarga de operadores >>, entrada de dados pelo teclado
    friend std::istream& operator >> (std::istream& in, CPoco& poco);

};

#endif // CPoco_h
