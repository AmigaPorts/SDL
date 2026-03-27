# dos.library/DeleteVar



NAME

```c
    DeleteVar -- Deletes a local or environment variable (V36)
```
SYNOPSIS

```c
    success = DeleteVar( name, flags )
    D0                    D1    D2

    BOOL DeleteVar(STRPTR, ULONG )
```
FUNCTION

    Deletes a local or environment variable.
INPUTS

```c
    name   - pointer to an variable name.  Note variable names follow
             filesystem syntax and semantics.
    flags  - combination of type of var to delete (low 8 bits), and
             flags to control the behavior of this routine.  Currently
             defined flags include:

             GVF_LOCAL_ONLY  - delete a local (to your process) variable.
             GVF_GLOBAL_ONLY - delete a global environment variable.

             The default is to delete a local variable if found, otherwise
             a global environment variable if found (only for LV_VAR).
```
RESULT

    success - If non-zero, the variable was sucessfully deleted, FALSE
              indicates failure.
BUGS

    LV_VAR is the only type that can be global
SEE ALSO

```c
    [GetVar()](../Includes_and_Autodocs_2._guide/node02BC.html), [SetVar()](../Includes_and_Autodocs_2._guide/node02FE.html), [FindVar()](../Includes_and_Autodocs_2._guide/node02A9.html), [DeleteFile()](../Includes_and_Autodocs_2._guide/node0293.html), [<dos/var.h>](../Includes_and_Autodocs_2._guide/node0073.html)
```
