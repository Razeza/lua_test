#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>


#include <stdio.h>

static int test_print (lua_State *L) {
    int top=lua_gettop(L);
  for (int i=1; i <= top; i++) {
    printf("%d\t%s\t", i, luaL_typename(L,i));
    switch (lua_type(L, i)) {
      case LUA_TNUMBER:
        printf("%g\n",lua_tonumber(L,i));
        break;
      case LUA_TSTRING:
        printf("%s\n",lua_tostring(L,i));
        break;
      case LUA_TBOOLEAN:
        printf("%s\n", (lua_toboolean(L, i) ? "true" : "false"));
        break;
      case LUA_TNIL:
        printf("%s\n", "nil");
        break;
      default:
        printf("%p\n",lua_topointer(L,i));
        break;
    }
  }
  return 0;
}


//name of this function is not flexible
int luaopen_mylib (lua_State *L){
    lua_register(L, "test_print", test_print);
    return 0;
}

