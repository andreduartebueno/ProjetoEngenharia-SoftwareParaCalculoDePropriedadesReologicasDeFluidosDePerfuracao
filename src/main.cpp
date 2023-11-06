#include <iostream>
#include <string>

#include "CAmostraFluido.h"
#include "CPropriedadesReologicas.h"
#include "CIndice.h"
#include "CPoco.h"
#include "CVelCritica.h"
#include "CVelCriticaPotencia.h"
#include "CPerdaCarga.h"
#include "CPerdaCargaPotencia.h"
#include "CGnuplot.h"

using namespace std;

string static linha = "_______________________________________________________________________________________ \n";

///Menu de execucao

int main()
{
    ///Objeto da classe CAmostraFluido
    CAmostraFluido amostra;

    ///Objeto da classe CPropriedadesReologicas
    CPropriedadesReologicas propriedade;

    ///Objeto da classe CIndice
    CIndice indice;

    ///Objeto da classe CPoco
    CPoco poco;

    ///Objeto da classe CVelCritica
    CVelCritica critica(&propriedade, &poco);

    ///Objeto da classe CVelCriticaPotencia
    CVelCriticaPotencia criticap(&indice, &poco);

    ///Objeto da classe CPerdaCarga
    CPerdaCarga carga(&propriedade, &poco);

    ///Objeto da classe CPerdaCargaPotencia
    CPerdaCargaPotencia cargap(&indice, &poco);


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

    /// Pedimos ao usuario os dados de entrada referente a amostra de fluido
    amostra.EntradadeDados();

    char escolha;  /// Caractere que armazena a resposta para a escolha das propriedades
    char unidade;  /// Caractere que armazena a resposta para a escolha da unidade a ser utilizada
    char selecao1; /// Caractere que armazena a resposta para a escolha da forma de circulacao
    char selecao2; /// Caractere que armazena a resposta para a escolha da forma de circulacao
    char fluxo;    /// Caractere que armazena a resposta para a escolha do regime de fluxo

    /// Solicita ao usuario a escolha de calculo de propriedades para fluidos Binghamianos ou de Potência
    do {
        cout << "Escolha entre as opcoes abaixo quais propriedades deseja calcular \n";
        cout << linha;
        cout << "Digite a opcao conforme indicacao: \n";
        cout << "1 - Fluidos Binghamianos - Viscosidade Aparente, Plastica e Limite de Escoamento\n";
        cout << "2 - Fluidos de Potencia  - Indice de Comportamento e Consistencia\n";
        cout << linha;
        cin >> escolha;

        /// Looping para Metodos referentes a Fluidos Binghamianos
        if(escolha == '1'){
            cout << linha;
            cout << "Propriedades para Fluidos Binghamianos: " << endl;
            cout << linha;
            propriedade.Visco_aparente(amostra);
            cout << "Viscosidade aparente: "  << propriedade.visco_aparente    << " cP"           << endl;
            propriedade.Visco_plastica(amostra);
            cout << "Viscosidade plastica: "  << propriedade.visco_plastica    << " cP"           << endl;
            propriedade.Limite_escoamento(amostra);
            cout << "Limite de escoamento: "  << propriedade.limite_escoamento << " lbf/100 ft^2" << endl;
            cout << linha;
        }

        /// Looping para Metodos referentes a Fluidos de Potencia
        else if (escolha == '2'){
            do {
                cout << linha;
                cout << "Propriedades para Fluidos de Potencia: " << endl;
                cout << linha;
                cout << "Selecione o local onde o fluido ira circular  \n";
                cout << linha;
                cout << "Digite a opcao conforme indicacao: \n";
                cout << "1 - Interior de Tubos\n";
                cout << "2 - Espaco Anular\n";
                cout << linha;
                cin >> selecao1;

                /// Circulacao pelo Interior de Tubos
                if (selecao1 == '1'){
                    cout << linha;
                    indice.N_it(amostra);
                    cout << "Indice de Comportamento para o Interior de Tubos: "  << indice.n_it  <<  "  adimensional"  << endl;
                    indice.K_it(amostra);
                    cout << "Indice de Consistencia para o Interior de Tubos:  "  << indice.k_it  <<  "  lbf.s^n/100 ft^2"  << endl;
                    cout << linha;

                /// Circulacao pelo Espaco Anular
                }else if (selecao1 == '2'){
                    cout << linha;
                    indice.N_ea(amostra);
                    cout << "Indice de Comportamento para o Espaco Anular:     "  << indice.n_ea  <<  " adimensional"  << endl;
                    indice.K_ea(amostra);
                    cout << "Indice de Consistencia para o Espaco Anular:      "  << indice.k_ea  <<  " lbf.s^n/100 ft^2"  << endl;
                    cout << linha;
                }

                /// Mensagem de erro se a selecao for errada
                if ((selecao1 != '1') && (selecao1 != '2')){cout << linha << "Opcao Invalida" << endl ;}

            }while ((selecao1 != '1') && (selecao1 != '2'));

        }

        /// Mensagem de erro se a escolha for errada
        if ((escolha != '1') && (escolha != '2')){cout << linha << "Opcao Invalida" << endl << linha;}

    }while ((escolha != '1') && (escolha!= '2'));


    string answer;
    cout << "Deseja calcular Velocidade Critica e Perda de carga? [s/n] \n";
    cout << linha;
    cin >> answer; cin.get();
    cout << linha;

    if ((answer == "s") || (answer == "S")){
        cout << "Selecione a unidade que sera utilizada  \n";
        cout << linha;
        cout << "Digite a opcao conforme indicacao: \n";
        cout << "1 - [SI] Sistema Internacional\n";
        cout << "2 - [UC] Unidades de Campo\n";
        cout << linha;
        cin >> unidade;
        cout << linha;

        cout << "Forneca os valores das variaveis solicitadas \n";
        cout << linha;
        cin >> poco;

        if (escolha == '1'){
            cout << "Selecione o local onde o fluido ira circular  \n";
            cout << linha;
            cout << "Digite a opcao conforme indicacao: \n";
            cout << "1 - Interior de Tubos\n";
            cout << "2 - Espaco Anular\n";
            cout << linha;
            cin >> selecao2;
            cout << linha;
        }

        /// Calculando a Velocidade Critica para fluidos Binghamianos e de Potencia
        if ((escolha == '1') && (unidade == '1') && (selecao2 == '1')){
            critica.Vel_critica_Binghamiano_it_SI();
            cout << "Velocidade Critica, fluido Binghamiano, interior de tubos, SI: " << critica.vel_critica_Binghamiano_it_SI << " m/s" << endl;
        } else if ((escolha == '1') && (unidade == '2') && (selecao2 == '1')){
            critica.Vel_critica_Binghamiano_it_UC();
            cout << "Velocidade Critica, fluido Binghamiano, interior de tubos, UC: " << critica.vel_critica_Binghamiano_it_UC << " ft/min" << endl;
        } else if ((escolha == '1') && (unidade == '1') && (selecao2 == '2')){
            critica.Vel_critica_Binghamiano_ea_SI();
            cout << "Velocidade Critica, fluido Binghamiano, espaco anular, SI: " << critica.vel_critica_Binghamiano_ea_SI << " m/s" << endl;
        }else if ((escolha == '1') && (unidade == '2') && (selecao2 == '2')){
            critica.Vel_critica_Binghamiano_ea_UC();
            cout << "Velocidade Critica, fluido Binghamiano, espaco anular, UC: " << critica.vel_critica_Binghamiano_ea_UC << " ft/min" << endl;
        }else if ((escolha == '2') && (unidade == '1') && (selecao1 == '1')){
            criticap.Vel_critica_Potencia_it_SI();
            cout << "Velocidade Critica, fluido de Potencia, interior de tubos, SI: " << criticap.vel_critica_Potencia_it_SI << " m/s" << endl;
        } else if ((escolha == '2') && (unidade == '2') && (selecao1 == '1')){
            criticap.Vel_critica_Potencia_it_UC();
            cout << "Velocidade Critica, fluido de Potencia, interior de tubos, UC: " << criticap.vel_critica_Potencia_it_UC << " ft/min" << endl;
        } else if ((escolha == '2') && (unidade == '1') && (selecao1 == '2')){
            criticap.Vel_critica_Potencia_ea_SI();
            cout << "Velocidade Critica, fluido de Potencia, espaco anular, SI: " << criticap.vel_critica_Potencia_ea_SI << " m/s" << endl;
        }else if ((escolha == '2') && (unidade == '2') && (selecao1 == '2')){
            criticap.Vel_critica_Potencia_ea_UC();
            cout << "Velocidade Critica, fluido de Potencia, espaco anular, UC: " << criticap.vel_critica_Potencia_ea_UC << " ft/min" << endl;
        }

        cout << linha;

        cout << "Escolha o regime de fluxo do fluido de perfuracao para o calculo da Perda de Carga " << endl;
        cout << linha;
        cout << "Digite a opcao conforme indicacao: \n";
        cout << "1 - Fluxo Laminar\n";
        cout << "2 - Fluxo Turbulento\n";
        cout << linha;
        cin >> fluxo;
        cout << linha;

        /// Calculando a Perda de Carga para fluidos Binghamianos e de Potencia
        if ((escolha == '1') && (unidade == '1') && (selecao2 == '1') && (fluxo == '1')){
          carga.Perda_carga_Binghamiano_fl_it_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, interior de tubos, SI: " << carga.perda_carga_Binghamiano_fl_it_SI << " Pa" << endl;
        }else if ((escolha == '1') && (unidade == '2') && (selecao2 == '1') && (fluxo == '1')){
            carga.Perda_carga_Binghamiano_fl_it_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, interior de tubos, UC: " << carga.perda_carga_Binghamiano_fl_it_UC << " psi" << endl;
        }else if ((escolha == '1') && (unidade == '1') && (selecao2 == '1') && (fluxo == '2')){
            carga.Perda_carga_Binghamiano_ft_it_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, interior de tubos, SI: " << carga.perda_carga_Binghamiano_ft_it_SI << " Pa" << endl;
        }else if ((escolha == '1') && (unidade == '2') && (selecao2 == '1') && (fluxo == '2')){
            carga.Perda_carga_Binghamiano_ft_it_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, interior de tubos, UC: " << carga.perda_carga_Binghamiano_ft_it_UC << " psi" << endl;
        }else if ((escolha == '1') && (unidade == '1') && (selecao2 == '2') && (fluxo == '1')){
            carga.Perda_carga_Binghamiano_fl_ea_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, espaco anular, SI: " << carga.perda_carga_Binghamiano_fl_ea_SI << " Pa" << endl;
        }else if ((escolha == '1') && (unidade == '2') && (selecao2 == '2') && (fluxo == '1')){
            carga.Perda_carga_Binghamiano_fl_ea_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, espaco anular, UC: " << carga.perda_carga_Binghamiano_fl_ea_UC << " psi" << endl;
        } else if ((escolha == '1') && (unidade == '1') && (selecao2 == '2') && (fluxo == '2')){
           carga.Perda_carga_Binghamiano_ft_ea_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, espaco anular, SI: " << carga.perda_carga_Binghamiano_ft_ea_SI << " Pa" << endl;
        } else if ((escolha == '1') && (unidade == '2') && (selecao2 == '2') && (fluxo == '2')){
            carga.Perda_carga_Binghamiano_ft_ea_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, espaco anular, UC: " << carga.perda_carga_Binghamiano_ft_ea_UC << " psi" << endl;
        } else if ((escolha == '2') && (unidade == '1') && (selecao1 == '1') && (fluxo == '1')){
            cargap.Perda_carga_Potencia_fl_it_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, interior de tubos, SI: " <<  cargap.perda_carga_Potencia_fl_it_SI << " Pa" << endl;
        } else if ((escolha == '2') && (unidade == '2') && (selecao1 == '1') && (fluxo == '1')){
            cargap.Perda_carga_Potencia_fl_it_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, interior de tubos, UC: " <<  cargap.perda_carga_Potencia_fl_it_UC << " psi" << endl;
        } else if ((escolha == '2') && (unidade == '1') && (selecao1 == '1') && (fluxo == '2')){
            cargap.Perda_carga_Potencia_ft_it_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, interior de tubos, SI: " <<  cargap.perda_carga_Potencia_ft_it_SI << " Pa" << endl;
        } else if ((escolha == '2') && (unidade == '2') && (selecao1 == '1') && (fluxo == '2')){
            cargap.Perda_carga_Potencia_ft_it_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, interior de tubos, UC: " <<  cargap.perda_carga_Potencia_ft_it_UC << " psi" << endl;
        } else if ((escolha == '2') && (unidade == '1') && (selecao1 == '2') && (fluxo == '1')){
            cargap.Perda_carga_Potencia_fl_ea_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, espaco anular, SI: " <<  cargap.perda_carga_Potencia_fl_ea_SI << " Pa" << endl;
        } else if ((escolha == '2') && (unidade == '2') && (selecao1 == '2') && (fluxo == '1')){
            cargap.Perda_carga_Potencia_fl_ea_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, espaco anular, UC: " <<  cargap.perda_carga_Potencia_fl_ea_UC << " psi" << endl;
        } else if ((escolha == '2') && (unidade == '1') && (selecao1 == '2') && (fluxo == '2')){
            cargap.Perda_carga_Potencia_ft_ea_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, espaco anular, SI: " <<  cargap.perda_carga_Potencia_ft_ea_SI << " Pa" << endl;
        } else if ((escolha == '2') && (unidade == '2') && (selecao1 == '2') && (fluxo == '2')){
            cargap.Perda_carga_Potencia_ft_ea_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, espaco anular, UC: " <<  cargap.perda_carga_Potencia_ft_ea_UC << " psi" << endl;
        }

        cout << linha;
        cout << "----------------------------------- FIM DO PROGRAMA ----------------------------------- " << endl << linha;

    }else {cout << "----------------------------------- FIM DO PROGRAMA ----------------------------------- " << endl << linha;}


    return 0;
}
