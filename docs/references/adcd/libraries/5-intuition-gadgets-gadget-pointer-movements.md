---
title: 5 Intuition Gadgets / Gadget Pointer Movements
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-pointer-movements
functions: []
libraries: []
---

# 5 Intuition Gadgets / Gadget Pointer Movements

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the [GACT_FOLLOWMOUSE](libraries/5-gadget-structure-gadget-activation-flags.md) flag is set for a gadget, the application will
receive mouse movement broadcasts as long as the gadget is active. This
section covers the behavior of [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md), [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) and [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets,
although there are major caveats in some cases:

  * Unlike [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) and [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s, the


```c
    [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field of an [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) IntuiMessage does not point to
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
    [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) or [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md).
```
  * [Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets only receive mouse messages if both [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md)

```c
    and [GACT_FOLLOWMOUSE](libraries/5-gadget-structure-gadget-activation-flags.md) are set.  Those cases described below with
    GACT_RELVERIFY cleared do not apply to boolean gadgets.
```
  * In general, [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) messages are sent when the mouse changes

```c
    position while the gadget is active.  [Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) and [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md)
    gadgets are active while the mouse button is held down, thus mouse
    move messages will be received when the user "drags" with the mouse.
    [String](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets are active until terminated by keyboard entry or
    another object becomes active (generally by user clicking the other
    object).  [GACT_FOLLOWMOUSE](libraries/5-gadget-structure-gadget-activation-flags.md) string gadgets will generate mouse moves
    the entire time they are active, not just when the mouse button is
    held.
```
The broadcasts received differ according to the gadget's flag settings.
If using the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) and [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) activation flags, the
program gets a gadget down message, receives mouse reports
([IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md)) as the mouse moves, and receives a gadget up message
when the mouse button is released.  For [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets, the mouse button
must be released while the pointer is over the gadget. If the button is
not released over the boolean gadget, an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with
the SELECTUP qualifier will be sent.

If only using the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) activation flag, the program gets a
gadget down message and receives mouse reports as the mouse moves. The
mouse reports will stop when the user releases the mouse select button.
This case does not apply to [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets as [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) must be set
for boolean gadgets to receive mouse messages. If only using the
GACT_RELVERIFY activation flag, the program gets mouse reports followed by
an up event for a gadget.  For boolean gadgets, the [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) event
will only be received if the button was released while the pointer was
over the gadget.  If the button is not released over the boolean gadget, a
[IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with the SELECTUP qualifier will be received if
the program is receiving these events.

If neither the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) nor the [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) activation flags are
set, the program will only receive mouse reports.  This case does not
apply to [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets  as GACT_RELVERIFY must be set for boolean
gadgets to receive mouse messages.

