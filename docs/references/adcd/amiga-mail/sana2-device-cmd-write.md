---
title: sana2.device/CMD_WRITE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-write
functions: []
libraries: []
---

# sana2.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Write -- Send packet to the network.
FUNCTION

```c
    This command causes the packet to be sent to the specified network
    interface. Normally, appropriate packet header and trailer information
    will be added to the packet data when it is sent.  If bit SANA2IOB_RAW
    is set in io_Flags, then the ios2_Data is assumed to contain an entire
    physical frame and will be sent (copied to the wire via
    CopyFromBuffer() unmodified.

    Note that the device should not check to see if the destination
    address is on the local hardware.  Network protocols should realize
    that the packet has a local destination long before it gets to a
    SANA-II driver.
```
IO REQUEST

    ios2_Command    - CMD_WRITE.
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
    ios2_WireError  - More specific error number.
```
NOTES

    The driver may not directly examine or modify anything pointed to by
    ios2_Data.  It *must* use the requester-provided functions to access
    this data.
SEE ALSO

    CMD_READ, S2_BROADCAST, S2_MULTICAST, any_protocol/CopyFromBuffer
BUGS

