#ifndef CAmostraFluido_h
#define CAmostraFluido_h

#include <iostream>
#include <string>
#include <vector>

#include "CGnuplot.h"

/**
@brief Classe responsavel pelo entrada de dados da amostra de fluido de perfuracao
@class CAmostraFluido
@file CAmostraFluido.h
*/

class CAmostraFluido {
///Atributos
public:
    /// Valor medido do pH
    double ph;
    /// Valor medido da temperatura
    double temp;
    /// Valor medido da estabilidade eletrica
    double eletrica;
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
    /// Nome dado para identificar o fluido de perfuracao
    std::string nomefluido;
    /// Nome do arquivo com os dados solicitados
    std::string nomearquivo;
    /// Caractere
    char opcao;
    /// Caractere
    char resp;
    /// Contador
    int i;
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
    CAmostraFluido() {};
    ///Destrutor
    ~CAmostraFluido() {};

    /// Metodos set e get
    void Ph(double _ph);               ///Set
    double Ph();                       ///Get

    void Temp(double _temp);           ///Set
    double Temp();                     ///Get

    void Eletrica(double _eletrica);   ///Set
    double Eletrica();                 ///Get

    void Teta600(double _teta600);     ///Set
    double Teta600();                  ///Get

    void Teta300(double _teta300);     ///Set
    double Teta300();                  ///Get

    void Teta200(double _teta200);     ///Set
    double Teta200();                  ///Get

    void Teta100(double _teta100);     ///Set
    double Teta100();                  ///Get

    void Teta006(double _teta006);      ///Set
    double Teta006();                   ///Get

    void Teta003(double _teta003);      ///Set
    double Teta003();                   ///Get

    void Gi(double _gi);                ///Set
    double Gi();                        ///Get

    void Gf(double _gf);                ///Set
    double Gf();                        ///Get


    ///Metodo que solicita a entrada de dados pelo teclado ou pelo disco
    void EntradadeDados();


};

#endif // CAmostraFluido_h
