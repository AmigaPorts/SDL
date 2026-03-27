# 5 / String Gadget Type / Program Control of String Gadgets


[ActivateGadget()](../Includes_and_Autodocs_2._guide/node01F9.html) allows the program to activate a [string](../Libraries_Manual_guide/node0164.html) gadget (and
certain [custom](../Libraries_Manual_guide/node0176.html) gadgets).  If successful, this function has the same effect
as the user clicking the mouse select button when the mouse pointer is
within the gadget's select box and any subsequent keystrokes will effect
the gadget's string.


```c
    BOOL ActivateGadget( struct Gadget *gadget, struct Window *window,
                         struct Requester *requester );
```
This function will fail if the user is in the middle of some other
interaction, such as menu or [proportional](../Libraries_Manual_guide/node0153.html) gadget operation.  In that case
it returns FALSE, otherwise it returns TRUE. The window or requester
containing the [string](../Libraries_Manual_guide/node0164.html) gadget to be activated must itself be open and
active.  Since some operations in Intuition may occur after the function
that initiates them completes, calling [ActivateGadget()](../Includes_and_Autodocs_2._guide/node01F9.html) after
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) or [Request()](../Libraries_Manual_guide/node01A2.html#line12) is no guarantee that the gadget will
actually activate. Instead, call ActivateGadget() only after having
received an [IDCMP_ACTIVEWINDOW](../Libraries_Manual_guide/node01E0.html#line36) or [IDCMP_REQSET](../Libraries_Manual_guide/node01DF.html) message for a newly opened
window or requester, respectively.


```c
    The Window Active Message Is Required.
    --------------------------------------
    It is incorrect to simply insert a small delay between the call to
    [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) or [Request()](../Libraries_Manual_guide/node01A2.html#line12) and the call to [ActivateGadget()](../Includes_and_Autodocs_2._guide/node01F9.html).
    Such schemes fail under various conditions, including changes in
    processor speed and CPU loading.
```
If you want to activate a [string](../Libraries_Manual_guide/node0164.html) gadget in a newly opened window that has
a shared IDCMP [UserPort](../Libraries_Manual_guide/node01D6.html#line16), there is an additional complication.  Sharing
UserPorts means that the window is opened without any IDCMP messages
enabled, and only later is [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) called to turn on message
passing.  If the newly opened window becomes active before ModifyIDCMP()
is called, the [IDCMP_ACTIVEWINDOW](../Libraries_Manual_guide/node01E0.html#line36) message will not be received (because
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
Note however that a window which has the [WA_Activate](../Libraries_Manual_guide/node0125.html#line90) attribute is not
guaranteed to be activated upon opening.  Certain conditions (like an
active [string](../Libraries_Manual_guide/node0164.html) gadget in another window) will prevent the automatic initial
activation of the window.  Therefore, do not let your code depend on
receiving the initial [IDCMP_ACTIVEWINDOW](../Libraries_Manual_guide/node01E0.html#line36) message.

 [String Gadget Example](../Libraries_Manual_guide/node0597.html) 

