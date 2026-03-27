---
title: 5 / String Gadget Type / Program Control of String Gadgets
manual: libraries
chapter: libraries
section: 5-string-gadget-type-program-control-of-string-gadgets
functions: [ActivateGadget, ModifyIDCMP, OpenWindowTagList, Request]
libraries: [intuition.library]
---

# 5 / String Gadget Type / Program Control of String Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[ActivateGadget()](autodocs-2.0/intuition-library-activategadget.md) allows the program to activate a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget (and
certain [custom](libraries/5-string-gadget-type-custom-gadgets.md) gadgets).  If successful, this function has the same effect
as the user clicking the mouse select button when the mouse pointer is
within the gadget's select box and any subsequent keystrokes will effect
the gadget's string.


```c
    BOOL ActivateGadget( struct Gadget *gadget, struct Window *window,
                         struct Requester *requester );
```
This function will fail if the user is in the middle of some other
interaction, such as menu or [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget operation.  In that case
it returns FALSE, otherwise it returns TRUE. The window or requester
containing the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget to be activated must itself be open and
active.  Since some operations in Intuition may occur after the function
that initiates them completes, calling [ActivateGadget()](autodocs-2.0/intuition-library-activategadget.md) after
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or [Request()](libraries/7-true-requesters-creating-application-requesters.md) is no guarantee that the gadget will
actually activate. Instead, call ActivateGadget() only after having
received an [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) or [IDCMP_REQSET](libraries/9-event-message-classes-and-flags-requester-flags.md) message for a newly opened
window or requester, respectively.


```c
    The Window Active Message Is Required.
    --------------------------------------
    It is incorrect to simply insert a small delay between the call to
    [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or [Request()](libraries/7-true-requesters-creating-application-requesters.md) and the call to [ActivateGadget()](autodocs-2.0/intuition-library-activategadget.md).
    Such schemes fail under various conditions, including changes in
    processor speed and CPU loading.
```
If you want to activate a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget in a newly opened window that has
a shared IDCMP [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md), there is an additional complication.  Sharing
UserPorts means that the window is opened without any IDCMP messages
enabled, and only later is [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) called to turn on message
passing.  If the newly opened window becomes active before ModifyIDCMP()
is called, the [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) message will not be received (because
IDCMP message passing was off at the time).  The following code will
handle this problem:


```c
       BOOL activated;

       /* Open window with NULL IDCMPFlags */
       win = OpenWindow( ... );

       /* Set the UserPort to your shared port, and turn on message
        * passing, which includes the IDCMP_ACTIVEWINDOW message.
        */
       win->UserPort = sharedport;
       ModifyIDCMP( win, ... | IDCMP_ACTIVEWINDOW | ... );

       /* If the window became active before the ModifyIDCMP() got
        * executed, then this ActivateGadget() can succeed.  If not, then
        * this ActivateGadget() might be too early, but in that case, we
        * know we'll receive the IDCMP_ACTIVEWINDOW event.  We handle that
        * below.
        */
        activated = ActivateGadget( stringgad, win, NULL );
```
  and later, in the event loop:


```c
    if ( (msg->Class == ACTIVEWINDOW) && ( !activated ) )
        success = ActivateGadget(stringgad,...);
```
Note however that a window which has the [WA_Activate](libraries/4-window-attributes-boolean-window-attribute-tags.md) attribute is not
guaranteed to be activated upon opening.  Certain conditions (like an
active [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget in another window) will prevent the automatic initial
activation of the window.  Therefore, do not let your code depend on
receiving the initial [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) message.

 [String Gadget Example](libraries/lib-examples-updatestrgad-c.md) 

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
