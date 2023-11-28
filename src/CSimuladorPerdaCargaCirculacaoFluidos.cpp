//  Dados inconsistentes estao travando o programa/bug;
//  Tarefa: verificar cálculos e definir forma de tratamento deste bug.
//  Hipótese inicial é criar uma funçao de saída alertando que dados inconsistentes geram bug.

#include <string>
#include <string_view>
#include <tuple>
#include <memory>

#include "CSimuladorPerdaCargaCirculacaoFluidos.h"

using namespace std;

static std::string_view linha =
    "-------------------------------------------------------------------------------------------\n";

static std::string_view cabecalho =
     "-------------------------------------------------------------------------------------------\n"
     "|               UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE - DARCY RIBEIRO                  |\n"
     "|                         CENTRO DE CIENCIAS E TECNOLOGIA - CCT                            |\n"
     "|               LABORATORIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP                 |\n"
     "|                       DISCIPLINA: PROPRAMACAO PRATICA - PROJETO C++                      |\n"
     "|                             PROFESSOR: ANDRE DUARTE BUENO                                |\n"
     "|                          ALUNO: ROBERT ALEPHY SOUZA DA SILVA                             |\n"
     "|       SIMULADOR PARA CALCULO DE PROPRIEDADES REOLOGICAS DE FLUIDOS DE PERFURACAO,        |\n"
     "|                VELOCIDADE CRITICA E PERDAS DE CARGA EM POCOS DE PETROLEO                 |\n"
     "|                                       Versao: 0.8                                        |\n"
     "-------------------------------------------------------------------------------------------" ;

void CSimuladorPerdaCargaCirculacaoFluidos::Cabecalho(ostream& os) {
    os << cabecalho << endl;
}

//  ============================================================== Simulacao reologia
void CSimuladorPerdaCargaCirculacaoFluidos::CriarAmostraFluido() {
    /// Objeto CAmostraFluido.
    amostraFluido = make_shared<CAmostraFluido>();
    amostraFluido->EntradaDeDados(cout, cin);
    amostraFluido->SaidaDeDados(cout);
    //  Como alterou a amostra precisa invalidar a simulacaoReologiaAtualizada
    simulacaoReologiaAtualizada = false;
    simulacaoFluxoAtualizada = false;
}

void CSimuladorPerdaCargaCirculacaoFluidos::CriarExperimentoViscosimetro() {
/// Objeto CExperimentoViscosimetroFan35A.
    eviscosimetro = make_shared<CExperimentoViscosimetroFan35A>();
    eviscosimetro->EntradaDeDados(cout, cin);
    eviscosimetro->SaidaDeDados(cout);
    //  Como alterou o eviscosimetro precisa invalidar resultados simulacaoReologiaAtualizada
    simulacaoReologiaAtualizada = false;
    simulacaoFluxoAtualizada = false;
}

void CSimuladorPerdaCargaCirculacaoFluidos::PrepararSimulacaoReologia() {
    CriarAmostraFluido();
    CriarExperimentoViscosimetro();
}

void CSimuladorPerdaCargaCirculacaoFluidos::VisualizarDadosSimulacaoReologia() {
    std::cout <<  '\n' << linha << "Dados Amostra:\n";
    amostraFluido->SaidaDeDados(cout);
    std::cout <<  '\n' << linha << "Dados Viscosimetro:\n";
    eviscosimetro->SaidaDeDados(cout);
}

bool CSimuladorPerdaCargaCirculacaoFluidos::ExecutarSimulacaoReologia() {
    std::cout << "\n Calculando resultados reologia";
    eviscosimetro->CalcularResultadosReologia();
    eviscosimetro->SaidaDeDadosTabelaResultadosReologia(cout);
    simulacaoReologiaAtualizada = true;
    return 1;
}

void CSimuladorPerdaCargaCirculacaoFluidos::VisualizarResultadosSimulacaoReologia() {
    //  Se amostra ou Viscosimetro foram alterados precisa reexecutar a simulacao
    if (simulacaoReologiaAtualizada == false) {
        std::cout <<  "\n********************** Advertencia **********************"
                      "\nApresenta-se a seguir os resultados de simulacao antiga,"
                      "\npois o objeto amostraFluido ou eviscosimetro foi alterado.\n"
                      "\nPara dados atualizados é necessário realizar a simulacao de reologia\n";
    }
    eviscosimetro->SaidaDeDadosTabelaResultadosReologia(cout);
}

//  ==============================================================  Simulacao fluxo
void CSimuladorPerdaCargaCirculacaoFluidos::CriarPoco() {                                         /// Objeto CPoco.
    poco = make_shared<CPoco>();
    poco->EntradaDeDados(cout, cin);
    poco->SaidaDeDados(cout);
    simulacaoFluxoAtualizada = false;
}

//  Solicita ao usuario a escolha do calculo de propriedades para fluidos Binghamianos ou de Potência
//  Usa polimorfismo nesta definicao.
void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoFluido() {
    char respUsuario = '1';
    TipoFluido tipoFluidoAntes = tipoFluido;
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
    if( tipoFluidoAntes !=  tipoFluido)
        simulacaoFluxoAtualizada = false;
}

///  Solicita ao usuario a escolha do local onde irá calcular a perda de carga e velocidade.
void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoCirculacao() {
    char respUsuario = '1';
    TipoCirculacao tipoCirculacaoAntes = tipoCirculacao;
    do {
        cout << linha
             << "Informe onde calcular a perda de carga e a velocidades:\n"
             << " Interior de Tubos.................(1)\n"
             << " Espaco Anular.....................(2) : ";
        cin >> respUsuario; cin.get();
        tipoCirculacao = static_cast<TipoCirculacao>(respUsuario);
    } while ((tipoCirculacao != TipoCirculacao::InteriorDeTubos) && (tipoCirculacao!= TipoCirculacao::EspacoAnular));
    if( tipoCirculacaoAntes !=  tipoCirculacao)
        simulacaoFluxoAtualizada = false;
}

void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoUnidade() {
    char respUsuario = '1';
    TipoUnidade tipoUnidadeAntes = tipoUnidade;
     do {
        cout <<  linha
             << "Informe a unidade que sera utilizada:\n"
             << " Sistema Internacional  [SI].......(1)\n"
             << " Unidades de Campo      [UC].......(2) : ";
        cin >> respUsuario; cin.get();
        tipoUnidade = static_cast<TipoUnidade>(respUsuario);
    } while ((tipoUnidade != TipoUnidade::SI) && (tipoUnidade!= TipoUnidade::UC));
    if( tipoUnidadeAntes !=  tipoUnidade)
        simulacaoFluxoAtualizada = false;
}

void CSimuladorPerdaCargaCirculacaoFluidos::SelecaoTipoFluxo() {
    char respUsuario = '1';
    TipoFluxo tipoFluxoAntes = tipoFluxo;
    do {
        cout << linha
             << "Informe o regime de fluxo do fluido de perfuracao para o calculo da Perda de Carga\n"
             << " Fluxo Laminar.....................(1)\n"
             << " Fluxo Turbulento..................(2) :" ;
        cin >> respUsuario; cin.get();
        tipoFluxo = static_cast<TipoFluxo>(respUsuario);
    } while ((tipoFluxo != TipoFluxo::Laminar) && (tipoFluxo!= TipoFluxo::Turbulento));
    if( tipoFluxoAntes !=  tipoFluxo)
        simulacaoFluxoAtualizada = false;
}


void CSimuladorPerdaCargaCirculacaoFluidos::CriarModeloEscoamento() {
    if( amostraFluido == nullptr )
        CriarAmostraFluido();
    if( poco == nullptr )
        CriarPoco();
    if( eviscosimetro == nullptr )
        CriarExperimentoViscosimetro();
        // CalcularResultadosReologia();
    //  Destroi objeto modelo antigo se existia
    if( modeloEscoamento !=  nullptr )
        modeloEscoamento.reset();
    // Cria objeto modelo escoamento de acordo com tipo de fluido
    if( tipoFluido == TipoFluido::Binghamianos )
        modeloEscoamento = make_shared<CModeloEscoamentoFluidoBinghamiano>(poco, eviscosimetro);
    else if( tipoFluido == TipoFluido::DePotencia )
        modeloEscoamento = make_shared<CModeloEscoamentoFluidoDePotencia>(poco, eviscosimetro, tipoCirculacao);
    simulacaoFluxoAtualizada = false;
}

void CSimuladorPerdaCargaCirculacaoFluidos::PrepararSimulacaoFluxo() {
    //Cabecalho(cout);
    CriarAmostraFluido();
    CriarExperimentoViscosimetro();
    CriarPoco();
    SelecaoTipoFluido();
    SelecaoTipoCirculacao();
    CriarModeloEscoamento();
    SelecaoTipoUnidade();
    SelecaoTipoFluxo();
}

void CSimuladorPerdaCargaCirculacaoFluidos::VisualizarDadosSimulacaoFluxo() {
    std::cout <<  '\n' << linha << "Dados Amostra:\n";
    amostraFluido->SaidaDeDados(cout);
    std::cout <<  '\n' << linha << "Dados Viscosimetro:\n";
    eviscosimetro->SaidaDeDados(cout);
    //eviscosimetro->CalcularResultadosReologia();
    //eviscosimetro->SaidaDeDadosTabelaResultadosReologia(cout);
    std::cout <<  '\n' << linha << "Dados Poco:\n";
    poco->SaidaDeDados(cout);
    std::cout   <<  '\n' << linha << "Dados Simulacao:\n"
                <<  "\n Tipo Fluido      = " <<  modeloEscoamento->StringTipoFluido(tipoFluido)
                <<  "\n Tipo Unidade     = " <<  modeloEscoamento->StringTipoUnidade(tipoUnidade)
                <<  "\n Tipo Circulacao  = " <<  modeloEscoamento->StringTipoCirculacao(tipoCirculacao)
                <<  "\n Tipo Fluxo       = " <<  modeloEscoamento->StringTipoFluxo(tipoFluxo) <<  std::endl;
}

bool CSimuladorPerdaCargaCirculacaoFluidos::ExecutarSimulacaoFluxo() {
    //PrepararSimulacao();                                  //  cria objetos e define seleções
    cout << "\n -> Calculando propriedades reologicas usando Viscosimetro Fann modelo 35A\n";
    eviscosimetro->CalcularResultadosReologia();                 //  calcula propriedades do Viscosimetro
    //eviscosimetro->SaidaDeDados(cout);
    //eviscosimetro->SaidaDeDadosTabelaResultadosReologia(cout);

    // realiza o pré processamto,  cálculo de variáveis necessárias de acordo com o modelo escolhido
    cout << "\n -> Calculando propriedades auxiliares do modelo de escoamento\n";
    modeloEscoamento->PreProcessamento();

    cout << "\n -> Calculando velocidade crítica e perda de carga\n";
    std::tuple<TipoCirculacao,TipoUnidade> tuplaRespostas = std::make_tuple(tipoCirculacao, tipoUnidade );
    /// Calculando a Velocidade Critica para fluidos Binghamianos e de Potencia
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::SI)) {
        modeloEscoamento->VelocidadeCritica_it_SI();
        if (tipoFluxo == TipoFluxo::Laminar)
            modeloEscoamento->PerdaDeCarga_fl_it_SI();
        else                                                //Turbulento
            modeloEscoamento->PerdaDeCarga_ft_it_SI();
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::UC)) {
        modeloEscoamento->VelocidadeCritica_it_UC();
        if (tipoFluxo == TipoFluxo::Laminar)
            modeloEscoamento->PerdaDeCarga_fl_it_UC();
        else                                                //Turbulento
            modeloEscoamento->PerdaDeCarga_ft_it_UC();
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::SI)) {
        modeloEscoamento->VelocidadeCritica_ea_SI();
        if (tipoFluxo == TipoFluxo::Laminar)
            modeloEscoamento->PerdaDeCarga_fl_ea_SI();
        else                                                //Turbulento
            modeloEscoamento->PerdaDeCarga_ft_ea_SI();
        }
    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::UC)) {
        modeloEscoamento->VelocidadeCritica_ea_UC() ;
        if (tipoFluxo == TipoFluxo::Laminar)
            cout << modeloEscoamento->PerdaDeCarga_fl_ea_UC();
        else                                                //Turbulento
            cout << modeloEscoamento->PerdaDeCarga_ft_ea_UC();
        }
    VisualizarResultadosSimulacaoFluxo();
    return 0;
}

void CSimuladorPerdaCargaCirculacaoFluidos::VisualizarResultadosSimulacaoFluxo() {
    if ( simulacaoFluxoAtualizada == false) {
        std::cout <<  "\n********************** Advertencia **********************"
                      "\nApresenta-se a seguir os dados de simulacao antiga,"
                      "\npois ocorreram alterações em dados usados na simulacao."
                      "\nObjetos utilizados:"
                      "\n amostraFluido, eviscosimetro,  poco"
                      "\nPropriedades utilizadas:"
                      "\n tipoFluido,  tipoUnidade,  tipoCirculacao,  tipoFluxo"
                      "\nPara dados atualizados é necessário realizar a simulacao de fluxo\n";
    }
    std::cout   <<  "\nResultados da simulacao de fluxo para:"
                <<  "\n Tipo Fluido      = " <<  modeloEscoamento->StringTipoFluido(tipoFluido)
                <<  "\n Tipo Unidade     = " <<  modeloEscoamento->StringTipoUnidade(tipoUnidade)
                <<  "\n Tipo Circulacao  = " <<  modeloEscoamento->StringTipoCirculacao(tipoCirculacao)
                <<  "\n Tipo Fluxo       = " <<  modeloEscoamento->StringTipoFluxo(tipoFluxo) <<  std::endl;

    std::tuple<TipoCirculacao,TipoUnidade> tuplaRespostas = std::make_tuple(tipoCirculacao, tipoUnidade );

    if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::SI)) {
        cout << "\n Velocidade Critica = " << modeloEscoamento->VelocidadeCriticaInterior()  << " m/s";
        cout << "\n Perda de Carga     = " << modeloEscoamento->PerdaDeCargaInterior()       << " Pa\n";
        }
    else if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::InteriorDeTubos, TipoUnidade::UC)) {
        cout << "\n Velocidade Critica = " << modeloEscoamento->VelocidadeCriticaInterior()  << " ft/min";
        cout << "\n Perda de Carga     = " << modeloEscoamento->PerdaDeCargaInterior()       << " psi\n";
        }
    else if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::SI)) {
        cout << "\n Velocidade Critica = " << modeloEscoamento->VelocidadeCriticaAnular()    << " m/s";
        cout << "\n Perda de Carga    = "  << modeloEscoamento->PerdaDeCargaAnular()         << " Pa\n";
        }
    else if ( tuplaRespostas  == std::make_tuple( TipoCirculacao::EspacoAnular, TipoUnidade::UC)) {
        cout << "\n Velocidade Critica = " << modeloEscoamento->VelocidadeCriticaAnular()    << " ft/min";
        cout << "\n Perda de Carga    = "  << modeloEscoamento->PerdaDeCargaAnular()         << " psi\n";
        }
}

/*
bool CSimuladorPerdaCargaCirculacaoFluidos::Menu() {
    char respUsuario = 9;
    do {
        Cabecalho(cout);
        cout<<  linha <<  "Menu simulacao:\n" <<  linha
            <<  "# Objetos - Criar/Alterar:\n"
            <<  "       Amostra.................................(1)\n"
            <<  "       Experimento Viscosimetro................(2)\n"
            <<  "       Poco....................................(3)\n"
            <<  "# Propriedades simulacao - Selecionar/Alterar:\n"
            <<  "       Tipo Fluido.............................(4)\n"
            <<  "       Tipo Circulacao.........................(5)\n"
            <<  "       Tipo Unidade............................(6)\n"
            <<  "       Tipo Fluxo..............................(7)\n"
            <<  "# Simulacao:\n"
            <<  "       Preparar (executa 1-7)..................(8)\n"
            <<  "       Visualizar Dados........................(9)\n"
            <<  "       Executar................................(0)\n"
            <<  "# Sair.........................................(q):\n"
            <<  "Qual opcao? : ";
    cin >> respUsuario; cin.get();
    switch (respUsuario) {
            case '1': CriarAmostraFluido();                 break;
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
}*/


bool CSimuladorPerdaCargaCirculacaoFluidos::Menu() {
    short int respUsuario = 9;
    do {
        Cabecalho(cout);
        cout<<  linha <<  "Menu :\n" <<  linha
            <<  "# === Etapa 1: Simulacao Reologia                         === \n"
            <<  "# Objetos - Criar/Alterar:\n"
            <<  "       Amostra Fluido..........................(1)\n"
            <<  "       Experimento Viscosimetro................(2)\n"
            <<  "# Simulacao Reologia:\n"
            <<  "       Preparar (executa 1-2)..................(3)\n"
            <<  "       Visualizar Dados .......................(4)\n"
            <<  "       Executar................................(5)\n"
            <<  "       Visualizar Resultados ..................(6)\n"
            <<  "\n"
            <<  "# === Etapa 2: Simulacao Fluxo - perda carga e velocidade === \n"
            <<  "# Objetos - Criar/Alterar:\n"
            <<  "       Poco....................................(7)\n"
            <<  "# Propriedades - Selecionar/Alterar:\n"
            <<  "       Tipo Fluido.............................(8)\n"
            <<  "       Tipo Circulacao.........................(9)\n"
            <<  "       Tipo Unidade............................(10)\n"
            <<  "       Tipo Fluxo..............................(11)\n"
            <<  "# Simulacao Fluxo:\n"
            <<  "       Preparar (executa 1,2,7,8,9,10,11)......(12)\n"
            <<  "       Visualizar Dados........................(13)\n"
            <<  "       Executar................................(14)\n"
            <<  "       Visualizar Resultados...................(15)\n"
            <<  "# Sair.........................................(16):\n"
            <<  "Qual opcao? : ";
    cin >> respUsuario; cin.get();
    switch (respUsuario) {
        //  Simulacao reologia
            case  1: CriarAmostraFluido();                break;
            case  2: CriarExperimentoViscosimetro();      break;
            case  3: PrepararSimulacaoReologia();         break;
            case  4: VisualizarDadosSimulacaoReologia();  break;
            case  5: ExecutarSimulacaoReologia();         break;
            case  6: VisualizarResultadosSimulacaoReologia();break;
        // Simulacao fluxo
            case  7: CriarPoco();                         break;
            case  8: SelecaoTipoFluido();                 break;
            case  9: SelecaoTipoCirculacao();             break;
            case 10: SelecaoTipoUnidade();                break;
            case 11: SelecaoTipoFluxo();                  break;
            case 12: PrepararSimulacaoFluxo();            break;
            case 13: VisualizarDadosSimulacaoFluxo();     break;
            case 14: ExecutarSimulacaoFluxo();            break;
            case 15: VisualizarDadosSimulacaoFluxo();     break;
            case 16: return 0;                            break;
    }
    } while (respUsuario != 'q' and respUsuario != 'Q');
    return 0;
}



