---
title: 8 / The Keyboard / How the Keyboard Data is Received
manual: hardware
chapter: hardware
section: 8-the-keyboard-how-the-keyboard-data-is-received
functions: []
libraries: []
---

# 8 / The Keyboard / How the Keyboard Data is Received

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The  [CNT line](hardware/e-connectors-and-interfaces-port-signal-assignments-for.md)  is used as a clock for the keyboard. On each transition of
this line, one bit of data is clocked in from the keyboard. The keyboard
sends this clock when each data bit is stable on the  [SP line](hardware/e-connectors-and-interfaces-port-signal-assignments-for.md) . The clock
is an active low pulse. The rising edge of this pulse clocks in the data.

After a data byte has been received from the keyboard, an  [interrupt](hardware/f-8520-complex-interface-adapters-interrupt-control.md)  from
the 8520 is issued to the processor.  The keyboard waits for a handshake
signal from the system before transmitting any more keystrokes. This
handshake is issued by the processor pulsing the  [SP line](hardware/e-connectors-and-interfaces-port-signal-assignments-for.md)  low then high.
While some keyboards can detect a 1 microsecond handshake pulse, the pulse
must be at least 85 microseconds for operation with all models of Amiga
keyboards.

If another keystroke is received before the previous one has been accepted
by the processor, the keyboard microprocessor holds keys in a 10 keycode
type-ahead buffer.

