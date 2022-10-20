#include "Perfil.h"
#include <iostream>

Perfil::Perfil(string nome, int maximoDeContatos, int maximoDePostagens):
nome (nome), maximoDeContatos (maximoDeContatos), maximoDePostagens (maximoDePostagens) {
    contatos = new Perfil*[maximoDeContatos];
    postagens = new Postagem*[maximoDePostagens];
}

Perfil::~Perfil() {
    cout << "Destrutor de perfil: " << nome << " - Quantidade de postagens feitas: " << quantidadeDePostagens << endl;
    for (int i = 0; i < quantidadeDePostagens; i++) {
        delete postagens[i];
    }
    delete[] postagens;
    delete[] contatos;
    cout << "Perfil deletado" << endl;
}


bool Perfil::adicionarContato(Perfil *contato) {
    if (quantidadeDeContatos < maximoDeContatos && contato != this) {
        for (int i = 0; i < quantidadeDeContatos; i++) {
            if (contatos[i] == contato) {
                return false;
            }
        }
        contatos[quantidadeDeContatos] = contato;
        quantidadeDeContatos += 1;
        contato->adicionarContato(this);
        return true;
    }
    else return false;
}

bool Perfil::adicionarPostagem(Postagem* p) {
    if (quantidadeDePostagens < maximoDePostagens) {
        postagens[quantidadeDePostagens] = p;
        quantidadeDePostagens = quantidadeDePostagens + 1;
        return true;
    }
    else {
        return false;
    }
}


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

string Perfil::getNome() {
    return nome;
}

int Perfil::getQuantidadeDeContatos() {
    return quantidadeDeContatos;
}

int Perfil::getQuantidadeDePostagens() {
    return quantidadeDePostagens;
}

Perfil** Perfil::getContatos() {
    return contatos;
}

Postagem** Perfil::getPostagens() {
    return postagens;
}

Postagem** Perfil::getPostagensDosContatos(int data, int &quantidade) {
    Postagem **postagensDosContatos = new Postagem*[maximoDeContatos*maximoDePostagens];
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
    return postagensDosContatos;
}
