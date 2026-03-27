---
title: 4 / Other Window Functions / Changing Message Queue Limits
manual: libraries
chapter: libraries
section: 4-other-window-functions-changing-message-queue-limits
functions: [SetMouseQueue]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Changing Message Queue Limits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Starting with V36, windows have limits on the number of mouse movement and
repeat key messages that may be waiting at their IDCMP at any time.  These
queue limits prevent the accumulation of these messages, which may arrive
at the IDCMP message port in large numbers.

Once a queue limit is reached, further messages of that type will be
discarded by Intuition.  The application will never hear about the
discarded messages; they are gone forever.  (Note that only mouse move and
key repeat messages are limited this way.  Other types of messages will
still be added to the port.)  Messages of the limited type will arrive at
the port again after the application has replied to one of the messages in
the queue.

The queue limits are independent of each other.  Having reached the limit
for one type of message does not prevent other types of messages (that
have not yet reached their queuing limits) from being added to the IDCMP.
Note that the queues apply only to the IDCMP and not to messages received
directly via an input handler or from the console device.

Order of event arrival is not a factor in the message count.  Messages may
be sequential or interspersed with other events--only the number of
messages of the specific type waiting at the IDCMP matters.

The [WA_RptQueue](libraries/4-window-attributes-window-attribute-tags.md) tag allows setting an initial value for the repeat key
backlog limit for the window.  There is no function to change this value
as of V37.  The default value for WA_RptQueue is 3.

The [WA_MouseQueue](libraries/4-window-attributes-window-attribute-tags.md) tag allows setting an initial value for the mouse
message backlog limit for the window.  The default value for WA_MouseQueue
is 5.  The number may later be changed with a call to [SetMouseQueue()](autodocs-2.0/intuition-library-setmousequeue.md):


```c
    LONG SetMouseQueue( struct Window *window, unsigned long queueLength );
```
Note that real information may be lost if the queue fills and Intuition is
forced to discard messages.  See the chapter
"[Intuition Mouse and Keyboard](libraries/10-the-mouse-mouse-messages.md)" for more information.

---

## See Also

- [SetMouseQueue — intuition.library](../autodocs/intuition.library.md#setmousequeue)
