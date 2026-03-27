---
title: 4 / Forming a Sprite / Shape of Sprites
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-shape-of-sprites
functions: []
libraries: []
---

# 4 / Forming a Sprite / Shape of Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A sprite can have any shape that will fit within the 16-pixel width. You
define a sprite's shape by specifying which pixels actually appear in each
of the sprite's locations. For example, Figures 4-3 and 4-4 show a
spaceship whose shape is marked by Xs. The first figure shows only the
spaceship as you might sketch it out on graph paper. The second figure
shows the spaceship within the 16-pixel width. The 0s around the spaceship
mark the part of the sprite not covered by the spaceship and transparent
when displayed.



                               XX
                             XXXXXX
                           XXXXXXXXXX
                           XXXXXXXXXX
                             XXXXXX
                               XX

                  Figure 4-3: Shape of Spaceship


                        0000XX0000000000
                        00XXXXXX00000000
                        XXXXXXXXXX000000
                        XXXXXXXXXX000000
                        00XXXXXX00000000
                        0000XX0000000000

          Figure 4-4: Sprite with Spaceship Shape Defined
In this example, the widest part of the shape is ten pixels and the shape
is shifted to the left of the sprite. Whenever the shape is narrower than
the sprite, you can control which part of the sprite is used to define the
shape. This particular shape could also start at any of the pixels from
2-7 instead of pixel 1.

