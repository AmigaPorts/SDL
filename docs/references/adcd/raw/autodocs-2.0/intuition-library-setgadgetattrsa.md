# intuition.library/SetGadgetAttrsA



NAME

```c
    SetGadgetAttrsA -- Specify attribute values for a boopsi gadget. (V36)
    SetGadgetAttrs -- Varargs stub for SetGadgetAttrsA(). (V36)
```
SYNOPSIS

```c
    result = SetGadgetAttrsA( [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145), TagList )
    D0                        A0      A1      A2         A3

    ULONG SetGadgetAttrsA( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    result = SetGadgetAttrs( [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145), Tag1, ...)

    ULONG SetGadgetAttrs( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, ULONG, ... );
```
FUNCTION

```c
    Same as SetAttrs(), but provides context information and
    arbitration for classes which implement custom Intuition gadgets.

    You should use this function for boopsi gadget objects which have
    already been added to a requester or a window, or for "models" which
    propagate information to gadget already added.

    Typically, the gadgets will refresh their visuals to reflect
    changes to visible attributes, such as the value of a slider,
    the text in a string-type gadget, the selected state of a button.

    You can use this as a replacement for SetAttrs(), too, if you
    specify NULL for the 'Window' and 'Requester' parameters.
```
INPUTS

```c
    [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) = abstract pointer to a boopsi gadget
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = window gadget has been added to using [AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html) or
             [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html)
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = for REQGADGETs, requester containing the gadget
    TagList = array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures with attribute/value pairs.
```
RESULT

    The object does whatever it wants with the attributes you provide,
    which might include updating its gadget visuals.

    The return value tends to be non-zero if the changes would require
    refreshing gadget imagery, if the object is a gadget.
NOTES

```c
    This function invokes the OM_SET method with a [GadgetInfo](../Includes_and_Autodocs_2._guide/node00D2.html#line26)
    derived from the 'Window' and 'Requester' pointers.
```
BUGS

    There should be more arbitration between this function and
    the calls that Intuition's input task will make to the
    gadgets.  In the meantime, this function, input processing,
    and refreshing must be mutually re-entrant.
SEE ALSO

```c
    [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html), [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html), [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html), [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```
