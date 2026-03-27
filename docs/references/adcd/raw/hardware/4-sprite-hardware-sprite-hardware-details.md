# 4 Sprite Hardware / Sprite Hardware Details


Sprites are produced by the circuitry shown in Figure 4-13. This figure
shows in block form how a pair of  [data words](../Hardware_Manual_guide/node00BC.html)  becomes a set of pixels
displayed on the screen.


```c
     [Figure 4-13: Sprite Control Circuitry](../Hardware_Manual_guide/node02D6.html) 
```
The circuitry elements for sprite display are explained below.

*  Sprite data registers.
   ----------------------
   The registers  [SPRxDATA and SPRxDATB](../Hardware_Manual_guide/node00CF.html)  hold the bit patterns that
   describe one horizontal line of a sprite for each of the eight
   sprites. A line is 16 pixels wide, and each line is defined by two
   words to provide selection of three colors and transparent.

*  Parallel-to-serial converters.
   ------------------------------
   Each of the 16 bits of the sprite data bit pattern is individually
   sent to the color select circuitry at the time that the pixel
   associated with that bit is being displayed on-screen.

   Immediately after the data is transferred from the sprite data
   registers, each parallel-to-serial converter begins shifting the bits
   out of the converter, most significant (leftmost) bit first. The
   shift occurs once during each low resolution pixel time and continues
   until all 16 bits have been transferred to the display circuitry. The
   shifting and data output does not begin again until the next time
   this converter is loaded from the data registers.

   Because the video image is produced by an electron beam that is being
   swept from left to right on the screen, the bit image of the data
   corresponds exactly to the image that actually appears on the screen
   (most significant data on the left).

*  Sprite serial video data.
   -------------------------
   Sprite data goes to the  [priority circuit](../Hardware_Manual_guide/node0159.html) to establish the priority
   between sprites and playfields.

*  Sprite position registers.
   --------------------------
   These registers, called  [SPRxPOS](../Hardware_Manual_guide/node00CD.html) , contain the horizontal position
   value (X value) and vertical position value (Y value) for each of the
   eight sprites.

*  Sprite control registers.
   -------------------------
   These registers, called  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) , contain the stopping position for
   each of the eight sprites and whether or not a sprite is  [attached](../Hardware_Manual_guide/node00C6.html).

*  Beam counter.
   -------------
   The  [beam counter](../Hardware_Manual_guide/node015E.html)  tells the system the current location of the video
   beam that is producing the picture.

*  Comparator.
   -----------
   This device compares the value of the beam counter to the Y value in
   the position register  [SPRxPOS](../Hardware_Manual_guide/node00CD.html) . If the beam has reached the position
   at which the leftmost upper pixel of the sprite is to appear, the
   comparator issues a load signal to the serial-to-parallel converter
   and the sprite display begins.

Figure 4-13 shows the following:

*  Writing to the sprite control registers disables the horizontal
   comparator circuitry. This prevents the system from sending any
   output from the data registers to the serial converter or to the
   screen.

*  Writing to the sprite A data register enables the horizontal
   comparator. This enables output to the screen when the horizontal
   position of the video beam equals the horizontal value in the
   position register.

*  If the comparator is enabled, the sprite data will be sent to the
   display, with the leftmost pixel of the sprite data placed at the
   position defined in the horizontal part of  [SPRxPOS](../Hardware_Manual_guide/node00CD.html) .

*  As long as the comparator remains enabled, the current contents of
   the sprite data register will be output at the selected horizontal
   position on a video line.

*  The data in the sprite data registers does not change. It is either
   rewritten by the user or modified under DMA control.

The components described above produce the automatic DMA display as
follows: When the sprites are in DMA mode, the 18-bit sprite pointer
register (composed of  [SPRxPTH and SPRxPTL](../Hardware_Manual_guide/node00BF.html#line3) ) is used to read the first two
words from the sprite  [data structure](../Hardware_Manual_guide/node00B9.html) . These words contain the starting
and stopping position of the sprite. Next, the pointers write these words
into  [SPRxPOS](../Hardware_Manual_guide/node00CD.html)  and  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) . After this write, the value in the pointers
points to the address of the first  [data word](../Hardware_Manual_guide/node00BC.html)  (low word of data for line
1 of the sprite.)

Writing into the  [SPRxCTL](../Hardware_Manual_guide/node00CE.html)  register disabled the sprite. Now the sprite
DMA channel will wait until the vertical beam counter value is the same as
the data in the VSTART (Y value) part of  [SPRxPOS](../Hardware_Manual_guide/node00CD.html) . When these values
match, the system enables the sprite data access.

The sprite DMA channel examines the contents of VSTOP (from  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) ,
which is the location of the line after the last line of the sprite) and
VSTART (from  [SPRxPOS](../Hardware_Manual_guide/node00CD.html) ) to see how many lines of sprite data are to be
fetched. Two words are fetched per line of sprite height, and these words
are written into the sprite data registers. The first word is stored in
 [SPRxDATA](../Hardware_Manual_guide/node00C8.html#line8)  and the second word in  [SPRxDATB](../Hardware_Manual_guide/node00C8.html#line8) .

The fetch and store for each horizontal scan line occurs during a
horizontal blanking interval, far to the left of the start of the screen
display. This arms the sprite horizontal comparators and allows them to
start the output of the sprite data to the screen when the horizontal beam
count value matches the value stored in the HSTART (X value) part of
 [SPRxPOS](../Hardware_Manual_guide/node00CD.html) .

If the count of VSTOP - VSTART equals zero, no sprite output occurs. The
next data word pair will be fetched, but it will not be stored into the
sprite data registers. It will instead become the next pair of data words
for  [SPRxPOS](../Hardware_Manual_guide/node00CD.html)  and  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) .

When a sprite is used only once within a single display field, the final
pair of data words, which follow the sprite  [color descriptor words](../Hardware_Manual_guide/node00BC.html) , is
loaded automatically as the next contents of the  [SPRxPOS](../Hardware_Manual_guide/node00CD.html)  and  [SPRxCTL](../Hardware_Manual_guide/node00CE.html) 
registers. To stop the sprite after that first data set, the pair of words
should contain all zeros.

Thus, if you have formed a sprite pattern in memory, this same pattern
will be produced as pixels automatically under DMA control one line at a
time.

