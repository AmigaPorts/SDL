# 2 Intuition and the Graphical Interface / A Simple Intuition Program


The sample Intuition program that follows shows all of the basic
requirements for an Intuition application. There are three important
points:

  * You must open the Intuition library before you can use the Intuition

```c
    functions.  Certain languages such as  require the pointer to the
    Intuition library to be assigned to a variable called IntuitionBase
    (see [Chapter 1](../Libraries_Manual_guide/node000D.html) for more about this).
```
  * When you set up a [window](../Libraries_Manual_guide/node00CF.html), you also specify the events that you want

```c
    to know about.  If the user performs some activity that triggers one
    of the events you specified, Intuition signals you and sends a
    [message](../Libraries_Manual_guide/node01D0.html).  The message is a pointer to an [IntuiMessage](../Libraries_Manual_guide/node01D9.html) data structure
    that describes the event in more detail.  Messages about Intuition
    events are sent to a [MsgPort](../Libraries_Manual_guide/node02EB.html) structure which queues up the messages
    for you in a linked list so that you may respond to them at your
    convenience.
```
  * Resources must be [returned](../Libraries_Manual_guide/node0334.html#line14) to the system.  In this case, any windows,

    screens or libraries that were opened are closed before exiting.
 [Example Intuition Event Loop](../Libraries_Manual_guide/node00D6.html) 
 [Intuition Example (V36 And Later)](../Libraries_Manual_guide/node05A6.html) 
 [Intuition Example (All Versions)](../Libraries_Manual_guide/node05A5.html) 

