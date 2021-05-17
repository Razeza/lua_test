#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>


#include <stdio.h>

void lua_stacktrace(lua_State* L)
{
    lua_Debug entry;
    int depth = 0; 

    while (lua_getstack(L, depth, &entry))
    {
        int status = lua_getinfo(L, "Sln", &entry);
        assert(status);

        printf("%s(%d): %s\n", entry.short_src, entry.currentline, entry.name ? entry.name : "?");
        depth++;
    }
}
