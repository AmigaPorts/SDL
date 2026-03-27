---
title: D / Errors / Menu Problems
manual: libraries
chapter: libraries
section: d-errors-menu-problems
functions: []
libraries: []
---

# D / Errors / Menu Problems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A flickering menu is caused by leaving a pixel or more space between menu
subitems when designing your menu.  Crashing after browsing a menu
(looking at menu without selecting any items) is caused by not properly
handling [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md) select messages.  Multiple selection not working is
caused by not handling [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) properly.  See the "[Intuition Menus](libraries/6-menu-selection-messages-multi-selection-of-menu-items.md)"
chapter.

