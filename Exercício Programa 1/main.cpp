#include <iostream>
#include <string>
#include "Perfil.h"
#include "RedeSocial.h"
#include "Postagem.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "PessoaNaoVerificada.h"
#include "Story.h"
using namespace std;

void mostrarPerfis(RedeSocial* rede) {
    for (int i = 0; i < rede->getQuantidadeDePerfis(); i++) {
        if (dynamic_cast<PessoaVerificada*>(rede->getPerfis()[i]) != NULL) {
            cout << i + 1 << ") " << rede->getPerfis()[i]->getNome() << " (Verificada)" << endl;
        }
        else {
            cout << i + 1 << ") " << rede->getPerfis()[i]->getNome() << endl;
        }
    }
    cout << "Digite o numero ou 0 para cancelar: ";
}

int main() {
    RedeSocial* rede = new RedeSocial;

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
                PessoaVerificada* perfil = new PessoaVerificada(nome, email, 20, 20);
                rede->adicionar(perfil);
            }
            else if(verificada == "n") {
                PessoaNaoVerificada* perfil = new PessoaNaoVerificada(nome, 20, 20);
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
            if (escolherProprietario <= rede->getQuantidadeDePerfis() && escolherProprietario != 0) {
                if (dynamic_cast<PessoaVerificada*>(rede->getPerfis()[escolherProprietario - 1]) != NULL) {
                    Pagina* pagina = new Pagina(nome, dynamic_cast<PessoaVerificada*>(rede->getPerfis()[escolherProprietario - 1]), 20, 20);
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
            if (escolherPerfil <= rede->getQuantidadeDePerfis() && escolherPerfil != 0) {
                do {
                    if (dynamic_cast<PessoaVerificada*>(rede->getPerfis()[escolherPerfil - 1]) != NULL) {
                        cout << rede->getPerfis()[escolherPerfil - 1]->getNome() << " - " << dynamic_cast<PessoaVerificada*>(rede->getPerfis()[escolherPerfil - 1])->getEmail() << endl;
                    }
                    else if (dynamic_cast<Pagina*>(rede->getPerfis()[escolherPerfil - 1]) != NULL) {
                        cout << rede->getPerfis()[escolherPerfil - 1]->getNome() << endl << "Proprietario: " << dynamic_cast<Pagina*>(rede->getPerfis()[escolherPerfil - 1])->getProprietario()->getNome() << endl;
                    }
                    else {
                        cout << rede->getPerfis()[escolherPerfil - 1]->getNome() << endl;
                    }
                    cout << "Contatos: " << rede->getPerfis()[escolherPerfil - 1]->getQuantidadeDeContatos() << endl
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
                            Story* story = new Story(texto, data, dataDeFim, rede->getPerfis()[escolherPerfil - 1]);
                            rede->getPerfis()[escolherPerfil - 1]->adicionarPostagem(story);
                        }

                        else {
                            Postagem* postagem = new Postagem(texto, data, rede->getPerfis()[escolherPerfil - 1]);
                            rede->getPerfis()[escolherPerfil - 1]->adicionarPostagem(postagem);
                        }
                    }

                    //Opção -> Ver Postagens dos Contatos
                    else if (escolherOpcao == 2) {
                        int data;
                        int quantidade = 0;
                        cout << "Data: ";
                        cin >> data;
                        Postagem** postagens = rede->getPerfis()[escolherPerfil - 1]->getPostagensDosContatos(data, quantidade);

                        cout << "Postagens dos ultimos 3 dias:" << endl;
                        for (int i = 0; i < quantidade; i++) {
                            postagens[i]->imprimir();
                        }
                    }

                    //Opção -> Adicioonar Contato
                    else if (escolherOpcao == 3) {
                        int contatoSolicitado;
                        cout << "Perfil:" << endl;
                        mostrarPerfis(rede);
                        cin >> contatoSolicitado;

                        if (contatoSolicitado > rede->getQuantidadeDePerfis() || contatoSolicitado == 0 || rede->getPerfis()[escolherPerfil - 1]->adicionarContato(rede->getPerfis()[contatoSolicitado - 1]) == false) {
                            cout << "Contato nao adicionado" << endl;
                        }
                    }
                } while (escolherOpcao != 0);
            }
        }

    } while (inicio != 0); // volta para a tela inicial
    delete rede;

    return 0;
}
//*/
