# workbench.library/AddAppIconA



NAME

```c
    AddAppIcon - add an icon to workbench's list of appicons.        (V36)
```
SYNOPSIS

```c
    AppIcon = AddAppIconA(id, userdata, text, msgport,
       D0                 D0     D1      A0     A1

                                    lock, diskobj, taglist)
                                     A2      A3      A4

    struct AppIcon *AddAppIconA(ULONG, ULONG, char *,
            struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [FileLock](../Includes_and_Autodocs_2._guide/node0078.html#line453) *, struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *,
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct AppIcon *AddAppIcon(ULONG, ULONG, char *,
                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [FileLock](../Includes_and_Autodocs_2._guide/node0078.html#line453) *,
                    struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *,
                    tag1, data1,
                    tag2, data2,
                    ...
                    TAG_END );
```
FUNCTION

```c
    Attempt to add an icon to workbench's list of appicons.  If
    successful, the icon is displayed on the workbench (the same
    place disk icons are displayed).
    This call is provided to allow applications to be notified when
    a graphical object (non neccessarely associated with a file)
    gets 'manipulated'. (explained later).
    The notification consists of an [AppMessage](../Includes_and_Autodocs_2._guide/node0135.html#line125) (found in workbench.h/i)
    of type 'MTYPE_APPICON' arriving at the message port you specified.
    The types of 'manipulation' that can occur are:
    1. Double-clicking on the icon.  am_NumArgs will be zero and
       am_ArgList will be NULL.
    2. Dropping an icon or icons on your appicon.  am_NumArgs will
      be the number of icons droppped on your app icon plus one.
      am_ArgList will be an array of ptrs to [WBArg](../Includes_and_Autodocs_2._guide/node0134.html#line35) structures.
      Refer to the 'WBStartup Message' section of the RKM for more info.
    3. Dropping your appicon on another icon.  NOT SUPPORTED.
```
INPUTS

```c
    id       - this variable is strictly for your own use and is ignored
               by workbench.  Typical uses in C are in switch and case
               statements, and in assembly language table lookup.
    userdata - this variable is strictly for your own use and is ignored
               by workbench.
    text     - name of icon (char *)
    lock     - NULL    (Currently unused)
    msgport  - pointer to message port workbench will use to send you an
               [AppMessage](../Includes_and_Autodocs_2._guide/node0135.html#line125) message of type 'MTYPE_APPICON' when your icon
               gets 'manipulted' (explained above).
    diskobj  - pointer to a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure filled in as follows:
        do_Magic - NULL
        do_Version - NULL
        do_Gadget - a gadget structure filled in as follows:
            NextGadget - NULL
            LeftEdge - NULL
            TopEdge - NULL
            Width - width of icon hit-box
            Height - height of icon hit-box
            Flags - NULL or GADGHIMAGE
            Activation - NULL
            GadgetType - NULL
            GadgetRender - pointer to [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structure filled in as follows:
                LeftEdge - NULL
                TopEdge - NULL
                Width - width of image (must be <= Width of hit box)
                Height - height of image (must be <= Height of hit box)
                Depth - # of bit-planes in image
                ImageData - pointer to actual word aligned bits (CHIP MEM)
                PlanePick - Plane mask ((1 << depth) - 1)
                PlaneOnOff - 0
                NextImage - NULL
            SelectRender - pointer to alternate [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) struct or NULL
            GadgetText - NULL
            MutualExclude - NULL
            SpecialInfo - NULL
            GadgetID - NULL
            UserData - NULL
        do_Type - NULL
        do_DefaultTool - NULL
        do_ToolTypes - NULL
        do_CurrentX - NO_ICON_POSITION (recommended)
        do_CurrentY - NO_ICON_POSITION (recommended)
        do_DrawerData - NULL
        do_ToolWindow - NULL
        do_StackSize - NULL

    (an easy way to create one of these (a DiskObject) is to create an icon
    with the V2.0 icon editor and save it out.  Your application can then
    call [GetDiskObject](../Includes_and_Autodocs_2._guide/node018A.html) on it and pass that to AddAppIcon.)

    taglist  - ptr to a list of tag items.  Must be NULL for V2.0.
```
RESULTS

```c
    AppIcon  - a pointer to an appicon structure which you pass to
               [RemoveAppIcon](../Includes_and_Autodocs_2._guide/node040A.html) when you want to remove the icon
               from workbench's list of appicons.  NULL
               if workbench was unable to add your icon; typically
               happens when workbench is not running or under low
               memory conditions.
```
EXAMPLE

```c
    You could design a print-spooler icon and add it to the workbench.
    Any file dropped on the print spooler would be printed.  If the
    user double-clicked (opended) your printer-spooler icon, you could
    open a window showing the status of the print spool, allow changes
    to print priorities, allow deletions, etc.  If you registered this
    window as an 'appwindow' (explained in workbench.library AddAppWindow)
    files could also be dropped in the window and added to the spool.
```
SEE ALSO

```c
    [RemoveAppIcon()](../Includes_and_Autodocs_2._guide/node040A.html)
```
BUGS

```c
    Currently [Info](../Includes_and_Autodocs_2._guide/node02BD.html) cannot be obtained on appicons.
```
