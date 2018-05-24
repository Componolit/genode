
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

    /* Constraint Error subtypes */

    /* Length check failed */
    void __gnat_rcheck_CE_Length_Check(char *file, int line)
    {
        Genode::error("Constraint Error: Length check failed in ",
                Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Length_Check();
    }

    /* Overflow check failed */
    void __gnat_rcheck_CE_Overflow_Check(char *file, int line)
    {
        Genode::error("Constraint Error: Overflow check failed in ",
                Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Overflow_Check();
    }

    /* Invalid data */
    void __gnat_rcheck_CE_Invalid_Data(char *file, int line)
    {
        Genode::error("Constraint Error: Invalid data in ",
                Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Invalid_Data();
    }

    /* Range check failed */
    void __gnat_rcheck_CE_Range_Check(char *file, int line)
    {
        Genode::error("Constraint Error: Range check failed in ",
                Genode::Cstring(file), " at line ", line);
        throw Ada::Exception::Range_Check();
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
