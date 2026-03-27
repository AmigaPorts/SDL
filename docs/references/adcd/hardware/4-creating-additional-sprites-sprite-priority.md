---
title: 4 / Creating Additional Sprites / Sprite Priority
manual: hardware
chapter: hardware
section: 4-creating-additional-sprites-sprite-priority
functions: []
libraries: []
---

# 4 / Creating Additional Sprites / Sprite Priority

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you have more than one sprite on the screen, you may need to take
into consideration their relative video priority, that is, which sprite
appears in front of or behind another. Each sprite has a fixed video
priority with respect to all the others. The lowest numbered sprite has
the highest priority and appears in front of all other sprites; the
highest numbered sprite has the lowest priority. This is illustrated in
Figure 4-8.

   More about priorities.
   ----------------------
   See Chapter 7, "System Control Hardware," for more information
   on  [sprite priorities](hardware/7-system-control-hardware-video-priorities.md) .

                                           _______
                                          |       |
                                       ___|___  7 |
                                      |       |___|
                                   ___|___  6 |
                                  |       |___|
                               ___|___  5 |
                              |       |___|
                           ___|___  4 |
                          |       |___|
                       ___|___  3 |
                      |       |___|
                   ___|___  2 |
                  |       |___|
               ___|___  1 |
              |       |___|
              |     0 |
              |_______|


                   Figure 4-8: Sprite Priority
