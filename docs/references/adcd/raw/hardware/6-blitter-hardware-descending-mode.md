# 6 Blitter Hardware / Descending Mode


Our standard memory copy blit works fine if the source does not overlap
the destination.  If we want to move an image one row down (towards
increasing addresses), however, we run into a problem -- we overwrite the
second row before we get a chance to copy it!  The blitter has a special
mode of operation -- descending mode -- that solves this problem nicely.

Descending mode is turned on by setting bit one of  [BLTCON1](../Hardware_Manual_guide/node001A.html)  (defined as
BLITREVERSE). If you use descending mode the address pointers will be
decremented by two (bytes) instead of incremented by two for each word
fetched.  In addition, the modulo values will be subtracted rather than
added.   [Shifts](../Hardware_Manual_guide/node011F.html)  are then towards the left, rather than the right, the
first word  [mask](../Hardware_Manual_guide/node011F.html#line42)  masks the last word in a row (which is still the first
word fetched), and the last word  [mask](../Hardware_Manual_guide/node011F.html#line42)  masks the first word in a row.

Thus, for a standard memory copy, the only difference in blitter setup
(assuming no  [shifting](../Hardware_Manual_guide/node011F.html)  or  [masking](../Hardware_Manual_guide/node011F.html#line42) ) is to initialize the
 [address pointer registers](../Hardware_Manual_guide/node011B.html#line6)  to point to the last word in a block, rather
than the first word.  The  [modulo values](../Hardware_Manual_guide/node011B.html#line102) ,  [blit size](../Hardware_Manual_guide/node011B.html#line82) , and all other
parameters should be set the same.

   NOTE:
   -----
   This differs from predecrement versus postincrement in the 680x0,
   where an address register would be initialized to point to the word
   after the last, rather than the last word.

Descending mode is also necessary for  [area filling](../Hardware_Manual_guide/node0122.html) , which will be
covered in a later section.

