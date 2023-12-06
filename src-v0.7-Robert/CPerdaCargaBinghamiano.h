#ifndef CPerdaCargaBinghamiano_h
#define CPerdaCargaBinghamiano_h

#include <iostream>

#include "CFluidoBinghamiano.h"
#include "CPoco.h"

/**
@brief Classe que calcula a perda de carga do fluido de perfuração no poço para fluidos Binghamianos
@class CPerdaCargaBinghamiano
@file CPerdaCargaBinghamiano.h
*/

class CPerdaCargaBinghamiano { /// Herdeira das classes CPropriedadesReologicas e CPoco
/// Atributos
public:
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Binghamiano_fl_it_SI;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades de Campo
    double perda_carga_Binghamiano_fl_it_UC;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double perda_carga_Binghamiano_fl_ea_SI;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades de Campo
    double perda_carga_Binghamiano_fl_ea_UC;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Binghamiano_ft_it_SI;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double perda_carga_Binghamiano_ft_it_UC;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Binghamiano_ft_ea_SI;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double perda_carga_Binghamiano_ft_ea_UC;
    /// Ponteiro para objeto da classe CFluidoBinghamiano
    CFluidoBinghamiano* ppropriedade;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
public:
    /// Construtor
    CPerdaCargaBinghamiano(CFluidoBinghamiano* _ppropriedade, CPoco* _ppoco) : ppropriedade(_ppropriedade), ppoco(_ppoco){};
    /// Destrutor
    ~CPerdaCargaBinghamiano() {};

    /// Metodo para calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_fl_it_SI();
    /// Metodo para calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_fl_it_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_fl_ea_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades de Campo
    double Perda_carga_Binghamiano_fl_ea_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_ft_it_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_ft_it_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_ft_ea_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_ft_ea_UC();

};

#endif // CPerdaCargaBinghamiano_h
