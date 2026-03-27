---
title: XI-1: Introduction to Commodities Exchange
manual: amiga-mail
chapter: amiga-mail
section: xi-1-introduction-to-commodities-exchange
functions: [DeleteCxObjAll]
libraries: [commodities.library]
---

# XI-1: Introduction to Commodities Exchange

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by John Orr


The input.device has a hand in almost all user input on the Amiga.  It
gathers input events from the keyboard, the gameport (mouse), and
several other sources, into one input "stream".  Special programs
called input event handlers intercept input events
 along this stream, examining and sometimes changing the input events.
Both Intuition and the console device use input handlers to process
user input.

Using the input.device, a program can introduce its own custom handler
into the chain of input handlers at almost any point in the chain.
"Hot key" programs, shell pop-up programs, and screen blankers all
commonly use custom input handlers to monitor u ser input before it
gets to the Intuition input handler.

Custom input handlers do have their drawbacks, however.  Not only are
these handlers hard to program, but because there is no standard way
to implement and control them, multiple handlers often do not work
well together.  Their antisocial behavior can res ult in load order
dependencies and incompatibilities between different custom input
handlers.  Even for the expert user, having several custom input
handlers coexist peacefully can be next to impossible.  The custom
input handler needs to take its next ev olutionary step.

Commodities Exchange is that step.  It provides a simple, standardized
way to program and control custom input handlers.  It is divided into
three parts: an Exec library, a controller program, and a scanned
library.

The Exec library is called commodities.library.  When it is first
opened, commodities.library establishes a single input handler just
before Intuition in the input chain.  When this input handler receives
an input event, it creates a CxMessage (Commoditie s Exchange Message)
corresponding to the input event, and diverts the CxMessage through
the network of Commodities Exchange input handlers.  These handlers
are made up of trees of different CxObjects (Commodities Exchange
Objects), each of which performs a simple operation on the CxMessages.
Any CxMessages that exit the network are returned to the
input.device's input stream as input events.

Through function calls to the commodities.library, an application can
install a custom input handler.  A Commodities Exchange application,
sometimes simply referred to as a commodity, uses the CxObject
primitives to do things such as filter certain CxMess ages, translate
CxMessages, signal a task when a CxObject receives a CxMessage, send a
message when a CxObject receives a CxMessage, or if necessary, call a
custom function when a CxObject receives a CxMessage.

The controller program is called Commodities Exchange.  The user can
monitor and control all the currently running Commodities Exchange
applications from this one program.  The user can enable and disable a
commodity, kill a commodity, or, if the commodit y has a window, ask
the commodity to show or hide its window.  When the user requests any
of these actions, the controller program sends the commodity a
message, telling it which action to perform.

The third component of Commodities Exchange is its scanned library
functions.  These functions are part of the amiga.lib scanned library.
They do a lot of the work involved with parsing command lines and tool
types.

Commodities Exchange is ideal for programs like hot keys/pop ups,
screen blankers, and mouse blankers that need to monitor all user
input.  Commodities Exchange should not be used as an alternate
method of receiving user input for an application.  Other a
pplications depend on getting user input in some form or another from
the input stream.  A greedy program that diverts input to itself
rather than letting the input go to where the user expects it can
seriously confuse the user, not to mention compromise the advantages
of multitasking.

 [CxObjects](amiga-mail/cxobjects.md)                [Filter CxObjects](amiga-mail/filter-cxobjects.md)         [Uniqueness](amiga-mail/uniqueness.md) 
 [Installing a Broker](amiga-mail/installing-a-broker.md)      [Senders CxObjects](amiga-mail/senders-cxobjects.md)        [DeleteCxObjAll()](amiga-mail/deletecxobjall.md) 
 [CxMessages](amiga-mail/cxmessages.md)               [Translate CxObjects](amiga-mail/translate-cxobjects.md)      [Other CxObjects](amiga-mail/other-cxobjects.md) 
 [Tool Types](amiga-mail/tool-types.md)               [CxObject Errors](amiga-mail/cxobject-errors.md)          [IX](amiga-mail/ix.md) 

---

## See Also

- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
