#ifndef CVelCritica_h
#define CVelCritica_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
@brief Classe que calcula a velocidade crítica do fluido de perfuração no poço
@class CVelCritica
@file CVelCritica.h
 */

class CVelCritica : public CPropriedadesReologicas, public CIndice { /// Herdeira das classes CPropriedadesReologicas e CIndice
///Atributos
public:
    /// Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double vel_critica_Bighamiano_it_SI;
    /// Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double vel_critica_Bighamiano_it_UC;
    /// Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
    double vel_critica_Bighamiano_ea_SI;
    /// Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades de Campo
    double vel_critica_Bighamiano_ea_UC;

    /// Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
    double vel_critica_Potencia_it_SI;
    /// Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
    double vel_critica_Potencia_it_UC;
    /// Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
    double vel_critica_Potencia_ea_SI;
    /// Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
    double vel_critica_Potencia_ea_UC;

///Métodos
public:
    ///Construtor default
    CVelCritica() {};
    ///Destrutor
    ~CVelCritica() {};

    /// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Bighamiano_it_SI(CPropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no interior de tubos e unidades de Campo
    double Vel_critica_Bighamiano_it_UC(CPropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades no Sistema Internacional
    double Vel_critica_Bighamiano_ea_SI(CPropiedadesReologicas& propriedade);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos Binghamianos, no espaço anular e unidades de Campo
    double Vel_critica_Bighamiano_ea_UC(CPropiedadesReologicas& propriedade);

    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
    double Vel_critica_Potencia_it_SI(CIndice& indice);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
    double Vel_critica_Potencia_it_UC(CIndice& indice);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
    double Vel_critica_Potencia_ea_SI(CIndice& indice);
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
    double Vel_critica_Potencia_ea_UC(CIndice& indice);

};

#endif // CVelCritica_h