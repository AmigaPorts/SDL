# 3 Intuition Screens / Custom Screen Functions


All applications require a screen to work in.  This can be an existing,
[public screen](../Libraries_Manual_guide/node00E6.html) or a new, custom screen created by the application itself.
To create a new, custom screen to work with, you call OpenScreen() or one
of its variants.


                 Table 3-3: Custom Screen Functions
  _____________________________________________________________________
 |                                                                     |
 |     [OpenScreenTags()](../Includes_and_Autodocs_2._guide/node0238.html)  Create a new, custom screen from a tag list.  |
 |  [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html)  Use either one of these with Release 2 (V36)  |
 |                       or later versions of the OS.                  |
 |                                                                     |
 |         [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html)  Create a new, custom screen from an           |
 |                       [ExtNewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure.  Use this if your     |
 |                       application must be compatible with 1.3 (V34) |
 |                       or earlier versions of the operating system.  |
 |                                                                     |
 |        [CloseScreen()](../Libraries_Manual_guide/node00E4.html)  Close a custom screen and free the memory     |
 |                       it used.                                      |
 |_____________________________________________________________________|


 [Creating A New Custom Screen](../Libraries_Manual_guide/node00E0.html)    [Screen Attributes](../Libraries_Manual_guide/node00E5.html) 

