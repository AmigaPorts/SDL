# amiga.lib/RemTOF



NAME

    RemTOF - remove a task from the VBlank interrupt server chain.
SYNOPSIS

```c
    RemTOF(i);

    VOID RemTOF(struct [Isrvstr](../Includes_and_Autodocs_2._guide/node00C1.html#line19) *);
```
FUNCTION

    Removes a task from the vertical-blanking interval interrupt server
    chain.
INPUTS

```c
    i - pointer to an [Isrvstr](../Includes_and_Autodocs_2._guide/node00C1.html#line19) structure
```
SEE ALSO

```c
    [AddTOF()](../Includes_and_Autodocs_2._guide/node013A.html), [<graphics/graphint.h>](../Includes_and_Autodocs_2._guide/node00C1.html)
```
