#include "Pessoa.h"
#include <iostream>
#include <list>
using namespace std;;

Pessoa::Pessoa(string nome) :
Perfil (nome) {
}

Pessoa::Pessoa(int id, string nome) :
Perfil (id, nome) {
}

Pessoa::~Pessoa()
{
    //dtor
}

void Pessoa::imprimir() {
    cout << endl << "Nome: " << nome << " - id: " << id << endl;
    cout << "Numero de postagens feitas: " << postagens->size() << endl;
    list<Postagem*>::iterator i = postagens->begin();
    while (i != postagens->end()) {
        cout << "Postagens na data " << (*i)->getData() << " - Texto: " << (*i)->getTexto() << endl;
        i++;
    }
    /*
    for (int i = 0; i < quantidadeDePostagens; i++)
        cout << "Postagens na data " << postagens[i]->getData()
             << " - Texto: " << postagens[i]->getTexto() << endl;
             */

    if (contatos->size() == 0)
        cout << "Sem contatos " << endl;
    else {
        for(int i = 0; i < contatos->size(); i++) {
            list<Postagem*>::iterator j = (*contatos)[i]->getPostagens()->begin();
            while (j != (*contatos)[i]->getPostagens()->end()) {
                cout << "Postagens na data " << (*j)->getData() << " do contato " << (*j)->getAutor()->getNome() << " - Texto: " << (*j)->getTexto() << endl;
                j++;
            }
            /*
            for(int j = 0; j < contatos[i]->getQuantidadeDePostagens(); j++)
                cout << "Postagens na data "
                     << contatos[i]->getPostagens()[j]->getData()
                     << " do contato " << contatos[i]->getNome()
                     << " - Texto: " << contatos[i]->getPostagens()[j]->getTexto()
                     << endl;
            }*/
        }
    }
}
