---
title: Configuration
manual: amiga-mail
chapter: amiga-mail
section: configuration
functions: []
libraries: []
---

# Configuration

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  S2_DEVICEQUERY     S2_CONFIGINTERFACE    S2_GETSTATIONADDRESS

The device driver needs to configure the hardware before using it. The
driver user must know some network hardware parameters (hardware address
and MTU, for example) when using it. These commands address those needs.

When a driver user is initialized, it should try to S2_CONFIGINTERFACE
even though an interface can only be configured once and someone else may
have done it. Before you call S2_CONFIGINTERFACE, first call
S2_GETSTATIONADDRESS to determine the factory address (if any). Also
provide for user-override of the factory address (that address may be
optional and the user may need to override it). When S2_CONFIGINTERFACE
returns, check the ios2_SrcAddr for the actual address the hardware has
been configured with. This is because some hardware (or serial line
standards such as PPP) always dynamically allocates an address at
initialization.

Driver users will want to use S2_DEVICEQUERY to determine the MTU and
other characteristics of the network. The structure returned from
S2_DEVICEQUERY is defined as:


```c
        struct Sana2DeviceQuery
        {
          ULONG SizeAvailable;
          ULONG SizeSupplied;
          ULONG DevQueryFormat;
          ULONG DeviceLevel;
          UWORD AddrFieldSize;
          ULONG MTU;
          ULONG BPS;
          ULONG HardwareType;
        };

    SizeAvailable  - Size, in bytes, of the space available in which to
                     place device information. This includes both size
                     fields.
    SizeSupplied   - Size, in bytes, of the data supplied.
    DevQueryFormat - The format defined here is format 0.
    DeviceLevel    - This spec defines level 0.
    AddrFieldSize  - The number of bits in an interface address.
    MTU            - Maximum Transmission Unit, the size, in bytes,
                     of the maximum packet size, not including header
                     and trailer information.
    BPS            - Best guess at the raw line rate for this network
                     in bits per second.
    HardwareType   - Specifies the type of network hardware the driver
                     controls.
```
