# 28 / / Bob Priorities / Letting the System Decide Priorities


The priority issue can be ignored and the system will render the Bobs as
it finds them in the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list.  To do this, set the Bob's [Before](../Libraries_Manual_guide/node03A4.html) and
[After](../Libraries_Manual_guide/node03A4.html) pointers to NULL.  Since the GelsInfo list is sorted by GEL x, y
values, Bobs that are higher on the display will appear behind the lower
ones, and Bobs that are more to the left on the display will appear behind
Bobs on the right.

As Bobs are moved about the display, their priorities will change.

