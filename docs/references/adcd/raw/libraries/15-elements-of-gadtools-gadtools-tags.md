# 15 / Elements of GadTools / GadTools Tags


Many of the GadTools functions use [TagItem](../Libraries_Manual_guide/node0497.html) arrays or tag lists to pass
information across the function interface.  These tag-based functions come
in two types, one that takes a pointer to an array of tag items and one
that takes a variable number of tag item arguments directly in the
function call.  In general, the second form, often called the varargs form
because the call takes a variable number of arguments, is provided for
convenience and is internally converted to the first form.  When looking
through the Autodocs or other Amiga reference material, the documentation
for both forms is usually available in the array-based function
description.

All GadTools tags begin with a leading "GT".  In general, they also have a
two-letter mnemonic for the kind of gadget in question.  For example,
slider gadgets recognize tags such as "[GTSL_Level](../Libraries_Manual_guide/node0265.html#line14)".  The GadTools tags are
defined in <libraries/[gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line192)>.  Certain GadTools gadgets also
recognize other Intuition tags such as GA_Disabled and PGA_Freedom, which
can be found in <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line30)>.

For more information on tags and tag-based functions, be sure to see the
"[Utility Library](../Libraries_Manual_guide/node0496.html)" chapter in this manual.

