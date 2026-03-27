---
title: 8 / Creating Images / Image Example
manual: libraries
chapter: libraries
section: 8-creating-images-image-example
functions: []
libraries: []
---

# 8 / Creating Images / Image Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A more complex example of the use of an [Image](libraries/8-creating-images-image-structure.md) is presented below.



```c
                  Plane 0, Open Rectangle

              ************************········
              **····················**········
              **····················**········
              **····················**········
              **····················**········
              **····················**········
              **····················**········
              **····················**········
              **····················**········
              ************************········

                 Plane 1, Filled Rectangle

              ································
              ································
              ································
              ········oooooooo················
              ········oooooooo················
              ········oooooooo················
              ········oooooooo················
              ································
              ································
              ································

                   3-Color Combined Image

              ************************········
              **····················**········
              **····················**········
              **······oooooooo······**········
              **······oooooooo······**········
              **······oooooooo······**········
              **······oooooooo······**········
              **····················**········
              **····················**········
              ************************········


    Figure 8-2: Picture of the More Complex Example Image


     [compleximage.c](libraries/lib-examples-compleximage-c.md) 
```
