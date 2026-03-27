# 4 Intuition Windows / Function Reference


The following are brief descriptions of the Intuition functions that
relate to the use of Intuition windows.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


                Table 4-2: Functions for Intuition Windows
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |    [OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html)  Open a window.                               |
 |       [OpenWindowTags()](../Includes_and_Autodocs_2._guide/node023A.html)  Alternate calling sequence for               |
 |                         OpenWindowTagList().                         |
 |           [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)  Pre-V36 way to open a window.                |
 |          [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)  Close a window.                              |
 |----------------------------------------------------------------------|
 |         [BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html)  Turn on optimized window refresh mode.       |
 |           [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html)  Turn off optimized window refresh mode.      |
 |   [RefreshWindowFrame()](../Includes_and_Autodocs_2._guide/node0242.html)  Redraw the borders and border gadgets of an  |
 |                         open window.                                 |
 |----------------------------------------------------------------------|
 |       [ActivateWindow()](../Includes_and_Autodocs_2._guide/node01FA.html)  Make an open window active.                  |
 |           [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html)  Change the size of an open window.           |
 |           [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html)  Change the position of an open window.       |
 |      [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html)  Change the size and position of an open      |
 |                         window.                                      |
 |         [WindowLimits()](../Includes_and_Autodocs_2._guide/node0263.html)  Change the minimum and maximum sizes of an   |
 |                         open window.                                 |
 |         [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html)  Move a window behind all other windows.      |
 |        [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html)  Move a window in front of all other windows. |
 |  [MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html)  Move a window in front of another window.    |
 |            [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html)  Change the size of window to its alternate   |
 |                         size.                                        |
 |      [SetWindowTitles()](../Includes_and_Autodocs_2._guide/node0258.html)  Change the window titles for the window and  |
 |                         the screen.                                  |
 |           [SetPointer()](../Includes_and_Autodocs_2._guide/node0255.html)  Set up a custom pointer to display whenever  |
 |                         the window is active.                        |
 |         [ClearPointer()](../Includes_and_Autodocs_2._guide/node0206.html)  Restore the mouse pointer to its default     |
 |                         imagery.                                     |
 |______________________________________________________________________|

