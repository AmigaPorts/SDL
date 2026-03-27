# gadtools.library/DrawBevelBoxA



NAME

```c
    DrawBevelBoxA -- Draws a bevelled box. (V36)
    DrawBevelBox -- Varargs stub for DrawBevelBox(). (V36)
```
SYNOPSIS

```c
    DrawBevelBoxA(rport, left, top, width, height, taglist)
                  A0     D0    D1   D2     D3      A1

    VOID DrawBevelBoxA(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, WORD, WORD,
        struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *taglist);

    DrawBevelBox(rport, left, top, width, height, firsttag, ...)

    VOID DrawBevelBox(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, WORD, WORD,
        Tag, ...);
```
FUNCTION

```c
    DrawBevelBoxA() renders a bevelled box of specified dimensions
    into the supplied [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
INPUTS

```c
    rport - The [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) into which the box is to be drawn.
    left - The left edge of the box.
    top - The top edge of the box.
    width - The width of the box.
    height - The height of the box.
    taglist - Pointer to a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list.
```
TAGS

```c
    GTBB_Recessed (BOOL):  Set to anything for a recessed-looking box.
        If absent, the box defaults, it would be raised.
    GT_VisualInfo (APTR):  You MUST supply the value you obtained
        from an earlier call to [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).
```
RESULT

    None.
EXAMPLE

NOTES

```c
    DrawBevelBox() is a rendering operation, not a gadget.  That
    means you must refresh it at the appropriate time, like any
    other rendering operation.
```
BUGS

SEE ALSO

```c
    [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html)
```
