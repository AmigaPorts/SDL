# 2 / / Gadgets, Menus And Requesters / The Intuition Input Event Loop


Once an application has set up the appropriate [screen](../Libraries_Manual_guide/node00CF.html), [window](../Libraries_Manual_guide/node00CF.html), [gadgets](../Libraries_Manual_guide/node00D1.html)
[menus](../Libraries_Manual_guide/node00D2.html) and [requesters](../Libraries_Manual_guide/node00D3.html), it waits for the user to do something.  Intuition
can notify an application whenever user activity occurs by sending a
[message](../Libraries_Manual_guide/node01D0.html).  The message is simply a pointer to some memory owned by
Intuition that contains an [IntuiMessage](../Libraries_Manual_guide/node01D9.html) data structure describing the user
activity that occurred.

To wait for user activity or other events, the Exec library provides a
special function named [Wait()](../Libraries_Manual_guide/node02F1.html).  The Exec Wait() function suspends your
task allowing other applications or system tasks to run while your
application is waiting for input or events from Intuition and other
sources.

Thus, the basic outline for any Intuition program is:

  * Set up the [window](../Libraries_Manual_guide/node00CF.html), [screen](../Libraries_Manual_guide/node00CF.html) and any required [gadgets](../Libraries_Manual_guide/node00D1.html), [menus](../Libraries_Manual_guide/node00D2.html) or

```c
    [requesters](../Libraries_Manual_guide/node00D3.html).
```
  * [Wait()](../Libraries_Manual_guide/node02F1.html) for a message from Intuition about user activity or other

    events. Copy needed data from the message and tell Intuition you
    received it by replying. Look at the data and take the appropriate
    action.
  * Repeat until the user wants to quit.

These steps, sometimes referred to as the Intuition input [event loop](../Libraries_Manual_guide/node01D7.html) are
basically the same for any Intuition application.

As you might expect, Intuition can send a message to your application
whenever the user presses a key on the keyboard or moves the mouse.  Other
types of input events Intuition will notify you about include gadget hits,
menu item selection, time elapsing, disk insertion, disk removal, and
window rearrangement.

[Gadgets](../Libraries_Manual_guide/node00D1.html), [menus](../Libraries_Manual_guide/node00D2.html), [requesters](../Libraries_Manual_guide/node00D3.html) are the nuts and bolts of the Intuition [GUI](../Libraries_Manual_guide/node00C8.html)
toolkit.  Much of the code in an application that uses Intuition deals
with the set up and operation of these important data objects.  No matter
how simple, complex, or fanciful your program design, it will fit within
the basic Intuition framework of [windows and screens](../Libraries_Manual_guide/node00CF.html), gadgets, menus and
requesters.  The users of the Amiga understand these basic Intuition
elements and trust that the building blocks remain constant.  This
consistency ensures that a well-designed program will be understandable to
the naive user as well as to the sophisticate.

