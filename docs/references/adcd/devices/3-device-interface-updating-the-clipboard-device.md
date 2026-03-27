---
title: 3 / Device Interface / Updating The Clipboard Device
manual: devices
chapter: devices
section: 3-device-interface-updating-the-clipboard-device
functions: []
libraries: []
---

# 3 / Device Interface / Updating The Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the final write is done, an update command must be sent to the device
to indicate that the writing is complete and the data is available. You
update the clipboard device by passing an IOClipReq to the device with
CMD_UPDATE set in io_Command.


```c
    ClipIO->io_Command = CMD_UPDATE;
    DoIO(ClipIO);
```
