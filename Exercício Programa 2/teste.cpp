#include <iostream>
#include <string>
#include "Perfil.h"
#include "RedeSocial.h"
#include "Postagem.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Story.h"
#include "Pessoa.h"
#include "PersistenciaDaRede.h"
using namespace std;
/*
void imprimirRede (Perfil** perfis, int quantidade) {
    cout << "==================================" << endl;
    for (int i = 0; i < quantidade; i++) {
        perfis[i]->imprimir();
    }
}

void teste() {
    /*PessoaVerificada* ana = new PessoaVerificada("Ana", "ana@usp.br", 5);
    Pessoa* silvio = new Pessoa("Silvio", 5);
    Pagina* pcs3111 = new Pagina("PCS3111", ana, 5);

    RedeSocial* r = new RedeSocial();

    r->adicionar(ana);
    r->adicionar(silvio);
    r->adicionar(pcs3111);

    ana->adicionarContato(silvio);
    pcs3111->adicionarContato(silvio);

    Postagem* p1 = new Postagem("M1", 1, ana);
    Postagem* p2 = new Postagem("M2", 2, silvio);
    Postagem* p3 = new Postagem("M3", 3, pcs3111);

    ana->adicionarPostagem(p1);
    silvio->adicionarPostagem(p2);
    pcs3111->adicionarPostagem(p3);

    list<Postagem*>* postagensDosContatosDeSilvio = silvio->getPostagensDosContatos();
    list<Postagem*>::iterator i = postagensDosContatosDeSilvio->begin();
    while (i != postagensDosContatosDeSilvio->end()) {
        (*i)->imprimir();
        i++;
    }
    delete r;
    //cout << Perfil::getUltimoId();
    Perfil *p = new Pessoa("a");

    string r3 = p->getNome();
    p->adicionar(new Pessoa(3, "a"));
    p->adicionar(new Postagem("a", 1, p));
    list<Postagem*>* r4 = p->getPostagens();
    list<Postagem*>* r5 = p->getPostagensDosContatos();
    list<Postagem*>* r6 = p->getPostagensDosContatos(5);
    vector<Perfil*>* r1 = p->getContatos();
    p->imprimir();

    int r2 = p->getId();
    Perfil::getUltimoId();
    Perfil::setUltimoId(2);
}

int main() {
    teste();
    return 0;
}
*/
