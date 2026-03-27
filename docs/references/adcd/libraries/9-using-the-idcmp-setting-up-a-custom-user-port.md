---
title: 9 / Using the IDCMP / Setting Up A Custom User Port
manual: libraries
chapter: libraries
section: 9-using-the-idcmp-setting-up-a-custom-user-port
functions: [AllocSignal, CloseWindow, CreateMsgPort, DeleteMsgPort, ModifyIDCMP, OpenWindow, OpenWindowTagList, ReplyMsg]
libraries: [exec.library, intuition.library]
---

# 9 / Using the IDCMP / Setting Up A Custom User Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application can use its own message port for the IDCMP instead of the
one set up by Intuition, although some care is required.

As described earlier, IDCMP communication takes place through a pair of
Exec message ports attached to a window: the [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) and the [WindowPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md).
The UserPort is the port where the application receives IDCMP messages
from Intuition.  The WindowPort is the reply port where Intuition receives
replies from the application (via the [ReplyMsg()](libraries/24-messages-replying.md) function).

In the simplest case, Intuition allocates (and deallocates) both of these
ports when the program opens a window with non-NULL IDCMP flags.
Intuition will also allocate these ports if the application calls
[ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) with non-NULL flags for a window that has NULL IDCMP flags.
These port variables will be set to NULL if there is no message port
allocated, otherwise they will contain a pointer to a message port.

If the [WindowPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) is not already opened when either [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or
[ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) is called, it will be allocated and initialized.

The [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) is checked separately to see whether it is already opened.

When Intuition initializes the [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md), it also allocates a signal bit
with a call to [AllocSignal()](libraries/22-the-signal-system-signal-allocation.md).  Since the application makes the call to
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md), this signal bit is valid for the
application's task.  The address of the application's task is saved in the
[SigTask](libraries/24-exec-messages-and-ports-message-ports.md) variable of the message port.

The program may choose to supply its own [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md).  This might be done in
an environment where the program is using several windows and would prefer
to monitor the input using only one message port.  This is done by with
the following procedure:

 1. Create a port for the IDCMP by calling either the Exec function

```c
    [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md) or the amiga.lib function [CreatePort()](libraries/24-message-ports-creating-a-message-port.md), both of which
    return a pointer to a port.  (CreateMsgPort() is a new Exec function
    in V36 and can therefore only be used on systems running Release 2 or
    a later version of the OS.)
```
 2. Open the windows with no IDCMP flags set.  This will prevent

    Intuition from allocating a port for this window.
 3. Place a pointer to the port created in step 1 into the [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) field

```c
    of the [Window](libraries/4-intuition-windows-the-window-structure.md) structure.
```
 4. Call [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to set the desired IDCMP flags for the port.

```c
    Intuition will use the port supplied with the window.

    Be Careful with Shared IDCMP Ports.
    -----------------------------------
    If the application is sharing an IDCMP among several windows, it
    must be very careful not to call [ModifyIDCMP](libraries/9-intuition-input-and-output-methods-function-reference.md)(window,NULL) for any
    of the windows that are using the shared port, as this will free the
    port and the signal bit.
```
 5. When an application decides to close a window that has a shared

```c
    IDCMP, there may be messages waiting at the port for any of the
    windows including the window being closed.  It is essential that
    messages destined for a given window be removed and replied to before
    that window is closed.

    [CloseWindowSafely()](libraries/lib-examples-closewindowsafely-c.md), listed in the next example, performs proper
    message cleanup before closing such a window.  It also sets the
    window's [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md) to NULL so that Intuition knows not to delete the
    port, which should be done by the application in this case.  It is
    incorrect (and dangerous) to simply call [CloseWindow()](libraries/4-basic-window-structures-and-functions-closing-windows.md) on a window
    that has a shared IDCMP.

    Note that [CloseWindowSafely()](libraries/lib-examples-closewindowsafely-c.md) assumes that the window has a [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md).
```
 6. After all windows have been closed, and the port has been removed

```c
    from each, delete the port that was created in step 1.  Use the
    amiga.lib function [DeletePort()](libraries/24-message-ports-deleting-a-message-port.md) (if [CreatePort()](libraries/24-message-ports-creating-a-message-port.md) was used) or the
    Exec function [DeleteMsgPort()](libraries/24-message-ports-deleting-a-message-port.md) (if [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md) was used).
```
 [Closing a Window with a Shared IDCMP](libraries/lib-examples-closewindowsafely-c.md) 

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
