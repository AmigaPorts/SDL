---
title: SANA-II Developer Support Package / Changes
manual: amiga-mail
chapter: amiga-mail
section: sana-ii-developer-support-package-changes
functions: []
libraries: []
---

# SANA-II Developer Support Package / Changes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There have been no substantive changes from the Novemeber 7 Draft for
Final Comment and approval.  There have been minor clarifications and
typographical corrections and a section was added to clarify ARCNET
framing.

Since the Fish Disk/'91 DevCon draft of the SANA-II standard, here is a
summary list of the important changes:

- Packet type specification has been drastically simplified.  The original
  standard called for a generalized "Packet Magic" which all drivers and
  protocols had to deal with, even though few people should ever have to
  worry about the problem.  We could also have specified that there are
  802.3 SANA-II drivers and that there are ethernet drivers and that if
  you want 802.3 and ethernet (even if on the same wire) from the same
  machine, use two ethernet boards.  This didn't make sense because we
  don't anticipate multiple protocols needing to use 802.3 frames nor
  much encouragement for hardware manufactures to provide special 802.3
  drivers. The current solution keeps the standard simple and allows
  highly efficient implementations, but it does make ethernet drivers a
  little more complex and does make using 802.3 frames harder.


- The original SANA-II device driver specification therefore called for
  drivers to have no internal buffers and to get all buffers from
  protocols in the form of a data structure called a NetBuff. Hence, all
  protocols were required to use NetBuffs.  This was highly
  unsatisfactory since most protocols are implemented from an existing
  code base which includes its own buffer management scheme.  NetBuffs
  are removed from the standard and replaced with a function callback.

- The original standard called for an interface to the ability of some
  hardware to simultaneously accept packets for several hardware
  addresses. Such a feature is of dubious usefulness.  In order to
  simplify the standard, station aliases are no longer part of the
  SANA-II Network Device Driver Specification. If station aliasing does
  turn out to be a useful feature available on some hardware for the
  Amiga, the standard can easily be extended to re-introduce station
  aliasing.  Remember that all Exec drivers must check for io_Command
  values not supported by the driver. Hence, SANA-II commands can be
  added without requiring that existing drivers be rev'd.

- Since the IOSana2Req structure had to be changed anyway, many names in
  <devices/sana2.h> have been changed to be more consistent with other
  system names. It is believed that global search and replace should make
  this a mostly trivial change and that the benefits gained from
  consistent naming outweigh the inconvenience to those few who have
  existing SANA-II code.

- Events are now defined as a bit mask rather than as scalars.

