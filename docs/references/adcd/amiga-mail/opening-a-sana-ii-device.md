---
title: Opening a SANA-II Device
manual: amiga-mail
chapter: amiga-mail
section: opening-a-sana-ii-device
functions: [OpenDevice]
libraries: [exec.library]
---

# Opening a SANA-II Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As when opening any other Exec device, on the call to OpenDevice() a
SANA-II device receives an IORequest structure which the device
initializes for the opener's use. The opener must copy this structure if
it desires to use multiple asynchronous requests. The SANA-II IORequest is
defined as follows:


```c
    struct IOSana2Req
    {
        struct IORequest ios2_Req;
        ULONG ios2_WireError;
        ULONG ios2_PacketType;
        UBYTE ios2_SrcAddr[SANA2_MAX_ADDR_BYTES];
        UBYTE ios2_DstAddr[SANA2_MAX_ADDR_BYTES];
        ULONG ios2_DataLength;
        APTR *ios2_Data;
        APTR *ios2_StatData;
        APTR *ios2_BufferManagement;
    };
```
  ios2_Req              - A standard Exec device IORequest.

  ios2_WireError        - A more specific device code which may be

```c
                          set when there is an io_Error. See
                          <[devices/sana2.h](amiga-mail/viii-51-include-devices-sana2-h.md)> for the defined
                          WireErrors.
```
  ios2_PacketType       - The type of packet requested. See the

```c
                          section on "[Packet Type](amiga-mail/packet-type.md)".
```
  ios2_SrcAddr          - The device fills in this field with the

```c
                          interface (network hardware) address of
                          the source of the packet that satisfied
                          a read command. The bytes used to hold
                          the address will be left justified but
                          the bit layout is dependent on the
                          particular type of network.
```
  ios2_DstAddr          - Before the device user sends a packet, it

```c
                          fills this with the interface destination
                          address of the packet. On receives, the
                          device fills this with the interface
                          destination address. Other commands may
                          use this field differently (see the SANA-II
                          Network Device Driver [Autodocs](amiga-mail/developer-support-package-sana2device-doc.md)). The
                          bytes used to hold the address will be
                          left justified but the bit layout is
                          dependent on the particular type of network.
```
  ios2_DataLength       - The device user initializes this field with

```c
                          the amount of data available in the Data
                          buffer before passing the IOSana2Req to
                          the device. The device fills in this field
                          with the size of the packet data as it was
                          sent on the wire. This does not include
                          the header and trailer information.
                          Depending on the network type and protocol
                          type, the driver may have to calculate
                          this value. This is generally used only
                          for reads and writes (including broadcast
                          and multicast).
```
  ios2_Data             - A pointer to some abstract data structure

```c
                          containing packet data. Drivers may not
                          directly manipulate or examine anything
                          pointed to by Data! This is generally
                          used only for reads and writes (including
                          broadcast and multicast).
```
  ios2_StatData         - Pointer to a structure in which to place

                          a snapshot of device statistics. The data
                          area must be long word aligned. This is
                          only used on calls to the statistics
                          commands.
  ios2_BufferManagement - The opener places a pointer to a tag list


```c
                          in this field before calling OpenDevice().
                          Functions pointed to in the tag list are
                          called by the device when processing
                          IORequests from the opener. When returned
                          from OpenDevice(), this field contains a
                          pointer to driver-private information
                          used to access these functions.
                          See "[Buffer Management](amiga-mail/buffer-management.md)" below for more
                          details.
```
The flags used with the device on OpenDevice() are (SANA2OPB_xxx):

  SANA2OPB_MINE  - Exclusive access to the unit requested.
  SANA2OPB_PROM  - Promiscuous mode requested. Hardware which


                   supports promiscuous mode allows all packets
                   sent over the wire to be captured whether or not
                   they are addressed to this node.
The flags used during I/O requests are (SANA2IOB_xxx):

  SANA2IOB_RAW   - Raw packet read/write requested. Raw packets
                   should include the entire data-link layer packet.
                   Devices with the same hardware device number
                   should have the same raw packet format.
  SANA2IOB_BCAST - Broadcast packet (received).
  SANA2IOB_MCAST - Multicast packet (received).
  SANA2IOB_QUICK - Quick IO requested.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
