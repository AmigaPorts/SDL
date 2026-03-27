# 15 / / Kinds of GadTools / Text-Display and Numeric-Display Gadgets


Text-display (TEXT_KIND) and numeric-display (NUMBER_KIND) gadgets are
read-only displays of information.  They are useful for displaying
information that is not editable or selectable, while allowing the
application to use the GadTools formatting and visuals.  Conveniently, the
visuals are automatically refreshed through normal GadTools gadget
processing.  The values displayed may be modified by the program in the
same way other GadTools gadgets may be updated.

Text-display and number-display gadgets consist of a fixed label (the one
supplied as the [NewGadget](../Libraries_Manual_guide/node0259.html)'s [ng_GadgetText](../Libraries_Manual_guide/node0259.html#line27)), as well as a changeable string
or number (GTTX_Text or GTNM_Number respectively).  The fixed label is
placed according to the PLACETEXT_ flag chosen in the NewGadget [ng_Flags](../Libraries_Manual_guide/node0259.html#line38)
field.  The variable part is aligned to the left-edge of the gadget.

Text-display gadgets recognize the following tags:

GTTX_Text (STRPTR)

```c
    Pointer to the string to be displayed or NULL for no string.  The
    default is NULL.  (Create and set.)
```
GTTX_Border (BOOL)

```c
    Set to TRUE to place a recessed border around the displayed string.
    The default is FALSE.  (Create only.)
```
GTTX_CopyText (BOOL)


```c
    This flag instructs the text-display gadget to copy the supplied
    GTTX_Text string instead of using only a pointer to the string.  This
    only works for the value of GTTX_Text set at [CreateGadget()](../Libraries_Manual_guide/node025A.html) time.  If
    GTTX_Text is changed, the new text will be referenced by pointer, not
    copied.  Do not use this tag without a non-NULL GTTX_Text.  (Create
    only.)
```
Number-display gadgets have the following tags:

GTNM_Number (LONG)

```c
    The number to be displayed.  The default is zero.  (Create or set.)
```
GTNM_Border (BOOL)

```c
    Set to TRUE to place a recessed border around the displayed number.
    The default is FALSE.  (Create only.)
```
Since they are not selectable, text-display and numeric-display gadgets
never cause [IntuiMessage](../Libraries_Manual_guide/node01D9.html)s to be sent to the application.

