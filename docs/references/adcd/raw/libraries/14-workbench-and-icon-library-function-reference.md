# 14 Workbench and Icon Library / Function Reference


The following are brief descriptions of the functions in workbench.library
and icon.library.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details on each function call.


                    Table 14-3: Icon Library Functions
  _______________________________________________________________________
 |                                                                       |
 |         Function                  Description                         |
 |=======================================================================|
 |      [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html)  Read the [.info](../Libraries_Manual_guide/node0238.html) file of an icon into a           |
 |                       [DiskObject](../Libraries_Manual_guide/node0241.html) structure                            |
 |   [GetDiskObjectNew()](../Includes_and_Autodocs_2._guide/node018B.html)  Same as GetDiskObject() but returns a default   |
 |                       icon if none exists                             |
 |      [PutDiskObject()](../Includes_and_Autodocs_2._guide/node018E.html)  Write a DiskObject structure to disk as a       |
 |                       .info file                                      |
 |     [FreeDiskObject()](../Includes_and_Autodocs_2._guide/node0187.html)  Free the DiskObject structure created by        |
 |                       GetDiskObject()                                 |
 |   [DeleteDiskObject()](../Includes_and_Autodocs_2._guide/node0185.html)  Deletes a given .info file from disk            |
 |-----------------------------------------------------------------------|
 |       [FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html)  Return the value of an entry in the icon's Tool |
 |                       Type array                                      |
 |     [MatchToolValue()](../Includes_and_Autodocs_2._guide/node018C.html)  Check a Tool Type entry against a given value   |
 |-----------------------------------------------------------------------|
 |   [GetDefDiskObject()](../Includes_and_Autodocs_2._guide/node0189.html)  Read the default icon for a given icon type     |
 |   [PutDefDiskObject()](../Includes_and_Autodocs_2._guide/node018D.html)  Replace the default icon for a given icon type  |
 |                       (V36)                                           |
 |-----------------------------------------------------------------------|
 |        [AddFreeList()](../Includes_and_Autodocs_2._guide/node0183.html)  Add memory you have allocated to a FreeList     |
 |       [FreeFreeList()](../Includes_and_Autodocs_2._guide/node0188.html)  Free all the memory for entries in the FreeList |
 |       [BumpRevision()](../Includes_and_Autodocs_2._guide/node0184.html)  Create a new name for a second copy of a        |
 |                       Workbench object                                |
 |_______________________________________________________________________|


                 Table 14-4: Workbench Library Functions
  _______________________________________________________________________
 |                                                                       |
 |         Function                  Description                         |
 |=======================================================================|
 |         [AddAppIcon()](../Includes_and_Autodocs_2._guide/node0407.html)  Add an AppIcon to Workbench                     |
 |     [AddAppMenuItem()](../Includes_and_Autodocs_2._guide/node0408.html)  Add an AppMenuItem to the Workbench Tools menu  |
 |       [AddAppWindow()](../Includes_and_Autodocs_2._guide/node0409.html)  Add an AppWindow to Workbench                   |
 |-----------------------------------------------------------------------|
 |      [RemoveAppIcon()](../Includes_and_Autodocs_2._guide/node040A.html)  Remove an AppIcon to Workbench                  |
 |  [RemoveAppMenuItem()](../Includes_and_Autodocs_2._guide/node040B.html)  Remove an AppMenuItem to the Workbench Tools    |
 |                       menu                                            |
 |    [RemoveAppWindow()](../Includes_and_Autodocs_2._guide/node040C.html)  Remove an AppWindow to Workbench                |
 |_______________________________________________________________________|

