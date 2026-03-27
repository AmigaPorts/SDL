# 6 Blitter Hardware / Blitter Key Points


This is a list of some key points that should be remembered when
programming the blitter.

*  Write  [BLTSIZE](../Hardware_Manual_guide/node011B.html#line82)  last; writing this register starts the blit.

*  Modulos and pointers are in bytes; width is in words and height is in
   pixels.  The least significant bit of all pointers and modulos is
   ignored.

*  The order of operations in the blitter is  [masking](../Hardware_Manual_guide/node011F.html#line42) ,  [shifting](../Hardware_Manual_guide/node011F.html) , logical
   combination of sources,  [area fill](../Hardware_Manual_guide/node0122.html) , and  [zero flag](../Hardware_Manual_guide/node0126.html)  setting.

*  In ascending mode, the blitter increments the pointers, adds the
   modulos, and  [shifts](../Hardware_Manual_guide/node011F.html)  to the right.

*  In  [descending mode](../Hardware_Manual_guide/node0120.html) , the blitter decrements the pointers, subtracts
   the modulos, and shifts to the left.

*   [Area fill](../Hardware_Manual_guide/node0122.html)  only works correctly in  [descending mode](../Hardware_Manual_guide/node0120.html) .

*  Check  [BLTDONE](../Hardware_Manual_guide/node0123.html)  before writing blitter registers or using the results
   of a blit.

*   [Shifts](../Hardware_Manual_guide/node011F.html)  are done on immediate data as soon as it is loaded.


```c
    [ECS blitter](../Hardware_Manual_guide/node00AA.html) .
```
   -------------
   For information relating to the blitter hardware in the Enhanced Chip
   Set, see  [Appendix C](../Hardware_Manual_guide/node0099.html) .


 [Example:  Clearmem](../Hardware_Manual_guide/node02DE.html) 
 [Example:  Simpleline](../Hardware_Manual_guide/node02DF.html) 
 [Example:  Rotatebits](../Hardware_Manual_guide/node02E0.html) 

