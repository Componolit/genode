
#include <base/log.h>
#include <util/string.h>

extern "C" {

    void raise_ada_exception(char *name, char *message)
    {
        Genode::error(Genode::Cstring(name), " raised: ", Genode::Cstring(message));
    }

    void warn_unimplemented_function(char *func)
    {
        Genode::warning(Genode::Cstring(func), " unimplemented");
    }

}
