---
title: 12 Serial Device / Multiple Serial Port Support
manual: devices
chapter: devices
section: 12-serial-device-multiple-serial-port-support
functions: []
libraries: []
---

# 12 Serial Device / Multiple Serial Port Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Applications that use the serial port should provide the user with a means
to select the name and unit number of the driver.  The defaults will be
"serial.device" and unit number 0.  Typically unit 0 refers to the
user-selected default.  Unit 1 refers to the built-in serial port.
Numbers above 1 are for extended units.  The physically lowest connector
on a board will always have the lowest unit number.

Careful attention to error handling is required to survive in a multiple
port environment.  Differing serial hardware will have different
capabilities.  The device will refuse to open non-existent unit numbers
(symbolic name mapping of unit numbers is not provided at the device
level). The [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) command will fail if the underlying hardware
cannot support your parameters.  Some devices may use quick I/O for read
or write requests, others will not.  Watch out for partially completed
read requests; io_Actual may not match your requested read length.

If the Tool Types mechanism is used for selecting the device and unit, the
defaults of "DEVICE=serial.device" and "UNIT=0" should be provided.
The user should be able to permanently set the device and unit in a
configuration file.

