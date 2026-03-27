# 4 / Forming a Sprite / Screen Position


A sprite's screen position is defined as a set of X,Y coordinates.
Position (0,0), where X = 0 and Y = 0, is the upper left-hand corner of
the display. You define a sprite's location by specifying the coordinates
of its upper left-hand pixel. Sprite position is always defined as though
the display modes were low resolution and non-interlaced. The X,Y
coordinate system and definition of a sprite's position are graphically
represented in Figure 4-1. Notice that because of display overscan,
position (0,0) (that is, X = 0, Y = 0) is not normally in a viewable
region of the screen.




```c
       (0,0) __
               \
                \
                 +-----------------------------+
                 |###############|#############|
                 |###############|#############|
                 |###+-----------|---------+###|
                 |###|                     |###|  __ visible screen
                 |###|        Y axis       |###| /     boundaries
                 |###|                     |###|/
                 |###|           |         |###/
                 |###|           |         |##/|
                 |###|           |         |#/#|
                 |----- X axis --+---+     |/##|
                 |###|           |/*\|     |###|
                 |###|           |***|     |###|
                 |###|           |\*/|     |###|
                 |###|           +---+     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###+---------------------+###|
                 |#############################|
                 |#############################|
                 +-----------------------------+


          Figure 4-1: Defining Sprite On-screen Position
```
The amount of viewable area is also affected by the size of the
 [playfield display window](../Hardware_Manual_guide/node006F.html)  (defined by the values in  [DDFSTRT](../Hardware_Manual_guide/node0072.html#line9) ,  [DDFSTOP](../Hardware_Manual_guide/node0072.html#line31) ,
 [DIWSTRT](../Hardware_Manual_guide/node0070.html) ,  [DIWSTOP](../Hardware_Manual_guide/node0071.html) , etc.). See the "Playfield Hardware" chapter for more
information about  [overscan and display windows](../Hardware_Manual_guide/node007E.html) .

 [Horizontal Position](../Hardware_Manual_guide/node00B2.html) 
 [Vertical Position](../Hardware_Manual_guide/node00B3.html) 
 [Clipped Sprites](../Hardware_Manual_guide/node00B4.html) 

