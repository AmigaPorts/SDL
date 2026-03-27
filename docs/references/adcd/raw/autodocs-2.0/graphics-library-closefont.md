# graphics.library/CloseFont



NAME

    CloseFont -- Release a pointer to a system font.
SYNOPSIS

```c
    CloseFont(font)
              A1

    void CloseFont(struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *);
```
FUNCTION

```c
    This function indicates that the font specified is no longer
    in use.  It is used to close a font opened by [OpenFont](../Includes_and_Autodocs_2._guide/node0462.html), so
    that fonts that are no longer in use do not consume system
    resources.
```
INPUTS

```c
    font -  a font pointer as returned by [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html) or [OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html)
```
RESULT

BUGS

SEE ALSO

```c
    [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)  [diskfont.library/OpenDiskFont](../Includes_and_Autodocs_2._guide/node01F7.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
