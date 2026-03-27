# 15 / / Functions for GadTools Menus / Creating Menus


The [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) function takes an array of [NewMenu](../Libraries_Manual_guide/node024F.html)s and creates a set of
initialized and linked Intuition [Menu](../Libraries_Manual_guide/node0199.html), [MenuItem](../Libraries_Manual_guide/node019A.html), [Image](../Libraries_Manual_guide/node01BA.html) and [IntuiText](../Libraries_Manual_guide/node01C7.html)
structures, that need only to be formatted before being used.  Like the
other tag-based functions, there is a [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html) call that takes a
pointer to an array of [TagItem](../Libraries_Manual_guide/node0497.html)s and a CreateMenus() version that expects
to find its tags on the stack.


```c
    struct Menu *CreateMenusA( struct NewMenu *newmenu,
                               struct TagItem *taglist );
    struct Menu *CreateMenus( struct NewMenu *newmenu, Tag tag1, ... );
```
The first argument to these functions, newmenu, is a pointer to an array
of [NewMenu](../Libraries_Manual_guide/node024F.html) structures as described earlier.  The tag arguments can be any
of the following items:

GTMN_FrontPen (ULONG)

    The pen number to use for menu text and separator bars.  The default
    is zero.
GTMN_FullMenu (BOOL)

```c
    (New for V37, ignored under V36).  This tag instructs [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html)
    to fail if the supplied [NewMenu](../Libraries_Manual_guide/node024F.html) structure does not describe a
    complete [Menu](../Libraries_Manual_guide/node0199.html) structure.  This is useful if the application does not
    have direct control over the NewMenu description, for example if it
    has user-configurable menus.  The default is FALSE.
```
GTMN_SecondaryError (ULONG *)

```c
    (New for V37, ignored under V36).  This tag allows [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) to
    return some secondary error codes.  Supply a pointer to a
    NULL-initialized ULONG, which will receive an appropriate error code
    as follows:

    GTMENU_INVALID
        Invalid menu specification.  For instance, a sub-item directly
        following a menu-title or an incomplete menu.  [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html)
        failed in this case, returning NULL.

    GTMENU_NOMEM
        Failed for lack of memory.  [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) returned NULL.

    GTMENU_TRIMMED
        The number of menus, items or sub-items exceeded the maximum
        number allowed so the menu was trimmed.  In this case,
        [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) does not fail but returns a pointer to the trimmed
        [Menu](../Libraries_Manual_guide/node0199.html) structure.

    NULL
        If no error was detected.
```
[CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) returns a pointer to the first [Menu](../Libraries_Manual_guide/node0199.html) structure created, while
all the [MenuItem](../Libraries_Manual_guide/node019A.html) structures and any other Menu structures are attached
through the appropriate pointers.  If the [NewMenu](../Libraries_Manual_guide/node024F.html) structure begins with an
entry of type [NM_ITEM](../Libraries_Manual_guide/node024F.html#line22) or [IM_ITEM](../Libraries_Manual_guide/node024F.html#line22), then CreateMenus() will return a pointer
to the first MenuItem created, since there will be no first Menu
structure.  If the creation fails, usually due to a lack of memory,
CreateMenus() will return NULL.

Starting with V37, GadTools will not create any menus, menu items or
sub-items in excess of the maximum number allowed by Intuition.  Up to 31
menus may be defined, each menu with up to 63 items, each item with up to
31 sub-items.  See the "[Intuition Menus](../Libraries_Manual_guide/node017E.html)" chapter for more information on
menus and their limitations.  If the [NewMenu](../Libraries_Manual_guide/node024F.html) array describes a menu that
is too big, [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) will return a trimmed version.
GTMN_SecondaryError can be used to learn when this happens.

Menus need to be added to the window with Intuition's [SetMenuStrip()](../Libraries_Manual_guide/node0181.html)
function.  Before doing this, they must be formatted with a call to
[LayoutMenus()](../Libraries_Manual_guide/node0252.html).

