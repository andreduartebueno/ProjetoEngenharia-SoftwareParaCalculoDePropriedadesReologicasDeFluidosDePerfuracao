#ifndef CEquipamento_h
#define CEquipamento_h

#include <iostream>
#include <string>

/// Representa um squipamento. Como exemplo equipamento de laboratório ou computador.
class CEquipamento {
	///  tipo do equipamento.
	std::string tipo;
	///  marca do equipamento.
	std::string marca;
	/// modelo do equipamento.
	std::string modelo;

public:
	/// Construtor sobrecarregado.
	CEquipamento( std::string _marca,  std::string _modelo,  std::string _nome)
	  : tipo(_nome),  marca(_marca), modelo(_modelo) {}

    /// Metodo que solicita a entrada de dados do objeto.
    void EntradaDeDados(std::ostream& out, std::istream& in);
    /// Método que mostra dados do objeto.
    void SaidaDeDados(std::ostream& out);
    /// Método que salva dados do objeto em disco.
    void SaidaDeDadosDisco(std::ostream& out);
};
# endif
