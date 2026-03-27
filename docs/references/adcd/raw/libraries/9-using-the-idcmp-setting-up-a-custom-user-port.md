# 9 / Using the IDCMP / Setting Up A Custom User Port


An application can use its own message port for the IDCMP instead of the
one set up by Intuition, although some care is required.

As described earlier, IDCMP communication takes place through a pair of
Exec message ports attached to a window: the [UserPort](../Libraries_Manual_guide/node01D6.html#line16) and the [WindowPort](../Libraries_Manual_guide/node01D6.html#line16).
The UserPort is the port where the application receives IDCMP messages
from Intuition.  The WindowPort is the reply port where Intuition receives
replies from the application (via the [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) function).

In the simplest case, Intuition allocates (and deallocates) both of these
ports when the program opens a window with non-NULL IDCMP flags.
Intuition will also allocate these ports if the application calls
[ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) with non-NULL flags for a window that has NULL IDCMP flags.
These port variables will be set to NULL if there is no message port
allocated, otherwise they will contain a pointer to a message port.

If the [WindowPort](../Libraries_Manual_guide/node01D6.html#line16) is not already opened when either [OpenWindow()](../Libraries_Manual_guide/node0103.html) or
[ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) is called, it will be allocated and initialized.

The [UserPort](../Libraries_Manual_guide/node01D6.html#line16) is checked separately to see whether it is already opened.

When Intuition initializes the [UserPort](../Libraries_Manual_guide/node01D6.html#line16), it also allocates a signal bit
with a call to [AllocSignal()](../Libraries_Manual_guide/node02D3.html#line5).  Since the application makes the call to
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) or [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5), this signal bit is valid for the
application's task.  The address of the application's task is saved in the
[SigTask](../Libraries_Manual_guide/node02EB.html#line36) variable of the message port.

The program may choose to supply its own [UserPort](../Libraries_Manual_guide/node01D6.html#line16).  This might be done in
an environment where the program is using several windows and would prefer
to monitor the input using only one message port.  This is done by with
the following procedure:

 1. Create a port for the IDCMP by calling either the Exec function

```c
    [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39) or the amiga.lib function [CreatePort()](../Libraries_Manual_guide/node02EC.html), both of which
    return a pointer to a port.  (CreateMsgPort() is a new Exec function
    in V36 and can therefore only be used on systems running Release 2 or
    a later version of the OS.)
```
 2. Open the windows with no IDCMP flags set.  This will prevent

    Intuition from allocating a port for this window.
 3. Place a pointer to the port created in step 1 into the [UserPort](../Libraries_Manual_guide/node01D6.html#line16) field

```c
    of the [Window](../Libraries_Manual_guide/node0121.html) structure.
```
 4. Call [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) to set the desired IDCMP flags for the port.

```c
    Intuition will use the port supplied with the window.

    Be Careful with Shared IDCMP Ports.
    -----------------------------------
    If the application is sharing an IDCMP among several windows, it
    must be very careful not to call [ModifyIDCMP](../Libraries_Manual_guide/node01E3.html#line5)(window,NULL) for any
    of the windows that are using the shared port, as this will free the
    port and the signal bit.
```
 5. When an application decides to close a window that has a shared

```c
    IDCMP, there may be messages waiting at the port for any of the
    windows including the window being closed.  It is essential that
    messages destined for a given window be removed and replied to before
    that window is closed.

    [CloseWindowSafely()](../Libraries_Manual_guide/node0583.html#line46), listed in the next example, performs proper
    message cleanup before closing such a window.  It also sets the
    window's [UserPort](../Libraries_Manual_guide/node01D6.html#line16) to NULL so that Intuition knows not to delete the
    port, which should be done by the application in this case.  It is
    incorrect (and dangerous) to simply call [CloseWindow()](../Libraries_Manual_guide/node0105.html) on a window
    that has a shared IDCMP.

    Note that [CloseWindowSafely()](../Libraries_Manual_guide/node0583.html#line46) assumes that the window has a [UserPort](../Libraries_Manual_guide/node01D6.html#line16).
```
 6. After all windows have been closed, and the port has been removed

```c
    from each, delete the port that was created in step 1.  Use the
    amiga.lib function [DeletePort()](../Libraries_Manual_guide/node02ED.html) (if [CreatePort()](../Libraries_Manual_guide/node02EC.html) was used) or the
    Exec function [DeleteMsgPort()](../Libraries_Manual_guide/node02ED.html#line26) (if [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39) was used).
```
 [Closing a Window with a Shared IDCMP](../Libraries_Manual_guide/node0583.html) 

