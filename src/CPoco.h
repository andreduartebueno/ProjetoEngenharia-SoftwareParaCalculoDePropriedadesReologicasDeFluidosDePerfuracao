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

    /// Definicao dos metodos set e get
    void    D(double _d)            { d = _d; }
    double  D()                     { return d; }
    void    Di(double _di)          { di = _di; }
    double Di()                     { return di; }
    void    Df(double _df)          { df = _df; }
    double  Df()                    { return df; }
    void    L(double _l)            { l = _l; }
    double  L()                     { return l; }
    void    V(double _v)            { v = _v; }
    double  V()                     { return v; }
    void    Rho(double _rho)        { rho = _rho; }
    double  Rho()                   { return rho; }

    /// Metodo que solicita a entrada de dados do objeto.
    void EntradaDeDados(std::ostream& out, std::istream& in);
    /// Método que mostra dados do objeto.
    void SaidaDeDados(std::ostream& out);
    /// Método que salva dados do objeto em disco.
    void SaidaDeDadosDisco(std::ostream& out);

    // Classes amigas
    friend class CModeloEscoamentoFluidoBinghamiano;
    friend class CModeloEscoamentoFluidoDePotencia;
};
#endif // CPoco_h
