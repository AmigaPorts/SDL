---
title: sana2.device/S2_READORPHAN
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-readorphan
functions: []
libraries: []
---

# sana2.device/S2_READORPHAN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReadOrphan -- Get a packet for which there is no reader.
FUNCTION

    Get the next packet available that does not satisfy any then-pending
    CMD_READ requests. The data returned in the ios2_Data structure is
    normally the Data Link Layer packet type field and the packet data. If
    bit SANA2IOB_RAW is set in ios2_Flags, then the entire Data Link Layer
    packet, including both header and trailer information, will be
    returned.
IO REQUEST

    ios2_Command    - CMD_READORPHAN.
    ios2_Flags      - Supported flags are:
                            SANA2IOB_RAW
                            SANA2IOB_QUICK
    ios2_DataLength - Length of the Data to be sent.
    ios2_Data       - Abstract data structure which packet data is
                      contained in.
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
    ios2_DataLength - Length of the Data to be sent.
    ios2_Data       - Abstract data structure which packet data is
                      contained in.
```
NOTES

```c
    This is intended for debugging and management tools.  Protocols should
    not use this.

    As with 802.3 packets on an ethernet, to determine which protocol
    family the returned packet belongs to you may have to specify
    SANA2IOB_RAW to get the entire data link layer wrapper (which is where
    the protocol type may be kept). Notice this necessarily means that
    this cannot be done in a network interface independent fashion.  The
    driver will, however, fill in the PacketType field to the best of its
    ability.
```
SEE ALSO

    CMD_READ, CMD_WRITE
BUGS

