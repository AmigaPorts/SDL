# workbench.library/RemoveAppIcon



NAME

```c
    RemoveAppIcon - remove an icon from workbench's list            (V36)
                     of appicons.
```
SYNOPSIS

```c
    error = RemoveAppIcon(AppIcon)
     D0                     A0
    BOOL RemoveAppIcon(struct AppIcon *);
```
FUNCTION

    Attempt to remove an appicon from workbench's list of appicons.
INPUTS

    AppIcon - pointer to an AppIcon structure returned by AddAppIcon.
RESULTS

    error - Currently always TRUE...
NOTES

    As with anything that deals with async operation, you will need to
    do a final check for messages on your App message port for messages
    that may have come in between the last time you checked and the
    call to removed the App.
SEE ALSO

```c
    [AddAppIconA()](../Includes_and_Autodocs_2._guide/node0407.html)
```
BUGS

    None
