# graphics.library/DrawGList



NAME

```c
    DrawGList -- [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) the gel list, queueing VSprites, drawing Bobs.
```
SYNOPSIS

```c
    DrawGList(rp, vp)
              A1  A0

    void DrawGList(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *);
```
FUNCTION

```c
    Performs one pass of the current gel list.
       - If nextLine and lastColor are defined, these are
         initialized for each gel.
      - If it's a [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73), build it into the copper list.
      - If it's a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140), draw it into the current raster.
      - Copy the save values into the "old" variables,
         double-buffering if required.
```
INPUTS

```c
    rp = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) where Bobs will be drawn
    vp = pointer to the [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) for which VSprites will be created
```
RESULT

BUGS

    MUSTDRAW isn't implemented yet.
SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)  [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
