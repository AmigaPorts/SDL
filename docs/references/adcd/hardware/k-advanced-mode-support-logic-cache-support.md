---
title: K / / Advanced Mode Support Logic / Cache Support
manual: hardware
chapter: hardware
section: k-advanced-mode-support-logic-cache-support
functions: []
libraries: []
---

# K / / Advanced Mode Support Logic / Cache Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The other advanced cycle modifier on the Zorro III bus is the cache
inhibit line,  [/CINH](hardware/k-signal-description-data-and-related-control-signals.md) .  On the Zorro II bus, there was originally no
caching envisioned, and therefore no real support for caching of Zorro II
PICs. First in the A2630 and later in the Zorro III bus' emulation of
Zorro II, conventions were adopted to permit caching of Zorro II cards.
These conventions aren't perfect; MMU tables will sometimes have to
supplant this geographic mapping.  While Zorro III doesn't have any cache
consistency mechanisms for managing caches between several caching bus
masters, it does allow cards that absolutely must not be cached to assert
a cache inhibit line,  [/CINH](hardware/k-signal-description-data-and-related-control-signals.md) , on a per-cycle basis (asserted at slave
time by a responding slave).  This cache management is basically the
lowest level of a cache management system, mainly useful for support of
I/O and other devices that shouldn't be cached.  Software will be required
for the higher levels of cache management.

