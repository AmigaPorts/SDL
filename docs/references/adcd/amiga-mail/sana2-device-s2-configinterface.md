---
title: sana2.device/S2_CONFIGINTERFACE
manual: amiga-mail
chapter: amiga-mail
section: sana2-device-s2-configinterface
functions: []
libraries: []
---

# sana2.device/S2_CONFIGINTERFACE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ConfigInterface -- Configure the network interface.
FUNCTION

    This command causes the device driver to initialize the interface
    hardware and to set the network interface address to the address in
    ios2_SrcAddr. This command can only be executed once and, if
    successful, will leave the driver and network interface fully
    operational and the network interface in ios2_SrcAddr.

    To set the interface address to the factory address, the network
    management software must use GetStationAddress first and then call
    ConfigInterface with the result. If there is no factory address then
    the network software must pick an address to use.

    Until this command is executed the device will not listen for any
    packets on the hardware.
IO REQUEST

    ios2_Command    - S2_CONFIGINTERFACE.
    ios2_Flags      - Supported flags are:
                            SANA2IOB_QUICK
    ios2_SrcAddr    - Address for this interface.
RESULTS

```c
    ios2_Error      - Zero if successful; non-zero otherwise.
    ios2_WireError  - More specific error number.
    ios2_SrcAddr    - Address of this interface as configured.
```
NOTES

    Some networks have the interfaces choose a currently unused interface
    address each time the interface is initialized. The caller must check
    ios2_SrcAddr for the actual interface address after configuring the
    interface.
SEE ALSO

    S2_GETSTATIONADDRESS
BUGS

