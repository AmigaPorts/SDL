# 12 Boopsi--Object Oriented Intuition / Function Reference


The following are brief descriptions of the Intuition and amiga.lib
functions discussed in this chapter.  See the "Amiga ROM Kernel Reference
Manual: Includes and Autodocs" for details on each function call.  All
these functions require Release 2 or a later version of the Amiga
operating system.

              Table 12-1: Intuition Library Boopsi Functions
  ________________________________________________________________________
 |                                                                        |
 |       Function                 Description                             |
 |========================================================================|
 |      [NewObjectA()](../Includes_and_Autodocs_2._guide/node022F.html)  Create a new Boopsi object (tag array form).        |
 |       [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html)  Create a new Boopsi object (varargs form).          |
 |   [DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html)  Dispose of a Boopsi object.                         |
 |        [SetAttrs()](../Includes_and_Autodocs_2._guide/node024E.html)  Set one or more of a Boopsi object's attributes     |
 |                    (tag array form).                                   |
 |  [SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node0252.html)  Set one or more of a Boopsi object's attributes     |
 |                    (varargs form).                                     |
 |         [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html)  Obtain an attribute from a Boopsi object.           |
 |------------------------------------------------------------------------|
 |       [MakeClass()](../Includes_and_Autodocs_2._guide/node0227.html)  Create a new private or public Boopsi class.        |
 |       [FreeClass()](../Includes_and_Autodocs_2._guide/node0216.html)  Free a Boopsi class created by MakeClass().         |
 |        [AddClass()](../Includes_and_Autodocs_2._guide/node01FB.html)  Add a public Boopsi class to Intuition's internal   |
 |                    list of public classes.                             |
 |     [RemoveClass()](../Includes_and_Autodocs_2._guide/node0245.html)  Remove a public Boopsi class that was added to      |
 |                    Intuition's internal list with AddClass().          |
 |------------------------------------------------------------------------|
 |   [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html)  Set up a [RastPort](../Libraries_Manual_guide/node034A.html) for use by a Boopsi gadget        |
 |                    dispatcher.                                         |
 |  [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html)  Free a RastPort set up by ReleaseGIRPort().         |
 |________________________________________________________________________|


                  Table 12-2: Amiga.lib Boopsi Functions
  ________________________________________________________________________
 |                                                                        |
 |       Function                 Description                             |
 |========================================================================|
 |       [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html)  Send a Boopsi message to a Boopsi object            |
 |                    (tag array form).                                   |
 |        [DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html)  Send a Boopsi message to a Boopsi object            |
 |                    (varargs form).                                     |
 |  [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of its class's superclass    |
 |                    (tag array form).                                   |
 |   [DoSuperMethod()](../Includes_and_Autodocs_2._guide/node0158.html)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of its class's superclass    |
 |                    (varargs form).                                     |
 |   [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of the specified class       |
 |                    (tag array form).                                   |
 |    [CoerceMethod()](../Includes_and_Autodocs_2._guide/node0145.html)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of the specified class       |
 |                    (varargs form).                                     |
 |   [SetSuperAttrs()](../Includes_and_Autodocs_2._guide/node0166.html)  Send a Boopsi [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message to the Boopsi object's |
 |                    superclass.                                         |
 |________________________________________________________________________|

