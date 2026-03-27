# 28 Graphics Sprites, Bobs and Animation / Using Bobs


The following section describes how to define a Bob (blitter object). Like
VSprites, a Bob is a software construct designed to make animation easier.
The main advantage of a Bob over a VSprite is that it allows more colors
and a width greater than 16 pixels to be defined.

To create a Bob, you need both a [Bob](../Libraries_Manual_guide/node0398.html) structure and a [VSprite](../Libraries_Manual_guide/node0381.html) structure.
The components common to all GELs -- height, collision-handling
information, position in the drawing area and pointers to the image
definition -- are part of the VSprite structure.  The added features --
such as drawing sequence, data about saving and restoring the background,
and other features not applicable to VSprites -- are further specified in
the Bob structure.

 [The VSprite Structure and Bobs](../Libraries_Manual_guide/node0396.html)        [Bob Priorities](../Libraries_Manual_guide/node03A2.html) 
 [VSprite Flags and Bobs](../Libraries_Manual_guide/node0397.html)                [Adding a Bob](../Libraries_Manual_guide/node03A5.html) 
 [The Bob Structure](../Libraries_Manual_guide/node0398.html)                     [Removing a Bob](../Libraries_Manual_guide/node03A6.html) 
 [Using Bob Flags](../Libraries_Manual_guide/node039A.html)                       [Sorting and Displaying Bobs](../Libraries_Manual_guide/node03A7.html) 
 [Specifying the Size of a Bob](../Libraries_Manual_guide/node039B.html)          [Changing Bobs](../Libraries_Manual_guide/node03A8.html) 
 [Specifying the Shape of a Bob](../Libraries_Manual_guide/node039C.html)         [Complete Bob Example](../Libraries_Manual_guide/node057B.html) 
 [Specifying the Colors of a Bob](../Libraries_Manual_guide/node039D.html)        [Double-Buffering](../Libraries_Manual_guide/node03A9.html) 
 [Other Items Influencing Bob Colors](../Libraries_Manual_guide/node039E.html) 

