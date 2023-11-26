#ifndef CAmostra_h
#define CAmostra_h

#include <iostream>
#include <string>

///  Representa uma amostra.
class CAmostra {

public:
    ///  identificador da amostra.
	std::string id;
	///  nome do pesquisador responsável pela descricao.
    std::string nomePesquisador;
    ///  descricao da amostra.
    std::string descricao;

    /// Metodo que solicita a entrada de dados do objeto.
    void EntradaDeDados(std::ostream& out, std::istream& in);
    /// Método que mostra dados do objeto.
    void SaidaDeDados(std::ostream& out);
    /// Método que salva dados do objeto em disco.
    void SaidaDeDadosDisco(std::ostream& out);
};
#endif

