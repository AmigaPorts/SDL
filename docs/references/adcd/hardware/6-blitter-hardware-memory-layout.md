---
title: 6 Blitter Hardware / Memory Layout
manual: hardware
chapter: hardware
section: 6-blitter-hardware-memory-layout
functions: []
libraries: []
---

# 6 Blitter Hardware / Memory Layout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The blitter is a word blitter, not a bit blitter.  All data fetched,
modified, and written are in full 16-bit words.  Through careful
programming, the blitter can do many "bit" type operations.

The blitter is particularly well suited to graphics operations.  As an
example, a 320 by 200 screen set up to display 16 colors is organized as
four bitplanes of 8,000 bytes each.  Each bitplane consists of 200 rows of
40 bytes or 20 16-bit words.  (From here on, a "word" will mean a 16-bit
word.)

