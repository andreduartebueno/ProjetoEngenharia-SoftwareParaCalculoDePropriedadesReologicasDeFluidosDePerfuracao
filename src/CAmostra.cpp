#include <string_view>
#include "CAmostra.h"

static std::string_view linha = "\n_______________________________________________________________________________________ \n";

void CAmostra::EntradaDeDados(std::ostream& out, std::istream& in){
    out <<  linha <<  "Entre com o identificador da amostra: ";
    getline(in, id);
	out <<  "\nEntre com o nome do pesquisador responsável pela descricao: ";
    getline(in, nomePesquisador);
	out <<  "\nEntre com a descricao da amostra: ";
    getline(in, descricao);
}

void CAmostra::SaidaDeDados(std::ostream& out){
	out <<  "\nid = " <<  id;
	out <<  "\nnomePesquisador = " <<  nomePesquisador;
	out <<  "\ndescricao = " <<  descricao;
}

void CAmostra::SaidaDeDadosDisco(std::ostream& out){
	out <<  id <<  ' ' <<  nomePesquisador <<  ' ' <<  descricao;
}
