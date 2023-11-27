#include <string_view>
#include "CAmostraFluido.h"

static std::string_view linha = "\n_________________________________\n";

void CAmostraFluido::EntradaDeDados(std::ostream& out, std::istream& in){
    out <<  linha
		<<  "Atributos CAmostraFluido:";
    CAmostra::EntradaDeDados(out, in);
    out << " Digite um nome para identificar o fluido de perfuracao.\n";
    out << " Sugestao --> Base do fluido_ + Numeracao_ + Parametros a serem analisados.\n";
    out << " Exemplo: FBA_07_Salinidade :";
    getline(in, nomeFluido);
    out << " Digite o valor da temperatura do fluido (em Fahrenheit): ";
    in >> temperatura;
    out  << " Digite o valor do pH (Potencial Hidrogenioco): ";
    in >> ph;
    out  << " Digite o valor da estabilidade eletrica (em Volts): ";
    in >> estabilidadeEletrica;
    //  densidade
}

void CAmostraFluido::SaidaDeDados(std::ostream& out){
    out <<  linha
		<<  "Atributos CAmostraFluido:";
    CAmostra::SaidaDeDados(out);
	out <<  "\nnomeFluido = "          <<  nomeFluido;
	out <<  "\ntemperatura = "         <<  temperatura;
	out <<  "\nph = "                  <<  ph;
	out <<  "\nestabilidadeEletrica = "<<  estabilidadeEletrica;
}

void CAmostraFluido::SaidaDeDadosDisco(std::ostream& out){
    CAmostra::SaidaDeDadosDisco(out);
	out <<  ' ' <<  nomeFluido <<  ' ' <<  temperatura <<  ' ' <<  ph <<' ' <<  estabilidadeEletrica;
    //  densidade
}
