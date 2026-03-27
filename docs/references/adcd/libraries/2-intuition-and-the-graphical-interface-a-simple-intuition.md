---
title: 2 Intuition and the Graphical Interface / A Simple Intuition Program
manual: libraries
chapter: libraries
section: 2-intuition-and-the-graphical-interface-a-simple-intuition
functions: []
libraries: []
---

# 2 Intuition and the Graphical Interface / A Simple Intuition Program

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The sample Intuition program that follows shows all of the basic
requirements for an Intuition application. There are three important
points:

  * You must open the Intuition library before you can use the Intuition

```c
    functions.  Certain languages such as  require the pointer to the
    Intuition library to be assigned to a variable called IntuitionBase
    (see [Chapter 1](libraries/1-programming-in-the-amiga-environment-libraries-of.md) for more about this).
```
  * When you set up a [window](libraries/2-how-an-application-sees-intuition-screens-and-windows.md), you also specify the events that you want

```c
    to know about.  If the user performs some activity that triggers one
    of the events you specified, Intuition signals you and sends a
    [message](libraries/9-intuition-input-and-output-methods-intuition-input.md).  The message is a pointer to an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) data structure
    that describes the event in more detail.  Messages about Intuition
    events are sent to a [MsgPort](libraries/24-exec-messages-and-ports-message-ports.md) structure which queues up the messages
    for you in a linked list so that you may respond to them at your
    convenience.
```
  * Resources must be [returned](libraries/27-loading-and-displaying-the-view-exiting-gracefully.md) to the system.  In this case, any windows,

    screens or libraries that were opened are closed before exiting.
 [Example Intuition Event Loop](libraries/2-a-simple-intuition-program-example-intuition-event-loop.md) 
 [Intuition Example (V36 And Later)](libraries/lib-examples-easyintuition37-c.md) 
 [Intuition Example (All Versions)](libraries/lib-examples-easyintuition-c.md) 

