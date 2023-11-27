#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "CExperimentoViscosimetroFan35A.h"

using namespace std;

static std::string_view linha = "\n_________________________________________\n";
void CExperimentoViscosimetroFan35A::EntradaDeDados(std::ostream& out, std::istream& in) {
    //amostraFluido->EntradaDeDados();
    out <<  linha
		<<  "Atributos CExperimentoViscosimetroFan35A:\n";

    out << "Entre com os dados das leituras de deflexao da mola do viscosimetro conforme sequencia:\n";

    /// Solicitando ao usuário os valores das leituras das deflexões
    out << linha << " 1 - Digite o valor de Teta600: ";
    in >> teta600;
    out << " 2 - Digite o valor de Teta300: ";
    in >> teta300;
    out << " 3 - Digite o valor de Teta200: "  ;
    in >> teta200;
    out << " 4 - Digite o valor de Teta100: "  ;
    in >> teta100;
    out << " 5 - Digite o valor de Teta006: "  ;
    in >> teta006;
    out << " 6 - Digite o valor de Teta003: " ;
    in >> teta003;

    /// Solicitando ao usuario os valores das leituras dos geis
    out << "Agora digite os valores lidos para os geis:\n";
    out << " 7 - Digite o valor do Gel inicial:\n";
    in >> gi;
    out << " 8 - Digite o valor do Gel Final:\n";
    in >> gf;

    /// Criando vetor para armazenar os valores das velocidades de rotacao
    rotacao = {600, 300, 200, 100, 6, 3};

    /// Criando vetor para armazenar as leituras das deflexões
    teta = {teta600, teta300,  teta200,  teta100,  teta006,  teta003};
    //  esta chamando a saida logo depois da entrada, então tem de calcular!
    //  a saída deveria ser chamada somente se calculos realizados
    CalculoPropriedades();
}

void CExperimentoViscosimetroFan35A::CalculoPropriedades() {
    /// Exibindo os vetores ao usuário em forma de tabela
    cout << "REOLOGIA: Viscosimetro Fann modelo 35A)\n" ;

    cout << "Rotacao, rpm: " ;
    for(int i = 0; i < rotacao.size(); i++)
        {cout << '\n' << i << ' ' << rotacao[i] ;}

    cout << "\nDeflexao, grau: ";
    for(int i = 0; i < teta.size(); i++)
        {cout << '\n' << i << ' ' << teta[i] ;}
    cout << endl << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    taxacisalhamento.resize(rotacao.size());

    /// Copiando elementos do vetor rotacao para o vetor taxacisalhamento e multiplicando pela constante de conversao
    cout << "\nTaxa de cisalhamento, (1/s): ";
    for(int i = 0; i < taxacisalhamento.size(); i++) {
        taxacisalhamento[i] = rotacao[i] * 1.703;
        cout << taxacisalhamento[i] << ' ';
    }
    cout << '\n' << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    tensaocisalhamento_uc.resize(teta.size());

    /// Copiando elementos do vetor teta para o vetor tensaocisalhamento_uc e multiplicando pela constante
    cout << "\nTensao de cisalhamento, (lbf/100 ft^2): ";
    for(int i = 0; i < tensaocisalhamento_uc.size(); i++) {
        tensaocisalhamento_uc[i] = teta[i] * 1.066;
        cout << tensaocisalhamento_uc[i] << ' ';
    }
    cout << '\n' << linha;

    /// Criando vetor para armazenar as taxas de cisalhamento
    tensaocisalhamento_si.resize(tensaocisalhamento_uc.size());

    /// Copiando elementos do vetor tensaocisalhamento_uc para o vetor taxacisalhamento e multiplicando pela constante
    cout << "\nTensao de cisalhamento, (mPa): ";
    for(int i = 0; i < tensaocisalhamento_si.size(); i++){
        tensaocisalhamento_si[i] = tensaocisalhamento_uc[i] * 478.8026;
        cout << tensaocisalhamento_si[i] << ' ';
    }
    cout << '\n' << linha;

    /// Criando vetor para armazenar as viscosidades
    visco_si.resize(rotacao.size());

    /// Criando o vetor das viscoidades dividindo tensaocisalhamento_si por taxa de cisalhamento
    cout << "\nViscosidade, (mPa.s): ";
    for(int i = 0; i < visco_si .size(); i++){
        visco_si [i] = tensaocisalhamento_si[i] / taxacisalhamento[i];
        cout << visco_si[i] << ' ';
    }
    cout << '\n' << linha;
}

void CExperimentoViscosimetroFan35A::SaidaDeDados(ostream& os) {
        os <<  linha
           <<  "Atributos CExperimentoViscosimetroFan35A:\n";
        os << " Leitura das deflexoes:" ;
        os << "\n Teta600: " << teta600 ;
        os << "\n Teta300: " << teta300 ;
        os << "\n Teta200: " << teta200 ;
        os << "\n Teta100: " << teta100 ;
        os << "\n Teta006: " << teta006 ;
        os << "\n Teta003: " << teta003 ;
        os << "\n Leitura dos geis:" ;
        os << "\n Gel inicial: " << gi ;
        os << "\n Gel Final:   " << gf ;

        os << "\n==> REOLOGIA:";
        os << "\nRotacao, rpm:\n";
        for(auto& e: rotacao)
            { os << right << setw(3) << e << ' ';}
        os  << "\nDeflexao, grau:\n";
        for(auto& e: teta)
            { os << right << setw(3) << e << ' ';}
        os << "\nTaxa de cisalhamento, (1/s):\n";
        for(auto& e: taxacisalhamento)
            { os << right << setw(3) << e << ' ';}
        os <<  "\nTensao de cisalhamento, (lbf/100 ft^2):\n";
        for(auto& e: tensaocisalhamento_uc)
            { os << right << setw(3) << e << ' ';}
        os  << "\nTensao de cisalhamento, (mPa):\n";
        for(auto& e: tensaocisalhamento_si)
            { os << right << setw(3) << e << ' ';}
        os << "\nViscosidade, (mPa.s):\n";
        for(auto& e: visco_si)
            { os << right << setw(3) << e << ' ';}

        // os  <<  setw(10) << "Rotacao(rpm)"
        //     <<  setw(10) << "Deflexao(grau)"
        //     <<  setw(10) << "Taxa cisalhamento(1/s)"
        //     <<  setw(10) << "Tensao cisalhamento(lbf/100 ft^2)"
        //     <<  setw(10) << "Tensao cisalhamento(mPa)"
        //     <<  setw(10) << "Viscosidade(mPa.s): ";
        os  <<  "\n   Rotacao  Deflexao  TaxaCisalhamento  TensaoCisalhamento  TensaoCisalhamento  Viscosidade"
            <<  "\n     (rpm)    (grau)             (1/s)      (lbf/100 ft^2)               (mPa)      (mPa.s)\n";
        for(int i = 0; i < rotacao.size(); i++){
            os  << right << setw(10) << rotacao[i]
                << right << setw(10) << teta[i]
                << right << setw(18) << taxacisalhamento[i]
                << right << setw(20) << tensaocisalhamento_uc[i]
                << right << setw(20) << tensaocisalhamento_si[i]
                << right << setw(13) << visco_si[i] << '\n';
        }
}

void CExperimentoViscosimetroFan35A::SaidaDeDadosDisco(std::ostream& out) {
        out << teta600  <<  ' '
            << teta300  <<  ' '
            << teta200  <<  ' '
            << teta100  <<  ' '
            << teta006  <<  ' '
            << teta003  <<  ' '
            << gi       <<  ' '
            << gf;
        for(int i = 0; i < rotacao.size(); i++)
            out << right << setw(3) << rotacao[i] << ' ';
        for(int i = 0; i < teta.size(); i++)
            out << right << setw(3) << teta[i] << ' ';
        for(int i = 0; i < taxacisalhamento.size(); i++)
            out << taxacisalhamento[i] << ' ';
        for(int i = 0; i < tensaocisalhamento_uc.size(); i++)
            out << tensaocisalhamento_uc[i] << ' ';
        for(int i = 0; i < tensaocisalhamento_si.size(); i++)
            out << tensaocisalhamento_si[i] << ' ';
        for(int i = 0; i < visco_si.size(); i++)
            out << visco_si[i] << ' ';
}

// void CExperimentoViscosimetroFan35A::SaidaDeDadosDisco(std::ostream& out) {
//     char salvar ==  's';
//     out << "Deseja salvar os resultados em disco? [s/n] \n";
//     out << linha;
//     in >> salvar; in.get();
//     out << linha;
//
//     if ((salvar == 's') || (salvar == 'S')){
//         string nomearquivo;
//         out << "Digite o nome do arquivo em que os resultados serao salvos: \n";
//         getline(in, nomearquivo);
//         out << linha;
//         nomearquivo += ".txt";
//
//         ofstream fout(nomearquivo.c_str());
//         //  Executa a saída de dados
//         SaidaDeDados(fout);
//
//         out << "Os dados foram salvos no arquivo externo " << nomearquivo << endl;
//         out << linha;
//         out << "Aperte ENTER para continuar\n";
//         out << linha;
//         in.get();
//
//     }else {out << endl;}
// }
