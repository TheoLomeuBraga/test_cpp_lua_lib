#include "animal.h"
#include "lua/lua.hpp"

class gato : public animal{
public:
    gato(){}
    virtual void barulho(){std::cout << "ponha barulho aqui\n";}
};

int pegar_gato(lua_State *L) {
    number = 10;
    lua_pushstring(L,ponteiro_string(new gato()).c_str());
    return 1;
}

extern "C" int luaopen_test_lib(lua_State* L) {
    // registrar a função Soma no Lua
    lua_register(L, "pegar_gato", pegar_gato);

    // indicar quantos valores foram empilhados
    return 0;
}