---
title: 9 Intuition Input and Output Methods / Using the IDCMP
manual: libraries
chapter: libraries
section: 9-intuition-input-and-output-methods-using-the-idcmp
functions: [ModifyIDCMP, OpenWindowTagList, ReplyMsg]
libraries: [exec.library, intuition.library]
---

# 9 Intuition Input and Output Methods / Using the IDCMP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IDCMP allow the application to receive information directly from
Intuition.  The program can use the IDCMP to learn about mouse, keyboard
and other Intuition events.  Also, certain useful Intuition features, most
notably the verification functions (described under "[IDCMP Flags](libraries/9-idcmp-flags-verification-functions.md)" below),
require that the IDCMP be opened, as this is the only mechanism available
for accessing these features.

The IDCMP consists of a pair of message ports, which may be allocated and
initialized by Intuition at the request of the program.  Alternately, the
application may choose to manage part of the allocation, such that one
port is supplied by the application and one port is supplied by Intuition.
These ports are standard Exec message ports, used to allow interprocess
communications in the Amiga multitasking environment.  To learn more about
message ports and message passing, see the "[Exec Messages and Ports](libraries/24-exec-messages-and-ports.md)"
chapter.

The IDCMP is always associated with a window, it is not possible to have
an IDCMP without an open window.  The IDCMP is made up of several fields
in the [Window](libraries/4-intuition-windows-the-window-structure.md) structure:

  * IDCMPFlags stores the IDCMP flags currently set for this port. This

```c
    field should never be directly set by the application; use the
    function [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) or set them when the window is opened instead.
```
  * UserPort is a pointer to the standard Exec message port where the

    application receives input event messages from Intuition
  * WindowPort is a pointer to the reply message port used by Intuition.

```c
    The messages sent by Intuition are set up such that [ReplyMsg()](libraries/24-messages-replying.md) will
    return them to this port.
```
To open these ports automatically, set at least one of the IDCMP flags in
the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.  To free these ports later in the program,
call the function [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) with NULL for the IDCMP flags or simply
close the window.


```c
    Don't Reply Any Messages After the IDCMP is Freed.
    --------------------------------------------------
    If an IDCMP is freed, either by calling [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) or by
    closing the window, Intuition will reclaim and deallocate all
    messages waiting at that port without waiting for a [ReplyMsg()](libraries/24-messages-replying.md).
    If the program attempts to ReplyMsg() to an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s after
    the IDCMP is closed, the system will probably crash.
```
If the IDCMP flags are NULL when the window is opened, no ports will be
allocated when the window is created.  To have Intuition allocate these
ports later, call the function [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) with any of the IDCMP flags
set.  (Starting in V37, ModifyIDCMP() returns NULL if it was unable to
create the necessary message ports.  Do not check the return code under
V36 or earlier.)

Once the IDCMP is opened, with the ports allocated, the program can
receive many types of information directly from Intuition, based on the
IDCMP flags that are set.

The IDCMP allows the application to receive only the events that it
considers important.  The program can, for instance, choose to learn about
gadget events but may not want to learn about other mouse or keyboard
events.  This is done by providing a "filter" or "mask" value for the
IDCMP which tells Intuition which events it should send to this specific
port.  Only messages with a type matching one of the flags set in the
[Window](libraries/4-intuition-windows-the-window-structure.md) structure's IDCMPFlags field will be sent to this port.  These
values may be set at creation time, or modified by calling the function
[ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md).

Messages sent to the IDCMP are instances of the structure [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).
This is an extended form of the Exec [Message](libraries/24-exec-messages-and-ports-messages.md) structure which allows
Intuition to send user interface specific information to the application.
The IntuiMessage structure is discussed at length below.

After the application opens an IDCMP, it must monitor the port for
messages.  At a minimum, this involves removing all messages from the port
and replying to them.  An event loop which processes messages arriving at
the IDCMP is discussed [below](libraries/9-using-the-idcmp-standard-intuimessage-event-loop.md).

 [Standard IntuiMessage Event Loop](libraries/9-using-the-idcmp-standard-intuimessage-event-loop.md)    [Setting Up A Custom User Port](libraries/9-using-the-idcmp-setting-up-a-custom-user-port.md) 
 [Event Loop Example](libraries/lib-examples-eventloop-c.md)                  [IntuiMessages](libraries/9-using-the-idcmp-intuimessages.md) 

---

## See Also

- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
