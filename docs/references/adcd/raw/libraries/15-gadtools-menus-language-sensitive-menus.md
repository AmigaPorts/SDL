# 15 / GadTools Menus / Language-Sensitive Menus


Allowing the application to switch the language displayed in the menus,
can be done quite easily.  Simply detach the menu strip and replace the
strings in the [IntuiText](../Libraries_Manual_guide/node01C7.html) structures as described above.  It may be
convenient to store some kind of index number in the [Menu](../Libraries_Manual_guide/node0199.html) and [MenuItem](../Libraries_Manual_guide/node019A.html)
[UserData](../Libraries_Manual_guide/node024F.html#line118) which can be used to retrieve the appropriate string for the
desired language.  After all the strings have been installed, call
[LayoutMenus()](../Libraries_Manual_guide/node0252.html) and [SetMenuStrip()](../Libraries_Manual_guide/node0181.html).

If the application has the localized strings when the menus are being
created, it simply places the pointers to the strings and command
shortcuts into the appropriate fields of the [NewMenu](../Libraries_Manual_guide/node024F.html) structure.  The menus
may then be processed in the normal way.

