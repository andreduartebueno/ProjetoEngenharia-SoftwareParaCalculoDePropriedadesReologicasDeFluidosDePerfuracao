#include <string_view>
#include "CAmostra.h"

static std::string_view linha = "_________________________________\n";

void CAmostra::EntradaDeDados(std::ostream& out, std::istream& in){
    //out <<  linha;
		//<<  "Atributos CAmostra:\n"
	out	<<  " Entre com o identificador da amostra (id): ";
    getline(in, id);
	out <<  " Entre com o nome do responsável pela descricao (nomePesquisador): ";
    getline(in, nomePesquisador);
	out <<  " Entre com a descricao da amostra (descricao): ";
    getline(in, descricao);
}

void CAmostra::SaidaDeDados(std::ostream& out){
    out <<  linha
		<<  "Atributos CAmostra:"
		<<  "\n id = " <<  id
		<<  "\n nomePesquisador = " <<  nomePesquisador
		<<  "\n descricao = " <<  descricao <<  std::endl;
}

void CAmostra::SaidaDeDadosDisco(std::ostream& out){
	out <<  id <<  ' ' <<  nomePesquisador <<  ' ' <<  descricao;
}
