#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/**
@class CPerdaCarga
@file CPerdaCarga.cpp
 */

using namespace std;

///Delta_P Fluidos Binghamianos

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades SI
double CPerdaCarga::Perda_carga_Binghamiano_fl_it_SI(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_fl_it_SI = (((32 * visco_plastica * L * v) / (pow(D, 2))) + ((4 * tau_L * L) / (D)));

    return perda_carga_Binghamiano_fl_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no interior de tubos, em unidades de Campo
double CPerdaCarga::Perda_carga_Binghamiano_fl_it_UC(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_fl_it_UC = (((visco_plastica * L * v) / (89775 * (pow(D, 2)))) + ((tau_L * L) / (300 * D)));

    return perda_carga_Binghamiano_fl_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades SI
double CPerdaCarga::Perda_carga_Binghamiano_fl_ea_SI(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_fl_ea_SI = (((48 * visco_plastica * L * v) / (pow((Do - Di), 2))) + ((4 * tau_L * L) / (Do - Di)));

    return perda_carga_Binghamiano_fl_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo laminar, no espaço anular, em unidades de Campo
double CPerdaCarga::Perda_carga_Binghamiano_fl_ea_UC(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_fl_ea_UC = (((visco_plastica * L * v) / (59851 * (pow((Do - Di), 2)))) + ((tau_L * L) / 300 * (Do - Di)));

    return perda_carga_Binghamiano_fl_ea_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades SI
double CPerdaCarga::Perda_carga_Binghamiano_ft_it_SI(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_ft_it_SI = ((0, 1 * L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / pow(D, 1.2));

    return perda_carga_Binghamiano_ft_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CPerdaCarga::Perda_carga_Binghamiano_ft_it_UC(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_ft_it_UC = ((L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / (3212923 * pow(D, 1.2)));

    return perda_carga_Binghamiano_ft_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades SI
double CPerdaCarga::Perda_carga_Binghamiano_ft_ea_SI(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_ft_ea_SI = ((0, 1275 * L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / pow((Do - Di), 1.2));

    return perda_carga_Binghamiano_ft_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos Binghamianos, em fluxo turbulento, no espaço anular, em unidades de Campo
double CPerdaCarga::Perda_carga_Binghamiano_ft_ea_UC(PropiedadesReologicas& propriedade) {

    perda_carga_Binghamiano_ft_ea_UC = ((L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / (2519939 * pow((Do - Di), 1.2)));

    return perda_carga_Binghamiano_ft_ea_UC;
}


///Delta_P Fluidos Binghamianos

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades SI
double CPerdaCarga::Perda_carga_Potencia_fl_it_SI(C & indice) {

    perda_carga_Potencia_fl_it_SI = (((4 * K * L) / (D)) * pow((v / D) * (((6 * n) + 2) / n)), n));

    return perda_carga_Potencia_fl_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no interior de tubos, em unidades de Campo
double CPerdaCarga::Perda_carga_Potencia_fl_it_UC(C& indice) {

    perda_carga_Potencia_fl_it_UC = (((K * L) / (300 * D)) * pow((((0.4 * v) / D) * (((3 * n) + 1) / n)), n));

    return perda_carga_Potencia_fl_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades SI
double CPerdaCarga::Perda_carga_Potencia_fl_ea_SI(C& indice) {

    perda_carga_Potencia_fl_ea_SI = (((4 * K * L) / (Do - Di)) * pow((v / (Do - Di)) * ((n + 4) / n)), n));

    return perda_carga_Potencia_fl_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo laminar, no espaço anular, em unidades de Campo
double CPerdaCarga::Perda_carga_Potencia_fl_ea_UC(C& indice) {

    perda_carga_Potencia_fl_ea_UC = (((K * L) / (300 * (Do - Di))) * pow((((0.8 * v) / (Do - Di)) * (((2 * n) + 1) / n)), n));

    return perda_carga_Potencia_fl_ea_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades SI
double CPerdaCarga::Perda_carga_Potencia_ft_it_SI(C& indice) {

    perda_carga_Potencia_ft_it_SI = ((0, 1 * L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / pow(D, 1.2));

    return perda_carga_Potencia_ft_it_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no interior de tubos, em unidades de Campo
double CPerdaCarga::Perda_carga_Potencia_ft_it_UC(C& indice) {

    perda_carga_Potencia_ft_it_UC = ((((log(n) + 2.5) * ro * pow(v, 2) * L) / (25 * D)) * pow(visco_plastica, 0.2)) / (3212923 * pow(D, 1.2)));

    return perda_carga_Potencia_ft_it_UC;
}

/// Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades SI
double CPerdaCarga::Perda_carga_Potencia_ft_ea_SI(C& indice) {

    perda_carga_Potencia_ft_ea_SI = ((0, 1275 * L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / pow((Do - Di), 1.2));

    return perda_carga_Potencia_ft_ea_SI;
}

///  Metodo para calculo da perda de carga para fluidos de Potencia, em fluxo turbulento, no espaço anular, em unidades de Campo
double CPerdaCarga::Perda_carga_Potencia_ft_ea_UC(C& indice) {

    perda_carga_Potencia_ft_ea_UC = ((L * pow(ro, 0.8) * pow(v, 1.8) * pow(visco_plastica, 0.2)) / (2519939 * pow((Do - Di), 1.2)));

    return perda_carga_Potencia_ft_ea_UC;
}
