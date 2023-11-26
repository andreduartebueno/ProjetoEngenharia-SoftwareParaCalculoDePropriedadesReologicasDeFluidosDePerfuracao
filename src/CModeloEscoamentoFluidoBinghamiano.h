#ifndef CModeloEscoamentoFluidoBinghamiano_h
#define CModeloEscoamentoFluidoBinghamiano_h

#include "CIModeloEscoamentoFluido.h"

///  Representa o modelo de escoamento de fluidos Binghamiano, calcula a perda de carga e a velocidade critica.
class CModeloEscoamentoFluidoBinghamiano : public CIModeloEscoamentoFluido {
///Atributos
private:
   /// Viscosidade Aparente
   double viscosidadeAparente;
   /// Viscosidade Plastica
   double viscosidadePlastica;
   /// Limite de Escoamento
   double limiteEscoamento;


/// Métodos
public:
   /// Construtor.
   CModeloEscoamentoFluidoBinghamiano(std::shared_ptr<CPoco> _poco, std::shared_ptr<CExperimentoViscosimetroFan35A> _eviscosimetro)
      : CIModeloEscoamentoFluido(_poco, _eviscosimetro) {}

   /// Metodo que calcula a viscosidade aparente.
   double ViscosidadeAparente();

   /// Metodo que calcula a viscosidade plastica.
   double ViscosidadePlastica();

   /// Metodo que calcula o limite de escoamento.
   double LimiteEscoamento();

   ///  Retorna tipo de fluido.
   std::string_view StringTipoFluido() override { return "Fluido Binghamiano"; };

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
