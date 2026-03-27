# 3 / / Coding For Correct Coloring / A One- or Two-Color Playfield


For a one-color playfield, all you need do is write "0"s in all the bits
of the single bitplane as shown in the example below. This code fills a
low resolution bitplane with the background color ( [COLOR00](../Hardware_Manual_guide/node0067.html#line26) ) by writing
all "0"s into its memory area. The bitplane starts at $21000 and is 8,000
bytes long.

```c
        LEA     $21000,a0       ; Point at bitplane
        MOVE.W  #2000,d0        ; Write 2000 longwords = 8000 bytes
```
LOOP:   MOVE.L  #0,(a0)+        ; Write out a zero

```c
        DBRA    d0,LOOP         ; Decrement counter and loop until done...
```
For a two-color playfield, you define a bitplane that has "0"s where you
want the background color and "1"s where you want the color in register 1.
The following example code is identical to the last example, except the
bitplane is filled with $FF00FF00 instead of all 0's. This will produce
two colors.

```c
        LEA     $21000,a0        ; Point at bitplane
        MOVE.W  #2000,d0         ; Write 2000 longwords = 8000 bytes
```
LOOP:   MOVE.L  #$FF00FF00,(a0)+ ; Write out $FF00FF00

```c
        DBRA    d0,LOOP        	; Decrement counter and loop until done...
```
