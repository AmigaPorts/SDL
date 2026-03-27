---
title: 8 Interface Hardware / Display Output Connections
manual: hardware
chapter: hardware
section: 8-interface-hardware-display-output-connections
functions: []
libraries: []
---

# 8 Interface Hardware / Display Output Connections

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All Amigas provide a 23-pin connector on the back.  This jack contains
video outputs and inputs for external genlock devices. Two separate type
of RGB video are available on the connector:

   *  RGB Monitors ("analog RGB"). Provides four outputs; Red (R),

```c
      Green (G), Blue (B), and Sync (S). They can generate up to 4,096
      different colors on-screen simultaneously using the circuitry
      presently available on the Amiga.
```
   *  Digital RGB Monitors. Provides four outputs, distinct from those

```c
      shown above, named Red (R), Green (G), Blue (B), Half-Intensity
      (I), and Sync (S).  All output levels are logic levels (0 or 1).
      On some monitors these outputs allow up to 15 possible color
      combinations, where the values 0000 and 0001 map to the same
      output value (Half intensity with no color present is the same
      as full intensity, no color). Some monitors arbitrarily map the
      16 combinations to 16 arbitrary colors.
```
   Note that the sync signals from the Amiga are unbuffered.  For use
   with any device that presents a heavy load on the sync outputs,
   external buffers will be required.

The Amiga 500 and 2000 provide a full-bandwidth monochrome video jack for
use with inexpensive monochrome monitors.  The Amiga colors are combined
into intensities based on the following table:


                       Red     Green   Blue
                       ---     -----   ----
                       30%      60%    10%
The A3000 is not equipped with a monochrome video jack.

The Amiga 1000 provides an RF modulator jack.  An adapter is available
that allows all Amiga models to use a television set for display.  Stereo
sound is available on the jack, but will generally be combined into
monaural sound for the TV set.

The Amiga 1000 provides a color composite video jack.  This is suitable
for recording directly with a VCR, but the output is not broadcast
quality. For use on a monochrome monitor, the color information often has
undesired effects; careful color selection or a modification to the
internal circuitry can improve the results.  The A500, A2000 and A3000 do
not have a color composite video jack. High quality composite adapters for
the A500, A1000, A2000 and A3000 plug into the 23 pin RGB port.

The Amiga 2000 and 3000 provide a special "video slot" that contains many
more signals than are available elsewhere:  all the 23-pin RGB port
signals, the unencoded digital video, light pen, power, audio, colorburst,
pixel switch, sync, clock signals, etc.

