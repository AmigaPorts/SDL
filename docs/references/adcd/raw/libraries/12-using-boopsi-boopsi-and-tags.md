# 12 / / Using Boopsi / Boopsi and Tags


Boopsi uses tag lists to pass and manipulate its attributes.  To Boopsi,
each [TagItem](../Libraries_Manual_guide/node0497.html) (defined in <utility/[tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html#line21)>) in a tag list is an
attribute/value pair.  The TagItem.ti_Tag field contains an ID for the
attribute and the ti_Data field holds the attribute's value.

For example, the string gadget class defines an attribute called
[STRINGA_LongVal](../Libraries_Manual_guide/node0512.html), which is the current integer value of the gadget. Certain
[gadgetclass](../Libraries_Manual_guide/node020A.html) objects have an attribute called GA_Image.  Its value is not
an integer, it is a pointer to an image.

Note that these tag lists can also contain utility.library Global System
control tags (like [TAG_SKIP](../Libraries_Manual_guide/node0498.html#line8) and [TAG_DONE](../Libraries_Manual_guide/node0498.html#line8)), which Boopsi uses in processing
its tag lists.  Any application that ends up processing these lists should
do so using the tag manipulation functions from utility.library.  For more
information on tags and utility.library, see the "[Utility Library](../Libraries_Manual_guide/node0495.html)" chapter
of this manual.

