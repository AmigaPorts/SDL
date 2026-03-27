# graphics.library/AskSoftStyle



NAME

    AskSoftStyle -- Get the soft style bits of the current font.
SYNOPSIS

```c
    enable = AskSoftStyle(rp)
    D0                    A1

    ULONG AskSoftStyle(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    This function returns those style bits of the current font
    that are not intrinsic in the font itself, but
    algorithmically generated.  These are the bits that are
    valid to set in the enable mask for [SetSoftStyle()](../Includes_and_Autodocs_2._guide/node047E.html).
```
INPUTS

```c
    rp - the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) from which the font and style    are extracted.
```
RESULTS

    enable - those bits in the style algorithmically generated.
             Style bits that are not defined are also set.
BUGS

SEE ALSO

```c
    [SetSoftStyle()](../Includes_and_Autodocs_2._guide/node047E.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
