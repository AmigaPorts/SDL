# 3 / / Creating A New Custom Screen / A Custom Screen Example


There are so many tag options available with screens it can be a bit
overwhelming.  Before discussing more details, it may be helpful to look
at a simple example.  The code below opens a new, [custom screen](../Libraries_Manual_guide/node00DF.html) using the
[OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6) call.  The example uses just two tag items ([SA_Depth](../Libraries_Manual_guide/node00E5.html#line65) and
[SA_Pens](../Libraries_Manual_guide/node00E5.html#line82)) which provide the minimum attributes needed to make a screen that
uses the new 3D look of Intuition available in Release 2.  (See the
section on "[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EB.html)" below for more information.)


```c
     [newlookscreen.c](../Libraries_Manual_guide/node05D0.html) 
```
The example above runs only under Release 2 (V36) and later versions of
the OS.  To make a [custom screen](../Libraries_Manual_guide/node00DF.html) that [works under both](../Libraries_Manual_guide/node00E2.html) Release 2 and
earlier versions of the operating system, use the original [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6)
function.

The [NewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure used with [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) has been extended with a
tag list in V36 to form an [ExtNewScreen](../Libraries_Manual_guide/node00DE.html#line6).  This is done by setting the
NS_EXTENDED bit in the Type field of the NewScreen structure and adding a
pointer to an array of tags to the end of the structure.  The NS_EXTENDED
bit is ignored in older versions of the operating system, so the tags can
be transparently added to existing applications and the features will
appear when executed in a system running V36 or greater.  See the
[OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html) Autodocs and the include file <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html)> for more
information on NS_EXTENDED and the ExtNewScreen structure.

