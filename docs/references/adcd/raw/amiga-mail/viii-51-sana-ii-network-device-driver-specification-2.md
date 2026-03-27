# VIII-51: SANA-II Network Device Driver Specification


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
  [standard.txt](../AmigaMail_Vol2_guide/node0119.html)  ....... The SANA-II spec itself.
  [changes.txt](../AmigaMail_Vol2_guide/node0212.html)  ........ changes from the previous preliminary spec.
  [ethernet.txt](../AmigaMail_Vol2_guide/node0213.html)  ....... useful ethernet information for programmers.
  [ARCNET.txt](../AmigaMail_Vol2_guide/node0214.html)  ......... useful ARCNET information for programmers.
  [copybuff.doc](../AmigaMail_Vol2_guide/node0215.html)  ....... autodocs for application provided functions.
  [sana2device.doc](../AmigaMail_Vol2_guide/node01E0.html) ..... autodoc for SANA-II device functions.
  [sana2specialstats.h](../AmigaMail_Vol2_guide/node01FD.html) . includes
  [sana2.h](../AmigaMail_Vol2_guide/node01DF.html) ............. includes
  [sana2specialstats.i](../AmigaMail_Vol2_guide/node0218.html) . includes
  [sana2.i](../AmigaMail_Vol2_guide/node0219.html) ............. includes
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

