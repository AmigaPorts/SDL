---
title: 9 / Intuition Input / Receiving Input Events from Intuition
manual: libraries
chapter: libraries
section: 9-intuition-input-receiving-input-events-from-intuition
functions: []
libraries: []
---

# 9 / Intuition Input / Receiving Input Events from Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two channels through which a window can receive events destined
for it.  The usual way is for the application to ask Intuition to send it
messages which are based on the input event that Intuition has processed.
These messages, called [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s, are standard Amiga Exec messages,
and are sent to a port called an Intuition Direct Communications Message
Port, or IDCMP.  Every window may have an IDCMP associated with it
(pointed to by [Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)).

There are many classes of [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s, and the application can control
which classes of events are routed to its window's port by setting the
appropriate IDCMP flags.  When Intuition has an event to send, but the
window does not have the corresponding IDCMP flag set, the event is
generally passed along to the next input handler in the chain.  One input
handler that resides below Intuition's is the console device's handler.
If your application's window has a console attached to it, the console
device will generally convert events it receives into console code
sequences, and send those to your console. In this manner, you can hear
these events.

Because [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s and the IDCMP are the primary way in which
applications receive communication from Intuition, discussions elsewhere
in the manual frequently refer to events from Intuition as messages,
IntuiMessages, or IDCMP messages.  However, most of the information sent
as IntuiMessages is also available through the console device, though that
option is used less often.  Elsewhere in this chapter, you can learn how
getting your events through the console differs from getting them through
your IDCMP.

Whichever way an application chooses to get its messages, it is frequently
designed to be event-driven.  That is to say, after some amount of
initialization, the application will go into a state where it is waiting
for some event to happen.  This event could be an input event, or some
other kind of event.  Based on the event received, the application would
take appropriate action, and return to its waiting state.

