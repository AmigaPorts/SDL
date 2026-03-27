# amiga.lib/AddTOF



NAME

    AddTOF - add a task to the VBlank interrupt server chain.
SYNOPSIS

```c
    AddTOF(i,p,a);

    VOID AddTOF(struct [Isrvstr](../Includes_and_Autodocs_2._guide/node00C1.html#line19) *, APTR, APTR);
```
FUNCTION

    Adds a task to the vertical-blanking interval interrupt server
    chain. This prevents C programmers from needing to write an
    assembly language stub to do this function.
INPUTS

```c
    i - pointer to an initialized [Isrvstr](../Includes_and_Autodocs_2._guide/node00C1.html#line19) structure
    p - pointer to the C-code routine that this server is to call each
        time TOF happens
    a - pointer to the first longword in an array of longwords that
        is to be used as the arguments passed to your routine
        pointed to by p.
```
SEE ALSO

```c
    [RemTOF()](../Includes_and_Autodocs_2._guide/node0164.html), [<graphics/graphint.h>](../Includes_and_Autodocs_2._guide/node00C1.html)
```
