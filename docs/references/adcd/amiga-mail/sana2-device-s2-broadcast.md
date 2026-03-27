---
title: sana2.device/S2_BROADCAST
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-broadcast
functions: []
libraries: []
---

# sana2.device/S2_BROADCAST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Broadcast -- Broadcast a packet on network.
FUNCTION

    This command works the same as CMD_WRITE except that it also performs
    whatever special processing of the packet is required to do a
    broadcast send. The actual broadcast mechanism is neccessarily
    network/interface/device specific.
IO REQUEST

    ios2_Command    - S2_BROADCAST.
    ios2_Flags      - Supported flags are:
                            SANA2IOB_RAW
                            SANA2IOB_QUICK
    ios2_PacketType - Packet type to send.
    ios2_DataLength - Length of the Data to be sent.
    ios2_Data       - Abstract data structure which packet data is
                      contained in.
RESULTS

```c
    ios2_DstAddr    - The contents of this field are to be
                      considered trash upon return of the IOReq.
    ios2_Error      - Zero if successful; non-zero otherwise.
                      This command can fail for many reasons and
                      is not supported by all networks and/or
                      network interfaces.
    ios2_WireError  - More specific error number.
```
NOTES

    The DstAddr field may be trashed by the driver because this function
    may be implemented by filling DstAddr with a broadcast address and
    internally calling CMD_WRITE.
SEE ALSO

    CMD_WRITE, S2_MULTICAST
BUGS

