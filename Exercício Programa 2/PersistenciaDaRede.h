#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H
#include "RedeSocial.h"
#include <vector>

class PersistenciaDaRede
{
    public:
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();

        void salvar(RedeSocial* r);
        RedeSocial* carregar();
    private:
        string arquivo;
        template<class T>
        vector<T*>* vetorDeUmTipo(int& quantidade, vector<Perfil*>* perfis);
};

#endif // PERSISTENCIADAREDE_H
