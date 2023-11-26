#ifndef CVelCritica_h
#define CVelCritica_h

#include <iostream>

#include "CPropriedadesReologicas.h"
#include "CPoco.h"

/**
@brief Classe que calcula a velocidade cr�tica do fluido de perfura��o no po�o para fluidos Binghamianos
@class CVelCritica
@file CVelCritica.h
 */

 class CVelCritica {
 /// Atributos
 public:
    /// Velocidade Cr�tica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double vel_critica_Binghamiano_it_SI;
    /// Velocidade Cr�tica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double vel_critica_Binghamiano_it_UC;
    /// Velocidade Cr�tica para Fluidos Binghamianos, no espa�o anular e unidades no Sistema Internacional
    double vel_critica_Binghamiano_ea_SI;
    /// Velocidade Cr�tica para Fluidos Binghamianos, no espa�o anular e unidades de Campo
    double vel_critica_Binghamiano_ea_UC;
    /// Ponteiro para objeto da classe CPropriedadesReologicas
    CPropriedadesReologicas* ppropriedade;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
 public:
    /// Construtor
    CVelCritica(CPropriedadesReologicas* _ppropriedade, CPoco* _ppoco) : ppropriedade(_ppropriedade), ppoco(_ppoco){};
    /// Destrutor
    CVelCritica();

    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Binghamiano_it_SI();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double Vel_critica_Binghamiano_it_UC();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos Binghamianos, no espa�o anular e unidades no Sistema Internacional
    double Vel_critica_Binghamiano_ea_SI();
    /// Metodo para o calculo da Velocidade Cr�tica para Fluidos Binghamianos, no espa�o anular e unidades de Campo
    double Vel_critica_Binghamiano_ea_UC();

 };

#endif // CVelCritica_h
