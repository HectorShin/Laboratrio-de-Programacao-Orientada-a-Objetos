#include "Perfil.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

int Perfil::ultimoId = 0;

Perfil::Perfil(string nome):
nome (nome) {
    contatos = new vector<Perfil*>();
    postagens = new list<Postagem*>();
    Perfil::ultimoId += 1;
    id = Perfil::ultimoId;
}

Perfil::Perfil(int id, string nome):
id (id), nome (nome) {
    contatos = new vector<Perfil*>();
    postagens = new list<Postagem*>();
}


Perfil::~Perfil() {
    cout << "Destrutor de perfil: " << nome << " - Quantidade de postagens feitas: " << postagens->size() << endl;
    while (!postagens->empty()) {
        Postagem* ultimo = postagens->front();
        postagens->pop_front();
        delete ultimo;
    }
    /*
    for (int i = 0; i < quantidadeDePostagens; i++) {
        delete postagens[i];
    } */
    delete postagens;
    delete[] contatos;
    cout << "Perfil deletado" << endl;
}


void Perfil::adicionar(Perfil *contato) { //adicionar contato
    if (contato == this) {
        throw new invalid_argument ("Perfil adicionando ele mesmo");
    }
    else {
        for (int i = 0; i < contatos->size(); i++) {
            if ((*contatos)[i] == contato) {
                throw new invalid_argument ("Perfil ja adicionado");
            }
        }
        try {
        contatos->push_back(contato);
        contato->adicionar(this);
        }
        catch (invalid_argument *e) {
        }
    }
}


void Perfil::adicionar(Postagem* p) { //adicionar postagem
    postagens->push_back(p);
}

/*
void Perfil::imprimir() {
    cout << endl << "Nome: " << nome << endl;
    cout << "Numero de postagens feitas: " << quantidadeDePostagens << endl;
    for (int i = 0; i < quantidadeDePostagens; i++)
        cout << "Postagens na data: " << postagens[i]->getData()
             << " - Texto: " << postagens[i]->getTexto() << endl;
    if (quantidadeDeContatos == 0)
        cout << "Sem contatos " << endl;
    else {
        for (int i = 0; i < quantidadeDeContatos; i++) {
            for (int j = 0; j < contatos[i]->getQuantidadeDePostagens(); j++)
                cout << "Postagens na data " << contatos[i]->getPostagens()[j]->getData()
                     << " do contato "<< contatos[i]->getNome()
                     << " - Texto: " << contatos[i]->getPostagens()[j]->getTexto() << endl;
        }
    }
}
*/

string Perfil::getNome() {
    return nome;
}

/*int Perfil::getQuantidadeDeContatos() {
    return quantidadeDeContatos;
}*/

vector<Perfil*>* Perfil::getContatos() {
    return contatos;
}

list<Postagem*>* Perfil::getPostagens() {
    return postagens;
}

list<Postagem*>* Perfil::getPostagensDosContatos(int data) {
    list<Postagem*>* postagensDosContatos = new list<Postagem*>();
    for (int i = 0; i < contatos->size(); i++) {
        list<Postagem*>::iterator j = (*contatos)[i]->getPostagens()->begin();
        while (j != (*contatos)[i]->getPostagens()->end()) {
            if ((*j)->getData() <= data && (*j)->getData() >= data - 3) {
                postagensDosContatos->push_back(*j);
            }
            j++;
        }
    }
    /*
    for (int i = data; i >= data - 3; i--) {
        for (int j = 0; j < quantidadeDeContatos; j++) {
            for (int k = 0; k < contatos[j]->quantidadeDePostagens; k++) {
                if (contatos[j]->postagens[k]->getData() == i) {
                    postagensDosContatos[quantidade] = contatos[j]->postagens[k];
                    quantidade += 1;
                }
            }
        }
    }
    */
    return postagensDosContatos;
}

list<Postagem*>* Perfil::getPostagensDosContatos() {
    list<Postagem*>* postagensDosContatos = new list<Postagem*>();
    for (int i = 0; i < contatos->size(); i++) {
        postagensDosContatos->insert(postagensDosContatos->end(), (*contatos)[i]->getPostagens()->begin(), (*contatos)[i]->getPostagens()->end());
    }
    return postagensDosContatos;
}

int Perfil::getId() {
    return id;
}

int Perfil::getUltimoId() {
    return Perfil::ultimoId;
}

void Perfil::setUltimoId(int ultimoId) {
    Perfil::ultimoId = ultimoId;
}
