#include "Pagina.h"
#include <iostream>

Pagina::Pagina(string nome, PessoaVerificada* proprietario, int maximoDeContatos, int maximoDePostagens):
Perfil (nome, maximoDeContatos, maximoDePostagens), proprietario (proprietario)
{
    adicionarContato(proprietario);
}

Pagina::~Pagina()
{
    //dtor
}

PessoaVerificada* Pagina::getProprietario() {
    return proprietario;
}

void Pagina::imprimir() {
    cout << "Nome: " << getNome() << " - Proprietario: "
         << proprietario->getNome() << endl;
}
