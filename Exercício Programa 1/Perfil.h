#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#include "Postagem.h"
using namespace std;;

class Postagem;

class Perfil{
protected:
    string nome;
    int maximoDeContatos;
    int maximoDePostagens;
private:
    Perfil **contatos;
    Postagem **postagens;
    int quantidadeDeContatos = 0;
    int quantidadeDePostagens = 0;
public:
    Perfil(string nome, int maximoDeContatos, int maximoDePostagens);
    virtual ~Perfil();

    string getNome();

    virtual bool adicionarContato(Perfil* contato);
    virtual bool adicionarPostagem(Postagem* p);

    virtual Postagem** getPostagens();
    virtual Postagem** getPostagensDosContatos(int data, int &quantidade);
    virtual int getQuantidadeDePostagens();

    virtual Perfil** getContatos();
    virtual int getQuantidadeDeContatos();

    virtual void imprimir();
};

#endif // PERFIL_H
