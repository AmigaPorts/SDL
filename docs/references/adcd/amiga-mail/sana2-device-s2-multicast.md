---
title: sana2.device/S2_MULTICAST
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-multicast
functions: []
libraries: []
---

# sana2.device/S2_MULTICAST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Multicast -- Multicast a packet on network.
FUNCTION

    This command works the same as CMD_WRITE except that it also performs
    whatever special processing of the packet is required to do a
    multicast send. The actual multicast mechanism is neccessarily
    network/interface/device specific.
IO REQUEST

    ios2_Command    - S2_MULTICAST.
    ios2_Flags      - Supported flags are:
                            SANA2IOB_RAW
                            SANA2IOB_QUICK
    ios2_PacketType - Packet type to send.
    ios2_DstAddr    - Destination interface address for this packet.
    ios2_DataLength - Length of the Data to be sent.
    ios2_Data       - Abstract data structure which packet data is
                      contained in.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
                      This command can fail for many reasons and
                      is not supported by all networks and/or
                      network interfaces.
    ios2_WireError  - More specific error number.
```
NOTES

```c
    The address supplied in ios2_DstAddr will be sanity checked (if
    possible) by the driver. If the supplied address fails this sanity
    check, the multicast request will fail immediately with ios2_Error
    set to S2WERR_BAD_MULTICAST.

    Another Amiga will not receive a multicast packet unless it has had
    the particular multicast address being used S2_ADDMULTICASTADRESS'd.
```
SEE ALSO

    CMD_WRITE, S2_BROADCAST, S2_ADDMULTICASTADDRESS
BUGS

