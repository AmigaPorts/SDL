# gadtools.library/FreeGadgets



NAME

```c
    FreeGadgets -- Free a linked list of gadgets. (V36)
```
SYNOPSIS

```c
    FreeGadgets(glist)
                A0

    VOID FreeGadgets(struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *glist);
                     A0
```
FUNCTION

```c
    Frees any GadTools gadgets found on the linked list of gadgets
    beginning with the specified one.  Frees all the memory that was
    allocated by [CreateGadgetA()](../Includes_and_Autodocs_2._guide/node03E8.html).  This function will return safely
    with no action if it receives a NULL parameter.
```
INPUTS

    glist - pointer to first gadget in list to be freed.
RESULT

    none
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CreateGadgetA()](../Includes_and_Autodocs_2._guide/node03E8.html)
```
