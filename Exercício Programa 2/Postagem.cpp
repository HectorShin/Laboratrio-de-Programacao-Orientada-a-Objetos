#include "Postagem.h"
#include <iostream>

Postagem::Postagem(string texto, int data, Perfil* autor):
texto (texto), data (data), autor (autor){
}

Postagem::~Postagem() {
    cout << "Destrutor de postagem: " << texto << endl;
}

string Postagem::getTexto() {
    return texto;
}

int Postagem::getData() {
    return data;
}

Perfil* Postagem::getAutor() {
    return autor;
}

void Postagem::imprimir() {
    cout << "Texto: " << texto << " - Data: " << data << " - Autor: " << autor->getNome() << endl;
}
