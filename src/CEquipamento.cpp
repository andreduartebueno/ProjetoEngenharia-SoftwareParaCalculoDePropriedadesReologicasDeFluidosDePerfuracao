#include <string_view>
#include "CEquipamento.h"

static std::string_view linha = "_________________________________\n";

void CEquipamento::EntradaDeDados(std::ostream& out, std::istream& in){
    //out <<  linha
	//	<<  "Atributos CEquipamento:\n";
    out << "Entre com o tipo de equipamento: ";
    getline(in, tipo);
    out  << "\nEntre com a marca do equipamento: ";
    getline(in, marca);
    out << "\nEntre com o modelo do equipamento: ";
    getline(in, modelo);
}

void CEquipamento::SaidaDeDados(std::ostream& out){
    out <<  linha
		<<  "Atributos CEquipamento:";
	out <<  "\ntipo = " 	<<  tipo
        <<  "\nmarca = " 	<<  marca
        <<  "\nmodelo = " 	<<  modelo <<  std::endl;
}

void CEquipamento::SaidaDeDadosDisco(std::ostream& out){
	out <<  tipo <<  ' ' <<  marca <<  ' ' <<  modelo;
    //  densidade
}
