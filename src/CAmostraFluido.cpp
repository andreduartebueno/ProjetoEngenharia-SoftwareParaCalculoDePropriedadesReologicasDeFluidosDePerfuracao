#include <string_view>
#include "CAmostraFluido.h"

static std::string_view linha = "---------------------------------\n";

void CAmostraFluido::EntradaDeDados(std::ostream& out, std::istream& in) {
    out <<  linha
		<<  "Entrada atributos CAmostraFluido:\n";
    CAmostra::EntradaDeDados(out, in);
    out << " Entre com um nome para identificar o fluido de perfuracao.\n"
        << " Sugestao --> Base do fluido_ + Numeracao_ + Parametros a serem analisados.\n"
        << " Exemplo: FBA_07_Salinidade :";
    getline(in, nomeFluido);
    out << " Entre com o valor da temperatura do fluido (em Fahrenheit): ";
    in >> temperatura;
    out << " Entre com o valor do pH (Potencial Hidrogenioco): ";
    in >> ph;
    out << " Entre com o valor da estabilidade eletrica (em Volts): ";
    in >> estabilidadeEletrica;
    //  densidade
}

void CAmostraFluido::SaidaDeDados(std::ostream& out) {
    CAmostra::SaidaDeDados(out);
    out                                                     //<<  linha
		<<  "Atributos CAmostraFluido:";
	out <<  "\n nomeFluido = "          <<  nomeFluido
        <<  "\n temperatura = "         <<  temperatura
        <<  "\n ph = "                  <<  ph
        <<  "\n estabilidadeEletrica = "<<  estabilidadeEletrica << std::endl;
}

void CAmostraFluido::SaidaDeDadosDisco(std::ostream& out) {
    CAmostra::SaidaDeDadosDisco(out);
	out <<  ' ' <<  nomeFluido <<  ' ' <<  temperatura <<  ' ' <<  ph <<' ' <<  estabilidadeEletrica;
    //  densidade
}
