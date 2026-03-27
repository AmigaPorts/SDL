---
title: 3 Clipboard Device
manual: devices
chapter: devices
section: 3-clipboard-device
functions: []
libraries: []
---

# 3 Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The clipboard device allows the exchange of data dynamically between one
application and another. It is responsible for caching data that has been
"cut" and providing data to "paste" in an application. A special
"post" mode allows an application to inform the clipboard device that
the application has data available. The clipboard device will request this
data only if the data is actually needed. The clipboard will cache the
data in RAM and will automatically spool the data to disk if necessary.

The clipboard device is implemented as an Exec-style device, and supports
random access reads and writes on data within the clipboard. All data in
the clipboard must be in IFF format.  A new library, [IFFParse Library](libraries/33-iffparse-library.md), has
been added to the Amiga libraries.  The routines in iffparse.library can
and should be used for reading and writing data to the clipboard.  This
chapter contains a brief discussion of IFF as it relates to the clipboard
(for more details see [Appendix A](devices/appendix-a-iff-interchange-file-format.md)).


```c
               NEW CLIPBOARD FEATURES FOR VERSION 2.0

                   Feature                 Description
               --------------             --------------
               [CBD_CHANGEHOOK](autodocs-2.0/clipboard-device-cbd-changehook.md)             Device Command
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 clipboard device are not backwards
   compatible.

 [Clipboard Device Commands and Functions](devices/3-clipboard-device-clipboard-device-commands-and-functions.md) 
 [Device Interface](devices/3-clipboard-device-device-interface.md) 
 [Monitoring Clipboard Changes](devices/3-clipboard-device-monitoring-clipboard-changes.md) 
 [Example Clipboard Programs](devices/devices-dev-examples-clipdemo-c.md) 
 [Support Functions Called from Example Programs](devices/devices-dev-examples-cbio-c.md) 
 [Include File for the Example Programs](devices/devices-dev-examples-cb-h.md) 
 [Additional Information on the Clipboard Device](devices/3-clipboard-device-additional-information-on-the-clipboard.md) 

