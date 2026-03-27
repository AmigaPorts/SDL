# 3 / / / Creating A Custom Screen that Works With Older Systems


Here's an example of how to use the old [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) call with an
[ExtNewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure to make a new, [custom screen](../Libraries_Manual_guide/node00DF.html) under any version of
the Amiga operating system.  If the version is V36 or later, additional
Release 2 features specified via tags, in this case the new 3D look of
Intuition, will be incorporated in the window.


```c
     [screen34to37.c](../Libraries_Manual_guide/node05D1.html) 
```
As you can see from the examples above, there are many ways to create a
new, [custom screen](../Libraries_Manual_guide/node00DF.html).  Further references to "[OpenScreenTagList()](../Libraries_Manual_guide/node00DF.html#line6)" in this
manual are referring to any one of the three calls: OpenScreenTagList(),
[OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6), or [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) used with tags in an [ExtNewScreen](../Libraries_Manual_guide/node00DE.html#line6) as
shown above.

