#include "Story.h"
#include <iostream>

Story::Story(string texto, int data, int dataDeFim, Perfil* autor) :
Postagem(texto, data, autor), dataDeFim (dataDeFim) {
    //ctor
}

Story::~Story()
{
    //dtor
}

int Story::getDataDeFim() {
    return dataDeFim;
}

void Story::imprimir() {
    cout << "Texto: " << texto << " - Data: " << data << " - Data De Fim: " << dataDeFim << " - Autor: " << autor->getNome() << endl;
}
