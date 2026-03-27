# 15 Resources / FileSystem Resource


The FileSystem resource returns the filesystems that are available on the
Amiga.  It has no functions.  Opening the FileSystem resource returns a
pointer to a [List](../Includes_and_Autodocs_2._guide/node007D.html) structure containing the current filesystems in the
Amiga.


```c
     [Get_Filesys.c](../Devices_Manual_guide/node01A4.html) 
```
Additional programming information on the FileSystem resource can be found
in the include files and the Autodocs for the FileSystem resource in the
Amiga ROM Kernel Reference Manual: [Includes and Autodocs](../Includes_and_Autodocs_2._guide/node0000.html) and the
"[Expansion](../Libraries_Manual_guide/node0414.html)" chapter of the Amiga ROM Kernel Reference Manual: Libraries.


```c
                       FileSystem Resource Information
                    --------------------------------------
                    INCLUDES        resources/[filesysres.h](../Includes_and_Autodocs_2._guide/node011D.html)
                                    resources/[filesysres.i](../Includes_and_Autodocs_2._guide/node011F.html)

                    AUTODOCS        [filesysres.doc](../Includes_and_Autodocs_2._guide/node053A.html)

                    LIBRARIES       expansion library
```
