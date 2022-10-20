#include "Pagina.h"
#include <iostream>

Pagina::Pagina(string nome, PessoaVerificada* proprietario):
Perfil (nome), proprietario (proprietario)
{
    adicionar(proprietario);
}

Pagina::Pagina(int id, string nome, PessoaVerificada* proprietario):
Perfil (id, nome), proprietario (proprietario) {
}

Pagina::~Pagina()
{
    //dtor
}

PessoaVerificada* Pagina::getProprietario() {
    return proprietario;
}

void Pagina::imprimir() {
    cout << "Nome: " << getNome() << " - id: " << id << " - Proprietario: "
         << proprietario->getNome() << endl;
}
