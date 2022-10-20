#include "RedeSocial.h"
#include <iostream>
#include "PessoaVerificada.h"
#include "PessoaNaoVerificada.h"
#include "Pagina.h"

Perfil** RedeSocial::getPerfis() {
    return perfis;
}

int RedeSocial::getQuantidadeDePerfis() {
    return quantidadeDePerfis;
}

bool RedeSocial::adicionar(Perfil* perfil) {
    if (quantidadeDePerfis < capacidade) {
        perfis[quantidadeDePerfis] = perfil;
        quantidadeDePerfis += 1;
        return true;
    }
    else return false;
}

RedeSocial::RedeSocial() {
    perfis = new Perfil*[capacidade];
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  for (int i = 0; i < quantidadeDePerfis ; i++) {
    delete perfis[i];
  }
  delete[] perfis;
  cout << "RedeSocial deletada " << endl;
}

void RedeSocial::imprimir() {
  cout << "==================================" << endl;
  cout << "Rede Social: " << quantidadeDePerfis << " perfis" << endl;
  cout << "==================================" << endl;
  if (quantidadeDePerfis == 0){
    cout << "Sem perfis" << endl;
    cout << "==================================" << endl;
  } else {
    for (int i = 0; i < quantidadeDePerfis; i++){
      perfis[i]->imprimir();
      cout << "==================================" << endl;
    }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas() {
    int quantidadeDePessoasNaoVerificadas = 0;
    int quantidadeDePessoasVerificadas = 0;
    int quantidadeDePaginas = 0;
    int quantidadeDePerfis = 0;
    for (int i = 0; i < this->quantidadeDePerfis; i++) {
        if (dynamic_cast<PessoaNaoVerificada*>(perfis[i]) != NULL) {
            quantidadeDePessoasNaoVerificadas += 1;
        }
        else if (dynamic_cast<PessoaVerificada*>(perfis[i]) != NULL) {
            quantidadeDePessoasVerificadas += 1;
        }
        else if (dynamic_cast<Pagina*>(perfis[i]) != NULL) {
            quantidadeDePaginas += 1;
        }
        else if (dynamic_cast<Perfil*>(perfis[i]) != NULL) {
            quantidadeDePerfis += 1;
        }
    }
    cout << "PessoaVerificada: " << quantidadeDePessoasVerificadas << endl
         << "PessoaNaoVerificada: " << quantidadeDePessoasNaoVerificadas << endl
         << "Pagina: " << quantidadeDePaginas << endl
         << "Perfil: " << quantidadeDePerfis << endl;
}
