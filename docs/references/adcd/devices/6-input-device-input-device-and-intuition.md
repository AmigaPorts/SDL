---
title: 6 Input Device / Input Device and Intuition
manual: devices
chapter: devices
section: 6-input-device-input-device-and-intuition
functions: []
libraries: []
---

# 6 Input Device / Input Device and Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several ways to receive information from the various devices
that are part of the input device. The first way is to communicate
directly with the device. This method is not recommended while the input
device task is running - which is most of the time. The second way is to
become a handler for the stream of events which the input device produces.
That method is shown above.

The third method of getting input from the input device is to retrieve the
data from the console device or from the IDCMP (Intuition Direct
Communications Message Port).   These are the preferred methods for
applications in a multitasking environment because each application can
receive juts its own input (i.e., only the input which occurs when one of
its window is active).  See the "[Intuition](libraries/user-interface-libraries.md)" chapters of Amiga ROM Kernel
Reference Manual: Libraries for more information on IDCMP messages. See
the [Console Device](devices/4-console-device.md) chapter of this manual for more information on
console device I/O.

