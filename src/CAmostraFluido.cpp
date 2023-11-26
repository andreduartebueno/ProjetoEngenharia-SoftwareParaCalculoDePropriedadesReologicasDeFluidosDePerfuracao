#include <string_view>
#include "CAmostraFluido.h"

static std::string_view linha = "\n_______________________________________________________________________________________ \n";

void CAmostraFluido::EntradaDeDados(std::ostream& out, std::istream& in){
    CAmostra::EntradaDeDados(out, in);
    out << "\nDigite um nome para identificar o fluido de perfuracao:";
    out << "\n[Sugestao --> Base do fluido_ + Numeracao_ + Parametros a serem analisados]";
    out << "\nExemplo: FBA_07_Salinidade\n:";
    getline(in, nomeFluido);
    out << "\nDigite o valor da temperatura do fluido (em Fahrenheit): ";
    in >> temperatura;
    out  << "\nDigite o valor do pH (Potencial Hidrogenioco): ";
    in >> ph;
    out  << "\nDigite o valor da estabilidade eletrica (em Volts): ";
    in >> estabilidadeEletrica;
    //  densidade
}

void CAmostraFluido::SaidaDeDados(std::ostream& out){
    CAmostra::SaidaDeDados(out);
	out <<  "\nnomeFluido = "          <<  nomeFluido;
	out <<  "\ntemperatura = "         <<  temperatura;
	out <<  "\nph = "                  <<  ph;
	out <<  "\nestabilidadeEletrica = " <<  estabilidadeEletrica;
}

void CAmostraFluido::SaidaDeDadosDisco(std::ostream& out){
    CAmostra::SaidaDeDadosDisco(out);
	out <<  ' ' <<  nomeFluido <<  ' ' <<  temperatura <<  ' ' <<  ph <<' ' <<  estabilidadeEletrica;
    //  densidade
}
