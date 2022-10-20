#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H
#include <string>
#include "Pessoa.h"
using namespace std;

class PessoaVerificada : public Pessoa {
public:
    PessoaVerificada(string nome, string email);
    PessoaVerificada(string nome);
    PessoaVerificada(int id, string nome, string email);
    virtual ~PessoaVerificada();

    string getEmail();
    void imprimir();

protected:

private:
    string email;
};

#endif // PESSOAVERIFICADA_H
