# intuition.library/OffMenu



NAME

    OffMenu -- Disable the given menu or menu item.
SYNOPSIS

```c
    OffMenu( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), MenuNumber )
             A0      D0

    VOID OffMenu( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, UWORD );
```
FUNCTION

    This command disables a sub-item, an item, or a whole menu.
    This depends on the contents of the data packed into MenuNumber,
    which is described in the Intuition Reference Manual.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window
    MenuNumber = the menu piece to be disabled
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OnMenu()](../Includes_and_Autodocs_2._guide/node0236.html), [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html)
```
