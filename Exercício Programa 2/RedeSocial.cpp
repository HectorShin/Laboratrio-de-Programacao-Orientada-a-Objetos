#include "RedeSocial.h"
#include <iostream>
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "PerfilInexistente.h"
#include <algorithm>

vector<Perfil*>* RedeSocial::getPerfis() {
    return perfis;
}

void RedeSocial::adicionar(Perfil* perfil) {
    vector<Perfil*>::iterator i;
    i = find(perfis->begin(), perfis->end(), perfil);
    if (i == perfis->end()) {
        perfis->push_back(perfil);
    }
    else throw new invalid_argument("Perfil ja adicionado na rede");
}

RedeSocial::RedeSocial() {
    perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << perfis->size() << " perfis" << endl;
  for (int i = 0; i < perfis->size() ; i++) {
    delete (*perfis)[i];
  }
  delete[] perfis;
  cout << "RedeSocial deletada " << endl;
}

void RedeSocial::imprimir() {
  cout << "==================================" << endl;
  cout << "Rede Social: " << perfis->size() << " perfis" << endl;
  cout << "==================================" << endl;
  if (perfis->size() == 0){
    cout << "Sem perfis" << endl;
    cout << "==================================" << endl;
  } else {
    for (int i = 0; i < perfis->size(); i++){
      (*perfis)[i]->imprimir();
      cout << "==================================" << endl;
    }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas() {
    int quantidadeDePessoas = 0;
    int quantidadeDePessoasVerificadas = 0;
    int quantidadeDePaginas = 0;
    int quantidadeDePerfis = 0;
    for (int i = 0; i < this->perfis->size(); i++) {
        if (dynamic_cast<Pessoa*>((*perfis)[i]) != NULL) {
            quantidadeDePessoas += 1;
        }
        else if (dynamic_cast<PessoaVerificada*>((*perfis)[i]) != NULL) {
            quantidadeDePessoasVerificadas += 1;
        }
        else if (dynamic_cast<Pagina*>((*perfis)[i]) != NULL) {
            quantidadeDePaginas += 1;
        }
        else {
            quantidadeDePerfis += 1;
        }
    }
    cout << "PessoaVerificada: " << quantidadeDePessoasVerificadas << endl
         << "Pessoa: " << quantidadeDePessoas << endl
         << "Pagina: " << quantidadeDePaginas << endl
         << "Perfil: " << quantidadeDePerfis << endl;
}

Perfil* RedeSocial::getPerfil (int id) {
    Perfil* perfilDesejado = NULL;
    for (int i = 0; i < perfis->size(); i++) {
        if ((*perfis)[i]->getId() == id) {
            perfilDesejado = (*perfis)[i];
        }
    }
    if (perfilDesejado == NULL) {
        throw new PerfilInexistente();
    }
    return perfilDesejado;
}

