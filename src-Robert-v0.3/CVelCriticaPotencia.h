#ifndef CVelCriticaPotencia_h
#define CVelCriticaPotencia_h

#include <iostream>

#include "CIndice.h"
#include "CPoco.h"

/**
@brief Classe que calcula a velocidade cr�tica do fluido de perfura��o no po�o para fluidos de Potencia
@class CVelCriticaPotemcia
@file CVelCriticaPotencia.h
*/

 class CVelCriticaPotencia{
 /// Atributos
 public:
      /// Velocidade Cr�tica para Fluidos de Pot�ncia, no interior de tubos e unidades no Sistema Internacional
     double vel_critica_Potencia_it_SI;
     /// Velocidade Cr�tica para Fluidos de Pot�ncia, no interior de tubos e unidades de Campo
     double vel_critica_Potencia_it_UC;
     /// Velocidade Cr�tica para Fluidos de Pot�ncia, no espa�o anular e unidades no Sistema Internacional
     double vel_critica_Potencia_ea_SI;
     /// Velocidade Cr�tica para Fluidos de Pot�ncia, no espa�o anular e unidades de Campo
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

    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos de Pot�ncia, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Potencia_it_SI();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos de Pot�ncia, no interior de tubos e unidades de Campo
    double Vel_critica_Potencia_it_UC();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos de Pot�ncia, no espa�o anular e unidades no Sistema Internacional
    double Vel_critica_Potencia_ea_SI();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos de Pot�ncia, no espa�o anular e unidades de Campo
    double Vel_critica_Potencia_ea_UC();

 };

#endif // CVelCriticaPotencia_h
