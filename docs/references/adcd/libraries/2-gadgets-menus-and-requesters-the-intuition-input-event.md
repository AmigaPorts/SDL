---
title: 2 / / Gadgets, Menus And Requesters / The Intuition Input Event Loop
manual: libraries
chapter: libraries
section: 2-gadgets-menus-and-requesters-the-intuition-input-event
functions: [Wait]
libraries: [exec.library]
---

# 2 / / Gadgets, Menus And Requesters / The Intuition Input Event Loop

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once an application has set up the appropriate [screen](libraries/2-how-an-application-sees-intuition-screens-and-windows.md), [window](libraries/2-how-an-application-sees-intuition-screens-and-windows.md), [gadgets](libraries/2-gadgets-menus-and-requesters-gadgets.md)
[menus](libraries/2-gadgets-menus-and-requesters-menus.md) and [requesters](libraries/2-gadgets-menus-and-requesters-requesters.md), it waits for the user to do something.  Intuition
can notify an application whenever user activity occurs by sending a
[message](libraries/9-intuition-input-and-output-methods-intuition-input.md).  The message is simply a pointer to some memory owned by
Intuition that contains an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) data structure describing the user
activity that occurred.

To wait for user activity or other events, the Exec library provides a
special function named [Wait()](libraries/24-messages-waiting-for-a-message.md).  The Exec Wait() function suspends your
task allowing other applications or system tasks to run while your
application is waiting for input or events from Intuition and other
sources.

Thus, the basic outline for any Intuition program is:

  * Set up the [window](libraries/2-how-an-application-sees-intuition-screens-and-windows.md), [screen](libraries/2-how-an-application-sees-intuition-screens-and-windows.md) and any required [gadgets](libraries/2-gadgets-menus-and-requesters-gadgets.md), [menus](libraries/2-gadgets-menus-and-requesters-menus.md) or

```c
    [requesters](libraries/2-gadgets-menus-and-requesters-requesters.md).
```
  * [Wait()](libraries/24-messages-waiting-for-a-message.md) for a message from Intuition about user activity or other

    events. Copy needed data from the message and tell Intuition you
    received it by replying. Look at the data and take the appropriate
    action.
  * Repeat until the user wants to quit.

These steps, sometimes referred to as the Intuition input [event loop](libraries/9-using-the-idcmp-standard-intuimessage-event-loop.md) are
basically the same for any Intuition application.

As you might expect, Intuition can send a message to your application
whenever the user presses a key on the keyboard or moves the mouse.  Other
types of input events Intuition will notify you about include gadget hits,
menu item selection, time elapsing, disk insertion, disk removal, and
window rearrangement.

[Gadgets](libraries/2-gadgets-menus-and-requesters-gadgets.md), [menus](libraries/2-gadgets-menus-and-requesters-menus.md), [requesters](libraries/2-gadgets-menus-and-requesters-requesters.md) are the nuts and bolts of the Intuition [GUI](libraries/2-user-interfaces-elements-of-the-graphical-user-interface.md)
toolkit.  Much of the code in an application that uses Intuition deals
with the set up and operation of these important data objects.  No matter
how simple, complex, or fanciful your program design, it will fit within
the basic Intuition framework of [windows and screens](libraries/2-how-an-application-sees-intuition-screens-and-windows.md), gadgets, menus and
requesters.  The users of the Amiga understand these basic Intuition
elements and trust that the building blocks remain constant.  This
consistency ensures that a well-designed program will be understandable to
the naive user as well as to the sophisticate.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
