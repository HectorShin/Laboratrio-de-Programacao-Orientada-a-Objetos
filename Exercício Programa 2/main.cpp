#include <iostream>
#include <string>
#include "Perfil.h"
#include "RedeSocial.h"
#include "Postagem.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Pessoa.h"
#include "Perfil.h"
#include "PerfilInexistente.h"
#include "PersistenciaDaRede.h"

#include "Story.h"
using namespace std;

void mostrarPerfis(RedeSocial* rede) {
    for (int i = 0; i < rede->getPerfis()->size(); i++) {
        Perfil* perfilMostrado = (*rede->getPerfis())[i];
        if (dynamic_cast<PessoaVerificada*>(perfilMostrado) != NULL) {
            cout << perfilMostrado->getId()  << ") " << perfilMostrado->getNome() << " (Verificada)" << endl;
        }
        else {
            cout << i + 1 << ") " << perfilMostrado->getNome() << endl;
        }
    }
    cout << "Digite o numero ou 0 para cancelar: ";
}

int main() {
    cout << "Arquivo: ";
    string arquivo; //nome do arquivo do qual sera feito a persistencia
    cin >> arquivo;

    PersistenciaDaRede* persistencia = new PersistenciaDaRede(arquivo);

    RedeSocial* rede;
    try {
        rede = persistencia->carregar();
    }
    catch (logic_error *e) {
        rede = new RedeSocial();
        cout << e->what();
    }

    //Tela inicial
    int inicio = 0;
    do {
        cout << "Escolha uma opcao:" << endl
         << "1) Cadastrar Pessoa" << endl
         << "2) Cadastrar Pagina" << endl
         << "3) Logar" << endl
         << "0) Terminar" << endl;
        cin >> inicio;

        //Se a opcao escolhida for 1 (Cadastrar pessoa)
        if (inicio == 1) {
            string nome;
            string verificada;

            cout << "Informe os dados da pessosa" << endl
                 << "Nome: ";
            cin >> nome;

            cout << "Verificada (s/n)? ";
            cin >> verificada;

            if (verificada == "s") {
                string email;
                cout << "Email: ";
                cin >> email;
                PessoaVerificada* perfil = new PessoaVerificada(nome, email);
                rede->adicionar(perfil);
            }
            else if(verificada == "n") {
                Pessoa* perfil = new Pessoa(nome);
                rede->adicionar(perfil);
            }
        }

        //Se a opcao escolhida for 2 (Cadastrar pagina)
        else if (inicio == 2) {
            string nome;
            int escolherProprietario;

            cout << "Informe os dados da pagina" << endl
                 << "Nome: ";
            cin >> nome;

            cout << "Proprietario:" << endl;
            mostrarPerfis(rede);
            cin >> escolherProprietario;
            if (escolherProprietario <= rede->getPerfis()->size() && escolherProprietario != 0) {
                if (dynamic_cast<PessoaVerificada*>(rede->getPerfil(escolherProprietario)) != NULL) {
                    Pagina* pagina = new Pagina(nome, dynamic_cast<PessoaVerificada*>(rede->getPerfil(escolherProprietario)));
                    rede->adicionar(pagina);
                }
                else {
                    cout << "Somente pessoas verificadas podem ser proprietarias" << endl;
                }
            }
        }

        //Se a opcao escolhida for 3 (Logar)
        else if (inicio == 3) {
            int escolherPerfil;
            cout << "Escolha um perfil:" << endl;
            mostrarPerfis(rede);
            cin >> escolherPerfil;

            int escolherOpcao;
            if (escolherPerfil <= rede->getPerfis()->size() && escolherPerfil != 0) {
                Perfil* perfilEscolhido = rede->getPerfil(escolherPerfil);
                do {
                    if (dynamic_cast<PessoaVerificada*>(perfilEscolhido) != NULL) {
                        cout << perfilEscolhido->getNome() << " - " << dynamic_cast<PessoaVerificada*>(perfilEscolhido)->getEmail() << endl;
                    }
                    else if (dynamic_cast<Pagina*>(perfilEscolhido) != NULL) {
                        cout << perfilEscolhido->getNome() << endl << "Proprietario: " << dynamic_cast<Pagina*>(perfilEscolhido)->getProprietario()->getNome() << endl;
                    }
                    else {
                        cout << perfilEscolhido->getNome() << endl;
                    }
                    cout << "Contatos: " << perfilEscolhido->getContatos() ->size() << endl
                         << "---" << endl
                         << "Escolha uma opcao:" << endl
                         << "1) Fazer postagem" << endl
                         << "2) Ver postagens dos contatos" << endl
                         << "3) Adicionar contato" << endl
                         << "0) Deslogar" << endl;
                    cin >> escolherOpcao;

                    //Opção -> Fazer Postagem
                    if (escolherOpcao == 1) {
                        string seStory;
                        int data;
                        string texto;

                        cout << "Story (s/n): ";
                        cin >> seStory;

                        cout <<  "Data: ";
                        cin >> data;

                        int dataDeFim;
                        if (seStory == "s") {
                            cout << "Data de Fim: ";
                            cin >> dataDeFim;
                        }

                        cout << "Texto: ";
                        cin >> texto;

                        if (seStory == "s") {
                            Story* story = new Story(texto, data, dataDeFim, perfilEscolhido);
                            perfilEscolhido->adicionar(story);
                        }

                        else {
                            Postagem* postagem = new Postagem(texto, data, perfilEscolhido);
                            perfilEscolhido->adicionar(postagem);
                        }
                    }

                    //Opção -> Ver Postagens dos Contatos
                    else if (escolherOpcao == 2) {
                        int data;
                        cout << "Data: ";
                        cin >> data;
                        list<Postagem*>* postagensDosContatos = perfilEscolhido->getPostagensDosContatos(data);

                        cout << "Postagens dos ultimos 3 dias:" << endl;
                        list<Postagem*>::iterator i = postagensDosContatos->begin();
                        while (i != postagensDosContatos->end()) {
                            (*i)->imprimir();
                        }
                    }

                    //Opção -> Adicioonar Contato
                    else if (escolherOpcao == 3) {
                        int idDoContatoSolicitado;
                        cout << "Perfil:" << endl;
                        mostrarPerfis(rede);
                        cin >> idDoContatoSolicitado;
                        Perfil* contatoSolicitado;
                        try {
                            contatoSolicitado = rede->getPerfil(idDoContatoSolicitado);
                            perfilEscolhido->adicionar(contatoSolicitado);
                        }
                        catch (invalid_argument *e) {
                            cout << e->what() << endl;
                            escolherOpcao = 0;  //Condicoes para
                            inicio = 0;         //terminar o programa
                        }
                        catch (PerfilInexistente *e) {
                            cout << e->what() << endl;
                            escolherOpcao = 0;
                            inicio = 0;
                        }

                        /*
                        if (idDoContatoSolicitado < rede->getPerfis()->size() && idDoContatoSolicitado != 0) {
                            try {
                                perfilEscolhido->adicionar(rede->getPerfil(idDoContatoSolicitado));
                            }
                            /*catch (invalid_argument *e) {
                                cout << "Contato nao adicionado" << endl;
                            }
                            catch (PerfilInexistente *e) {
                                cout << e->what() << endl;
                            }
                        }*/
                    }
                } while (escolherOpcao != 0);
            }
        }

    } while (inicio != 0); // volta para a tela inicial
    cout << "Deseja salvar? (s/n) ";
    string seSalvar;
    cin >> seSalvar;
    if (seSalvar == "s") {
        try {
            persistencia->salvar(rede);
        }
        catch (logic_error *e) {
            cout << e->what();
        }
    }
    cout << "terminei o programa";
    delete rede;

    return 0;
}
