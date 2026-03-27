---
title: K / / Expansion Bus Loading / Open Collector Signals
manual: hardware
chapter: hardware
section: k-expansion-bus-loading-open-collector-signals
functions: []
libraries: []
---

# K / / Expansion Bus Loading / Open Collector Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Many of the bus signals are shared via open collector or open drain
outputs rather than via tri-stated signals; this is of course required for
some  [asynchronous](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  things like the shared interrupt lines, and it works
well for other types of signals as well.  Of course, a backplane resistor
pulls these lines high, PICs only drive the line low.


```c
        [/OWN](hardware/k-signal-description-dma-control-signals-2.md)      [/BGACK](hardware/k-signal-description-dma-control-signals-2.md)     [/CINH](hardware/k-signal-description-data-and-related-control-signals.md)       [/BERR](hardware/k-signal-description-system-control-signals-2.md) 
        [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)    [/RESET](hardware/k-signal-description-system-control-signals-2.md)     [/INT2](hardware/k-signal-description-system-control-signals-2.md)       [/INT6](hardware/k-signal-description-system-control-signals-2.md) 
        [/HLT](hardware/k-signal-description-system-control-signals-2.md) 
```
