package body Except is

    procedure Raise_Program
    is
    begin
        raise Program_Error;
    end Raise_Program;

    procedure Raise_Constraint
    is
    begin
        raise Constraint_Error;
    end Raise_Constraint;

    procedure Raise_Storage
    is
    begin
        raise Storage_Error;
    end Raise_Storage;

end Except;
