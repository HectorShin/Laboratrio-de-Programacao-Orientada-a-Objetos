#ifndef PAGINA_H
#define PAGINA_H
#include <string>
#include "Perfil.h"
#include "PessoaVerificada.h"
using namespace std;;

class Pagina : public Perfil{
public:
    Pagina(string nome, PessoaVerificada* proprietario, int maximoDeContatos, int maximoDePostagens);
    virtual ~Pagina();

    PessoaVerificada* getProprietario();
    void imprimir();
protected:

private:
    PessoaVerificada* proprietario;
};

#endif // PAGINA_H
