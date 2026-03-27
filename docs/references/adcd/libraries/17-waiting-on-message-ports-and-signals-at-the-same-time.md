---
title: 17 / / Waiting on Message Ports and Signals at the Same Time
manual: libraries
chapter: libraries
section: 17-waiting-on-message-ports-and-signals-at-the-same-time
functions: [Wait]
libraries: [exec.library]
---

# 17 / / Waiting on Message Ports and Signals at the Same Time

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most applications need to wait for a variety of messages and signals from
a variety of sources.  For example, an application might be waiting for
Window events and also timer.device messages.  In this case, an
application must [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) on the combined signal bits of all signals it is
interested in, including the signals for the message ports where any
messages might arrive.

The [MsgPort](libraries/24-exec-messages-and-ports-message-ports.md) structure, which is defined in <exec/[ports.h](autodocs-2.0/includes-exec-ports-h.md)>, is what Exec
uses to keep track of a message port.  The [UserPort](libraries/4-intuition-windows-the-window-structure.md) field from the [example](libraries/17-introduction-to-exec-interprocess-communications.md)
above points to one of these structures.  In this structure is a field
called [mp_SigBit](libraries/24-exec-messages-and-ports-message-ports.md), which contains the number (not the actual bit mask) of
the message port's signal bit.  To [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) on the signal of a message port,
Wait() on a bit mask created by shifting 1L to the left mp_SigBit times
(1L << msgport->mp_SigBit).  The resulting bit mask can be OR'd with the
bit masks for any other signals you wish to simultaneously wait on.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
