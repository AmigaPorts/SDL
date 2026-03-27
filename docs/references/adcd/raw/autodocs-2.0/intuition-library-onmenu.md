# intuition.library/OnMenu



NAME

    OnMenu -- Enable the given menu or menu item.
SYNOPSIS

```c
    OnMenu( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), MenuNumber )
            A0      D0

    VOID OnMenu( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, UWORD );
```
FUNCTION

    This command enables a sub-item, an item, or a whole menu.
    This depends on the contents of the data packed into MenuNumber,
    which is described in the Intuition Reference Manual.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window
    MenuNumber = the menu piece to be enables
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OffMenu()](../Includes_and_Autodocs_2._guide/node0234.html), [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html)
```
