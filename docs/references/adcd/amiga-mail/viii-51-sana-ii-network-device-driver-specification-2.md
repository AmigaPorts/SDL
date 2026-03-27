---
title: VIII-51: SANA-II Network Device Driver Specification
manual: amiga-mail
chapter: amiga-mail
section: viii-51-sana-ii-network-device-driver-specification-2
functions: []
libraries: []
---

# VIII-51: SANA-II Network Device Driver Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SANA-II Developer Support Package  - May 21, 1992
--------------------------------------------------
Commodore-Amiga Networking Group

All files in this archive are (C) Copyright 1992-1999 Amiga, Inc.

Warning
-------

The information contained herein is subject to change without
notice. Amiga specifically does not make any endorsement or
representation with respect to the use, results, or performance of
the information (including without limitation its capabilities,
appropriateness, reliability, currentness or availability).

Disclaimer
----------

This information is provided "As Is" without warranty of any
kind, either express or implied.  The entire risk as to the use of
this information is assumed by the user.  In no event will
Amiga or its affiliated companies be liable for any damages,
direct, indirect, incidental, special or consequential, resulting
from any claim arising out of the information presented herein,
even if it has been advised of the possibility of such damages.
Some states do not allow the exclusion or limitation of such
implied warranties, so the above limitations may not apply.

----------------------------------------------------------------------
All the files in this archive are freely redistributable as long as
the above Copyright, Warning and Disclaimer are present in all copies.
----------------------------------------------------------------------

This archive contains the following files:

  readme  ............. this file.
  [standard.txt](amiga-mail/viii-51-sana-ii-network-device-driver-specification.md)  ....... The SANA-II spec itself.
  [changes.txt](amiga-mail/sana-ii-developer-support-package-changes.md)  ........ changes from the previous preliminary spec.
  [ethernet.txt](amiga-mail/sana-ii-developer-support-package-ethernet-txt.md)  ....... useful ethernet information for programmers.
  [ARCNET.txt](amiga-mail/viii-51-sana-ii-network-device-driver-specification-3.md)  ......... useful ARCNET information for programmers.
  [copybuff.doc](amiga-mail/developer-support-package-copybuff-doc.md)  ....... autodocs for application provided functions.
  [sana2device.doc](amiga-mail/developer-support-package-sana2device-doc.md) ..... autodoc for SANA-II device functions.
  [sana2specialstats.h](amiga-mail/viii-51-include-devices-sana2specialstats-h.md) . includes
  [sana2.h](amiga-mail/viii-51-include-devices-sana2-h.md) ............. includes
  [sana2specialstats.i](amiga-mail/viii-51-include-devices-sana2specialstats-i.md) . includes
  [sana2.i](amiga-mail/viii-51-include-devices-sana2-i.md) ............. includes
  a2060.device ........ (BETA) SANA-II driver for CBM A2060 card.
  a2065.device ........ SANA-II driver for CBM A2065 card.


                      ------- NOTE NOTE -------
Developers, please note ...  The standard system location for SANA-II
network device drivers is in a directory called 'sana2' which exists
in the "DEVS:" directory.  Example:

devs:sana2/a2065.device

This is the official location for these drivers. It may be necessary
for your install programs/scripts to create this directory.


                      ------- NOTE NOTE -------
The included A2060 device driver is a BETA driver and should be dealt
with accordingly. At the time of this writing the driveer has NOT
received the testing that it should.  You can get our attention on
this subject via email to 'networking@cbmvax.commodore.com'. Please
let us know of any problems so we can fix them a.s.a.p.


                      ----- QUESTIONS ??? -----
Bug reports and enhancement requests may be submitted as follows:

  Please clearly state that the subsystem is "sana2".

  If possible, generate your reports using the Amiga "Report"
  program (distributed on the 2.0 Native Developer Update
  Software Toolkit II disk).

  (When sending enhancement requests, substitute "suggestions" for
  "bugs" in the following addresses)

Mail:

  European registered developers send reports to their support
  manager.

  U.S./others mail to: Amiga Software Engineering,

                       ATTN: BUG REPORTS,
                       CBM,
                       1200 Wilson Drive,
                       West Chester, PA., 19380, USA
  European ADSP users: Post bugs to adsp.bugs

UUCP:

  to uunet!cbmvax!bugs OR rutgers!cbmvax!bugs OR bugs@commodore.COM
  (enhancement requests to cbmvax!suggestions instead of cbmvax!bugs)

  For technical questions regarding SANA-2 implementation, send to
  networking@cbmvax.commodore.com

BIX:

  Post bugs in the appropriate bugs topic of your closed conference.
  Non-registered developer, post in BIX amiga.dev bugs or suggestions.

