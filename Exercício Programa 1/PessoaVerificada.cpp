#include "PessoaVerificada.h"
#include <iostream>

PessoaVerificada::PessoaVerificada(string nome, string email, int maximoDeContatos, int maximoDePostagens):
Perfil (nome, maximoDeContatos, maximoDePostagens), email (email) {
}

PessoaVerificada::PessoaVerificada(string nome, int maximoDeContatos, int maximoDePostagens):
Perfil (nome, maximoDeContatos, maximoDePostagens) {
    email = "email.padrao@usp.br";
}

PessoaVerificada::~PessoaVerificada()
{
    //dtor
}

string PessoaVerificada::getEmail() {
    return email;
}

void PessoaVerificada::imprimir() {
    cout << getEmail() << endl;
    Perfil::imprimir();
}
