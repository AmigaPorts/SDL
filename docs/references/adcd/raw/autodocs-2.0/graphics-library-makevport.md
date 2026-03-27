# graphics.library/MakeVPort



NAME

    MakeVPort -- generate display copper list for a viewport.
SYNOPSIS

```c
    MakeVPort( view, viewport )
                a0      a1

    void MakeVPort( struct [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) *, struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) * );
```
FUNCTION

```c
    Uses information in the [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57), [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40), ViewPort->RasInfo to
    construct and intermediate copper list for this [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40).
```
INPUTS

```c
    view - pointer to a [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure
    viewport - pointer to a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure
             The viewport must have valid pointer to a RasInfo.
```
RESULTS

```c
    constructs intermediate copper list and puts pointers in
    viewport.DspIns
    If the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) ptr in [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) is NULL then it uses colors
    from the default color table.
    If DUALPF in Modes then there must be a second RasInfo pointed
    to by the first RasInfo
```
BUGS

```c
    Narrow Viewports (whose righthand edge is less than 3/4 of the
    way across the display) still do not work properly.
```
SEE ALSO

```c
    [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html) [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html) [intuition.library/MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html)
    [intuition.library/RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html) [intuition.library/RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html)
```
