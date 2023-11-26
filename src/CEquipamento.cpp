#include <string_view>
#include "CEquipamento.h"

static std::string_view linha = "\n_______________________________________________________________________________________ \n";

void CEquipamento::EntradaDeDados(std::ostream& out, std::istream& in){
    out <<  linha << "Digite o tipo de equipamento: ";
    getline(in, tipo);
    out  << "\nDigite a marca do equipamento: ";
    getline(in, marca);
    out << "\nDigite o modelo do equipamento: ";
    getline(in, modelo);
}

void CEquipamento::SaidaDeDados(std::ostream& out){
	out <<  "\ntipo = " 	<<  tipo;
	out <<  "\nmarca = " 	<<  marca;
	out <<  "\nmodelo = " 	<<  modelo;
}

void CEquipamento::SaidaDeDadosDisco(std::ostream& out){
	out <<  tipo <<  ' ' <<  marca <<  ' ' <<  modelo;
    //  densidade
}
