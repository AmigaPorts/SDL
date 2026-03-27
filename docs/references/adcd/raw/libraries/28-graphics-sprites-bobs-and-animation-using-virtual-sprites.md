# 28 Graphics Sprites, Bobs and Animation / Using Virtual Sprites


This section describes how to set up the [VSprite](../Libraries_Manual_guide/node0381.html) structure so that it
represents a true VSprite.  True VSprites are managed by the GELs system
which converts them to Simple Sprites and displays them.  (Later sections
describe how a VSprite structure can be set up for Bobs and AnimComps.)

Before the system is told of a VSprite's existence, space for the [VSprite](../Libraries_Manual_guide/node0381.html)
data structure must be allocated and initialized to correctly represent a
VSprite.  Since the system does no validity checking on the VSprite
structure, the result of using a bogus structure is usually a fireworks
display, followed by a system failure.

The system software provides a way to detect collisions between VSprites
and other on-screen objects.  There is also a method of extending the
[VSprite](../Libraries_Manual_guide/node0381.html) structure to incorporate user defined variables.  These subjects
are applicable to all GELs and are explained later in the section on
"[Collisions and GEL Structure Extensions](../Libraries_Manual_guide/node03AB.html)".

 [Specification of VSprite Structure](../Libraries_Manual_guide/node0381.html) 
 [Reserved VSprite Members](../Libraries_Manual_guide/node0382.html) 
 [Using VSprite Flags](../Libraries_Manual_guide/node0383.html) 
 [VSprite Position](../Libraries_Manual_guide/node0384.html) 
 [VSprite Image Size](../Libraries_Manual_guide/node0385.html) 
 [VSprites and Collision Detection](../Libraries_Manual_guide/node0386.html) 
 [VSprite Image Data](../Libraries_Manual_guide/node0387.html) 
 [Specifying the Colors of a VSprite](../Libraries_Manual_guide/node0388.html) 
 [Adding and Removing VSprites](../Libraries_Manual_guide/node0389.html) 
 [Changing VSprites](../Libraries_Manual_guide/node038A.html) 
 [Getting the VSprite List In Order](../Libraries_Manual_guide/node038B.html) 
 [Displaying the VSprites](../Libraries_Manual_guide/node038C.html) 

