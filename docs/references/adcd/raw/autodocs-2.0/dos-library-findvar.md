# dos.library/FindVar



NAME

```c
    FindVar -- Finds a local variable (V36)
```
SYNOPSIS

```c
    var = FindVar( name, type )
    D0              D1    D2

    struct [LocalVar](../Includes_and_Autodocs_2._guide/node0073.html#line26) * FindVar(STRPTR, ULONG )
```
FUNCTION

    Finds a local variable structure.
INPUTS

```c
    name - pointer to an variable name.  Note variable names follow
           filesystem syntax and semantics.

    type - type of variable to be found (see [<dos/var.h>](../Includes_and_Autodocs_2._guide/node0073.html))
```
RESULT


```c
    var  - pointer to a [LocalVar](../Includes_and_Autodocs_2._guide/node0073.html#line26) structure or NULL
```
SEE ALSO

```c
    [GetVar()](../Includes_and_Autodocs_2._guide/node02BC.html), [SetVar()](../Includes_and_Autodocs_2._guide/node02FE.html), [DeleteVar()](../Includes_and_Autodocs_2._guide/node0294.html), [<dos/var.h>](../Includes_and_Autodocs_2._guide/node0073.html)
```
