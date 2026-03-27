# graphics.library/RemFont



NAME

    RemFont -- Remove a font from the system list.
SYNOPSIS

```c
    RemFont(textFont)
            A1

    void RemFont(struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *);
```
FUNCTION

```c
    This function removes a font from the system, ensuring that
    access to it is restricted to those applications that
    currently have an active pointer to it: i.e. no new [SetFont](../Includes_and_Autodocs_2._guide/node0479.html)
    requests to this font are satisfied.
```
INPUTS

```c
    textFont - the [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) structure to remove.
```
RESULT

BUGS

SEE ALSO

```c
    [SetFont()](../Includes_and_Autodocs_2._guide/node0479.html)  [AddFont()](../Includes_and_Autodocs_2._guide/node0410.html)  [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)
```
