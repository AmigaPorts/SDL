---
title: 7 / Beam Position Detection / Using the Beam Position Counter
manual: hardware
chapter: hardware
section: 7-beam-position-detection-using-the-beam-position-counter
functions: []
libraries: []
---

# 7 / Beam Position Detection / Using the Beam Position Counter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are four addresses that access the beam position counter. Their
usage is described in Table 7-5.




          Table 7-5: Contents of the Beam Position Counter
  VPOSR   Read-only   Read the high bit of the vertical position (V8) and

```c
                      the frame-type bit.

          Bit 15      LOF (Long-frame bit). Used to initialize interlaced
                      displays.

          Bits 14-1   Unused

          Bit 0       High bit of the vertical position (V8).  Allows PAL
                      line counts (313) to appear in PAL versions of the
                      Amiga.
```
  VHPOSR  Read-only   Read vertical and horizontal position of the counter

```c
                      that is producing the beam on the screen (also
                      reads the light pen).

          Bits 15-8   Low bits of the vertical position, bits V7-V0

          Bits  7-0   The horizontal position, bits H8-H1.  Horizontal
                      resolution is 1/160th of the screen width.
```
  VPOSW   Write only  Bits same as VPOSR above.

  VHPOSW  Write only  Bits same as VHPOSR above.  Used for counter


                      synchronization with chip test patterns.
As usual, the address pairs VPOSR,VHPOSR and VPOSW,VHPOSW can be read from
and written to as long words, with the most significant addresses being
VPOSR and VPOSW.

