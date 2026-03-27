# intuition.library/ReleaseGIRPort



NAME

```c
    ReleaseGIRPort -- Release a custom gadget [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). (V36)
```
SYNOPSIS

```c
    ReleaseGIRPort( RPort )
                    A0

    VOID ReleaseGIRPort( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) * );
```
FUNCTION

```c
    The corresponding function to [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html), it releases
    arbitration used by Intuition for gadget RastPorts.
```
INPUTS

```c
    Pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) returned by [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html).
    This pointer can be NULL, in which case nothing happens.
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html), [Custom](../Includes_and_Autodocs_2._guide/node00CD.html#line26) [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) documentation
```
