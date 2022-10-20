#include "PerfilInexistente.h"
#include <stdexcept>
using namespace std;

PerfilInexistente::PerfilInexistente() : logic_error("Perfil Inexistente") {
}

PerfilInexistente::~PerfilInexistente()
{
    //dtor
}
