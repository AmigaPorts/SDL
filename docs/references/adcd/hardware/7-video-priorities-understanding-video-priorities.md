---
title: 7 / Video Priorities / Understanding Video Priorities
manual: hardware
chapter: hardware
section: 7-video-priorities-understanding-video-priorities
functions: []
libraries: []
---

# 7 / Video Priorities / Understanding Video Priorities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The concept of video priorities is easy to understand if you imagine that
four fingers of one of your hands represent the four pairs of sprites and
two fingers of your other hand represent the two playfields. Just as you
cannot change the sequence of the four fingers on the one hand, neither
can you change the  [relative priority](hardware/7-video-priorities-fixed-sprite-priorities.md)  of the sprites. However, just as
you can intertwine the two fingers of one hand in many different ways
relative to the four fingers of the other hand, so can you position the
playfields in front of or behind the sprites. This is illustrated in
Figure 7-2.


```c
     [Figure 7-2: Analogy for Video Priority](hardware/hard-pics-7-2-pic.md) 
```
Five possible positions can be chosen for each of the two "playfield
fingers." For example, you can place playfield 1 on top of sprites 0 and 1
(0), between sprites 0 and 1 and sprites 2 and 3 (1), between sprites 2
and 3 and sprites 4 and 5 (2), between sprites 4 and 5 and sprites 6 and 7
(3), or beneath sprites 6 and 7 (4). You have the same possibilities for
playfield 2.

The numbers 0 through 4 shown in parentheses in the preceding paragraph
are the actual values you use to select the playfield priority positions.
See next section  [Setting the Priority Control Register](hardware/7-video-priorities-setting-the-priority-control-register.md) .

You can also control the priority of playfield 2 relative to playfield 1.
This gives you additional choices for the way you can design the
 [screen priorities](hardware/3-dual-playfield-display-dual-playfield-priority-and-control.md) .

