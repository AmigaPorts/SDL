---
title: 9 Intuition Input and Output Methods / Intuition Input
manual: libraries
chapter: libraries
section: 9-intuition-input-and-output-methods-intuition-input
functions: []
libraries: []
---

# 9 Intuition Input and Output Methods / Intuition Input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has an input device to monitor all input activity.  The input
activity nominally includes keyboard and mouse events, but which can be
extended to include other types of input signals.  When the user moves the
mouse, presses a mouse button or types on the keyboard, the input device
detects the activity from the specific device, and constructs an
[InputEvent](autodocs-2.0/includes-devices-inputevent-h.md).

An [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) is a message describing a single event, such as the
transition of a key on the keyboard from up to down.

The input device then passes the input events down a prioritized chain of
input handlers, which are routines in memory that process the input
events.  The sequence of input events passing through this chain of input
handlers is known as the input stream.  Any handler linked into this chain
can monitor and modify the event stream.

Each input handler may block (consume) events, allow events to pass
through to the next handler in the chain or add new events to the sequence.

Other devices and programs can add input events to the input stream by
sending messages to the input device.  For instance, AmigaDOS is able to
generate an input event whenever a disk is inserted or removed.

See the "[Input Device](devices/6-input-device.md)" chapter of the Amiga ROM Kernel Reference Manual:
Devices for more information on the Input device.

 [Intuition as an Input Handler](libraries/9-intuition-input-intuition-as-an-input-handler.md) 
 [Receiving Input Events from Intuition](libraries/9-intuition-input-receiving-input-events-from-intuition.md) 
 [IDCMP Events and the Input Focus](libraries/9-intuition-input-idcmp-events-and-the-input-focus.md) 

