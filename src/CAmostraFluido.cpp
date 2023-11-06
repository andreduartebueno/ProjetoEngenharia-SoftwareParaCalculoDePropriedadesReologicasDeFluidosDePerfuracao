#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "CAmostraFluido.h"
#include "CGnuplot.h"

/**
@class CAmostraFluido
@file CAmostraFluido.h
*/

using namespace std;

/// Definicao dos metodos set e get

void CAmostraFluido::Ph(double _ph){ph=_ph;}

double CAmostraFluido::Ph() {return ph;}

void CAmostraFluido::Temp(double _temp){temp=_temp;}

double CAmostraFluido::Temp(){return temp;}

void CAmostraFluido::Eletrica(double _eletrica){eletrica=_eletrica;}

double CAmostraFluido::Eletrica(){return eletrica;}

void CAmostraFluido::Teta600(double _teta600){teta600=_teta600;}

double CAmostraFluido::Teta600() {return teta600;}

void CAmostraFluido::Teta300(double _teta300){teta300=_teta300;}

double CAmostraFluido::Teta300(){return teta300;}

void CAmostraFluido::Teta200(double _teta200){teta200=_teta200;}

double CAmostraFluido::Teta200(){return teta200;}

void CAmostraFluido::Teta100(double _teta100){teta100=_teta100;}

double CAmostraFluido::Teta100() {return teta100;}

void CAmostraFluido::Teta006(double _teta006){teta006=_teta006;}

double CAmostraFluido::Teta006(){return teta006;}

void CAmostraFluido::Teta003(double _teta003){teta003=_teta003;}

double CAmostraFluido::Teta003(){return teta003;}

void CAmostraFluido::Gi(double _gi){gi=_gi;}

double CAmostraFluido::Gi(){return gi;}

void CAmostraFluido::Gf(double _gf){gf=_gf;}

double CAmostraFluido::Gf(){return gf;}


string linha = "_______________________________________________________________________________________ \n";


void CAmostraFluido::EntradadeDados() {

    cout << "Digite um nome para identificar o fluido de perfuracao: " << endl;
    cout << "[Sugestao --> Base do fluido_ + Numeracao_ + Parametros a serem analisados] " <<endl;
    cout << "Exemplo: FBA_07_Salinidade" << endl;
    cout << linha;
    cin.ignore(); /// limpeza de caracteres residuais no buffer
    getline(cin, nomefluido);
    cout << linha;

    cout << "Digite o valor do pH (Potencial Hidrogenioco): " << endl;
    cout << linha;
    cin >> ph;
    cout << linha;

    cout << "Digite o valor da temperatura do fluido (em Fahrenheit): " << endl;
    cout << linha;
    cin >> temp;
    cout << linha;

    cout << "Digite o valor da estabilidade eletrica (em Volts): " << endl;
    cout << linha;
    cin >> eletrica;
    cout << linha;

    cout << "Entre com os dados das leituras de deflexao da mola do viscosimetro" << endl;
    cout << linha;
    cout << "Entre com os valores das leituras conforme sequencia:\n";
    cout << linha;

    /// Solicitando ao usuário os valores das leituras das deflexões
    cout << "1 - Digite o valor de Teta600: \n" << endl;
    cin >> teta600;

    cout << " \n2 - Digite o valor de Teta300: \n"  << endl;
    cin >> teta300;

    cout << " \n3 - Digite o valor de Teta200: \n"  << endl;
    cin >> teta200;

    cout << " \n4 - Digite o valor de Teta100: \n"  << endl;
    cin >> teta100;

    cout << " \n5 - Digite o valor de Teta006: \n"  << endl;
    cin >> teta006;

    cout << " \n6 - Digite o valor de Teta003: \n"  << endl;
    cin >> teta003;
    cout << linha;

    /// Solicitando ao usuario os valores das leituras dos geis
    cout << "Agora digite os valores lidos para os geis: " << endl;
    cout << linha;

    cout << " \n7 - Digite o valor do Gel inicial: \n";
    cin >> gi;

    cout << " \n8 - Digite o valor do Gel Final: \n";
    cin >> gf;
    cout << linha;


    /// Criando vetor para armazenar os valores das velocidades de rotacao
    vector<double> rotacao = {600, 300, 200, 100, 6, 3};

    /// Criando vetor para armazenar as leituras das deflexões
    vector<double> teta;


    /// Adicionando os valores inseridos ao vetor referente as deflexoes
    teta.push_back(teta600);
    teta.push_back(teta300);
    teta.push_back(teta200);
    teta.push_back(teta100);
    teta.push_back(teta006);
    teta.push_back(teta003);

    /// Exibindo os vetores ao usuário em forma de tabela
    cout << "REOLOGIA: Viscosimetro Fann modelo 35A)" << endl;
    cout << linha;

    cout << "Rotacao, rpm   " ;
    for(i = 0; i < rotacao.size(); i++){cout << right << setw(3) << rotacao[i] << " ";}
    cout << endl;

    cout << "Deflexao, grau ";
    for(i = 0; i < teta.size(); i++){cout << right << setw(3) << teta[i] << " ";}
    cout << endl;
    cout << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    vector<double> taxacisalhamento(6);

    /// Copiando elementos do vetor rotacao para o vetor taxacisalhamento e multiplicando pela constante de conversao
    for(i = 0; i < 6; i++){taxacisalhamento[i] = rotacao[i] * 1.703;}
    cout << endl;
    cout << "Taxa de cisalhamento, (1/s): ";
    for(i = 0; i < taxacisalhamento.size(); i++){cout << taxacisalhamento[i] << " ";}
    cout << endl;
    cout << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    vector<double> tensaocisalhamento_uc(6);

    /// Copiando elementos do vetor teta para o vetor tensaocisalhamento_uc e multiplicando pela constante
    for(i = 0; i < 6; i++){tensaocisalhamento_uc[i] = teta[i] * 1.066;}
    cout << endl;
    cout << "Tensao de cisalhamento, (lbf/100 ft^2): ";
    for(i = 0; i < tensaocisalhamento_uc.size(); i++){cout << tensaocisalhamento_uc[i] << " ";}
    cout << endl;
    cout << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    vector<double> tensaocisalhamento_si(6);

    /// Copiando elementos do vetor tensaocisalhamento_uc para o vetor taxacisalhamento e multiplicando pela constante
    for(i = 0; i < 6; i++){tensaocisalhamento_si[i] = tensaocisalhamento_uc[i] * 478.8026;}
    cout << endl;
    cout << "Tensao de cisalhamento, (mPa): ";
    for(i = 0; i < tensaocisalhamento_uc.size(); i++){cout << tensaocisalhamento_uc[i] << " ";}
    cout << endl;
    cout << linha;

    /// Criando vetor para armazenar as viscosidades
    vector<double> visco_si(6);

    /// Criando o vetor das viscoidades dividindo tensaocisalhamento_si por taxa de cisalhamento
    for(i = 0; i < 6; i++){visco_si [i] = tensaocisalhamento_si[i] / taxacisalhamento[i];}
    cout << endl;
    cout << "Viscosidade, (mPa.s): ";
    for(i = 0; i < visco_si.size(); i++){cout << visco_si[i] << " ";}
    cout << endl;
    cout << linha;




}


