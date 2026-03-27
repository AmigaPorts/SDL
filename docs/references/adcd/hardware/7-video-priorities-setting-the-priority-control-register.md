---
title: 7 / Video Priorities / Setting the Priority Control Register
manual: hardware
chapter: hardware
section: 7-video-priorities-setting-the-priority-control-register
functions: []
libraries: []
---

# 7 / Video Priorities / Setting the Priority Control Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This register lets you define how objects will pass in front of each other
or hide behind each other. Normally, playfield 1 appears in front of
playfield 2. The PF2PRI bit reverses this relationship, making playfield 2
more important. You control the video priorities by using the bits in
BPLCON2 (for "bitplane control register number 2") as shown in Table
7-1.




```c
                  Table 7-1: Bits in BPLCON2

             Bit
            Number         Name           Function
            ------         ----           --------
             15-7                      Not used (keep at 0)

                6     PF2PRI           Playfield 2 priority

              5-3     PF2P2 - PF2P0    Playfield 2 placement with
                                       respect to the sprites

              2-0     PF1P2 - PF1P0    Playfield 1 placement with
                                       respect to the sprites
```
The binary values that you give to bits PF1P2-PF1P0 determine where
playfield 1 occurs in the priority chain as shown in Table 7-2. This
matches the description given in the previous section.

   Be careful:
   -----------
   PF2P2 - PF2P0, bits 5-3, are the priority bits for normal (non-dual)
   playfields.


  Table 7-2: Priority of Playfields Based on Values of Bits PF1P2-PF1P0



```c
             Value                 Placement
             -----                 ---------
                    (from most important to least important)

              000     PF1     SP01    SP23    SP45    SP67
              001     SP01    PF1     SP23    SP45    SP67
              010     SP01    SP23    PF1     SP45    SP67
              011     SP01    SP23    SP45    PF1     SP67
              100     SP01    SP23    SP45    SP67    PF1
```
In this table, PF1 stands for playfield 1, and SP01 stands for the
 [group of sprites](hardware/7-video-priorities-how-sprites-are-grouped.md)  numbered 0 and 1. SP23 stands for sprites 2 and 3 as a
group; SP45 stands for sprites 4 and 5 as a group; and SP67 stands for
sprites 6 and 7 as a group.

Bits PF2P2-PF2P0 let you position playfield 2 among the sprite priorities
in exactly the same way. However, it is the PF2PRI bit that determines
which of the two playfields appears in front of the other on the screen.
Here is a sample of possible BPLCON2 register contents that would create
something a little unusual:


              BITS    15-7    PF2PRI  PF2P2-0 PF1P2-0
              VALUE     0s      1       010     000
This will result in a sprite/playfield priority placement of:


                PF1  SP01  SP23  PF2  SP45  SP67
In other words, where objects pass across each other, playfield 1 is in
front of sprite 0 or 1; and sprites 0 through 3 are in front of playfield
2. However, playfield 2 is in front of playfield 1 in any area where they
overlap and where playfield 2 is not blocked by sprites 0 through 3.

Figure 7-3 shows one use of sprite/playfield priority. The single sprite
object shown on the diagram is sprite 0. The sprite can "fly" across
playfield 2, but when it crosses playfield 1 the sprite disappears behind
that playfield. The result is an unusual video effect that causes the
object to disappear when it crosses an invisible boundary on the screen.



    +---------------------+    +---------------------+
    |#####################|    |                     |
    |#####################|    |                     |
    |#####################|    |      ·········      |
    |#####################|    |      ·········      |
    |####                 |    |·····················|         __
    |####                 |    |·····················|        /  \
    |####                 |    |·····················|     __/____\__
    |####                 |    |·····················|    |          |
    |####                 |    |·····················|    |__________|
    |####                 |    |·····················|       \    /
    |####                 |    |·····················|        \__/
    |####                 |    |·····················|
    |#####################|    |      ·········      |      Sprite 0
    |#####################|    |      ·········      |
    |#####################|    |                     |
    |#####################|    |                     |
    +---------------------+    +---------------------+

          Playfield 1                Playfield 2


    +---------------------+
    |#####################|
    |#####################|
    |######·········######|
    |######·-·-·-·-·######|- - - - -
    |···|·__··············|
    |····/  \·············|    When everything is displayed together.
    |···|____\__··········|    sprite 0 is more important than playfield 2
    |····       |·········|    but less important than playfield 1.
    |···|____ __|·········|    So even though you can't see the boundary,
    |····    /············|    the sprite disappears "behind" the
    |···|\__/·············|    invisible PF1 boundary.
    |·····················|
    |######·-·-·-·-·######|- - - - -
    |######·········######|
    |#####################|
    |#####################|
    +---------------------+


                  Figure 7-3: Sprite/Playfield Priority
