#ifndef CIndice_h
#define CIndice_h

#include <iostream>

#include "CAmostraFluido.h"

/**
@brief Classe responsavel pelo calculo das propriedades para fluidos de Potência (Modelo de Ostwald de Waale)
@class CIndice
@file CIndice_h
 */

class CIndice : public CAmostraFluido { /// Herdeira da classe CAmostraFluido
//Atributos
public:
    double x;
    double y;
    /// Indice de comportamento para interior de tubos
    double n_it;
    /// Indice de comportamento para espaço anular
    double n_ea;
    /// Indice de consistencia para interior de tubos
    double k_it;
    /// Indice de consistencia para espaço anular
    double k_ea;

 ///Metodos
 public:
    /// Construtor default
    CIndice() {};
    /// Destrutor
    ~CIndice() {};

    /// Metodos set e get
    void Teta600(double _teta600);     ///Set
    double Teta600();                  ///Get

    void Teta300(double _teta300);     ///Set
    double Teta300();                  ///Get

    void Teta003(double _teta003);     ///Set
    double Teta003();                  ///Get


    /// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
    double N_it(const CAmostraFluido&);
    /// Metodo que calcula o Indice de Comportamento para o Espaço Anular
    double N_ea(const CAmostraFluido&);
    /// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
    double K_it(const CAmostraFluido&);
    /// Metodo que calcula o Indice de Consistencia para o Espaço Anular
    double K_ea(const CAmostraFluido&);

};

#endif // CIndice_h
