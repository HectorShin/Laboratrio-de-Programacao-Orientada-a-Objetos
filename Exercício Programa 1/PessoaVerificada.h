#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H
#include <string>
#include "Perfil.h"
using namespace std;;

class PessoaVerificada : public Perfil {
public:
    PessoaVerificada(string nome, string email, int maximoDeContatos, int maximoDePostagens);
    PessoaVerificada(string nome, int maximoDeContatos, int maximoDePostagens);
    virtual ~PessoaVerificada();

    string getEmail();
    void imprimir();

protected:

private:
    string email;
};

#endif // PESSOAVERIFICADA_H
