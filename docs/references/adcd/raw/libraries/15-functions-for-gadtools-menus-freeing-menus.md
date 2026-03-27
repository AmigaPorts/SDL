# 15 / / Functions for GadTools Menus / Freeing Menus


The [FreeMenus()](../Includes_and_Autodocs_2._guide/node03EC.html) function frees all the memory allocated by the
corresponding call to [CreateMenus()](../Libraries_Manual_guide/node0251.html).


```c
    void FreeMenus( struct Menu *menu );
```
Its one argument is the [Menu](../Libraries_Manual_guide/node0199.html) or [MenuItem](../Libraries_Manual_guide/node019A.html) pointer that was returned by
[CreateMenus()](../Libraries_Manual_guide/node0251.html).  It is safe to call [FreeMenus()](../Includes_and_Autodocs_2._guide/node03EC.html) with a NULL parameter,  the
function will then return immediately.

