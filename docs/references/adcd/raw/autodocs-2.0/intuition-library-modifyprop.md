# intuition.library/ModifyProp



NAME

    ModifyProp -- Modify the current parameters of a proportional gadget.
SYNOPSIS

```c
    ModifyProp( [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145),
                A0      A1      A2
                Flags, HorizPot, VertPot, HorizBody, VertBody )
                D0     D1        D2       D3         D4

    VOID ModifyProp( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, UWORD, UWORD, UWORD, UWORD, UWORD );
```
FUNCTION

```c
    Modifies the parameters of the specified proportional gadget.  The
    gadget's internal state is then recalculated and the imagery
    is redisplayed in the window or requester that contains the gadget.

    The requester variable can point to a requester structure.  If the
    gadget has the GTYP_REQGADGET flag set, the gadget is in a requester
    and the window pointer must point to the window of the requester.
    If this is not the gadget of a requester, the requester argument may
    be NULL.

    NOTE: this function causes all gadgets from the proportional
    gadget to the end of the gadget list to be refreshed, for
    reasons of compatibility.
    For more refined display updating, use [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html).

    New for V36: ModifyProp() refreshing consists of redrawing gadgets
    completely.  [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html) has changed this behavior (see
    [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html)).
```
INPUTS

```c
    PropGadget = pointer to a proportional gadget
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window containing the gadget or the window
        containing the requester containing the gadget.
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = pointer to a requester (may be NULL if this isn't
        a requester gadget)
    Flags = value to be stored in the Flags field of the [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line454)
    HorizPot = value to be stored in the HorizPot field of the [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line454)
    VertPot = value to be stored in the VertPot field of the [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line454)
    HorizBody = value to be stored in the HorizBody field of the [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line454)
    VertBody = value to be stored in the VertBody field of the [PropInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line454)
```
RESULT

    None
BUGS

SEE ALSO

```c
    [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html)
    The Intuition Reference Manual and Amiga Rom Kernel Manual contain
    more information on Proportional Gadgets.
```
