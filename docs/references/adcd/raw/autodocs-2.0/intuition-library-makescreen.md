# intuition.library/MakeScreen



NAME

```c
    MakeScreen -- Do an Intuition-integrated [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) of a screen.
```
SYNOPSIS

```c
    MakeScreen( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) )
                A0

    VOID MakeScreen( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) * );
```
FUNCTION

```c
    This procedure allows you to do a [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) for the viewport of your
    custom screen in an Intuition-integrated way.  This way you can
    do your own screen manipulations without worrying about interference
    with Intuition's usage of the same viewport.

    The operation of this function is as follows:
        - Block until the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure is not in being changed.
        - Set the view modes correctly to reflect if there is a (visible)
          interlaced screen.
        - call [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html), passing the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) and your screen's
          [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40).
        - Unlocks the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57).

    After calling this routine, you should call [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html) to
    incorporate the new viewport of your custom screen into the
    Intuition display.

    NOTE: Intuition may determine that because of a change in global
    interlace needs that all viewports need to be remade, so
    it may effectively call [RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html).
```
INPUTS

```c
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = address of the custom screen structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html), [RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html), [graphics.library/MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html)
```
