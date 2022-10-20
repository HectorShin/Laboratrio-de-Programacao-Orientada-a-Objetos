#include "PersistenciaDaRede.h"
#include <fstream>
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Pessoa.h"
#include <stdexcept>
#include <iostream> //para testar
using namespace std;

PersistenciaDaRede::PersistenciaDaRede(string arquivo) :
arquivo (arquivo)
{
    //ctor
}

PersistenciaDaRede::~PersistenciaDaRede()
{
    //dtor
}

template <class T>
vector<T*>* PersistenciaDaRede::vetorDeUmTipo(int& quantidade, vector<Perfil*>* perfis) {
    quantidade = 0;
    vector<T*>* vetorDoTipo = new vector<T*>();
    T* perfilConvertido;
    for (int i = 0; i < perfis->size(); i++) {
        perfilConvertido = dynamic_cast<T*>((*perfis)[i]);
        if (perfilConvertido != NULL) {
            vetorDoTipo->push_back(perfilConvertido);
            quantidade += 1;
        }
    }
    return vetorDoTipo;
}

void PersistenciaDaRede::salvar(RedeSocial* r) {
    ofstream output;
    output.open(arquivo);
    output << Perfil::getUltimoId() << endl;
    /*vector<PessoaVerificada*>* vetorDePessoasVerificadas = new vector<PessoaVerificada*>();
    vector<Pessoa*>* vetorDePessoas = new vector<Pessoa*>();
    vector<Pagina*>* vetorDePaginas = new vector<Pagina*>();
    for(int i = 0; r->getPerfis->size(); i++) {
        if (dynamic_cast<PessoaVerificada*>(r->getPerfis()[i]) != NULL) {
            quantidadeDePessoasVerificadas
            vetorDePessoasVerificadas->push_back(dynamic_cast<PessoaVerificada*>(r->getPerfis()[i]));
        }
        else if (dynamic_cast<Pessoa*>(r->getPerfis()[i]) != NULL) {
            vetorDePessoas->push_back(dynamic_cast<Pessoa*>(r->getPerfis()[i]));
        }
        else if (dynamic_cast<Pagina*>(r->getPerfis()[i]) != NULL) {
            vetorDePessoasVerificadas->push_back(dynamic_cast<Pagina*>(r->getPerfis()[i]));
        }
    }*/

    vector<Perfil*>* vetorDePerfis = r->getPerfis();

    cout << "peidei";

    int quantidade;
    vector<PessoaVerificada*>* vetorDePessoasVerificadas = vetorDeUmTipo<PessoaVerificada>(quantidade, vetorDePerfis);
    output << quantidade << endl;
    for (int i = 0; i < vetorDePessoasVerificadas->size(); i++) {
        if (output) {
            output << (*vetorDePessoasVerificadas)[i]->getId() << " " << (*vetorDePessoasVerificadas)[i]->getNome() << " " << (*vetorDePessoasVerificadas)[i]->getEmail() << endl;
        }
        else throw new logic_error("Erro ao escrever");
    }

    cout << "peidei";

    vector<Pessoa*>* vetorDePessoas = vetorDeUmTipo<Pessoa>(quantidade, vetorDePerfis);
    cout << "wa";
    output << quantidade << endl;
    for (int i = 0; i < vetorDePessoas->size(); i++) {
        if (output) {
            output << (*vetorDePessoas)[i]->getId() << " " << (*vetorDePessoas)[i]->getNome() << endl;
        }
        else throw new logic_error("Erro ao escrever");
        cout << "mano";
    }

    cout << "peidei";

    vector<Pagina*>* vetorDePaginas = vetorDeUmTipo<Pagina>(quantidade, vetorDePerfis);
    output << quantidade << endl;
    for (int i = 0; i < vetorDePaginas->size(); i++) {
        if (output) {
            output << (*vetorDePaginas)[i]->getId() << " " << (*vetorDePaginas)[i]->getProprietario() << " " << (*vetorDePessoasVerificadas)[i]->getNome() << endl;
        }
        else throw new logic_error("Erro ao escrever");
    }

    cout << "peidei";

    for (int i = 0; i < vetorDePerfis->size(); i++) {
        vector<Perfil*>* vetorDeContatosDoPerfil = (*vetorDePerfis)[i]->getContatos();
        for (int j = 0; j < vetorDeContatosDoPerfil->size(); i++) {
            if (output) {
                output << (*vetorDePerfis)[i]->getId() << " " << (*vetorDeContatosDoPerfil)[j]->getId();
            }
            else throw new logic_error("Erro ao escrever");
        }
    }

    cout << "peidei";
}
    /*
    for (int i = 0; i < r->perfis->size(); i++) {
        if )output) {

        }

        if (output) {
            perfilConvertido = dynamic_cast<PessoaVerificada*>(r->getPerfis()[i]);
            output << endl << perfilConvertido->getId() << " " << perfilConvertido->getNome() << " " << perfilConvertido->getEmail();
        }
        else {
            throw new logic_error("Erro ao escrever");
            output.close();
        }
    }
    output.close();
}*/

RedeSocial* PersistenciaDaRede::carregar() {
    RedeSocial* rede = new RedeSocial();
    ifstream input;
    input.open(arquivo);
    if (input.fail()) {
        throw new logic_error("Arquivo nao encontrado");
    }
    else {
        int ultimoId;
        input >> ultimoId;
        Perfil::setUltimoId(ultimoId);

        //Variaveis comuns a qualquer tipo de perfil
        int id;
        string nome;

        //Adicionando Pessoas Verificadas á rede:
        int quantidade;
        input >> quantidade; //Quantidade de Pesoas Verificadas
        string email; //Variavel especifica de PessoaVerificada
        int contador = 1;
        while (contador <= quantidade && input) {
            input >> id >> nome >> email;
            rede->adicionar(new PessoaVerificada(id, nome, email));
            contador += 1;
        }

        //Adicionando Pessoas á rede:
        input >> quantidade; //Quantidade de Pessoas
        contador = 1;
        while (contador <= quantidade && input) {
            input >> id >> nome;
            rede->adicionar(new Pessoa(id, nome));
            contador += 1;
        }

        //Adicionando Paginas a rede:
        input >> quantidade;
        int idDoProprietario;
        contador = 1;
        while (contador <= quantidade && input) {
            input >> id >> idDoProprietario >> nome;
            rede->adicionar(new Pagina(id, nome, dynamic_cast<PessoaVerificada*>(rede->getPerfil(idDoProprietario))));
            contador += 1;
        }
        cout << id;


        //Adicionando os contatos:
        int idDoContato;
        while (input) {
            input >> id >> idDoContato;
            cout << id;
            rede->getPerfil(id)->adicionar(rede->getPerfil(idDoContato));
        }
        cout << "5";

        if (!input.eof()) {
            throw new logic_error("Erro");
        }
    }
    input.close();
    return rede;

    /*
    else {
        int id;
        string nome, email;
        input >> id;
        input >> id >> nome >> email;
        while (input) {
            rede->adicionar(new PessoaVerificada(nome, email, 5));
            input >> id >> nome >> email;
        }
        if (!input.eof()) {
            throw new logic_error("Erro");
        }
    }
    input.close();
    return rede;*/
}
