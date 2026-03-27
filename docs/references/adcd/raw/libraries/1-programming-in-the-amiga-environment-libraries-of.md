# 1 / Programming in the Amiga Environment / Libraries of Functions


Most of the routines that make up the Amiga's operating system are
organized into groups called libraries.  In order to call a function on
the Amiga you must first open the library that contains the function.  For
example, if you want to call the [Read()](../Includes_and_Autodocs_2._guide/node02E0.html) function to read data from disk
you must first open the DOS library.

The system's master library, called [Exec](../Libraries_Manual_guide/node0013.html), is always open.  Exec keeps
track of all the other libraries and is in charge of opening and closing
them.  One Exec function, [OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html), is used to open all the other
libraries.

Almost any program you write for the Amiga will have to call the
[OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html) function.  Usage is as follows:


```c
    struct Library *LibBase;      /* Global: declare this above main() */

    main()
    {
    LibBase = OpenLibrary("library.name",version);

    if(!LibBase) { /* Library did not open, so exit        */ }
    else         { /* Library opened, so use its functions */ }
    }
```
LibBase

```c
    This is a pointer to the library structure in memory, often referred
    to as the library base.  The library base must be global because the
    system uses it to handle the library's function calls.  The name of
    this pointer is established by the system (you cannot use any name
    you want).  Refer to the list below for the appropriate name.
```
library.name

    This is a C string that describes the name of the library you wish to
    open.  The list of Amiga library names is given below.
version

```c
    This should be set to the earliest acceptable [library version](../Libraries_Manual_guide/node0014.html).  A
    value of 0 matches any version.  A value of 33 means you require at
    least version 33, or a later version of the library.  If the library
    version in the system is older than the one you specify,
    [OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html) will fail (return 0).
```
The following table shows all the function libraries that are currently
part of the Amiga system software.  Column one shows the name string to
use with [OpenLibrary()](../Includes_and_Autodocs_2._guide/node0367.html); column two shows the name of the global variable
you should use to hold the pointer to the library; column three shows the
oldest [version](../Libraries_Manual_guide/node0014.html) of the library still in use.




```c
         Table 1-1: Parameters to Use With OpenLibrary()


                                                    Oldest Version
     Library Name              Library Base Name        In Use
    (library.name)*               (LibBase)            (version)
    --------------             -----------------    --------------
    [asl](../Includes_and_Autodocs_2._guide/node017B.html).library                AslBase                    36
    [commodities](../Includes_and_Autodocs_2._guide/node019C.html).library        CxBase                     36
    [diskfont](../Includes_and_Autodocs_2._guide/node01F2.html).library           DiskfontBase               33
    [dos](../Includes_and_Autodocs_2._guide/node0279.html).library                DOSBase                    33
    [exec](../Includes_and_Autodocs_2._guide/node0322.html).library               SysBase                    33
    [expansion](../Includes_and_Autodocs_2._guide/node03AD.html).library          ExpansionBase              33
    [gadtools](../Includes_and_Autodocs_2._guide/node03E6.html).library           GadToolsBase               36
    [graphics](../Includes_and_Autodocs_2._guide/node040D.html).library           GfxBase                    33
    [icon](../Includes_and_Autodocs_2._guide/node0182.html).library               IconBase                   33
    [iffparse](../Includes_and_Autodocs_2._guide/node01B6.html).library           IFFParseBase               36
    [intuition](../Includes_and_Autodocs_2._guide/node01F8.html).library          IntuitionBase              33
    [keymap](../Includes_and_Autodocs_2._guide/node0312.html).library             KeymapBase                 33
    [layers](../Includes_and_Autodocs_2._guide/node038D.html).library             LayersBase                 33
    [mathffp](../Includes_and_Autodocs_2._guide/node03C0.html).library            MathBase                   33
    [mathtrans](../Includes_and_Autodocs_2._guide/node0267.html).library          MathTransBase              33
    [mathieeedoubbas](../Includes_and_Autodocs_2._guide/node03F9.html).library    MathIeeeDoubBasBase        33
    [mathieeedoubtrans](../Includes_and_Autodocs_2._guide/node0492.html).library  MathIeeeDoubTransBase      33
    [mathieeesingbas](../Includes_and_Autodocs_2._guide/node018F.html).library    MathIeeeSingBasBase        33
    [mathieeesingtrans](../Includes_and_Autodocs_2._guide/node01E0.html).library  MathIeeeSingTransBase      33
    [rexxsyslib](../Includes_and_Autodocs_2._guide/node0317.html).library         RexxSysBase                36
    [translator](../Includes_and_Autodocs_2._guide/node03AB.html).library         TranslatorBase             33
    [utility](../Includes_and_Autodocs_2._guide/node03CD.html).library            UtilityBase                36
    [wb](../Includes_and_Autodocs_2._guide/node0406.html).library          WorkbenchBase              33
```
  * Other libraries may exist that are not supplied by Amiga, Inc. since


    it is a feature of the operating system to allow such libraries.
 [Opening a Library in C](../Libraries_Manual_guide/node000E.html)            [Another Kind of Function Library](../Libraries_Manual_guide/node0010.html) 
 [Opening a Library in Assembler](../Libraries_Manual_guide/node000F.html)    [Libraries, Devices and Resources](../Libraries_Manual_guide/node0011.html) 

