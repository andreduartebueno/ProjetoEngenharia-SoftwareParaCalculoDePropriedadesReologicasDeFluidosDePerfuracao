#ifndef CPerdaCarga_h
#define CPerdaCarga_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
@brief Classe que calcula a perda de carga do fluido de perfuração no poço para fluidos Binghamianos e de Potência
@class CPerdaCarga
@file CPerdaCarga.h
 */

class CPerdaCarga : public CPropriedadesReologicas, public CIndice { /// Classe herdeira de CPropriedadesReologicas e CIndice
///Atributos
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

    /// Perda de Carga para Fluidos de Potência, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Potencia_fl_it_SI;
    /// Perda de Carga para Fluidos de Potência, com fluxo laminar, no interior de tubos e unidades de Campo
    double perda_carga_Potencia_fl_it_UC;
    /// Perda de Carga para Fluidos de Potência, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double perda_carga_Potencia_fl_ea_SI;
    /// Perda de Carga para Fluidos de Potência, com fluxo laminar, no espaço anular e unidades de Campo
    double perda_carga_Potencia_fl_ea_UC;
    /// Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Potencia_ft_it_SI;
    /// Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades de Campo
    double perda_carga_Potencia_ft_it_UC;
    /// Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double perda_carga_Potencia_ft_ea_SI;
    /// Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades de Campo
    double perda_carga_Potencia_ft_ea_UC;


    ///Métodos
public:
    ///Construtor default
    CPerdaCarga() {};
    ///Destrutor
    ~CPerdaCarga() {};

    /// Metodo para calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_fl_it_SI(PropiedadesReologicas& propriedade);
    /// Metodo para calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_fl_it_UC(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_fl_ea_SI(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades de Campo
    double Perda_carga_Binghamiano_fl_ea_UC(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_ft_it_SI(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_ft_it_UC(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Binghamiano_ft_ea_SI(PropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Binghamiano_ft_ea_UC(PropiedadesReologicas& propriedade);

    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Potencia_fl_it_SI(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo laminar, no interior de tubos e unidades de Campo
    double Perda_carga_Potencia_fl_it_UC(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double Perda_carga_Potencia_fl_ea_SI(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo laminar, no espaço anular e unidades de Campo
    double Perda_carga_Potencia_fl_ea_UC(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Potencia_ft_it_SI(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Potencia_ft_it_UC(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double Perda_carga_Potencia_ft_ea_SI(CIndice& indice);
    /// Metodo para o calculo da Perda de Carga para Fluidos de Potência, com fluxo turbulento, no interior de tubos e unidades de Campo
    double Perda_carga_Potencia_ft_ea_UC(CIndice& indice);

};

#endif //CPerdaCarga_h