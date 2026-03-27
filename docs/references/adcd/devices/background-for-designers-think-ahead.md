---
title: Background for Designers / Think Ahead
manual: devices
chapter: devices
section: background-for-designers-think-ahead
functions: []
libraries: []
---

# Background for Designers / Think Ahead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Let's think ahead and build programs that read and write files for each
other and for programs yet to be designed.  Build data formats to last for
future computers so long as the overhead is acceptable.  This extends the
usefulness and life of today's programs and data.

To maximize interconnectivity, the standard file structure and the
specific object formats must all be general and extensible.  Think ahead
when designing an object.  File formats should serve many purposes and
allow many programs to store and read back all the information they need;
even squeeze in custom data.  Then a programmer can store the available
data and is encouraged to include fixed contextual details.  Recipient
programs can read the needed parts, skip unrecognized stuff, default
missing data, and use the stored context to help transform the data as
needed.

