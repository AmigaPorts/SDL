---
title: Addressing
manual: amiga-mail
chapter: amiga-mail
section: addressing
functions: []
libraries: []
---

# Addressing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the SANA-II standard, network hardware addresses are stored in an array
of n bytes. No meaning is ascribed by the standard to the contents of the
array.

In case there exists a network which does not have an address field
consisting of a number of bits not divisible by eight, add pad bits at the
end of the bit stream. For example, if an address is ten bits long it will
be stored like this:


    98765432 10PPPPPP
    BYTE 0   BYTE 1
Where the numerals are bit numbers and 'P' is a pad (ignored) bit.

Driver users which do not implement the bit shifting necessary to use a
network with such addressing (if one exists) should at least check the
number of significant bits in the address field (returned from the
device's S2_DEVICEQUERY function) to make sure that it is evenly divisible
by eight.

Driver users will map hardware addresses to protocol addresses in a
protocol and hardware dependent manner, as described by the relevant
standards (i.e., RFC 826 for TCP/IP over Ethernet, RFC 1201 or 1051 for
TCP/IP over ARCNET). Some protocols will always use the same mapping on
all hardware, but other protocols will have particular address mapping
schemes for some particular hardware and a reasonable default for other
(unknown) hardware.

Some SANA-II devices will have "hardware addresses" which aren't really
hardware addresses. As an example, consider PPP (Point-to-Point Protocol).
PPP is a standard for transmitting IP packets over a serial line. It uses
IP addresses negotiated during the establishment of a connection. In a
SANA-II driver implementation of PPP, the driver would negotiate the
address at S2_CONFIGINTERFACE. Thus, the address in SrcAddr returned by
the device on an S2_CONFIGINTERFACE (or in a subsequent
S2_GETSTATIONADDRESS) will be a protocol address, not a true hardware
address.


```c
    Note:
    -----
    Some hardware always uses a ROM hardware address. Other hardware
    which has a ROM address or is configurable with DIP switches may be
    overridden by software. Some hardware always dynamically allocates a
    new hardware address at initialization. See "[Configuration](amiga-mail/configuration.md)" for
    details on how this is handled by driver writers and by driver users.
```
