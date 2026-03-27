# graphics.library/WaitBOVP



NAME

    WaitBOVP -- Wait till vertical beam reached bottom of
                this viewport.
SYNOPSIS

```c
    WaitBOVP( vp )
              a0

    void WaitBOVP( struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) * );
```
FUNCTION

    Returns when the vertical beam has reached the bottom of this viewport
INPUTS

```c
    vp - pointer to [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure
```
RESULT

    This function will return sometime after the beam gets beyond
    the bottom of the viewport.  Depending on the multitasking load
    of the system, the actual beam position may be different than
    what would be expected in a lightly loaded system.
BUGS

```c
    Horrors! This function currently busy waits waiting for the
    beam to get to the right place.  It should use the copper
    interrupt to trigger and send signals like [WaitTOF](../Includes_and_Autodocs_2._guide/node048B.html) does.
```
SEE ALSO

```c
    [WaitTOF()](../Includes_and_Autodocs_2._guide/node048B.html) [VBeamPos()](../Includes_and_Autodocs_2._guide/node0487.html)
```
