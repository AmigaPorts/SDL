---
title: FTXT IFF Formatted / Appendix A: Character Code Table
manual: devices
chapter: devices
section: ftxt-iff-formatted-appendix-a-character-code-table
functions: []
libraries: []
---

# FTXT IFF Formatted / Appendix A: Character Code Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This table corresponds to the ISO/DIS 6429.2 and ANSI X3.64-1979 8-bit
character set standards.  Only the core character set of those standards
is used in [FTXT](devices/ftxt-iff-formatted-text-introduction.md).

Two G1 characters aren't defined in the standards and are shown as dark
gray entries in this table.  Light gray shading denotes control
characters.  (DEL is a control character although it belongs to the
graphic group G0.)


```c
           ISO/DIS 6429.2 and ANSI X3.64-1979 Character Code Table
           -------------------------------------------------------

        MSN (most significant nybble)
        0  1    2   3   4   5   6   7     8   9     A    B   C   D   E   F
     +--------+-------------------------+---------+------------------------
```
LSN 0| NUL   | SP   0   @   P   `   p  |     DCS |NBSP   °   À   Ð   à   ð

```c
    1|       |  !   1   A   Q   a   q  |         |  ¡    ±   Á   Ñ   á   ñ
    2|       |  "   2   B   R   b   r  |         |  ¢    ²   Â   Ò   â   ò
    3|       |  #   3   C   S   c   s  |         |  £    ³   Ã   Ó   ã   ó
    4|       |  $   4   D   T   d   t  |         |  ¤        Ä   Ô   ä   ô
    5|       |  %   5   E   U   e   u  |         |  ¥    µ   Å   Õ   å   õ
    6|       |  &   6   F   V   f   v  |         |  ¦    ¶   Æ   Ö   æ   ö
    7|       |  '   7   G   W   g   w  |         |  §    ·   Ç   ×   ç   ÷
    8|       |  (   8   H   X   h   x  |         | uml   ¸   È   Ø   è   ø
    9|       |  )   9   I   Y   i   y  |         | (c)   ¹   É   Ù   é   ù
    A| LF    |  *   :   J   Z   j   z  |         |       º   Ê   Ú   ê   ú
    B|    ESC|  +   ;   K   [   k   {  |     CSI |  «    »   Ë   Û   ë   û
    C|       |  ,   <   L   \   l   |  |     ST  |  ¬    ¼   Ì   Ü   ì   ü
    D| CR    |  -   =   M   ]   m   }  |     OSC | SHY   ½   Í   Ý   í   ý
    E|       |  .   >   N   ^   n   ~  | SS2 PM  |  ®    ¾   Î   Þ   î   þ
    F|       |  /   ?   O   _   o  DEL | SS3 APC |  ­    ¿   Ï   ß   ï   ÿ
      \__ __/ \___________ ___________/ \___ ___/ \___________ ___________/
         V                 V                 V                 V
       Control       Graphic Group        Control        Graphic Group
       Group C0            G0             Group C1            G1
```
NBSP is non-breaking space
SHY is soft hyphen

