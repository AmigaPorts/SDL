# 18 Exec Libraries / Adding a Library


Exec provides several ways to add your own libraries to the system library
list.  One rarely used way is to call [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html) (a DOS library function)
to load your library and then use the Exec [MakeLibrary()](../Includes_and_Autodocs_2._guide/node0361.html) and [AddLibrary()](../Includes_and_Autodocs_2._guide/node0327.html)
functions to initialize your library and add it to the system.

[MakeLibrary()](../Includes_and_Autodocs_2._guide/node0361.html) allocates space for the code vectors and data area,
initializes the library node, and initializes the data area according to
your specifications, returning to you a library base pointer.  The base
pointer may then be passed to [AddLibrary()](../Includes_and_Autodocs_2._guide/node0327.html) to add your library to the
system.

Another way to initialize and add a library or device to the system is
through the use of a [Resident](../Libraries_Manual_guide/node0298.html) structure or romtag (see <exec/[resident.h](../Includes_and_Autodocs_2._guide/node00A0.html#line19)>).
A romtag allows you to place your library or device in a directory
(default LIBS: for libraries, DEVS: for devices) and have the OS
automatically load and initialize it when an application tries to open it
with [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15) or [OpenDevice()](../Libraries_Manual_guide/node029E.html).

Two additional initialization methods exist for a library or device which
is bound to a particular Amiga expansion board.  The library or device
(containing a romtag) may be placed in the SYS:Expansion drawer, along
with an icon containing the Manufacturer and Product number of the board
it requires.  If the startup-sequence BindDrivers command finds that board
in the system, it will load and initialize the matching Expansion drawer
device or library. In addition, since 1.3, the Amiga system software
supports ROM drivers on expansion boards.  See the "[Expansion Library](../Libraries_Manual_guide/node0418.html)"
chapter for additional information on ROM drivers and Expansion drawer
drivers.  The [sample device code](../Devices_Manual_guide/node0159.html) in the Amiga ROM Kernel Reference Manual:
Devices volume of this manual set may be conditionally assembled as an
Expansion drawer driver.

 [Resident (Romtag) Structure](../Libraries_Manual_guide/node0298.html) 

