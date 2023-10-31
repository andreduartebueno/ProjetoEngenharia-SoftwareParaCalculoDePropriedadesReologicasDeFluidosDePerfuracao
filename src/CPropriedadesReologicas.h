#ifndef CPropriedadesReologicas_h
#define CPropriedadesReologicas_h

/**
@brief Classe responsavel pelo calculo das propriedades reológicas para fluidos Binghamianos (Modelo de Bingham ou plastico ideal)
@class CPropriedadesReologicas
@file CPropriedadesReologicas.h
 */

class CPropriedadesReologicas {
 //Atributos
public:
    /// Viscosidade Aparente
    double visco_aparente;
    /// Viscosidade Plastica
    double visco_plastica;
    /// Limite de Escoamento
    double limite_escoamento;

//Metodos
public:
    /// Construtor default
    CPropriedadesReologicas() {};
    /// Destrutor
    ~CPropriedadesReologicas() {};

    /// Metodo que calcula a viscosidade aparente
    double Visco_aparente();
    /// Metodo que calcula a viscosidade plastica
    double Visco_plastica();
    /// Metodo que calcula o limite de escoamento
    double Limite_escoamento();

};

#endif // CPropriedadesReologicas_h
