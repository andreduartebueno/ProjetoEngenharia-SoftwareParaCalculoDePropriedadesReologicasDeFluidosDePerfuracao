#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "CAmostraFluido.h"/*
#include "CPropriedadesReologicas.h"
#include "CIndice.h"
#include "CPoco.h"
#include "CPerdaCarga.h"
#include "CVelCritica.h*/


using namespace std;

string linha = "___________________________________________________________________________________ \n";

///Menu de execucao

int main()
{
    ///Objeto da classe CAmostraFluido
    CAmostraFluido amostra;/*
    ///Objeto da classe CPropriedadesReologicas 
    CPropriedadesReologicas propriedade;
    ///Objeto da classe CIndice
    CIndice indice;
    ///Objeto da classe CPerdaCarga
    CPerdaCarga perdacarga;
    ///Objeto da classe CVelCritica
    CVelCritica velcritica;*/

    ///Cabeçalho

    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "|             UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE - DARCY RIBEIRO               |" << endl;
    cout << "|                       CENTRO DE CIENCIAS E TECNOLOGIA - CCT                         |" << endl;
    cout << "|             LABORATORIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP              |" << endl;
    cout << "|                     DISCIPLINA: PROPRAMACAO PRATICA - PROJETO C++                   |" << endl;
    cout << "|                           PROFESSOR: ANDRE DUARTE BUENO                             |" << endl;
    cout << "|                        ALUNO: ROBERT ALEPHY SOUZA DA SILVA                          |" << endl;
    cout << "|     PROGRAMA PARA CALCULO DE PROPRIEDADES REOLOGICAS DE FLUIDOS DE PERFURACAO,      |" << endl;
    cout << "|              VELOCIDADE CRITICA E PERDAS DE CARGA EM POCOS DE PETROLEO              |" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    
    amostra.EntradadeDados(); ///Pedimos ao usuario os dados de entrada (deflexões da mola do viscosimetro e geis inicial e final)
    /*
    propriedade.Visco_aparente();
    propriedade.Visco_plastica();
    propriedade.Limite_escoamento();

    indice.N_it();
    indice.N_ea();
    indice.K_it();
    indice.K_ea();


    */
    return 0;
}
