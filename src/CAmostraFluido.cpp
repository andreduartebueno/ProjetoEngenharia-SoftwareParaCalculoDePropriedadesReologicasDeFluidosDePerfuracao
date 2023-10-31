#include <iostream>
#include <string>
#include "CAmostraFluido.h"

using namespace std;

void CAmostraFluido::EntradadeDados() {
    string nomearquivo;
    char opcao;
    do {
        cout << linha;
        cout << "Como deseja entrar com os dados: \n";
        cout << " 1 - Teclado \n";
        cout << " 2 - Arquivo de disco \n";
        cout << linha;
        cin >> opcao; cin.get();

        ///Entrada de dados pelo teclado
        if(opcao == '1'){
            cout << linha;
            cout << " Entrada de dados pelo teclado" << endl;
            cout << linha;
            cin >> resp;
        }

        /// Entrada de dados pelo disco
        else if (opcao == '2'){
            cout << linha;
            cout << " Entrada de dados por arquivo de disco" << endl;
            cout << linha;
            cout << " Informe o nome do arquivo com a extensao (ex: .txt, .dat)" << endl;
            getline(cin, nomearquivo);
            ifstream fin;
            fin.open(nomearquivo.c_str());
            fin >> resp;
        }

        /// Mensagem de erro se a escolha for errada
        if ((opcao != '1') && (opcao!= '2')){cout << "Opcao Invalida" << endl;}

        }while ((opcao != '1') && (opcao!= '2'));
*/
}

