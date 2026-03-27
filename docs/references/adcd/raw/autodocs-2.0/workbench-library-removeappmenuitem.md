# workbench.library/RemoveAppMenuItem



NAME

```c
    RemoveAppMenuItem - remove a menuitem from workbench's list      (V36)
                        of appmenuitems.
```
SYNOPSIS

```c
    error = RemoveAppMenuItem(AppMenuItem)
     D0                            A0
    BOOL RemoveAppMenuItem(struct [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) *);
```
FUNCTION

    Attempt to remove an appmenuitem from workbench's list
    of appmenuitems.
INPUTS

```c
    [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) - pointer to an [AppMenuItem](../Includes_and_Autodocs_2._guide/node0135.html#line147) structure returned by
                  AddAppMenuItem.
```
RESULTS

    error - Currently always TRUE...
NOTES

    As with anything that deals with async operation, you will need to
    do a final check for messages on your App message port for messages
    that may have come in between the last time you checked and the
    call to removed the App.
SEE ALSO

```c
    [AddAppMenuItemA()](../Includes_and_Autodocs_2._guide/node0408.html)
```
BUGS

    None
