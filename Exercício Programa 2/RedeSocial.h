#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"
#include <vector>

class RedeSocial {
public:
  RedeSocial ();
  virtual ~RedeSocial();

  vector<Perfil*>* getPerfis();
  Perfil* getPerfil(int id);
  void adicionar(Perfil* perfil);
  void imprimir();
  void imprimirEstatisticas();

private:
  vector<Perfil*>* perfis;
};

#endif // REDESOCIAL_H
