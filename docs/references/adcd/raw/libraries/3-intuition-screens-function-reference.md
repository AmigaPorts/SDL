# 3 Intuition Screens / Function Reference


The following are brief descriptions of the Intuition functions that
relate to the use of Intuition screens.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


             Table 3-10: Functions for Intuition Screens
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |    [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html)  Open a screen.                               |
 |       [OpenScreenTags()](../Includes_and_Autodocs_2._guide/node0238.html)  Alternate calling sequence for               |
 |                         OpenScreenTagList().                         |
 |           [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html)  Pre-V36 open screen function.                |
 |          [CloseScreen()](../Includes_and_Autodocs_2._guide/node0207.html)  Close an open screen.                        |
 |----------------------------------------------------------------------|
 |           [MoveScreen()](../Includes_and_Autodocs_2._guide/node022B.html)  Change the position of an open screen.       |
 |         [ScreenToBack()](../Includes_and_Autodocs_2._guide/node024C.html)  Move a screen behind all other screens.      |
 |        [ScreenToFront()](../Includes_and_Autodocs_2._guide/node024D.html)  Move a screen in front of all other screens. |
 |            [ShowTitle()](../Includes_and_Autodocs_2._guide/node0259.html)  Show the screen in front of through backdrop |
 |                         windows.                                     |
 |----------------------------------------------------------------------|
 |    [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html)  Get the DrawInfo information for an open     |
 |                         screen.                                      |
 |   [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html)  Free the DrawInfo information for a screen.  |
 |----------------------------------------------------------------------|
 |        [QueryOverscan()](../Includes_and_Autodocs_2._guide/node023F.html)  Find overscan information for a specific     |
 |                         display type.                                |
 |----------------------------------------------------------------------|
 |        [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html)  Obtain a lock on a public screen.            |
 |      [UnlockPubScreen()](../Includes_and_Autodocs_2._guide/node025D.html)  Release a lock on a public screen.           |
 |        [NextPubScreen()](../Includes_and_Autodocs_2._guide/node0231.html)  Return the name of the next public screen in |
 |                         the list.                                    |
 |      [PubScreenStatus()](../Includes_and_Autodocs_2._guide/node023E.html)  Make a public screen private or private      |
 |                         screen public.                               |
 |----------------------------------------------------------------------|
 |    [LockPubScreenList()](../Includes_and_Autodocs_2._guide/node0226.html)  Lock the public screen list (for a public    |
 |                         screen utility).                             |
 |  [UnlockPubScreenList()](../Includes_and_Autodocs_2._guide/node025E.html)  Unlock the public screen list.               |
 |  [SetDefaultPubScreen()](../Includes_and_Autodocs_2._guide/node024F.html)  Change the default public screen.            |
 |    [SetPubScreenModes()](../Includes_and_Autodocs_2._guide/node0257.html)  Establish global public screen behavior.     |
 |  [GetDefaultPubScreen()](../Includes_and_Autodocs_2._guide/node021C.html)  Copies the name of the default public screen |
 |                         to a buffer.                                 |
 |----------------------------------------------------------------------|
 |        [OpenWorkBench()](../Includes_and_Autodocs_2._guide/node023B.html)  Open the Workbench screen, if closed.        |
 |       [CloseWorkBench()](../Includes_and_Autodocs_2._guide/node0209.html)  Close the Workbench screen, if possible.     |
 |         [WBenchToBack()](../Includes_and_Autodocs_2._guide/node0261.html)  Move the Workbench screen behind all other   |
 |                         screens.                                     |
 |        [WBenchToFront()](../Includes_and_Autodocs_2._guide/node0262.html)  Move the Workbench screen in front of all    |
 |                         other screens.                               |
 |        [GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html)  Pre-V36 way to return information on an open |
 |                         screen.                                      |
 |----------------------------------------------------------------------|
 |          [ViewAddress()](../Includes_and_Autodocs_2._guide/node025F.html)  Return the address of a screen's View.       |
 |      [ViewPortAddress()](../Includes_and_Autodocs_2._guide/node0260.html)  Use &screen->ViewPort instead.               |
 |----------------------------------------------------------------------|
 |           [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html)  Low level screen handling--rebuild Copper    |
 |                         list.                                        |
 |       [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html)  Low level screen handling--incorporate       |
 |                         Copper list changes.                         |
 |        [RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html)  MakeScreen() for all screens, then           |
 |                         RethinkDisplay().                            |
 |______________________________________________________________________|

