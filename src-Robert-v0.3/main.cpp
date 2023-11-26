#include <iostream>
#include <string>
#include <tuple>
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

string static linha = "_______________________________________________________________________________________\n";
void Cabecalho() {
    cout <<
     "---------------------------------------------------------------------------------------\n"
     "|             UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE - DARCY RIBEIRO               |\n"
     "|                       CENTRO DE CIENCIAS E TECNOLOGIA - CCT                         |\n"
     "|             LABORATORIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP              |\n"
     "|                     DISCIPLINA: PROPRAMACAO PRATICA - PROJETO C++                   |\n"
     "|                           PROFESSOR: ANDRE DUARTE BUENO                             |\n"
     "|                        ALUNO: ROBERT ALEPHY SOUZA DA SILVA                          |\n"
     "|     PROGRAMA PARA CALCULO DE PROPRIEDADES REOLOGICAS DE FLUIDOS DE PERFURACAO,      |\n"
     "|              VELOCIDADE CRITICA E PERDAS DE CARGA EM POCOS DE PETROLEO              |\n"
     "---------------------------------------------------------------------------------------" << endl;
}

// Enumeracoes para identificar as escolhas do usuário
// A vantagem é eliminar números magicos e deixar os códigos mais legíveis e seguros
 enum class TipoFluido:     char { Binghamianos = '1',  DePotencia = '2' };
 enum class TipoUnidade:    char { SI = '1', UC= '2' };
 enum class TipoCirculacao: char { InteriorDeTubos = '1', EspacoAnular= '2' };
 enum class TipoFluxo:      char { Laminar = '1', Turbulento= '2' };

/// Menu de execucao
int main()
{
    /// Objeto da classe CAmostraFluido
    CAmostraFluido amostra;

    /// Objeto da classe CPropriedadesReologicas
    CPropriedadesReologicas propriedade;

    /// Objeto da classe CIndice
    CIndice indice;

    /// Objeto da classe CPoco
    CPoco poco;

    /// Objeto da classe CVelCritica
    CVelCritica critica(&propriedade, &poco);

    /// Objeto da classe CVelCriticaPotencia
    CVelCriticaPotencia criticap(&indice, &poco);

    /// Objeto da classe CPerdaCarga
    CPerdaCarga carga(&propriedade, &poco);

    /// Objeto da classe CPerdaCargaPotencia
    CPerdaCargaPotencia cargap(&indice, &poco);


    /// Cabeçalho
    Cabecalho();

    ///  Pedimos ao usuario os dados de entrada referente a amostra de fluido
    amostra.EntradaSaidadeDados();

    TipoFluido tipoFluido;  /// resposta para a escolha das propriedades
    TipoUnidade tipoUnidade;  /// resposta para a escolha da unidade a ser utilizada
    TipoCirculacao tipoCirculacao; /// resposta para a escolha da forma de circulacao1
    TipoCirculacao tipoCirculacao2; /// resposta para a escolha da forma de circulacao2
    TipoFluxo tipoFluxo;    /// resposta para a escolha do regime de fluxo

    char respUsuario;

    ///  Solicita ao usuario a escolha de calculo de propriedades para fluidos Binghamianos ou de Potência
    do {
        cout << "Escolha entre as opcoes abaixo quais propriedades deseja calcular \n";
        cout << linha;
        cout << "Digite a opcao conforme indicacao: \n";
        cout << "1 - Fluidos Binghamianos - Viscosidade Aparente, Plastica e Limite de Escoamento\n";
        cout << "2 - Fluidos de Potencia  - Indice de Comportamento e Consistencia\n";
        cout << linha;
        cin >> respUsuario;
        cin.get(); // bueno - retira do teclado a tecla enter
        tipoFluido = static_cast<TipoFluido>(respUsuario);

        /// Looping para Metodos referentes a Fluidos Binghamianos
        if(tipoFluido == TipoFluido::Binghamianos){
          cout << linha <<  "Propriedades para Fluidos Binghamianos:\n" << linha;
          propriedade.Visco_aparente(amostra);
          cout << "Viscosidade aparente: "  << propriedade.visco_aparente    << " cP\n";
          propriedade.Visco_plastica(amostra);
          cout << "Viscosidade plastica: "  << propriedade.visco_plastica    << " cP\n";
          propriedade.Limite_escoamento(amostra);
          cout << "Limite de escoamento: "  << propriedade.limite_escoamento << " lbf/100 ft^2\n";
          cout << linha;
        }

        /// Looping para Metodos referentes a Fluidos de Potencia
        else if (tipoFluido == TipoFluido::DePotencia) {
            do {
              cout << linha << "Propriedades para Fluidos de Potencia:\n" << linha;
              cout << "Selecione o local onde o fluido ira circular\n" << linha;
              cout << "Digite a opcao conforme indicacao: \n";
              cout << "1 - Interior de Tubos\n";
              cout << "2 - Espaco Anular\n";
              cout << linha;
              cin >> respUsuario; cin.get();
              tipoCirculacao = static_cast<TipoCirculacao>(respUsuario);

              /// Circulacao pelo Interior de Tubos
              if (tipoCirculacao == TipoCirculacao::InteriorDeTubos) {
                cout << linha;
                indice.N_it(amostra);
                cout << "Indice de Comportamento para o Interior de Tubos: "  << indice.n_it  <<  "  adimensional\n" ;
                indice.K_it(amostra);
                cout << "Indice de Consistencia para o Interior de Tubos:  "  << indice.k_it  <<  "  lbf.s^n/100 ft^2\n";
                cout << linha;

                /// Circulacao pelo Espaco Anular
              } else if (tipoCirculacao == TipoCirculacao::EspacoAnular){
                cout << linha;
                indice.N_ea(amostra);
                cout << "Indice de Comportamento para o Espaco Anular:     "  << indice.n_ea  <<  " adimensional\n";
                indice.K_ea(amostra);
                cout << "Indice de Consistencia para o Espaco Anular:      "  << indice.k_ea  <<  " lbf.s^n/100 ft^2\n";
                cout << linha;
              }

              /// Mensagem de erro se a selecao for errada
              if ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao != TipoCirculacao::EspacoAnular)){cout << linha << "Opcao Invalida\n" ;}

            } while ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao != TipoCirculacao::EspacoAnular));

        }

        /// Mensagem de erro se a escolha for errada
        if ((tipoFluido != TipoFluido::Binghamianos) && (tipoFluido != TipoFluido::DePotencia)){cout << linha << "Opcao Invalida\n" << linha;}

    }while ((tipoFluido != TipoFluido::Binghamianos) && (tipoFluido!= TipoFluido::DePotencia));


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
        cin >> respUsuario;
        tipoUnidade = static_cast<TipoUnidade>(respUsuario);
        cout << linha;

        cout << "Forneca os valores das variaveis solicitadas \n";
        cout << linha;
        cin >> poco;

        if (tipoFluido == TipoFluido::Binghamianos){
            cout << "Selecione o local onde o fluido ira circular  \n";
            cout << linha;
            cout << "Digite a opcao conforme indicacao: \n";
            cout << "1 - Interior de Tubos\n";
            cout << "2 - Espaco Anular\n";
            cout << linha;
            cin >> respUsuario;
            tipoCirculacao2 = static_cast<TipoCirculacao>(respUsuario);
            cout << linha;
        }
        //  Tupla com as respotas
//        auto tuplaRespostas = std::make_tuple{tipoFluido, tipoUnidade, tipoCirculacao };
//        std::tuple<TipoFluido,TipoUnidade,TipoCirculacao> tuplaRespostas {tipoFluido, tipoUnidade, tipoCirculacao };
        std::tuple<TipoFluido,TipoUnidade,TipoCirculacao> tuplaRespostas {tipoFluido, tipoUnidade, tipoCirculacao };

        /// Calculando a Velocidade Critica para fluidos Binghamianos e de Potencia
        if ( tuplaRespostas  == std::make_tuple(TipoFluido::Binghamianos, TipoUnidade::SI, TipoCirculacao::InteriorDeTubos)){
            critica.Vel_critica_Binghamiano_it_SI();
            cout << "Velocidade Critica, fluido Binghamiano, interior de tubos, SI: " << critica.vel_critica_Binghamiano_it_SI << " m/s" << endl;
        } else if (tuplaRespostas  == std::make_tuple( TipoFluido::Binghamianos, TipoUnidade::UC, TipoCirculacao::InteriorDeTubos)){
            critica.Vel_critica_Binghamiano_it_UC();
            cout << "Velocidade Critica, fluido Binghamiano, interior de tubos, UC: " << critica.vel_critica_Binghamiano_it_UC << " ft/min" << endl;
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular)){
            critica.Vel_critica_Binghamiano_ea_SI();
            cout << "Velocidade Critica, fluido Binghamiano, espaco anular, SI: " << critica.vel_critica_Binghamiano_ea_SI << " m/s" << endl;
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular)){
            critica.Vel_critica_Binghamiano_ea_UC();
            cout << "Velocidade Critica, fluido Binghamiano, espaco anular, UC: " << critica.vel_critica_Binghamiano_ea_UC << " ft/min" << endl;
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos)){
            criticap.Vel_critica_Potencia_it_SI();
            cout << "Velocidade Critica, fluido de Potencia, interior de tubos, SI: " << criticap.vel_critica_Potencia_it_SI << " m/s" << endl;
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos)){
            criticap.Vel_critica_Potencia_it_UC();
            cout << "Velocidade Critica, fluido de Potencia, interior de tubos, UC: " << criticap.vel_critica_Potencia_it_UC << " ft/min" << endl;
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular)){
            criticap.Vel_critica_Potencia_ea_SI();
            cout << "Velocidade Critica, fluido de Potencia, espaco anular, SI: " << criticap.vel_critica_Potencia_ea_SI << " m/s" << endl;
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular)){
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
        cin >> respUsuario;
        tipoFluxo = static_cast<TipoFluxo>(respUsuario);
        cout << linha;

        /// Calculando a Perda de Carga para fluidos Binghamianos e de Potencia
        if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Laminar)){
          carga.Perda_carga_Binghamiano_fl_it_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, interior de tubos, SI: " << carga.perda_carga_Binghamiano_fl_it_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Laminar)){
            carga.Perda_carga_Binghamiano_fl_it_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, interior de tubos, UC: " << carga.perda_carga_Binghamiano_fl_it_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Turbulento)){
            carga.Perda_carga_Binghamiano_ft_it_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, interior de tubos, SI: " << carga.perda_carga_Binghamiano_ft_it_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Turbulento)){
            carga.Perda_carga_Binghamiano_ft_it_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, interior de tubos, UC: " << carga.perda_carga_Binghamiano_ft_it_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Laminar)){
            carga.Perda_carga_Binghamiano_fl_ea_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, espaco anular, SI: " << carga.perda_carga_Binghamiano_fl_ea_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Laminar)){
            carga.Perda_carga_Binghamiano_fl_ea_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo laminar, espaco anular, UC: " << carga.perda_carga_Binghamiano_fl_ea_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Turbulento)){
           carga.Perda_carga_Binghamiano_ft_ea_SI();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, espaco anular, SI: " << carga.perda_carga_Binghamiano_ft_ea_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::Binghamianos) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Turbulento)){
            carga.Perda_carga_Binghamiano_ft_ea_UC();
            cout << "Perda de carga, fluido Binghamiano, fluxo turbulento, espaco anular, UC: " << carga.perda_carga_Binghamiano_ft_ea_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Laminar)){
            cargap.Perda_carga_Potencia_fl_it_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, interior de tubos, SI: " <<  cargap.perda_carga_Potencia_fl_it_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Laminar)){
            cargap.Perda_carga_Potencia_fl_it_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, interior de tubos, UC: " <<  cargap.perda_carga_Potencia_fl_it_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Turbulento)){
            cargap.Perda_carga_Potencia_ft_it_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, interior de tubos, SI: " <<  cargap.perda_carga_Potencia_ft_it_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::InteriorDeTubos) && (tipoFluxo == TipoFluxo::Turbulento)){
            cargap.Perda_carga_Potencia_ft_it_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, interior de tubos, UC: " <<  cargap.perda_carga_Potencia_ft_it_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Laminar)){
            cargap.Perda_carga_Potencia_fl_ea_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, espaco anular, SI: " <<  cargap.perda_carga_Potencia_fl_ea_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Laminar)){
            cargap.Perda_carga_Potencia_fl_ea_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo laminar, espaco anular, UC: " <<  cargap.perda_carga_Potencia_fl_ea_UC << " psi\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::SI) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Turbulento)){
            cargap.Perda_carga_Potencia_ft_ea_SI();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, espaco anular, SI: " <<  cargap.perda_carga_Potencia_ft_ea_SI << " Pa\n";
        } else if ((tipoFluido == TipoFluido::DePotencia) && (tipoUnidade == TipoUnidade::UC) && (tipoCirculacao == TipoCirculacao::EspacoAnular) && (tipoFluxo == TipoFluxo::Turbulento)){
            cargap.Perda_carga_Potencia_ft_ea_UC();
            cout << "Perda de Carga, fluido de Potencia, fluxo turbulento, espaco anular, UC: " <<  cargap.perda_carga_Potencia_ft_ea_UC << " psi\n";
        }

        cout << linha;
        cout << "----------------------------------- FIM DO PROGRAMA ----------------------------------- \n" << linha;

    }else {cout << "----------------------------------- FIM DO PROGRAMA ----------------------------------- \n" << linha;}


    return 0;
}
