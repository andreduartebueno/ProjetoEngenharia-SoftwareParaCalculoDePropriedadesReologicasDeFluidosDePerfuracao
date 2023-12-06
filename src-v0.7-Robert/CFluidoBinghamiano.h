#ifndef CFluidoBinghamiano_h
#define CFluidoBinghamiano_h

#include <iostream>
#include "CAmostraFluido.h"

/**
@brief Classe responsavel pelo calculo das propriedades reologicas para fluidos Binghamianos (Modelo de Bingham ou plastico ideal)
@class CFluidoBinghamiano
@file CFluidoBinghamiano.h
 */

class CFluidoBinghamiano : public CAmostraFluido { /// Herdeira da classe CAmostraFluido
///Atributos
public:
    /// Viscosidade Aparente
    double visco_aparente;
    /// Viscosidade Plastica
    double visco_plastica;
    /// Limite de Escoamento
    double limite_escoamento;


///Metodos
public:
    /// Construtor default
    CCFluidoBinghamiano () {};
    /// Destrutor
    ~CFluidoBinghamiano() {};

    /// Metodos set e get
    void Teta600(double _teta600);     ///Set
    double Teta600();                  ///Get

    void Teta300(double _teta300);     ///Set
    double Teta300();                  ///Get


    /// Metodo que calcula a viscosidade aparente do fluido de perfuracao
    double Visco_aparente(const CAmostraFluido&);
    /// Metodo que calcula a viscosidade plastica do fluido de perfuracao
    double Visco_plastica(const CAmostraFluido&);
    /// Metodo que calcula o limite de escoamento do fluido de perfuracao
    double Limite_escoamento(const CAmostraFluido&);
};

#endif // CFluidoBinghamiano_h
