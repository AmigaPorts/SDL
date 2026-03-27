---
title: 12 Serial Device
manual: devices
chapter: devices
section: 12-serial-device
functions: []
libraries: []
---

# 12 Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The serial device provides a hardware-independent interface to the Amiga's
built-in RS-232C compatible serial port.  Serial ports have a wide range
of uses, including communication with modems, printers, MIDI devices, and
other computers.  The same device interface can be used for additional
"byte stream oriented devices" - usually more serial ports.  The serial
device is based on the conventions of Exec device I/O, with extensions for
parameter setting and control.


                   Serial Device Characteristics
                   -----------------------------
                   MODES           Exclusive
                                   Shared Access

                   BAUD RATES      110-292,000

                   HANDSHAKING     Three-Wire
                                   Seven-Wire
 [Serial Device Commands and Functions](devices/12-serial-device-serial-device-commands-and-functions.md) 
 [Device Interface](devices/12-serial-device-device-interface.md) 
 [A Simple Serial Port Example](devices/devices-dev-examples-simple-serial-c.md) 
 [Alternative Modes for Serial Input or Output](devices/12-serial-device-alternative-modes-for-serial-input-or.md) 
 [Setting Serial Parameters (SDCMD_SETPARAMS)](devices/12-serial-device-setting-serial-parameters-sdcmd-setparams.md) 
 [Querying the Serial Device](devices/12-serial-device-querying-the-serial-device.md) 
 [Sending the Break Command](devices/12-serial-device-sending-the-break-command.md) 
 [Error Codes from the Serial Device](devices/12-serial-device-error-codes-from-the-serial-device.md) 
 [Multiple Serial Port Support](devices/12-serial-device-multiple-serial-port-support.md) 
 [Taking Over the Hardware](devices/12-serial-device-taking-over-the-hardware.md) 
 [Advanced Example of Serial Device Usage](devices/devices-dev-examples-complex-serial-c.md) 
 [Additional Information on the Serial Device](devices/12-serial-device-additional-information-on-the-serial-device.md) 

