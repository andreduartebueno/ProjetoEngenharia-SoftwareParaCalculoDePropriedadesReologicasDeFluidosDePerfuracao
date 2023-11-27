#ifndef CVelCriticaPotencia_h
#define CVelCriticaPotencia_h

#include <iostream>

#include "CIndice.h"
#include "CPoco.h"

/**
@brief Classe que calcula a velocidade crítica do fluido de perfuração no poço para fluidos de Potencia
@class CVelCriticaPotemcia
@file CVelCriticaPotencia.h
*/

 class CVelCriticaPotencia{
 /// Atributos
 public:
      /// Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
     double vel_critica_Potencia_it_SI;
     /// Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
     double vel_critica_Potencia_it_UC;
     /// Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
     double vel_critica_Potencia_ea_SI;
     /// Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
     double vel_critica_Potencia_ea_UC;
     /// Ponteiro para objeto da classe CIndice
    CIndice* pindice;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
 public:
    /// Construtor
    CVelCriticaPotencia(CIndice* _pindice, CPoco* _ppoco) : pindice(_pindice), ppoco(_ppoco){};
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
