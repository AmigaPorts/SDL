# workbench.library/RemoveAppWindow



NAME

```c
    RemoveAppWindow - remove a window from workbench's list         (V36)
                      of appwindows.
```
SYNOPSIS

```c
    error = RemoveAppWindow(AppWindow)
     D0                       A0
    BOOL RemoveAppWindow(struct [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) *);
```
FUNCTION

    Attempt to remove an appwindow from workbench's list of appwindows.
INPUTS

```c
    [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) - pointer to an [AppWindow](../Includes_and_Autodocs_2._guide/node0135.html#line145) structure returned by
                AddAppWindow.
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
    [AddAppWindowA()](../Includes_and_Autodocs_2._guide/node0409.html)
```
BUGS

    None
