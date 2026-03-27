# intuition.library/ViewAddress



NAME

```c
    ViewAddress -- Return the address of the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure.
```
SYNOPSIS

```c
    view = ViewAddress()
    D0

    struct [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) *ViewAddress( VOID );
```
FUNCTION

```c
    Returns the address of the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure.  If you
    want to use any of the graphics, text, or animation primitives
    in your window and that primitive requires a pointer to a view,
    this routine will return the address of the view for you.
```
INPUTS

    None
RESULT

```c
    Returns the address of the Intuition [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure
```
BUGS

SEE ALSO

    graphics.library
