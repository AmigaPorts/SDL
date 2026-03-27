# intuition.library/WBenchToBack



NAME

    WBenchToBack -- Send the Workbench screen in back of all screens.
SYNOPSIS

```c
    Success = WBenchToBack()
    D0

    BOOL WBenchToBack( VOID );
```
FUNCTION

    Causes the Workbench screen, if it's currently opened, to go behind
    all other screens.  This does not 'move' the screen up or down,
    instead only affects the depth-arrangement of the screens.
INPUTS

    None
RESULT

    If the Workbench screen was opened, this function returns TRUE,
    otherwise it returns FALSE.
BUGS

SEE ALSO

```c
    [WBenchToFront()](../Includes_and_Autodocs_2._guide/node0262.html), [ScreenToFront()](../Includes_and_Autodocs_2._guide/node024D.html)
```
