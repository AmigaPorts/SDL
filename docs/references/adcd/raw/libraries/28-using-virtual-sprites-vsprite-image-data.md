# 28 / Using Virtual Sprites / VSprite Image Data


The [ImageData](../Includes_and_Autodocs_2._guide/node00C3.html#line109) pointer of the [VSprite](../Libraries_Manual_guide/node0381.html) structure must be initialized with
the address of the first word of the image data array.  The image data
array must be in Chip memory.  It takes two sequential 16-bit words to
define each line of a VSprite.  This means that the data area containing
the VSprite image is always Height x 2 (10 in the example case) words long.

A VSprite image is defined just like a real hardware sprite.  The
combination of bits in corresponding locations in the two data words that
define each line select the color for that pixel.  The first of the pair
of words supplies the low-order bit of the color selector for that pixel;
the second word supplies the high-order bit.

These binary values select colors as follows:


    00 - selects "transparent"
    01 - selects the first of three VSprite colors
    10 - selects the second VSprite color
    11 - selects the third VSprite color
In those areas where the combination of bits yields a value of 0, the
VSprite is transparent.  This means that the playfield, and all Bobs and
AnimComps, and any VSprite whose priority is lower than this VSprite will
all show through in transparent sections.  For example:


```c
    (&VSprite->ImageData)           1010 0000 0000 0000
    (&VSprite->ImageData + 1)       0110 0000 0000 0000
```
Reading from top to bottom, left to right, the combinations of these two
sequential data words form the binary values of 01, 10, 11, and then all
00s.  This VSprite's first pixel will be color 1, the next color 2, the
third color 3. The rest will be transparent, making this VSprite appear to
be three pixels wide. Thus, a three-color image, with some transparent
areas, can be formed from a data set like the following sample:




    Address        Binary Data        VSprite Image Data
    -------        -----------        ------------------
    mem        1111 1111 1111 1111    Defines top line
    mem + 1    1111 1111 1111 1111    3333 3333 3333 3333

    mem + 2    0011 1100 0011 1100    Defines second line
    mem + 3    0011 0000 0000 1100    0033 1100 0011 3300

    mem + 4    0000 1100 0011 0000    Defines third line
    mem + 5    0000 1111 1111 0000    0000 3322 2233 0000

    mem + 6    0000 0010 0100 0000    Defines fourth line
    mem + 7    0000 0011 1100 0000    0000 0032 2300 0000

    mem + 8    0000 0001 1000 0000    Defines fifth line
    mem + 9    0000 0001 1000 0000    0000 0003 3000 0000
The [VSprite.Height](../Libraries_Manual_guide/node0385.html) for this sample image is 5.

