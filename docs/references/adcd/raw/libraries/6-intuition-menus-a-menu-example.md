# 6 Intuition Menus / A Menu Example


This example shows how to implement menus.  The menu code is simply part
of the processing for Intuition messages as shown in the [IDCMP example](../Libraries_Manual_guide/node058A.html) in
the "Intuition Input and Output Methods" chapter.  The example implements
extended selection for menus, adaptation to fonts of different sizes,
mutual exclusion and checkmarks.

If possible, applications should use the menu layout routines available in
the GadTools library, rather than doing the job themselves as this example
does.  See the "[GadTools Library](../Libraries_Manual_guide/node024E.html)" chapter for more information.


```c
     [menulayout.c](../Libraries_Manual_guide/node05AF.html) 
```
