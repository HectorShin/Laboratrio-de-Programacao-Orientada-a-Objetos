#ifndef POSTAGEM_H
#define POSTAGEM_H
#include <string>
#include "Perfil.h"
using namespace std;;

class Perfil;

class Postagem {
protected:
    string texto;
    int data;
    Perfil *autor;

public:
    Postagem(string texto, int data, Perfil* autor);
    virtual ~Postagem();

    string getTexto();
    int getData();
    Perfil* getAutor();
    virtual void imprimir();
};

#endif // POSTAGEM_H
