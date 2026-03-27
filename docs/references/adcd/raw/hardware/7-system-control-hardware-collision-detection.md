# 7 System Control Hardware / Collision Detection


You can use the hardware to detect collisions between one  [sprite group](../Hardware_Manual_guide/node0157.html) 
and another  [sprite group](../Hardware_Manual_guide/node0157.html) , any  [sprite group](../Hardware_Manual_guide/node0157.html)  and either of the
playfields, the two playfields, or any combination of these items.

The first kind of collision is typically used in a game operation to
determine if a missile has collided with a moving player. The second kind
of collision is typically used to keep a moving object within specified
on-screen boundaries. The third kind of collision detection allows you to
define sections of playfield as individual objects, which you may move
using the blitter. This is called playfield animation. If one playfield is
defined as the backdrop or playing area and the other playfield is used to
define objects (in addition to the sprites), you can sense collisions
between the playfield-objects and the sprites or between the
playfield-objects and the other playfield.

 [How Collisions are Determined](../Hardware_Manual_guide/node015B.html) 
 [How To Interpret the Collision Data](../Hardware_Manual_guide/node015C.html) 
 [How Collision Detection is Controlled](../Hardware_Manual_guide/node015D.html) 

