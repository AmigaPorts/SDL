# 6 / Line Mode / Register Summary for Line Mode


Preliminary setup:

   The line goes from (x1,y1) to (x2,y2).

   dx = max(abs(x2 - x1), abs(y2 - y1)) ;
   dy = min(abs(x2 - x1), abs(y2 - y1)) ;

Register setup:

   [BLTADAT](../Hardware_Manual_guide/node011B.html#line31)  = $8000
   [BLTBDAT](../Hardware_Manual_guide/node011B.html#line31)  = line texture pattern ($FFFF for a solid line)

   [BLTAFWM](../Hardware_Manual_guide/node011F.html#line49)  = $FFFF
   [BLTALWM](../Hardware_Manual_guide/node011F.html#line49)  = $FFFF

   [BLTAMOD](../Hardware_Manual_guide/node011B.html#line102)  = 4 * (dy - dx)
   [BLTBMOD](../Hardware_Manual_guide/node011B.html#line102)  = 4 * dy
   [BLTCMOD](../Hardware_Manual_guide/node011B.html#line102)  = width of the bitplane in bytes
   [BLTDMOD](../Hardware_Manual_guide/node011B.html#line102)  = width of the bitplane in bytes

   [BLTAPT](../Hardware_Manual_guide/node011B.html#line6)   = (4 * dy) - (2 * dx)
   [BLTBPT](../Hardware_Manual_guide/node011B.html#line6)   = unused
   [BLTCPT](../Hardware_Manual_guide/node011B.html#line6)   = word containing the first pixel of the line
   [BLTDPT](../Hardware_Manual_guide/node011B.html#line6)   = word containing the first pixel of the line

   [BLTCON0](../Hardware_Manual_guide/node001A.html)  bits 15-12 = x1 modulo 15
   [BLTCON0](../Hardware_Manual_guide/node001A.html)  bits SRCA, SRCC, and SRCD = 1
   [BLTCON0](../Hardware_Manual_guide/node001A.html)  bit  SRCB = 0

```c
            If exclusive-or line mode:                  _   _
                     then BLTCON0  [LF control byte](../Hardware_Manual_guide/node011C.html#line37)  = ABC + AC
                                                           _
                     else BLTCON0  [LF control byte](../Hardware_Manual_guide/node011C.html#line37)  = AB + AC
```
   [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [LINEMODE](../Hardware_Manual_guide/node0128.html)  = 1
   [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [OVFLAG](../Hardware_Manual_guide/node0128.html#line114)  = 0
   [BLTCON1](../Hardware_Manual_guide/node001A.html)  bits 4-2 =  [octant number](../Hardware_Manual_guide/node0128.html#line13)  from table
   [BLTCON1](../Hardware_Manual_guide/node001A.html)  bits 15-12 = start bit for line texture (0 = last significant

```c
            If (((4 * dy) - (2 * dx)) < 0):                bit)
                     then  [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [SIGNFLAG](../Hardware_Manual_guide/node0128.html#line96)  = 1
                     else  [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [SIGNFLAG](../Hardware_Manual_guide/node0128.html#line96)  = 0
            If one pixel/row:
                     then  [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [ONEDOT](../Hardware_Manual_guide/node0128.html#line114)  = 1
                     else  [BLTCON1](../Hardware_Manual_guide/node001A.html)  bit  [ONEDOT](../Hardware_Manual_guide/node0128.html#line114)  = 0
```
   [BLTSIZE](../Hardware_Manual_guide/node011B.html#line82)  bits 15-6 = dx + 1
   [BLTSIZE](../Hardware_Manual_guide/node011B.html#line82)  bits  5-0 = 2

   Warning:
   --------
   You must set the  [BLTSIZE](../Hardware_Manual_guide/node011B.html#line82)  register last as it starts the blit.

