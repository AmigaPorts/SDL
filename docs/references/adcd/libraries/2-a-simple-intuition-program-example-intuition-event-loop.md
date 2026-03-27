---
title: 2 / A Simple Intuition Program / Example Intuition Event Loop
manual: libraries
chapter: libraries
section: 2-a-simple-intuition-program-example-intuition-event-loop
functions: [Wait]
libraries: [exec.library]
---

# 2 / A Simple Intuition Program / Example Intuition Event Loop

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Intuition [event loop](libraries/9-using-the-idcmp-standard-intuimessage-event-loop.md) used in the example is very simple.  The example
first sets up a [custom screen](libraries/3-intuition-screens-custom-screen-functions.md), [opens a window](libraries/4-basic-window-structures-and-functions-opening-a-window.md) on it, then waits for
Intuition to send messages about user input with the following event loop:


```c
    winsignal = 1L << window1->UserPort->mp_SigBit;  /* window signal */
    signalmask = winsignal;   /* example only waits for window events */

    while( !done )  {
        signals = Wait(signalmask);
        if (signals & winsignal)
            done = handleIDCMP(window1);
    }
```
Intuition sends messages about user activity to a special port known as
the [IDCMP](libraries/9-intuition-input-receiving-input-events-from-intuition.md).  Each window can have its own IDCMP (in the code above the
IDCMP is window1->UserPort).  To wait for event messages to arrive at the
IDCMP port, the example code calls the Exec [Wait()](libraries/24-messages-waiting-for-a-message.md) function.  It then
processes and replies to any event messages that it gets in a subroutine
named handleIDCMP().  For this example, the only event Intuition will
report is the close window event.  When the example detects this event, it
[closes the window](libraries/4-basic-window-structures-and-functions-closing-windows.md), [closes the screen](libraries/3-creating-a-new-custom-screen-closing-the-screen.md), [closes the Intuition library](libraries/17-introduction-to-exec-libraries-and-devices.md) and
exits.  [Event loops](libraries/9-using-the-idcmp-standard-intuimessage-event-loop.md) similar to this one are used in Intuition examples
throughout this book.  For more information about IDCMP and user input,
see the chapters on "[Intuition Windows](libraries/4-intuition-windows-communicating-with-intuition.md)" and "[Intuition Input and Output](libraries/9-intuition-input-and-output-methods.md)".

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
