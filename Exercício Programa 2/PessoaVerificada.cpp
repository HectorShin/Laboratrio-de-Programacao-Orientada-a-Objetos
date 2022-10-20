#include "PessoaVerificada.h"
#include <iostream>

PessoaVerificada::PessoaVerificada(string nome, string email):
Pessoa (nome), email (email) {
}

PessoaVerificada::PessoaVerificada(string nome):
Pessoa (nome) {
    email = "email.padrao@usp.br";
}

PessoaVerificada::PessoaVerificada(int id, string nome, string email):
Pessoa (id, nome), email (email) {
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
    Pessoa::imprimir();
}
