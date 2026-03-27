# cia.resource/RemICRVector



NAME

```c
    RemICRVector -- Detach an interrupt handler from a [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) bit.
```
SYNOPSIS

```c
    RemICRVector( Resource, iCRBit, interrupt )
                  A6        D0      A1

    void RemICRVector( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD, struct [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) *);
```
FUNCTION

```c
    Disconnect interrupt processing code for a particular
    interrupt bit of the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) ICR.

    This function will also disable the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) interrupt for the
    given ICR bit.
```
INPUTS

```c
    iCRBit          Bit number to set (0..4).
    interrupt       Pointer to interrupt structure.
```
RESULT

NOTE

```c
    The [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resources require an extra parameter
    to specify which [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    RemICRVector( Resource, iCRBit, interrupt )
                  A6        D0      A1

    void RemICRVector( struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *, WORD, struct [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) *);
```
SEE ALSO

```c
    [cia.resource/AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html)
```
