---
title: 27 / Display Routines and Structures / Limitations on Use of Viewports
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-limitations-on-use-of
functions: []
libraries: []
---

# 27 / Display Routines and Structures / Limitations on Use of Viewports

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system software for defining [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s allows only vertically stacked
fields to be defined. The following figure shows acceptable and
unacceptable display configurations.



```c
                                     \\\\                   ////
       _________________________      \\\\_________________////
      |                         |    |                         |
      |  _____________________  |    |  _____________________  |
      | |                     | |    | |                     | |
      | |                     | |    | |                     | |
      | |                     | |    | |                     | |
      | |                     | |    | |                     | |
      | |_____________________| |    | |_____________________| |
      |   ___________________   |    | |                     | |
      |  |                   |  |    | |                     | |
      |  |                   |  |    | |                     | |
      |  |                   |  |    | |                     | |
      |  |___________________|  |    | |_____________________| |
      |  _____________________  |    | |                     | |
      | |                     | |    | |                     | |
      | |                     | |    | |                     | |
      | |                     | |    | |                     | |
      | |_____________________| |    | |_____________________| |
      |                         |    |                         |
      |_________________________|    |_________________________|
                                      ////                 \\\\
              ACCEPTABLE             ////     INCORRECT     \\\\
              ----------                      ---------
                                     (Does not use at least one
                                    blank line between ViewPorts)


      \\\\                   ////    \\\\                   ////
       \\\\_________________////      \\\\_________________////
      |                         |    |                         |
      |  _____________________  |    |  _________   _________  |
      | |                     | |    | |         | |         | |
      | |                     | |    | |         | |         | |
      | |                     | |    | |         | |         | |
      | |     ___________     | |    | |         | |         | |
      | |    |           |    | |    | |         | |         | |
      | |____|           |____| |    | |         | |         | |
      |      |           |      |    | |         | |         | |
      |      |           |      |    | |         | |         | |
      |  ____|           |____  |    | |         | |         | |
      | |    |           |    | |    | |         | |         | |
      | |    |___________|    | |    | |         | |         | |
      | |                     | |    | |         | |         | |
      | |                     | |    | |         | |         | |
      | |                     | |    | |         | |         | |
      | |_____________________| |    | |_________| |_________| |
      |                         |    |                         |
      |_________________________|    |_________________________|
       ////                 \\\\      ////                 \\\\
      ////     INCORRECT     \\\\    ////     INCORRECT     \\\\
               ---------                      ---------
       (Cannot have overlapping        (Cannot create multiple
               ViewPorts)               horizontal ViewPorts)


        Figure 27-10: Correct and Incorrect Uses of ViewPorts
```
A [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is related to the custom screen option of Intuition. In a
custom screen, you can split the screen into slices as shown in the
"correct" illustration of the above figure. Each custom screen can have
its own set of colors, use its own resolution, and show its own display
area.

