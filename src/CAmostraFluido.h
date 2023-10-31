#ifndef CAmostraFluido_h
#define CAmostraFluido_h

#include <iostream>
#include <string>

class CAmostraFluido {
    ///Atributos
public:
    std::string nomearquivo;
    char opcao;
    char resp;

    ///Metodos
public:
    ///Construtor default
    CAmostraFluido() {};
    ///Destrutor
    ~CAmostraFluido() {};
    
    ///Metodo que solicita a entrada de dados
    void EntradadeDados();
    
};

#endif // CAmostraFluido_h
