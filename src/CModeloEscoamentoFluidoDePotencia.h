#ifndef CModeloEscoamentoFluidoDePotencia_h
#define CModeloEscoamentoFluidoDePotencia_h

#include "CIModeloEscoamentoFluido.h"

///  Representa o modelo de escoamento de fluidos de Potencia,  calcula a perda de carga e a velocidade critica.
class CModeloEscoamentoFluidoDePotencia : public CIModeloEscoamentoFluido {
///Atributos
private:
    //  ?
    //double x;
    //  ?
    //double y;
    /// Indice de comportamento para interior de tubos
    double n_it;
    /// Indice de comportamento para espaço anular
    double n_ea;
    /// Indice de consistencia para interior de tubos
    double k_it;
    /// Indice de consistencia para espaço anular
    double k_ea;
   ///  O tipo de circulacao do fluido (interior de tubos ou anular)
   TipoCirculacao tipoCirculacao;

/// Métodos
public:
   /// Construtor.
   CModeloEscoamentoFluidoDePotencia(std::shared_ptr<CPoco> _poco, std::shared_ptr<CExperimentoViscosimetroFan35A> _eviscosimetro,
                                       TipoCirculacao _tipoCirculacao)
      : CIModeloEscoamentoFluido(_poco, _eviscosimetro),  tipoCirculacao(_tipoCirculacao) {}

      /// Metodo que calcula o Indice de Comportamento para o Interior de Tubos
    double N_it();
    /// Metodo que calcula o Indice de Comportamento para o Espaço Anular
    double N_ea();
    /// Metodo que calcula o Indice de Consistencia para o Interior de Tubos
    double K_it();
    /// Metodo que calcula o Indice de Consistencia para o Espaço Anular
    double K_ea();

    ///  Retorna tipo de fluido.
    std::string_view StringTipoFluido() override { return "Fluido De Potencia"; };

    /// Realiza procedimento de pré-processamento,  calculando variaveis necessárias.
    void PreProcessamento() override;

    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades no Sistema Internacional
    double PerdaDeCarga_fl_it_SI() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no interior de tubos e unidades de Campo
    double PerdaDeCarga_fl_it_UC() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades no Sistema Internacional
    double PerdaDeCarga_fl_ea_SI() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo laminar, no espaço anular e unidades de Campo
    double PerdaDeCarga_fl_ea_UC() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double PerdaDeCarga_ft_it_SI() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double PerdaDeCarga_ft_it_UC() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades no Sistema Internacional
    double PerdaDeCarga_ft_ea_SI() override;
    /// Perda de Carga para Fluidos Binghamianos, com fluxo turbulento, no interior de tubos e unidades de Campo
    double PerdaDeCarga_ft_ea_UC() override;

    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades no Sistema Internacional
    double VelocidadeCritica_it_SI() override;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no interior de tubos e unidades de Campo
    double VelocidadeCritica_it_UC() override;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades no Sistema Internacional
    double VelocidadeCritica_ea_SI() override;
    /// Metodo para o calculo da Velocidade Crítica para Fluidos de Potência, no espaço anular e unidades de Campo
    double VelocidadeCritica_ea_UC() override;
};
#endif
