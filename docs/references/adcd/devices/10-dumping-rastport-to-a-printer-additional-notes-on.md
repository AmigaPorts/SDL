---
title: 10 / Dumping Rastport to a Printer / Additional Notes on Graphic Dumps
manual: devices
chapter: devices
section: 10-dumping-rastport-to-a-printer-additional-notes-on
functions: []
libraries: []
---

# 10 / Dumping Rastport to a Printer / Additional Notes on Graphic Dumps

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   1. When dumping a 1 bitplane image select the black and white mode in

      Preferences. This is much faster than a grey-scale or color dump.
   2. Horizontal dumps are much faster than vertical dumps.

   3. Smoothing doubles the print time.  Use it for final copy only.

   4. F-S dithering doubles the print time.  Ordered and half-tone

      dithering incur no extra overhead.
   5. The lower the density, the faster the printout.

   6. Friction-fed paper tends to be much more accurate than tractor-fed

```c
      paper in terms of vertical dot placement (i.e., less horizontal
      strips or white lines).
```
   7. Densities which use more than one pass tend to produce muddy

      grey-scale or color printouts.  It is recommended not to choose these
      densities when doing a grey-scale or color dump.
   Keep This in Mind.
   ------------------
   It is possible that the printer has been instructed to receive a
   certain amount of data and is still in an "expecting" state if an
   I/O request has been aborted by the user. This means the printer
   would try to finish the job with the data the next I/O request might
   send. Currently the best way to overcome this problem is for the
   printer to be reset.

