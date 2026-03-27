# 2 / A Simple Intuition Program / Example Intuition Event Loop


The Intuition [event loop](../Libraries_Manual_guide/node01D7.html) used in the example is very simple.  The example
first sets up a [custom screen](../Libraries_Manual_guide/node00DF.html), [opens a window](../Libraries_Manual_guide/node0103.html) on it, then waits for
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
the [IDCMP](../Libraries_Manual_guide/node01D2.html).  Each window can have its own IDCMP (in the code above the
IDCMP is window1->UserPort).  To wait for event messages to arrive at the
IDCMP port, the example code calls the Exec [Wait()](../Libraries_Manual_guide/node02F1.html) function.  It then
processes and replies to any event messages that it gets in a subroutine
named handleIDCMP().  For this example, the only event Intuition will
report is the close window event.  When the example detects this event, it
[closes the window](../Libraries_Manual_guide/node0105.html), [closes the screen](../Libraries_Manual_guide/node00E4.html), [closes the Intuition library](../Libraries_Manual_guide/node028E.html#line91) and
exits.  [Event loops](../Libraries_Manual_guide/node01D7.html) similar to this one are used in Intuition examples
throughout this book.  For more information about IDCMP and user input,
see the chapters on "[Intuition Windows](../Libraries_Manual_guide/node010C.html)" and "[Intuition Input and Output](../Libraries_Manual_guide/node01CE.html)".

