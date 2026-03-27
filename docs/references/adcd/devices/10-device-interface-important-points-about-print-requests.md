---
title: 10 / Device Interface / Important Points About Print Requests
manual: devices
chapter: devices
section: 10-device-interface-important-points-about-print-requests
functions: []
libraries: []
---

# 10 / Device Interface / Important Points About Print Requests

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

*  Perform printer I/O from a separate task or process
   It is quite reasonable for a user to expect that printing will be
   performed as a background operation.  You should try to accommodate
   this expectation as much as possible.

*  Give the user a chance to stop
   Your application should always allow the user to stop a print request
   before it is finished.

*  Don't confuse aborting a print request with cancelling a page
   Some applications seem to offer the user the ability to abort a
   multi-page print request when in fact the abort is only for the
   current page being printed. This results in the next page being
   printed instead of the request being stopped. Do not do this!  It
   only confuses the user and takes away from your application.  There
   is nothing wrong with allowing the user to cancel a page and continue
   to the next page, but it should be explicit that this is the case. If
   you abort a print request, the entire request should be aborted.

