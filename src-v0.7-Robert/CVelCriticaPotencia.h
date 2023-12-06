#ifndef CVelCriticaPotencia_h
#define CVelCriticaPotencia_h

#include <iostream>

#include "CFluidoPotencia.h"
#include "CPoco.h"

/**
@brief Classe que calcula a velocidade critica do fluido de perfuração no poço para fluidos de Potencia
@class CVelCriticaPotemcia
@file CVelCriticaPotencia.h
*/

 class CVelCriticaPotencia{
 /// Atributos
 public:
      /// Velocidade Critica para Fluidos de Potencia, no interior de tubos e unidades no Sistema Internacional
     double vel_critica_Potencia_it_SI;
     /// Velocidade Critica para Fluidos de Potencia, no interior de tubos e unidades de Campo
     double vel_critica_Potencia_it_UC;
     /// Velocidade Critica para Fluidos de Potencia, no espaço anular e unidades no Sistema Internacional
     double vel_critica_Potencia_ea_SI;
     /// Velocidade Critica para Fluidos de Potencia, no espaço anular e unidades de Campo
     double vel_critica_Potencia_ea_UC;
     /// Ponteiro para objeto da classe CFluidoPotencia
    CFluidoPotencia* pindice;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
 public:
    /// Construtor
    CVelCriticaPotencia(CFluidoPotencia* _pindice, CPoco* _ppoco) : pindice(_pindice), ppoco(_ppoco){};
    /// Destrutor
    CVelCriticaPotencia();

    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Potencia_it_SI();
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
    double Vel_critica_Potencia_it_UC();
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
    double Vel_critica_Potencia_ea_SI();
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
    double Vel_critica_Potencia_ea_UC();

 };

#endif // CVelCriticaPotencia_h
