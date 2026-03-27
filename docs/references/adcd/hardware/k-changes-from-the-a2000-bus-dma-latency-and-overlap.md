---
title: K / / Changes from the A2000 Bus / DMA Latency and Overlap
manual: hardware
chapter: hardware
section: k-changes-from-the-a2000-bus-dma-latency-and-overlap
functions: []
libraries: []
---

# K / / Changes from the A2000 Bus / DMA Latency and Overlap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Zorro II bus masters in a Zorro III backplane will, in many cases, receive
a bus grant much sooner than they would in a standard Zorro II backplane.
Additionally, in some cases, expansion bus cycles will overlap local bus
cycles.  The latency incurred on the Zorro II bus during heavy custom chip
activity has been greatly reduced for any Zorro III bus master. This
should be transparent to the card in question, though keep this in mind.

