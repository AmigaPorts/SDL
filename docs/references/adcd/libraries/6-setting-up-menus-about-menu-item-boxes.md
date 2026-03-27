---
title: 6 / Setting Up Menus / About Menu Item Boxes
manual: libraries
chapter: libraries
section: 6-setting-up-menus-about-menu-item-boxes
functions: []
libraries: []
---

# 6 / Setting Up Menus / About Menu Item Boxes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The item box is the rectangle containing the menu items or sub-items.

The size and location of the item or sub-item boxes is not directly
described by the application.  Instead, the size is indirectly described
by the placement of items and sub-items.  When presented with a menu
strip, Intuition first calculates the minimum size box required to hold
the items.  It then adjusts the box to ensure the menu display conforms to
certain design philosophy constraints for items and sub-items.


```c
     [Figure 6-2: Example Item Box](libraries/lib-pics-6-2-pic.md) 
```
The item box must start no further right than the leftmost position of the
menu header's select box.  It must end no further left than the rightmost
position of the menu header's select box.  The top edge of each item box
must overlap the screen's title bar by one line.  Each sub-item box must
overlap its item's select box somewhere.


```c
    Always Overlap.
    ---------------
    If your application is designed to work on systems prior to V37, do
    not leave space between sub-items in a sub-item list.  This may cause
    flickering as the pointer moves off one item into the gap between the
    items.  Even a single line between the items may cause flickering.
    This flickering is eliminated starting with V37.

     [Figure 6-3: Example Sub-item Box](libraries/lib-pics-6-3-pic.md) 
```
