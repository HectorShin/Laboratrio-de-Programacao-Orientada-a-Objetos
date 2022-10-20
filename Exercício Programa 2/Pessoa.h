#ifndef PESSOA_H
#define PESSOA_H
#include "Perfil.h"
#include <string>

class Pessoa : public Perfil {
public:
    Pessoa(string nome);
    Pessoa(int id, string nome);
    virtual ~Pessoa();

    void imprimir();
protected:

private:

};

#endif // PESSOA_H
