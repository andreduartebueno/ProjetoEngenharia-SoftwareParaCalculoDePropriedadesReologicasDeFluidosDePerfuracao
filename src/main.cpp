#include <iostream>
#include "CSimuladorPerdaCargaCirculacaoFluidos.h"


void EncerraComBug() {
    std::cout << "Excecao nao tratada\n" << std::flush;
    std::cout << "Nota:: Dados de engenharia inconsistentes travam o programa!\n" << std::flush;
    std::abort();
}

/// funcao main,  cria simulador e executa a simulacao.
int main() {
    std::set_terminate(EncerraComBug);
    CSimuladorPerdaCargaCirculacaoFluidos simulador;
    while( simulador.Menu() ){
    };
    return 0;
}
