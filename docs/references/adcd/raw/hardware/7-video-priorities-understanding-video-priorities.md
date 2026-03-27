# 7 / Video Priorities / Understanding Video Priorities


The concept of video priorities is easy to understand if you imagine that
four fingers of one of your hands represent the four pairs of sprites and
two fingers of your other hand represent the two playfields. Just as you
cannot change the sequence of the four fingers on the one hand, neither
can you change the  [relative priority](../Hardware_Manual_guide/node0156.html)  of the sprites. However, just as
you can intertwine the two fingers of one hand in many different ways
relative to the four fingers of the other hand, so can you position the
playfields in front of or behind the sprites. This is illustrated in
Figure 7-2.


```c
     [Figure 7-2: Analogy for Video Priority](../Hardware_Manual_guide/node02E2.html) 
```
Five possible positions can be chosen for each of the two "playfield
fingers." For example, you can place playfield 1 on top of sprites 0 and 1
(0), between sprites 0 and 1 and sprites 2 and 3 (1), between sprites 2
and 3 and sprites 4 and 5 (2), between sprites 4 and 5 and sprites 6 and 7
(3), or beneath sprites 6 and 7 (4). You have the same possibilities for
playfield 2.

The numbers 0 through 4 shown in parentheses in the preceding paragraph
are the actual values you use to select the playfield priority positions.
See next section  [Setting the Priority Control Register](../Hardware_Manual_guide/node0159.html) .

You can also control the priority of playfield 2 relative to playfield 1.
This gives you additional choices for the way you can design the
 [screen priorities](../Hardware_Manual_guide/node007B.html) .

