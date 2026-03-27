---
title: sana2.device/CMD_READ
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-cmd-read
functions: []
libraries: []
---

# sana2.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Read -- Get a packet from the network.
FUNCTION

```c
    Get the next packet available of the requested packet type. The data
    copied (via a call to the requestor-provided CopyToBuffer function)
    into ios2_Data is normally the Data Link Layer packet data only. If
    bit SANA2IOB_RAW is set in ios2_Flags, then the entire physical frame
    will be returned.

    Unlike most Exec devices, SANA-II device drivers do not have internal
    buffers.  If you wish to read data from a SANA-II device you should
    have multiple CMD_READ requests pending at any given time.  The
    functions provided by you the requestor will be used for any incoming
    packets of the type you've requested.  If no read requests are
    outstanding for a type which comes in and no read_orphan requests are
    outstanding, the packet will be lost.
```
IO REQUEST

    ios2_Command    - CMD_READ
    ios2_Flags      - Supported flags are:
                        SANA2IOB_RAW
                        SANA2IOB_QUICK
    ios2_PacketType - Packet type desired.
    ios2_Data       - Abstract data structure to hold packet data.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
    ios2_Flags      - The following flags may be returned:
                        SANA2IOB_RAW
                        SANA2IOB_BCAST
                        SANA2IOB_MCAST
    ios2_SrcAddr    - Source interface address of packet.
    ios2_DstAddr    - Destination interface address of packet.
    ios2_DataLength - Length of packet data.
    ios2_Data       - Abstract data structure which packet data is
                      contained in.
```
NOTES

    The driver may not directly examine or modify anything pointed to by
    ios2_Data.  It *must* use the requester-provided functions to access
    this data.
SEE ALSO

    S2_READORPHAN, CMD_WRITE, any_protocol/CopyToBuffer
BUGS

