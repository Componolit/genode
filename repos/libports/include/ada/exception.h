
#include <base/exception.h>

namespace Ada {
    namespace Exception {
        class Program_Error : Genode::Exception {};
        class Constraint_Error : Genode::Exception {};
        class Storage_Error : Genode::Exception {};
    };
};
