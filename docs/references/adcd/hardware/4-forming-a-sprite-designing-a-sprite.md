---
title: 4 / Forming a Sprite / Designing a Sprite
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-designing-a-sprite
functions: []
libraries: []
---

# 4 / Forming a Sprite / Designing a Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For design purposes, it is convenient to lay out the sprite on paper
first. You can show the desired colors as numbers from 0 to 3. For
example, the spaceship shown above might look like this:




                        0000122332210000
                        0001223333221000
                        0012223333222100
                        0001223333221000
                        0000122332210000
The next step is to convert the numbers 0-3 into binary numbers, which
will be used to build the  [color descriptor words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  of the sprite
 [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) . The next section shows how to do this.

