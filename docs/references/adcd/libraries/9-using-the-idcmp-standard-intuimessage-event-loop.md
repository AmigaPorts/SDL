---
title: 9 / Using the IDCMP / Standard IntuiMessage Event Loop
manual: libraries
chapter: libraries
section: 9-using-the-idcmp-standard-intuimessage-event-loop
functions: [Wait]
libraries: [exec.library]
---

# 9 / Using the IDCMP / Standard IntuiMessage Event Loop

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application should handle events quickly.  Any delay in this handling
will make the user interface appear sluggish to the user.  Additionally,
certain events such as [IDCMP_SIZEVERIFY](libraries/9-event-message-classes-and-flags-window-flags.md) may time-out if the application
does not respond to them quickly  (this is to help prevent system
deadlocks).  The action taken by Intuition when an event times-out may not
match the action desired by the program.  When IDCMP_SIZEVERIFY times out,
the window sizing operation is cancelled by Intuition.

Code should be able to handle the case where there are multiple events
waiting at the port.  When events are being generated quickly, Intuition
may post many events to the IDCMP before the application regains control.
This can happen regardless of how fast the application processes the
messages waiting at the port.  Since messages queue up but signals do not,
the application may not see a signal for each message posted.  Because of
these facts, the code should remove all the messages waiting at the port,
regardless of the number, each time [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) returns.

Code should also be able to handle the case where the signal is set but no
events are waiting at the port.  This could happen if a new message
arrives at the IDCMP while an application is still processing the previous
message.  Since applications typically process all queued messages before
returning to [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md), the second message gets handled with the signal bit
still set.  The subsequent call to Wait() will return immediately even
though no message is present.  These cases should be quietly ignored.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
