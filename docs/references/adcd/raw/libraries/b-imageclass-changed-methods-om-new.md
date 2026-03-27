# B / imageclass / Changed Methods: OM_NEW


The instance data for [imageclass](../Libraries_Manual_guide/node04D1.html) contains an [Image](../Libraries_Manual_guide/node01BA.html) structure, and its
[Depth](../Libraries_Manual_guide/node01BA.html#line41) field is initialized to CUSTOMIMAGEDEPTH, which identifies such
images to Intuition.  The Image's [Width](../Libraries_Manual_guide/node01BA.html#line32) and [Height](../Libraries_Manual_guide/node01BA.html#line32) fields default to
arbitrary positive numbers for safety, but an imageclass subclass or an
application should set these attributes to something meaningful.

