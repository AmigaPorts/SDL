---
title: Handler Internal
manual: amiga-mail
chapter: amiga-mail
section: handler-internal
functions: []
libraries: []
---

# Handler Internal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several actions that are generally used by handlers to
allow messages returning from requested services (typically an Exec
device) to look like incoming request packets.  This allows the
handler to request an asynchronous operation but be notified of the
completion.  For example, a handler sends the serial.device a request
for a read, but instead of sending a plain IO request, it sends a DOS
packet disguised as an IO request.  The serial.device treats the
packet like a normal IO request, returning it to the handler when it
is finished. When the handler gets back its disguised DOS packet, it
knows that the read has completed.

ACTION_NIL               0       <internal>

Although not specifically an action, many returns look like this
value because the action field has not been filled in.

ACTION_READ_RETURN       1001    <internal>

Generally used to indicate the completion of an asynchronous read
request.

ACTION_WRITE_RETURN      1002    <internal>

Generally used to indicate the completion of an asynchronous write
request.

ACTION_TIMER             30     <internal>

Used to indicate the passage of a time interval.  Many handlers have
a steady stream of ACTION_TIMER packets so that they can schedule
house keeping and flush buffers when no activity has occurred for a
given time interval.

