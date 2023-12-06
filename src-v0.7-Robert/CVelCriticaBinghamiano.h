#ifndef CVelCriticaBinghamiano_h
#define CVelCriticaBinghamiano_h

#include <iostream>

#include "CFluidoBinghamiano.h"
#include "CPoco.h"

/**
@brief Classe que calcula a velocidade critica do fluido de perfuracao no poco para fluidos Binghamianos
@class CVelCriticaBinghamiano
@file CVelCriticaBinghamiano.h
 */

 class CVelCriticaBinghamiano {
 /// Atributos
 public:
    /// Velocidade Critica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double vel_critica_Binghamiano_it_SI;
    /// Velocidade Critica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double vel_critica_Binghamiano_it_UC;
    /// Velocidade Critica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
    double vel_critica_Binghamiano_ea_SI;
    /// Velocidade Critica para Fluidos Binghamianos, no espaço anular e unidades de Campo
    double vel_critica_Binghamiano_ea_UC;
    /// Ponteiro para objeto da classe CFluidoBinghamiano
    CFluidoBinghamiano* ppropriedade;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
 public:
    /// Construtor
    CVelCriticaBinghamiano(CFluidoBinghamiano* _ppropriedade, CPoco* _ppoco) : ppropriedade(_ppropriedade), ppoco(_ppoco){};
    /// Destrutor
    CVelCriticaBinghamiano();

    /// Metodo para o calculo da Velocidade Critica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Binghamiano_it_SI();
    /// Metodo para o calculo da Velocidade Critica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double Vel_critica_Binghamiano_it_UC();
    /// Metodo para o calculo da Velocidade Critica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
    double Vel_critica_Binghamiano_ea_SI();
    /// Metodo para o calculo da Velocidade Critica para Fluidos Binghamianos, no espaço anular e unidades de Campo
    double Vel_critica_Binghamiano_ea_UC();

 };

#endif // CVelCriticaBinghamiano_h
