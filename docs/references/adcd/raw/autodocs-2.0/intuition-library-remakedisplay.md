# intuition.library/RemakeDisplay



NAME

    RemakeDisplay -- Remake the entire Intuition display.
SYNOPSIS

```c
    RemakeDisplay()

    VOID RemakeDisplay( VOID );
```
FUNCTION

```c
    This is the big one.

    This procedure remakes the entire [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure for the
    Intuition display.  It does the equivalent of [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html) for
    every screen in the system, and then it calls the internal
    equivalent of [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html).

    WARNING:  This routine can take many milliseconds to run, so
    do not use it lightly.

    Calling [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html) followed by [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html) is typically
    a more efficient method for affecting changes to a single
    screen's [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40).
```
INPUTS

    None
RESULT

    None
BUGS

SEE ALSO

```c
    [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html), [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html), [graphics.library/MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html)
    [graphics.library/MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html), [graphics.library/LoadView()](../Includes_and_Autodocs_2._guide/node0459.html)
```
