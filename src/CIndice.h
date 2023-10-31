#ifndef CIndice_h
#define CIndice_h

/**
@brief Classe responsavel pelo calculo das propriedades para fluidos de Potência (Modelo de Ostwald de Waale)
@class CIndice
@file CIndice_h
 */

class CIndice {
//Atributos
public:
    /// Indice de comportamento para interior de tubos
    double n_it;
    /// Indice de comportamento para espaço anular
    double n_ea;
    /// Indice de consistencia para interior de tubos
    double k_it;
    /// Indice de consistencia para espaço anular
    double k_ea;
    
 ///Metodos
 public:
    /// Construtor default
    CIndice() {};
    /// Destrutor
    ~CIndice() {};

    /// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
    int N_it();
    /// Metodo que calcula o Indice de Comportamento para o Espaço Anular
    int N_ea();
    /// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
    int K_it();
    /// Metodo que calcula o Indice de Consistencia para o Espaço Anular
    int K_ea();

};

#endif // CIndice_h
