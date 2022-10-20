#ifndef PESSOANAOVERIFICADA_H
#define PESSOANAOVERIFICADA_H
#include <string>
#include "Perfil.h"
using namespace std;;

class PessoaNaoVerificada : public Perfil {
public:
    PessoaNaoVerificada(string nome, int maximoDeContatos, int maximoDePostagens);
    virtual ~PessoaNaoVerificada();
protected:

private:
};

#endif // PESSOANAOVERIFICADA_H
