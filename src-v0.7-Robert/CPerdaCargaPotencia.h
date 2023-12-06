#ifndef CPerdaCargaPotencia_h
#define CPerdaCargaPotencia_h

#include <iostream>

#include "CFluidoPotencia.h"
#include "CPoco.h"

/**
@brief Classe que calcula a perda de carga do fluido de perfuração no poco para fluidos de Potencia
@class CPerdaCargaPotencia
@file CPerdaCargaPotencia.h
*/

class CPerdaCargaPotencia {
/// Atributos
public:
    /// Perda de Carga para Fluidos de Potencia, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Potencia_fl_it_SI;
    /// Perda de Carga para Fluidos de Potencia, com fluxo laminar, no interior de tubos e unidades de Campo
    double perda_carga_Potencia_fl_it_UC;
    /// Perda de Carga para Fluidos de Potencia, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double perda_carga_Potencia_fl_ea_SI;
    /// Perda de Carga para Fluidos de Potencia, com fluxo laminar, no espaço anular e unidades de Campo
    double perda_carga_Potencia_fl_ea_UC;
    /// Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Potencia_ft_it_SI;
    /// Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no interior de tubos e unidades de Campo
    double perda_carga_Potencia_ft_it_UC;
    /// Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no espaço anular e unidades no Sistema Internacional
    double perda_carga_Potencia_ft_ea_SI;
    /// Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no espaço anular e unidades de Campo
    double perda_carga_Potencia_ft_ea_UC;
    /// Ponteiro para objeto da classe CFluidoPotencia
    CFluidoPotencia* pindice;
    /// Ponteiro para objeto da classe CPoco
    CPoco* ppoco;

/// Metodos
public:
    /// Construtor
    CPerdaCargaPotencia(CFluidoPotencia* _pindice, CPoco* _ppoco) : pindice(_pindice), ppoco(_ppoco){};
    /// Destrutor
    ~CPerdaCargaPotencia() {};

    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Potencia_fl_it_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo laminar, no interior de tubos e unidades de Campo
    double Perda_carga_Potencia_fl_it_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double Perda_carga_Potencia_fl_ea_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo laminar, no espaço anular e unidades de Campo
    double Perda_carga_Potencia_fl_ea_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Potencia_ft_it_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Potencia_ft_it_UC();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no espaço anular e unidades no Sistema Internacional
    double Perda_carga_Potencia_ft_ea_SI();
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potencia, com fluxo turbulento, no espaço anular e unidades de Campo
    double Perda_carga_Potencia_ft_ea_UC();

};

#endif // CPerdaCargaPotencia_h
