# graphics.library/RemBob



NAME

```c
    RemBob -- Macro to remove a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) from the gel list.
```
SYNOPSIS

```c
    RemBob(bob)

    RemBob(struct [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) *);
```
FUNCTION

```c
    Marks a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) as no-longer-required.  The gels internal code then
    removes the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) from the list of active gels the next time
    [DrawGList](../Includes_and_Autodocs_2._guide/node0438.html) is executed. This is implemented as a macro.
    If the user is double-buffering the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140), it could take two
    calls to [DrawGList](../Includes_and_Autodocs_2._guide/node0438.html) before the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) actually disappears from
    the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
INPUTS

```c
    [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) = pointer to the [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) to be removed
```
RESULT

BUGS

SEE ALSO

```c
    [RemIBob()](../Includes_and_Autodocs_2._guide/node0470.html)  [DrawGList()](../Includes_and_Autodocs_2._guide/node0438.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)  [graphics/gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html)
```
