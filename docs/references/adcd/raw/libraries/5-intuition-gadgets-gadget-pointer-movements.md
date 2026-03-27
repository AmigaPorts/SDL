# 5 Intuition Gadgets / Gadget Pointer Movements


If the [GACT_FOLLOWMOUSE](../Libraries_Manual_guide/node014B.html#line40) flag is set for a gadget, the application will
receive mouse movement broadcasts as long as the gadget is active. This
section covers the behavior of [proportional](../Libraries_Manual_guide/node0153.html), [boolean](../Libraries_Manual_guide/node014C.html) and [string](../Libraries_Manual_guide/node0164.html) gadgets,
although there are major caveats in some cases:

  * Unlike [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) and [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) [IntuiMessage](../Libraries_Manual_guide/node01D9.html)s, the


```c
    [IAddress](../Libraries_Manual_guide/node01D9.html#line73) field of an [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) IntuiMessage does not point to
    the gadget.  The application must track the active gadget (this
    information is readily obtained from the IDCMP_GADGETDOWN message)
    instead of using the IAddress field.
```
	Right                          Wrong

```c
        -----                          -----
        imsg=GetMsg(win->UserPort);    imsg=GetMsg(win->UserPort);
        class=imsg->Class;             class=imsg->Class;
        code=imsg->Code;               code=imsg->Code;
        /* OK */                       /* ILLEGAL ! */
        iaddress=imsg->IAddress;       gadid=((struct Gadget *)
                                               imsg->IAddress)->GadgetID;
        ReplyMsg(imsg);                ReplyMsg(imsg);


    Using the code in the left column, it is acceptable to get the
    address of a gadget with gadid=((struct Gadget *)iaddress)->GadgetID
    but only after you have checked to make sure the message is an
    [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) or [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html).
```
  * [Boolean](../Libraries_Manual_guide/node014C.html) gadgets only receive mouse messages if both [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14)

```c
    and [GACT_FOLLOWMOUSE](../Libraries_Manual_guide/node014B.html#line40) are set.  Those cases described below with
    GACT_RELVERIFY cleared do not apply to boolean gadgets.
```
  * In general, [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) messages are sent when the mouse changes

```c
    position while the gadget is active.  [Boolean](../Libraries_Manual_guide/node014C.html) and [proportional](../Libraries_Manual_guide/node0153.html)
    gadgets are active while the mouse button is held down, thus mouse
    move messages will be received when the user "drags" with the mouse.
    [String](../Libraries_Manual_guide/node0164.html) gadgets are active until terminated by keyboard entry or
    another object becomes active (generally by user clicking the other
    object).  [GACT_FOLLOWMOUSE](../Libraries_Manual_guide/node014B.html#line40) string gadgets will generate mouse moves
    the entire time they are active, not just when the mouse button is
    held.
```
The broadcasts received differ according to the gadget's flag settings.
If using the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) and [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) activation flags, the
program gets a gadget down message, receives mouse reports
([IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23)) as the mouse moves, and receives a gadget up message
when the mouse button is released.  For [boolean](../Libraries_Manual_guide/node014C.html) gadgets, the mouse button
must be released while the pointer is over the gadget. If the button is
not released over the boolean gadget, an [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) message with
the SELECTUP qualifier will be sent.

If only using the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) activation flag, the program gets a
gadget down message and receives mouse reports as the mouse moves. The
mouse reports will stop when the user releases the mouse select button.
This case does not apply to [boolean](../Libraries_Manual_guide/node014C.html) gadgets as [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) must be set
for boolean gadgets to receive mouse messages. If only using the
GACT_RELVERIFY activation flag, the program gets mouse reports followed by
an up event for a gadget.  For boolean gadgets, the [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) event
will only be received if the button was released while the pointer was
over the gadget.  If the button is not released over the boolean gadget, a
[IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) message with the SELECTUP qualifier will be received if
the program is receiving these events.

If neither the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) nor the [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) activation flags are
set, the program will only receive mouse reports.  This case does not
apply to [boolean](../Libraries_Manual_guide/node014C.html) gadgets  as GACT_RELVERIFY must be set for boolean
gadgets to receive mouse messages.

