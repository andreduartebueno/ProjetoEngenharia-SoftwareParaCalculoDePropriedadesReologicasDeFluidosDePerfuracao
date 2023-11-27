#include <string_view>
#include "CAmostra.h"

static std::string_view linha = "\n_________________________________\n";

void CAmostra::EntradaDeDados(std::ostream& out, std::istream& in){
    out <<  linha
		<<  "Atributos CAmostra:\n"
		<<  " Entre com o identificador da amostra (id): ";
    getline(in, id);
	out <<  " Entre com o nome do responsável pela descricao (nomePesquisador): ";
    getline(in, nomePesquisador);
	out <<  " Entre com a descricao da amostra (descricao): ";
    getline(in, descricao);
}

void CAmostra::SaidaDeDados(std::ostream& out){
    out <<  linha
		<<  "Atributos CAmostra:";
	out <<  "\nid = " <<  id;
	out <<  "\nnomePesquisador = " <<  nomePesquisador;
	out <<  "\ndescricao = " <<  descricao;
}

void CAmostra::SaidaDeDadosDisco(std::ostream& out){
	out <<  id <<  ' ' <<  nomePesquisador <<  ' ' <<  descricao;
}
