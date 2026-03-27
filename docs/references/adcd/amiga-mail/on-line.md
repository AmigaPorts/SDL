---
title: On-line
manual: amiga-mail
chapter: amiga-mail
section: on-line
functions: []
libraries: []
---

# On-line

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

     S2_ONLINE       S2_ONEVENT       S2_OFFLINE
In order to run hardware tests on an otherwise live system, the S2_OFFLINE
command allows the SANA-II device driver to be "turned off" until the
tests are complete and an ONLINE is sent to the driver. S2_ONLINE causes
the interface to re-configure and re-initialize. Any packets destined for
the hardware while the device is off-line will be lost. All pending and
new requests to the driver shall be returned with S2ERR_OUTOFSERVICE when
a device is off-line.

All driver users must understand that any IO request may return with
S2ERR_OUTOFSERVICE because the driver is off-line (any other program may
call S2_OFFLINE to make it so). In such an event, the driver will usually
want to wait until the unit comes back on-line (for the program which
called S2_OFFLINE to call S2_ONLINE). It may do this by calling S2_ONEVENT
to wait for S2EVENT_ONLINE. S2_ONEVENT allows the driver user to wait on
various events.

A driver must track events, but may not distinguish between some types of
events. Drivers return S2_ONEVENT with S2_ERR_NOT SUPPORTED and
S2WERR_BAD_EVENT for unsupported Events. One error may cause more than one
Event (see below). Errors which seem to have been caused by a malformed or
unusual request should not generally trigger an event.


```c
    Event types (S2EVENT_xxx):

      ERROR    - Return when any error occurs.
      TX       - Return on any transmit error (always an error).
      RX       - Return on any receive error (always an error).
      ONLINE   - Return when unit goes on-line or return immediately if
                 unit is already on-line (not an error).
      OFFLINE  - Return when unit goes off-line or return immediately if
                 unit is already off-line (not an error.)
      BUFF     - Return on any buffer management function error (always
                 an error).
      HARDWARE - Return when any hardware error occurs (always an error,
                 may be a TX or RX, too).
      SOFTWARE - Return when any software error occurs (always an error,
                 may be a TX or RX, too).
```
