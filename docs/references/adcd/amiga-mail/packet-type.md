---
title: Packet Type
manual: amiga-mail
chapter: amiga-mail
section: packet-type
functions: []
libraries: []
---

# Packet Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Network frames always have a type field associated with them. These type
fields vary in length, position and meaning by frame type (frame types
generally correspond one-to-one with hardware types, but see
"[Ethernet Packet Types](amiga-mail/ethernet-packet-types.md)" below). The meanings of the type numbers are
always carefully defined and every type number is registered with some
official body. Do not use a type number which is not registered for any
standard hardware you use or in a manner inconsistent with that
registration.

The type field allows the SANA-II device driver to fulfill CMD_READs based
on the type of packet the driver user wants. Multiple protocols can
therefore run over the same wire using the same driver without stepping on
each other's toes.

Packet types are specified as a long word. Unfortunately, the type field
means different things on different wires. Driver users must allow their
software to be configured with a SANA-II device name, unit number and the
type number(s) used by the protocol stack with each device. This way, if
new hardware becomes available, a hardware manufacturer can supply a
listing of type assignments to configure pre-existing software.

