# 3 / Custom Screen Functions / Creating A New Custom Screen


There are three functions you can use to open a [custom screen](../Libraries_Manual_guide/node00DF.html):
[OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6), [OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6) or [OpenScreenTagList()](../Libraries_Manual_guide/node00DF.html#line6).  Prior to Release 2
(V36), OpenScreen() was used to create a new screen.  With V36 and later
versions of the operating system, this call is superseded by
OpenScreenTagList() and OpenScreenTags().

   struct Screen *OpenScreen( struct NewScreen *)
   struct Screen *OpenScreenTagList( struct NewScreen * , struct TagItem *)
   struct Screen *OpenScreenTags( struct NewScreen *, ULONG, ULONG, ... )

The old [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) call relied on a fixed size data structure
([NewScreen](../Libraries_Manual_guide/node00DE.html#line6)) which made little allowance for extensions and growth.  The
new calls are tag based, allowing for the addition of new features without
modification of existing structures and applications.  The
"[Screen Attributes](../Libraries_Manual_guide/node00E5.html)" section below contains a complete list of all the tag
options available for setting up an Intuition screen.  For a general
description of tag items, see the "[Utility Library](../Libraries_Manual_guide/node0496.html)" chapter.

 [A Custom Screen Example](../Libraries_Manual_guide/node00E1.html) 
 [Creating A Custom Screen that Works With Older Systems](../Libraries_Manual_guide/node00E2.html) 
 [Return Values from OpenScreenTagList()](../Libraries_Manual_guide/node00E3.html) 
 [Closing the Screen](../Libraries_Manual_guide/node00E4.html) 

