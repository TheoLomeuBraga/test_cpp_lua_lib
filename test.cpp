#include "animal.h"
#include "lua/lua.hpp"

animal* criaturinha = NULL;

int applicar_ponteiro_animal(lua_State *L) {
    std::string ptr = lua_tostring(L, 1);
    std::cout << ptr << std::endl;

    criaturinha = string_ponteiro<animal>(ptr.c_str());
    criaturinha->barulho();
    return 0;
}

int main(){
    //criaturinha = new animal();
    //criaturinha->barulho();

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "carregar_lib.lua");

    lua_register(L, "applicar_ponteiro_animal", applicar_ponteiro_animal);
    lua_getglobal(L, "run_test");
    lua_pcall(L, 0, 1, 0);


    lua_close(L);

    return 0;
}