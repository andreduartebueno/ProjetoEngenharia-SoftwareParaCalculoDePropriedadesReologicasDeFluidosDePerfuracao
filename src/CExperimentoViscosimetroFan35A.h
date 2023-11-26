#ifndef CExperimentoViscosimetroFan35A_h
#define CExperimentoViscosimetroFan35A_h

#include <iostream>
#include <string>
#include <vector>
#include "CEquipamento.h"

///  Representa o viscosimetro da marca fan modelo 35A
class CViscosimetroFan35A :  CEquipamento{
    CViscosimetroFan35A(): CEquipamento{"viscosimetro", "FAN", "35A"} {};
};

/// Representa um experimento específico usando o viscosimetro fan 35A
// Tarefa: ver as propriedades de outros viscosimetros e generatlizar se possível
class CExperimentoViscosimetroFan35A  {
    /// Valor lido da deflexao da mola do viscosimetro em 600 rpm
    double teta600;
    /// Valor lido da deflexao da mola do viscosimetro em 300 rpm
    double teta300;
    /// Valor lido da deflexao da mola do viscosimetro em 200 rpm
    double teta200;
    /// Valor lido da deflexao da mola do viscosimetro em 100 rpm
    double teta100;
    /// Valor lido da deflexao da mola do viscosimetro em 006 rpm
    double teta006;
    /// Valor lido da deflexao da mola do viscosimetro em 003 rpm
    double teta003;
    /// Valor lido da deflexao da mola para o gel inicial
    double gi;
    /// Valor lido da deflexao da mola para o gel final
    double gf;
    /// Vetor de velocidades de rotacao
    std::vector<double> rotacao;
    /// Vetor de deflexoes da mola (600, 300, 200, 100, 6 e 3 rpm)
    std::vector<double> teta;
    /// Vetor de taxa de cisalhamento
    std::vector<double> taxacisalhamento;
    /// Vetor de taxa de cisalhamento em unidade de campo
    std::vector<double> tensaocisalhamento_uc;
    /// Vetor de taxa de cisalhamento no sistema internacional
    std::vector<double> tensaocisalhamento_si;
    /// Vetor de taxa de viscosidade no sistema internacional
    std::vector<double> visco_si;
	///Metodos
public:
    ///Construtor default
    CExperimentoViscosimetroFan35A() {};
    ///Destrutor
    ~CExperimentoViscosimetroFan35A() {};

    /// Metodos set e get
    void Teta600(double _teta600)   { teta600 = _teta600; }
    double Teta600()                { return teta600; }
    void Teta300(double _teta300)   { teta300 = _teta300; }
    double Teta300()                { return teta300; }
    void Teta200(double _teta200)   { teta200 = _teta200; }
    double Teta200()                { return teta200; }
    void Teta100(double _teta100)   { teta100 = _teta100; }
    double Teta100()                { return teta100; }
    void Teta006(double _teta006)   { teta006 = _teta006; }
    double Teta006()                { return teta006; }
    void Teta003(double _teta003)   { teta003 = _teta003; }
    double Teta003()                { return teta003; }
    void Gi(double _gi)             { gi = _gi; }
    double Gi()                     { return gi; }
    void Gf(double _gf)             { gf = _gf; }
    double Gf()                     { return gf; }

    /// Metodo que solicita a entrada de dados do objeto.
    void EntradaDeDados(std::ostream& out, std::istream& in);
    /// Método que mostra dados do objeto.
    void SaidaDeDados(std::ostream& out);
    /// Método que salva dados do objeto em disco.
    void SaidaDeDadosDisco(std::ostream& out);
    ///  Calculo das propriedades
    void CalculoPropriedades();
};
#endif
