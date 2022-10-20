#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#include "Postagem.h"
#include <list>
#include <vector>
using namespace std;;

class Postagem;

class Perfil{
protected:
    string nome;
    vector<Perfil*>* contatos;
    list<Postagem*>* postagens;
    int id;
private:
    static int ultimoId;
public:
    Perfil(string nome);
    Perfil(int id, string nome);
    virtual ~Perfil();

    string getNome();

    void adicionar(Perfil* contato); //adicionar contato
    void adicionar(Postagem* p); //adicionar postagem

    list<Postagem*>* getPostagens();
    list<Postagem*>* getPostagensDosContatos(int data);
    list<Postagem*>* getPostagensDosContatos();

    vector<Perfil*>* getContatos();
    //virtual int getQuantidadeDeContatos();

    virtual void imprimir() = 0;

    int getId();
    static void setUltimoId(int ultimoId);
    static int getUltimoId();
};

#endif // PERFIL_H
