---
title: 3 / / Horiz. Scrolling / Specifying Data Fetch in Horizontal Scrolling
manual: hardware
chapter: hardware
section: 3-horiz-scrolling-specifying-data-fetch-in-horizontal
functions: []
libraries: []
---

# 3 / / Horiz. Scrolling / Specifying Data Fetch in Horizontal Scrolling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The normal data-fetch start for non-scrolled displays is ($38). If
horizontal scrolling is desired, then the data fetch must start one word
sooner ( [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  = $0030). Incidentally, this will disable  [sprite 7](hardware/4-sprite-hardware-creating-additional-sprites.md) .
 [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  remains unchanged. Remember that the settings of the data-fetch
registers affect both playfields.

