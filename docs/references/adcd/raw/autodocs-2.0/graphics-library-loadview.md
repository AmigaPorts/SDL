# graphics.library/LoadView



NAME

```c
    LoadView -- Use a (possibly freshly created) coprocessor instruction
               list to create the current display.
```
SYNOPSIS

```c
    LoadView( [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) )
              A1

    void LoadView( struct [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) * );
```
FUNCTION

```c
    Install a new view to be displayed during the next display
    refresh pass.
    Coprocessor instruction list has been created by
    [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html), [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html), and [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html).
```
INPUTS

```c
    [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) - a pointer to the [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure which contains the
    pointer to the constructed coprocessor instructions list, or NULL.
```
RESULT

```c
    If the [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) pointer is non-NULL, the new [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) is displayed,
    according to your instructions.  The vertical blank routine
    will pick this pointer up and direct the copper to start
    displaying this [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57).

    If the [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) pointer is NULL, no [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) is displayed.
```
NOTE

```c
    Even though a LoadView(NULL) is performed, display DMA will still be
    active.  Sprites will continue to be displayed after a LoadView(NULL)
    unless an OFF_SPRITE is subsequently performed.
```
BUGS

SEE ALSO

```c
    [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html) [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html) [intuition/RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html)
    [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
