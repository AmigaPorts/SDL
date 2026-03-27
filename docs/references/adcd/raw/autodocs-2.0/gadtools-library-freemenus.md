# gadtools.library/FreeMenus



NAME

```c
    FreeMenus -- Frees memory allocated by [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html). (V36)
```
SYNOPSIS

```c
    FreeMenus(menu)
              A0

    VOID FreeMenus(struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *);
```
FUNCTION

```c
    Frees the menus allocated by [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html).  It is safe to
    call this function with a NULL parameter.
```
INPUTS

```c
    menu - Pointer to menu structure (or first MenuItem) obtained
    from [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html).
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html)
```
