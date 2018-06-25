
#include <base/log.h>
#include <base/exception.h>

extern "C" {

    void __gnat_malloc()
    {
        Genode::error(__func__, " not implemented");
        throw Genode::Exception();
    }

    void __gnat_free()
    {
        Genode::error(__func__, " not implemented");
        throw Genode::Exception();
    }
}
