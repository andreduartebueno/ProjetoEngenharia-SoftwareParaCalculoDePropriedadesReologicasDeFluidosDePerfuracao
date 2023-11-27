#include <string>
#include <string_view>
#include <tuple>
#include <memory>

#include "CSimuladorPerdaCargaCirculacaoFluidos.h"

using namespace std;

static std::string_view linha = "_______________________________________________________________________________________\n";

void CSimuladorPerdaCargaCirculacaoFluidos::Cabecalho(ostream& os) {
    os <<
     "---------------------------------------------------------------------------------------\n"
     "|             UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE - DARCY RIBEIRO               |\n"
     "|                       CENTRO DE CIENCIAS E TECNOLOGIA - CCT                         |\n"
     "|             LABORATORIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP              |\n"
     "|                     DISCIPLINA: PROPRAMACAO PRATICA - PROJETO C++                   |\n"
     "|                           PROFESSOR: ANDRE DUARTE BUENO                             |\n"
     "|                        ALUNO: ROBERT ALEPHY SOUZA DA SILVA                          |\n"
     "|     PROGRAMA PARA CALCULO DE PROPRIEDADES REOLOGICAS DE FLUIDOS DE PERFURACAO,      |\n"
     "|              VELOCIDADE CRITICA E PERDAS DE CARGA EM POCOS DE PETROLEO              |\n"
     "|                                     Versao: 0.8                                     |\n"
     "---------------------------------------------------------------------------------------" << endl;
}

void CSimuladorPerdaCargaCirculacaoFluidos::CriarAmostra() {
    /// Objeto CAmostraFluido.
    amostra = make_shared<CAmostraFluido>();
    amostra->EntradaDeDados(cout, cin);
    amostra->SaidaDeDados(cout);
}

void CSimuladorPerdaCargaCirculacaoFluidos::CriarExperimentoViscosimetro() {
/// Objeto CExperimentoViscosimetroFan35A.
    eviscosimetro = make_shared<CExperimentoViscosimetroFan35A>();
    eviscosimetro->EntradaDeDados(cout, cin);
    eviscosimetro->SaidaDeDados(cout);
}

void CSimuladorPerdaCargaCirculacaoFluidos::CriarPoco() {                                         /// Objeto CPoco.
    poco = make_shared<CPoco>();
    poco->EntradaDeDados(cout, cin);
    poco->SaidaDeDados(cout);
}

//  Solicita ao usuario a escolha do calculo de propriedades para fluidos Binghamianos ou de Potência
//  Usa polimorfismo nesta definicao.
void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoFluido() {
    char respUsuario = '1';
    do {
        cout << linha
             << "Informe o modelo de escoamento:\n"
             << " Fluidos Binghamianos.......................................(1)\n"
             << "  Viscosidade Aparente, Plastica e Limite de Escoamento\n"
             << " Fluidos de Potencia........................................(2)\n"
             << "  Indice de Comportamento e Consistencia                        : ";
        cin >> respUsuario;        cin.get(); // bueno - retira do teclado a tecla enter
        tipoFluido = static_cast<TipoFluido>(respUsuario);
    } while ((tipoFluido != TipoFluido::Binghamianos) && (tipoFluido != TipoFluido::DePotencia));
}

///  Solicita ao usuario a escolha do local onde irá calcular a perda de carga e velocidade.
void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoCirculacao() {
    char respUsuario = '1';
    do {
        cout << linha
             << "Informe onde calcular a perda de carga e a velocidades:\n"
             << " Interior de Tubos.................(1)\n"
             << " Espaco Anular.....................(2) : ";
        cin >> respUsuario; cin.get();
        tipoCirculacao = static_cast<TipoCirculacao>(respUsuario);
    } while ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao!= TipoCirculacao::EspacoAnular));
}

void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoUnidade() {
   char respUsuario = '1';
     do {
        cout <<  linha
             << "Informe a unidade que sera utilizada:\n"
             << " Sistema Internacional  [SI].......(1)\n"
             << " Unidades de Campo      [UC].......(2) : ";
        cin >> respUsuario; cin.get();
        tipoUnidade = static_cast<TipoUnidade>(respUsuario);
    } while ((tipoUnidade != TipoUnidade::SI) && (tipoUnidade!= TipoUnidade::UC));
}

void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoFluxo() {
    char respUsuario = '1';
    do {
        cout << linha
             << "Informe o regime de fluxo do fluido de perfuracao para o calculo da Perda de Carga\n"
             << " Fluxo Laminar.....................(1)\n"
             << " Fluxo Turbulento..................(2) :" ;
        cin >> respUsuario; cin.get();
        tipoFluxo = static_cast<TipoFluxo>(respUsuario);
    } while ((tipoFluxo != TipoFluxo::Laminar) && (tipoFluxo!= TipoFluxo::Turbulento));
}

void CSimuladorPerdaCargaCirculacaoFluidos::CriarModeloEscoamento() {
    if(poco ==  nullptr)
        CriarPoco();
    if(eviscosimetro ==  nullptr)
        CriarExperimentoViscosimetro();
    // Cria objeto modelo escoamento
    if(tipoFluido == TipoFluido::Binghamianos)
        modeloEscoamento = make_shared<CModeloEscoamentoFluidoBinghamiano>(poco, eviscosimetro);
    else if(tipoFluido == TipoFluido::DePotencia)
        modeloEscoamento = make_shared<CModeloEscoamentoFluidoDePotencia>(poco, eviscosimetro, tipoCirculacao);
    // switch(tipoFluido ) {
    //     case TipoFluido::Binghamianos:
    //         modeloEscoamento = make_shared<CIModeloEscoamentoFluidoBinghamiano>();
    //         break;
    //     case TipoFluido::DePotencia:
    //         modeloEscoamento = make_shared<CIModeloEscoamentoFluidoDePotencia>();
    //         break;
    // }
}

void CSimuladorPerdaCargaCirculacaoFluidos::PrepararSimulacao() {
    Cabecalho(cout);
    CriarAmostra();
    CriarExperimentoViscosimetro();
    CriarPoco();
    SelecaoTipoFluido();
    SelecaoTipoCirculacao();
    CriarModeloEscoamento();
    SelecaoTipoUnidade();
    SelecaoTipoFluxo();
}

void CSimuladorPerdaCargaCirculacaoFluidos::VisualizarDadosSimulacao() {
    std::cout <<  '\n' << linha << "Dados Amostra: ";
    amostra->SaidaDeDados(cout);
    std::cout <<  '\n' << linha << "Dados Viscosimetro: ";
    eviscosimetro->SaidaDeDados(cout);
    std::cout <<  '\n' << linha << "Dados Poco: ";
    poco->SaidaDeDados(cout);
    std::cout   <<  '\n' << linha << "Dados Simulacao: "
                <<  "\n Tipo Fluido      = " <<  modeloEscoamento->StringTipoFluido(tipoFluido)
                <<  "\n Tipo Unidade     = " <<  modeloEscoamento->StringTipoUnidade(tipoUnidade)
                <<  "\n Tipo Circulacao  = " <<  modeloEscoamento->StringTipoCirculacao(tipoCirculacao)
                <<  "\n Tipo Fluxo       = " <<  modeloEscoamento->StringTipoFluxo(tipoFluxo) <<  std::endl;
}

bool CSimuladorPerdaCargaCirculacaoFluidos::ExecutarSimulacao() {
    //Cabecalho(cout);
    //PrepararSimulacao();                                  //  cria objetos e define seleções
    eviscosimetro->CalculoPropriedades();                   //  calcula propriedades do Viscosimetro
    // realiza o pré processamto,  cálculo de variáveis necessárias de acordo com o modelo escolhido
    modeloEscoamento->PreProcessamento();                   //  passar tipoCirculacao?

    char calcularVelocidadeEPerdaDeCarga = 's';
    do {
        cout << linha << "Informe se deseja calcular a Velocidade Critica e a Perda de Carga? [s/n]\n" ;
        cin >> calcularVelocidadeEPerdaDeCarga; cin.get();
    } while ( (calcularVelocidadeEPerdaDeCarga != 'n') && (calcularVelocidadeEPerdaDeCarga != 'N')
            && (calcularVelocidadeEPerdaDeCarga != 's') && (calcularVelocidadeEPerdaDeCarga != 'S'));

if ((calcularVelocidadeEPerdaDeCarga == 's') || (calcularVelocidadeEPerdaDeCarga == 'S')) {
    SelecaoTipoUnidade();
    SelecaoTipoFluxo();

    std::tuple<TipoCirculacao,TipoUnidade> tuplaRespostas = std::make_tuple(tipoCirculacao, tipoUnidade );
    /// Calculando a Velocidade Critica para fluidos Binghamianos e de Potencia
    cout << linha <<  "Resultados para: " <<  modeloEscoamento->StringTipoFluido() << linha ;
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::SI)) {
        cout << "\nVelocidade Critica, interior de tubos, SI: " << modeloEscoamento->VelocidadeCritica_it_SI() << " m/s";
        if (tipoFluxo == TipoFluxo::Laminar)
            cout << "\nPerda de Carga, fluxo laminar, interior de tubos, SI: " << modeloEscoamento->PerdaDeCarga_fl_it_SI() << " Pa\n";
        else                                                //Turbulento
            cout << "\nPerda de Carga, fluxo turbulento, interior de tubos, SI: " << modeloEscoamento->PerdaDeCarga_ft_it_SI() << " Pa\n";
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::UC)) {
        cout << "\nVelocidade Critica, interior de tubos, UC: " << modeloEscoamento->VelocidadeCritica_it_UC() << " ft/min";
        if (tipoFluxo == TipoFluxo::Laminar)
            cout << "\nPerda de Carga, fluxo laminar, interior de tubos, UC: " << modeloEscoamento->PerdaDeCarga_fl_it_UC() << " psi\n";
        else                                                //Turbulento
            cout << "\nPerda de Carga, fluxo turbulento, interior de tubos, UC: " << modeloEscoamento->PerdaDeCarga_ft_it_UC() << " psi\n";
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::SI)) {
        cout << "\nVelocidade Critica, interior de tubos, SI: " << modeloEscoamento->VelocidadeCritica_ea_SI() << " m/s";
        if (tipoFluxo == TipoFluxo::Laminar)
            cout << "\nPerda de Carga, fluxo laminar, interior de tubos, SI: " << modeloEscoamento->PerdaDeCarga_fl_ea_SI() << " Pa\n";
        else                                                //Turbulento
            cout << "\nPerda de Carga, fluxo turbulento, interior de tubos, SI: " << modeloEscoamento->PerdaDeCarga_ft_ea_SI() << " Pa\n";
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::UC)) {
        cout << "\nVelocidade Critica, interior de tubos, UC: " << modeloEscoamento->VelocidadeCritica_ea_UC() << " ft/min";
        if (tipoFluxo == TipoFluxo::Laminar)
            cout << "\nPerda de Carga, fluxo laminar, interior de tubos, UC: " << modeloEscoamento->PerdaDeCarga_fl_ea_UC() << " psi\n";
        else                                                //Turbulento
            cout << "\nPerda de Carga, fluxo turbulento, interior de tubos, UC: " << modeloEscoamento->PerdaDeCarga_ft_ea_UC() << " psi\n";
        }
    }
    return 0;
}

bool CSimuladorPerdaCargaCirculacaoFluidos::Menu() {
    char respUsuario = 9;
    do {
    cout    <<  linha <<  "Qual opcao?\n" <<  linha
            <<  "Criar Amostra.................................(1)\n"
            <<  "Criar Experimento Viscosimetro................(2)\n"
            <<  "Criar Poco....................................(3)\n"
            <<  "Selecao Tipo Fluido...........................(4)\n"
            <<  "Selecao Tipo Circulacao.......................(5)\n"
            <<  "Selecao Tipo Unidade..........................(6)\n"
            <<  "Selecao Tipo Fluxo............................(7)\n"
            <<  "Preparar Simulacao(executa 1-7)...............(8)\n"
            <<  "Visualizar Dados Simulacao....................(9)\n"
            <<  "Executar Simulacao............................(0)\n"
            <<  "Sair..........................................(q): ";
    cin >> respUsuario; cin.get();
    switch (respUsuario) {
            case '1': CriarAmostra();                 break;
            case '2': CriarExperimentoViscosimetro(); break;
            case '3': CriarPoco();                    break;
            case '4': SelecaoTipoFluido();            break;
            case '5': SelecaoTipoCirculacao();        break;
            case '6': SelecaoTipoUnidade();           break;
            case '7': SelecaoTipoFluxo();             break;
            case '8': PrepararSimulacao();            break;
            case '9': VisualizarDadosSimulacao();     break;
            case '0': ExecutarSimulacao();            break;
            case 'q':
            case 'Q': return 0;                       break;
    }
    } while (respUsuario != 'q' and respUsuario != 'Q');
    return 0;
}
