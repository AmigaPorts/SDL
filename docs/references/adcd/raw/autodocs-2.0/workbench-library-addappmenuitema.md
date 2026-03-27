# workbench.library/AddAppMenuItemA



NAME

```c
    AddAppMenuItem - add a menuitem to workbench's list              (V36)
                    of appmenuitems.
```
SYNOPSIS

```c
    [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) = AddAppMenuItemA(id, userdata, text, msgport, taglist)
    D0                            D0     D1      A0     A1       A2

    struct [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) *AddAppMenuItemA(ULONG, ULONG, char *,
                                            struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,
                                            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    Alternate, varargs version:
    struct [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) *AddAppMenuItem(ULONG, ULONG, char *,
                                    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
```
FUNCTION

```c
    Attempt to add the text as a menuitem to workbench's list
    of appmenuitems (the 'Tools' menu strip).
```
INPUTS

```c
    id       - this variable is strictly for your own use and is ignored
               by workbench.  Typical uses in C are in switch and case
               statements, and in assembly language table lookup.
    userdata - this variable is strictly for your own use and is ignored
               by workbench.
    text     - text for the menuitem (char *)
    msgport  - pointer to message port workbench will use to send you an
               [AppMessage](../Includes_and_Autodocs_2._guide/node0135.html#line125) message of type 'MTYPE_APPMENUITEM' when your
               menuitem gets selected.
    taglist  - ptr to a list of tag items.  Must be NULL for V2.0.
```
RESULTS

```c
    [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) - a pointer to an appmenuitem structure which you pass to
                  [RemoveAppMenuItem](../Includes_and_Autodocs_2._guide/node040B.html) when you want to remove the menuitem
                  from workbench's list of appmenuitems.  NULL if
                  workbench was unable to add your menuitem; typically
                  happens when workbench is not running or under low
                  memory conditions.
```
SEE ALSO

```c
    [RemoveAppMenuItem()](../Includes_and_Autodocs_2._guide/node040B.html)
```
BUGS

    Currently does not limit the system to 63 menu items...
    Any menu items after the 63rd will not be selectable.
