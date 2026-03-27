# intuition.library/ObtainGIRPort



NAME

```c
    ObtainGIRPort -- Set up a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) for a custom gadget. (V36)
```
SYNOPSIS

```c
    RPort = ObtainGIRPort( GInfo )
    D0                     A0

    struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *ObtainGIRPort( struct [GadgetInfo](../Includes_and_Autodocs_2._guide/node00D2.html#line26) * );
```
FUNCTION

```c
    Sets up a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) for use (only) by custom gadget hook routines.
    This function must be called EACH time a hook routine needing
    to perform gadget rendering is called, and must be accompanied
    by a corresponding call to [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html).

    Note that if a hook function passes you a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) pointer,
    e.g., GM_RENDER, you needn't call ObtainGIRPort() in that case.
```
INPUTS

```c
    A pointer to a [GadgetInfo](../Includes_and_Autodocs_2._guide/node00D2.html#line26) structure, as passed to each custom
    gadget hook function.
```
RESULT

```c
    A pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) that may be used for gadget rendering.
    This pointer may be NULL, in which case you should do no rendering.
    You may (optionally) pass a null return value to [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html).
```
BUGS

SEE ALSO

```c
    [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html), [Custom](../Includes_and_Autodocs_2._guide/node00CD.html#line26) [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) documentation
```
