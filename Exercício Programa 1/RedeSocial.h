#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"

class RedeSocial {
public:
  RedeSocial ();
  virtual ~RedeSocial();

  virtual Perfil** getPerfis();
  virtual int getQuantidadeDePerfis();
  virtual bool adicionar(Perfil* perfil);
  virtual void imprimir();
  virtual void imprimirEstatisticas();

private:
  Perfil** perfis;
  const int capacidade = 100;
  int quantidadeDePerfis = 0;
};

#endif // REDESOCIAL_H
