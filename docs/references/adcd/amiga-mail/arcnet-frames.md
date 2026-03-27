---
title: ARCNET Frames
manual: amiga-mail
chapter: amiga-mail
section: arcnet-frames
functions: []
libraries: []
---

# ARCNET Frames

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ARCNET also has a special problem with framing. ARCNET frames consist of a
hardware header and a software header. The software header is in the data
area of the hardware packet, and includes at least the protocol ID.

There are two types of software header. Old-style ARCNET software headers
consist entirely of a one or two byte protocol ID. New ARCNET software
headers (defined in RFC 1201 and in the paper "ARCNET Packet Header
Definition Standard", Novell, Inc., 1989) include more information. They
allow more efficient use of ARCNET through data link layer fragmentation
and reassembly (ARCNET has a small Maximum Transmission Unit) and allow
sending any size packet up to the MTU (rather than requiring that packets
of size 253, 254 and 255 be padded to at least 256 bytes).

SANA-II device drivers for ARCNET should implement the old ARCNET packet
headers. Driver users which wish to interoperate with platforms using the
new software headers must add the new fields to the data to be sent and
must process it for incoming data. A SANA-II driver which implemented the
data link layer fragmentation internally (and advertised a large MTU)
could be more efficient than requiring the driver user to do it. This
would make driver writing more difficult and reduce interoperability, but
if there is ever a demand for that extra performance, a new hardware type
may be assigned by Commodore for SANA-II ARCNET device drivers which
implement the new framing.

