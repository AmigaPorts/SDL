# intuition.library/WBenchToFront



NAME

    WBenchToFront -- Bring the Workbench screen in front of all screens.
SYNOPSIS

```c
    Success = WBenchToFront()
    D0

    BOOL WBenchToFront( VOID );
```
FUNCTION

```c
    Causes the Workbench [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97), if it's currently opened, to come to
    the foreground.  This does not 'move' the screen up or down, instead
    only affects the depth-arrangement of the screen.
```
INPUTS

    None
RESULT

    If the Workbench screen was opened, this function returns TRUE,
    otherwise it returns FALSE.
BUGS

SEE ALSO

```c
    [WBenchToBack()](../Includes_and_Autodocs_2._guide/node0261.html), [ScreenToBack()](../Includes_and_Autodocs_2._guide/node024C.html)
```
