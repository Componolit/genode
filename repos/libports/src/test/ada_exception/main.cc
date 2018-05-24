
#include <base/log.h>
#include <base/component.h>
#include <ada/exception.h>

extern "C" void except__raise_program();
extern "C" void except__raise_constraint();
extern "C" void except__raise_storage();

void Component::construct(Genode::Env &env)
{
    env.exec_static_constructors();

    Genode::log("Ada exception test");

    try {
        Genode::log("Raising Program_Error");
        except__raise_program();
    }catch (Ada::Exception::Program_Error){
        Genode::log("Catched Program_Error");
    }

    try {
        Genode::log("Raising Constraint_Error");
        except__raise_constraint();
    }catch (Ada::Exception::Constraint_Error){
        Genode::log("Catched Constraint_Error");
    }

    try {
        Genode::log("Raising Storage_Error");
        except__raise_storage();
    }catch (Ada::Exception::Storage_Error){
        Genode::log("Catched Storage_Error");
    }

    Genode::log("Ada exception test successful");

    env.parent().exit(0);
}
