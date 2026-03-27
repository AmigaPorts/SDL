# intuition.library/EraseImage



NAME

```c
    EraseImage -- Erases an [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621). (V36)
```
SYNOPSIS

```c
    EraseImage( RPort, [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621), LeftOffset, TopOffset )
                A0     A1     D0          D1

    VOID EraseImage( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) *, WORD, WORD );
```
FUNCTION

```c
    Erases an [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621).  For a normal [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structure, this will
    call the graphics function [EraseRect()](../Includes_and_Autodocs_2._guide/node0439.html) (clear using layer
    backfill, if any) for the [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) box (LeftEdge/TopEdge/Width/Height).

    For custom image, the exact behavior is determined by the
    custom image class.
```
INPUTS

```c
    RPort   - [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to erase a part of
    [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621)   - custom or standard image
    LeftOffset,RightOffset - pixel offsets of [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) position
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [graphics.library/EraseRect()](../Includes_and_Autodocs_2._guide/node0439.html).
```
