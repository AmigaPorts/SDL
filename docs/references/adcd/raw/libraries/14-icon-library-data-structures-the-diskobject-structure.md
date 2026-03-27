# 14 / / Icon Library Data Structures / The DiskObject Structure


The actual data present in the [.info](../Libraries_Manual_guide/node0238.html) file is organized as a DiskObject
structure which is defined in the include file <workbench/[workbench.h](../Includes_and_Autodocs_2._guide/node0135.html#line61)>.
For a complete listing, see the Amiga ROM Kernel Reference Manual:
Includes and Autodocs.  The DiskObject structure contains the following
elements:


```c
    struct DiskObject
        {
        UWORD              do_Magic;   /* magic number at start of file */
        UWORD              do_Version; /* so we can change structure    */
        struct Gadget      do_Gadget;  /* a copy of in core gadget      */
        UBYTE              do_Type;
        char              *do_DefaultTool;
        char             **do_ToolTypes;
        LONG               do_CurrentX;
        LONG               do_CurrentY;
        struct DrawerData *do_DrawerData;
        char              *do_ToolWindow;  /* only applies to tools */
        LONG               do_StackSize;   /* only applies to tools */
        };
```
do_Magic

```c
    A magic number that the icon library looks for to make sure that the
    file it is reading really contains an icon.  It should be the
    manifest constant WB_DISKMAGIC.  [PutDiskObject()](../Libraries_Manual_guide/node0243.html#line4) will put this value
    in the structure, and [GetDiskObject()](../Libraries_Manual_guide/node0243.html#line4) will not believe that a file is
    really an icon unless this value is correct.
```
do_Version

```c
    This provides a way to enhance the [.info](../Libraries_Manual_guide/node0238.html) file in an
    upwardly-compatible way.  It should be WB_DISKVERSION.  The icon
    library will set this value for you and will not believe weird values.
```
do_Gadget

```c
    This contains all the imagery for the icon. See the "[Gadget Structure](../Libraries_Manual_guide/node0242.html)"
    section below for more details.
```
do_Type


```c
    The type of the icon; can be set to any of the following values.


            WBDISK     The root of a disk
            WBDRAWER   A directory on the disk
            WBTOOL     An executable program
            WBPROJECT  A data file
            WBGARBAGE  The Trashcan directory
            WBKICK     A Kickstart disk
            WBAPPICON  Any object not directly associated
                       with a filing system object, such as
                       a print spooler (new in Release 2).


               Table 14-2: Workbench Object Types
```
do_DefaultTool

```c
    Default tools are used for project and disk icons.  For projects
    (data files), the default tool is the program Workbench runs when the
    project is activated.  Any valid AmigaDOS path may be entered in this
    field such as "SYS:myprogram", "df0:mypaint", "myeditor" or
    ":work/mytool".

    For disk icons, the default tool is the diskcopy program
    ("SYS:System/DiskCopy") that will be used when this disk is the
    source of a copy.
```
do_ToolTypes

```c
    This is an array of free-format strings.  Workbench does not enforce
    any rules on these strings, but they are useful for passing
    environment information.  See the section on "[The Tool Types Array](../Libraries_Manual_guide/node0244.html)"
    below for more information.
```
do_CurrentX, do_CurrentY

    Drawers have a virtual coordinate system.  The user can scroll around
    in this system using the scroll gadgets on the window that opens when
    the drawer is activated.  Each icon in the drawer has a position in
    the coordinate system.  CurrentX and CurrentY contain the icon's
    current position in the drawer.  Picking a position for a newly
    created icon can be tricky.  NO_ICON_POSITION is a system constant
    for do_CurrentX and do_CurrentY that instructs Workbench to pick a
    reasonable place for the icon.  Workbench will place the icon in an
    unused region of the drawer.  If there is no space in the drawers
    window, the icon will be placed just to the right of the visible
    region.
do_DrawerData

```c
    If the icon is associated with a directory (WBDISK, WBDRAWER,
    WBGARBAGE), it needs a [DrawerData](../Includes_and_Autodocs_2._guide/node0135.html#line51) structure to go with it.  This
    structure contains an Intuition [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure (see the
    "[Intuition Windows](../Libraries_Manual_guide/node0102.html)" chapter for more information):

        struct DrawerData
            {
            struct NewWindow dd_NewWindow; /* structure to open window */
            LONG             dd_CurrentX;  /* current x coordinate of  */
                                           /* origin                   */
            LONG             dd_CurrentY;  /* current y coordinate of  */
                                           /* origin                   */
            };

    Workbench uses this to hold the current window position and size of
    the window so it will reopen in the same place.
```
do_ToolWindow

    This field is reserved for future use.
do_StackSize

```c
    This is the size of the stack (in bytes) used for running the tool.
    If this is NULL, then Workbench will use a reasonable default stack
    size (currently 4K bytes).

    Stack Size is Taken from the Project Icon.
    -----------------------------------------
    When a tool is run via the default tool mechanism (i.e., a project
    was activated, not the tool itself), Workbench uses the stack size
    specified in the project's [.info](../Libraries_Manual_guide/node0238.html) file and the tool's .info file is
    ignored.
```
