
#include <base/log.h>
#include <util/string.h>
#include <ada/exception.h>

extern "C" {

    /* Program Error */
    void __gnat_rcheck_PE_Explicit_Raise(char *file, int line)
    {
        Genode::error("Program Error in ", Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Program_Error();
    }

    /* Constraint Error */
    void __gnat_rcheck_CE_Explicit_Raise(char *file, int line)
    {
        Genode::error("Constraint Error in ", Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Constraint_Error();
    }

    /* Storage Error */
    void __gnat_rcheck_SE_Explicit_Raise(char *file, int line)
    {
        Genode::error("Storage Error in ", Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Storage_Error();
    }

    void raise_ada_exception(char *name, char *message)
    {
        Genode::error(Genode::Cstring(name), " raised: ", Genode::Cstring(message));
    }

    void warn_unimplemented_function(char *func)
    {
        Genode::warning(Genode::Cstring(func), " unimplemented");
    }

}
