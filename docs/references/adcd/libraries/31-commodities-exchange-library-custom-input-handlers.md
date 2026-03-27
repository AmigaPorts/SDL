---
title: 31 Commodities Exchange Library / Custom Input Handlers
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-custom-input-handlers
functions: []
libraries: []
---

# 31 Commodities Exchange Library / Custom Input Handlers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The input.device has a hand in almost all user input on the Amiga.  It
gathers input events from the keyboard, the gameport (mouse), and several
other sources, into one input "stream".  Special programs called input
event handlers intercept input events along this stream, examining and
sometimes changing the input events.  Both Intuition and the console
device use input handlers to process user input.


```c
     [Figure 31-1: The Amiga Input Stream](libraries/lib-pics-31-1-pic.md) 
```
Using the input.device, a program can introduce its own custom handler
into the chain of input handlers at almost any point in the chain.  "Hot
key" programs, shell pop-up programs, and screen blankers all commonly use
custom input handlers to monitor user input before it gets to the
Intuition input handler.



```c
     [Figure 31-2: A Custom Input Handler](libraries/lib-pics-31-2-pic.md) 
```
Custom input handlers do have their drawbacks, however.  Not only are
these handlers hard to program, but because there is no standard way to
implement and control them, multiple handlers often do not work well
together.  Their antisocial behavior can result in load order dependencies
and incompatibilities between different custom input handlers.  Even for
the expert user, having several custom input handlers coexist peacefully
can be next to impossible.


```c
     [Figure 31-3: The Commodities Network](libraries/lib-pics-31-3-pic.md) 
```
Commodities Exchange eliminates these problems by providing a simple,
standardized way to program and control custom input handlers.  It is
divided into three parts: an Exec library, a controller program, and some
amiga.lib functions.

The Exec library is called commodities.library.  When it is first opened,
commodities.library establishes a single input handler just before
Intuition in the input chain.  When this input handler receives an input
event, it creates a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) (Commodities Exchange Message) corresponding
to the input event, and diverts the CxMessage through the network of
Commodities Exchange input handlers (Figure 31-3).

These handlers are made up of trees of different [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) (Commodities
Exchange Objects), each of which performs a simple operation on the
[CxMessages](libraries/31-commodities-exchange-library-cxmessages.md).  Any CxMessages that exit the network are returned to the
input.device's input stream as input events.

Through function calls to the commodities.library, an application can
install a custom input handler.  A Commodities Exchange application,
sometimes simply referred to as a commodity, uses the [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) primitives
to do things such as filter certain [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md), translate CxMessages,
signal a task when a CxObject receives a CxMessage, send a message when a
CxObject receives a CxMessage, or if necessary, call a custom function
when a CxObject receives a CxMessage.

The controller program is called Commodities Exchange.  The user can
monitor and control all the currently running Commodities Exchange
applications from this one program.  The user can enable and disable a
commodity, kill a commodity, or, if the commodity has a window, ask the
commodity to show or hide its window.  When the user requests any of these
actions, the controller program sends the commodity a message, telling it
which action to perform.

The third component of Commodities Exchange is its scanned library
functions.  These functions are part of the amiga.lib scanned library.
They do a lot of the work involved with parsing command lines and Tool
Types.

Commodities Exchange is ideal for programs like hot keys/pop ups, screen
blankers, and mouse blankers that need to monitor all user input.
Commodities Exchange should never be used as an alternate method of
receiving user input for an application.  Other applications depend on
getting user input in some form or another from the input stream.   A
greedy program that diverts input to itself rather than letting the input
go to where the user expects it can seriously confuse the user, not to
mention compromise the advantages of multitasking.

