# intuition.library/AddGList



NAME

    AddGList -- Add a linked list of gadgets to a window or requester.
SYNOPSIS

```c
    RealPosition = AddGList( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), Position, Numgad, [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) )
    D0                       A0      A1      D0        D1      A2

    UWORD AddGList( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, UWORD, WORD,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) * );
```
FUNCTION

```c
    Adds the list of gadgets to the gadget list of the given window
    or requester linked in at the position in the list specified by
    the position argument.

    See [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html) for more information about gadget list position,
    and more information about gadgets in general.

    The requester parameter will be ignored unless the GTYP_REQGADGET
    bit is set in the GadgetType field of the first gadget in the list.
    In that case, the gadget list is added to the requester gadgets.
    NOTE: be sure that GTYP_REQGADGET is either set or cleared consistently
    for all gadgets in the list.  NOTE ALSO: The window parameter
    should point to the window that the requester (will) appear in.

    Will add 'Numgad' gadgets from gadget list linked by the field
    NextGadget, or until some NextGadget field is found to be NULL.  Does
    not assume that the Numgad'th gadget has NextGadget equal to NULL.

    NOTE WELL: In order to link your gadget list in, the NextGadget
    field of the Numgad'th (or last) gadget will be modified.  Thus, if
    you are adding the first 3 gadgets from a linked list of five gadgets,
    this call will sever the connection between your third and fourth
    gadgets.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window to get your gadget
    [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) = pointer to the first gadget to be added
    Position = integer position in the list for the new gadget
        (starting from zero as the first position in the list)
    Numgad = the number of gadgets from the linked list to be added
        if Numgad equals -1, the entire null-terminated list of
        gadgets will be added.
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = the requester the gadgets will be added to if the
        GTYP_REQGADGET GadgetType flag is set for the first gadget
        in the list
```
RESULT

    Returns the position of where the first gadget in the list was actually
    added.
BUGS

SEE ALSO

```c
    [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html), [RemoveGadget()](../Includes_and_Autodocs_2._guide/node0246.html), [RemoveGList()](../Includes_and_Autodocs_2._guide/node0247.html)
```
