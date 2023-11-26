#ifndef CAmostraFluido_h
#define CAmostraFluido_h

#include <iostream>
#include <string>
#include "CAmostra.h"

///  Representa uma amostra de fluido específica.
class CAmostraFluido :  public CAmostra {
	///  Nome do fluido
	std::string nomeFluido;
	///  temperatura do fluido.
	double temperatura;
	///  ph  do fluido.
	double ph;
	///  estabilidade eletrica do fluido.
	double estabilidadeEletrica;
	///  densidade do fluido.
	//double densidade;

public:
    /// Metodo que solicita a entrada de dados do objeto.
    void EntradaDeDados(std::ostream& out, std::istream& in);
    /// Método que mostra dados do objeto.
    void SaidaDeDados(std::ostream& out);
    /// Método que salva dados do objeto em disco.
    void SaidaDeDadosDisco(std::ostream& out);
};
#endif
