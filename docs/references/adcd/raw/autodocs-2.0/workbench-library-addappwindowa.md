# workbench.library/AddAppWindowA



NAME

```c
    AddAppWindow - add a window to workbench's list of appwindows.  (V36)
```
SYNOPSIS

```c
    [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) = AddAppWindowA(id, userdata, window, msgport, taglist)
    D0                        D0     D1       A0      A1       A2

    struct [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) *AddAppWindowA(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) *AddAppWindow(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
```
FUNCTION

```c
    Attempt to add the window to workbench's list of appwindows.
    Normally non-workbench windows (those not opened by workbench)
    cannot have icons dropped in them.  This call is provided to
    allow applications to be notified when an icon or icons get
    dropped inside a window that they have registered with workbench.
    The notification consists of an [AppMessage](../Includes_and_Autodocs_2._guide/node0135.html#line125) (found in workbench.h/i)
    of type 'MTYPE_APPWINDOW' arriving at the message port you specified.
    What you do with the list of icons (pointed to by am_ArgList) is
    up to you, but generally you would want to call [GetDiskObjectNew](../Includes_and_Autodocs_2._guide/node018B.html) on
    them.
```
INPUTS

```c
    id       - this variable is strictly for your own use and is ignored
               by workbench.  Typical uses in C are in switch and case
               statements, and in assembly language table lookup.
    userdata - this variable is strictly for your own use and is ignored
               by workbench.
    window   - pointer to window to add.
    msgport  - pointer to message port workbench will use to send you an
               [AppMessage](../Includes_and_Autodocs_2._guide/node0135.html#line125) message of type 'MTYPE_APPWINDOW' when your
               window gets an icon or icons dropped in it.
    taglist  - ptr to a list of tag items.  Must be NULL for V2.0.
```
RESULTS

```c
    [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) - a pointer to an appwindow structure which you pass to
                [RemoveAppWindow](../Includes_and_Autodocs_2._guide/node040C.html) when you want to remove the window
                from workbench's list of appwindows.  NULL
                if workbench was unable to add your window; typically
                happens when workbench is not running or under low
                memory conditions.
```
SEE ALSO

```c
    [RemoveAppWindow()](../Includes_and_Autodocs_2._guide/node040C.html)
```
NOTES
   The V2.0 icon editor is an example of an app window.  Note that app
   window applications generally want to call [GetDiskObjectNew](../Includes_and_Autodocs_2._guide/node018B.html)
   (as opposed to GetDiskObject) to get the disk object for the icon
   dropped in the window.

BUGS

    None
