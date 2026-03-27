# 28 Graphics Sprites, Bobs and Animation / Function Reference


The following are brief descriptions of the Amiga's graphics animation
functions.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details on each function call.


                 Table 28-1: Graphics Animation Functions
  ________________________________________________________________________
 |                                                                        |
 |     Animation                                                          |
 |     Function                   Description                             |
 |========================================================================|
 |     [AddAnimOb()](../Includes_and_Autodocs_2._guide/node040E.html)  Add an AnimOb to the linked list of AnimObs.          |
 |        [AddBob()](../Includes_and_Autodocs_2._guide/node040F.html)  Add a Bob to the current gel list.                    |
 |    [AddVSprite()](../Includes_and_Autodocs_2._guide/node0411.html)  Add a VSprite to the current gel list.                |
 |       [Animate()](../Includes_and_Autodocs_2._guide/node0415.html)  Process every AnimOb in the current animation list.   |
 |  [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html)  Change the sprite image pointer.                      |
 |   [DoCollision()](../Includes_and_Autodocs_2._guide/node0435.html)  Test every gel in gel list for collisions.            |
 |     [DrawGList()](../Includes_and_Autodocs_2._guide/node0438.html)  Process the gel list, queueing VSprites, drawing Bobs.|
 |  [FreeGBuffers()](../Includes_and_Autodocs_2._guide/node0441.html)  Deallocate memory obtained by GetGBuffers().          |
 |    [FreeSprite()](../Includes_and_Autodocs_2._guide/node0443.html)  Return sprite for use by others and virtual sprite    |
 |                  machine.                                              |
 |   [GetGBuffers()](../Includes_and_Autodocs_2._guide/node0447.html)  Attempt to allocate all buffers of an entire AnimOb.  |
 |     [GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html)  Attempt to get a sprite for the simple sprite manager.|
 |      [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  Initialize a gel list; must be called before using    |
 |                  gels.                                                 |
 |    [InitGMasks()](../Includes_and_Autodocs_2._guide/node0452.html)  Initialize all of the masks of an AnimOb.             |
 |     [InitMasks()](../Includes_and_Autodocs_2._guide/node0453.html)  Initialize the [BorderLine](../Libraries_Manual_guide/node03B0.html) and [CollMask](../Libraries_Manual_guide/node03AF.html) masks of a     |
 |                  VSprite.                                              |
 |    [MoveSprite()](../Includes_and_Autodocs_2._guide/node045E.html)  Move sprite to a point relative to top of [ViewPort](../Libraries_Manual_guide/node00F1.html#line4).   |
 |        [RemBob()](../Includes_and_Autodocs_2._guide/node046E.html)  Remove a Bob from the gel list.                       |
 |       [RemIBob()](../Includes_and_Autodocs_2._guide/node0470.html)  Immediately remove a Bob from the gel list and the    |
 |                  [RastPort](../Libraries_Manual_guide/node034A.html).                                             |
 |    [RemVSprite()](../Includes_and_Autodocs_2._guide/node0471.html)  Remove a VSprite from the current gel list.           |
 |  [SetCollision()](../Includes_and_Autodocs_2._guide/node0477.html)  Set a pointer to a user collision routine.            |
 |     [SortGList()](../Includes_and_Autodocs_2._guide/node047F.html)  Sort the current gel list, ordering its y,x           |
 |                  coordinates.                                          |
 |________________________________________________________________________|

