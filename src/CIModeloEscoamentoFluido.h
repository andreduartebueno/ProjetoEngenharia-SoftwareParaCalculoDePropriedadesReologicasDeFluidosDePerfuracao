#ifndef CIModeloEscoamentoFluido_h
#define CIModeloEscoamentoFluido_h

#include <memory>
#include <string_view>
#include "CPoco.h"
#include "CExperimentoViscosimetroFan35A.h"

///  Representa o tipo de fluido.
enum class TipoFluido:     char { Binghamianos = '1',  DePotencia = '2' };
///  Representa o tipo de unidade física usada nos calculos.
enum class TipoUnidade:    char { SI = '1', UC= '2' };
///  Representa o tipo de circulacao.
enum class TipoCirculacao: char { InteriorDeTubos = '1', EspacoAnular= '2' };
///  Representa o tipo de fluxo.
enum class TipoFluxo:      char { Laminar = '1', Turbulento= '2' };

///  Representa uma classe de interface para modelo de escoamento de fluido.
class CIModeloEscoamentoFluido {

protected:
    ///  Acesso aos dados do CPoco.
    std::shared_ptr<CPoco> poco;
    ///  Acesso aos dados do CExperimentoViscosimetroFan35A.
    std::shared_ptr<CExperimentoViscosimetroFan35A> eviscosimetro;

    ///  Representa a perda de carga no interior da tubulacao.
	double perdaDeCargaInterior;
	///  Representa a perda de carga no anular da tubulacao.
	double perdaDeCargaAnular;
	///  Representa a velocidade critica no interior da tubulacao.
	double velocidadeCriticaInterior;
	///  Representa a velocidade critica no anular da tubulacao.
	double velocidadeCriticaAnular;

public:
    ///  Retorna tipo de fluido.
    virtual std::string_view StringTipoFluido() = 0;
    /// Realiza procedimento de pré-processamento,  calculando variaveis necessárias.
    virtual void PreProcessamento() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    virtual double PerdaDeCarga_fl_it_SI() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades de Campo
    virtual double PerdaDeCarga_fl_it_UC() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    virtual double PerdaDeCarga_fl_ea_SI() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades de Campo
    virtual double PerdaDeCarga_fl_ea_UC() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    virtual double PerdaDeCarga_ft_it_SI() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    virtual double PerdaDeCarga_ft_it_UC() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    virtual double PerdaDeCarga_ft_ea_SI() = 0;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    virtual double PerdaDeCarga_ft_ea_UC() = 0;

    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
    virtual double VelocidadeCritica_it_SI() = 0;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
    virtual double VelocidadeCritica_it_UC() = 0;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
    virtual double VelocidadeCritica_ea_SI() = 0;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
    virtual double VelocidadeCritica_ea_UC() = 0;

protected:
/// Construtor.
    CIModeloEscoamentoFluido(std::shared_ptr<CPoco> _poco, std::shared_ptr<CExperimentoViscosimetroFan35A> _eviscosimetro):
        poco(_poco), eviscosimetro(_eviscosimetro) {}
};
# endif
