# graphics.library/AddFont



NAME

    AddFont -- add a font to the system list
SYNOPSIS

```c
    AddFont(textFont)
            A1

    void AddFont(struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *);
```
FUNCTION

    This function adds the text font to the system, making it
    available for use by any application.  The font added must be
    in public memory, and remain until successfully removed.
INPUTS

```c
    textFont - a [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) structure in public ram.
```
RESULT

BUGS

SEE ALSO

```c
    [SetFont()](../Includes_and_Autodocs_2._guide/node0479.html)  [RemFont()](../Includes_and_Autodocs_2._guide/node046F.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
