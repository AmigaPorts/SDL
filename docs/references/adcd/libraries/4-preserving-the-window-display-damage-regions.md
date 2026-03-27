---
title: 4 / Preserving the Window Display / Damage Regions
manual: libraries
chapter: libraries
section: 4-preserving-the-window-display-damage-regions
functions: []
libraries: []
---

# 4 / Preserving the Window Display / Damage Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layers library and Intuition maintain a damage region for each window,
which is the part of the window whose imagery is in need of repair, or
refreshing.  Several things can add areas of the window to the damage
region:

  * Revealing an obscured part of a Simple Refresh window adds that area

    to the damage region
  * Sizing a Simple or Smart Refresh window bigger along either axis adds

    the new area to the damage region
  * Resizing a Simple or Smart Refresh window (smaller or bigger) adds

```c
    the old and new border areas, and the areas occupied by certain
    gadgets (those whose position or size depend on window size) to the
    damage region.
```
