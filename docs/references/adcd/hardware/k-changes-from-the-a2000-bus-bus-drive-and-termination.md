---
title: K / / Changes from the A2000 Bus / Bus Drive and Termination
manual: hardware
chapter: hardware
section: k-changes-from-the-a2000-bus-bus-drive-and-termination
functions: []
libraries: []
---

# K / / Changes from the A2000 Bus / Bus Drive and Termination

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Finally, the Zorro III bus uses different bus termination than that in the
A2000.  The Zorro II specification didn't specify the termination
expected; backplanes were built that didn't even have termination.  The
A2000 bus used a circuit consisting of a capacitor in series with a
resistor to ground for most of the bus signals.  This has good reflection
cancelling properties without increasing crosstalk (a major concern on the
2-layer A2000 motherboard), but it does slow operations down measureably.

The main reason for the change on the A3000 backplane is to support the
faster Zorro III bus modes.  The multi-layer A3000 motherboard permits a
reasonably high current bus without undue crosstalk.  The thevenin
termination makes switching logic levels start from a midpoint instead of
a rail, especially for a bus coming out of tri-state (which, based on the
Zorro III design, happens constantly). This should not cause problems with
Zorro II cards, but it's conceivable that some cards may need to be
adjusted to work in this bus (the Zorro III bus requires somewhat higher
current capability than the Zorro II bus does.  The A3000 does not support
enough slots for loading to be a likely problem, but future Zorro III
backplanes will have more slots and make this an important consideration).


```c
                                                    o  +5V
                                                    |
                                                    |
                |\                                  \
      LS or ALS | \____                             /
         Driver | /    |                            \  220W
                |/    _|_                           /
                      ___ 0.01mF                    \
                       |                            /
                       |                     |\     |
                       \            F Driver | \____|
                       /                     | /    |
                       \  1KW                |/     |
                       /                            \
                       \                            /
      a) A2000 Bus     /                            \  330W
         Termination   |                            /
                     __|__                          \
                      ___          b) A3000 Bus     /
                       _              Termination   |
                                                  __|__
                                                   ___
                                                    _

            Figure K-2: A2000 vs. A3000 Bus Termination
```
