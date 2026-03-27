---
title: Broadcast and Multicast
manual: amiga-mail
chapter: amiga-mail
section: broadcast-and-multicast
functions: []
libraries: []
---

# Broadcast and Multicast

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  S2_ADDMULTICASTADDRESS        S2_MULTICAST
  S2_DELMULTICASTADDRESS        S2_BROADCAST

Some hardware supports broadcast and/or multicast. A broadcast is a packet
sent to all other machines. A multicast is a packet sent to a set of
machines. Drivers for hardware which does not allow broadcast or multicast
will return ios2_Error S2ERR_NOT_SUPPORTED as appropriate.

To send a broadcast, use S2_BROADCAST instead of CMD_WRITE. Broadcasts are
received just like any other packets (using a CMD_READ for the appropriate
packet type).

To send a multicast, use S2_MULTICAST instead of CMD_WRITE. The device
keeps a list of addresses that want to receive multicasts. You add a
receiver's address to this list by using S2_ADDMULTICASTADDRESS. The
receiver then posts a CMD_READ for the type of packet to be received. Some
SANA-II devices which support multicast may have a limit on the number of
addresses that can simultaneously wait for packets. Always check for an
S2WERR_MULTICAST_FULL error return when adding a multicast address.

Note that when the device adds a multicast address, it is usually added
for all users of the device, not just the driver user which called
S2_ADDMULTICASTADDRESS. In other words, received multicast packets will
fill a read request of the appropriate type regardless of whether the
requesting driver user is the same one which added the multicast address.

In general, driver users should not care how received packets were sent
(normally or broadcast/multicast), only that it was received. If a driver
user really must know, however, it can check for SANA2IOB_BCAST and/or
SANA2IOB_MCAST in the ios2_Flags field.

Drivers should keep a count for the number of opens on a multicast address
so that they don't actually remove it until it has been
S2_DELMULTICASTADDRESS'd as many times as it has been
S2_ADDMULTICASTADDRESS'd.

