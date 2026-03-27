# Sprites

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 11.7.6 Sprites

Sprites are small graphic elements that can be used completely 

independently of the playfields. Each sprite is 16 pixels wide and can have a  maximum height of the entire screen window. It can be displayed anywhere on the screen.

Normally a  sprite is in front of the playfield(s) and its pixels hide the 

graphic behind it. The mouse pointer, for example, is implemented as a sprite. Up to eight sprites are possible on the Amiga. A  sprite normally has three colors, but two sprites can be combined into one to give a fifteen-color sprite.

Construction of the sprites 

Color selection 

The color selection for sprites is very similar to that of a  dual-playfield screen. A  sprite has a  width of 16 pixels, which are represented by two data words. The words act like "mini bit-planes," since the color of a  pixel is formed by combining corresponding bits of both the words. The color of the first (leftmost) pixel of the sprite is selected by the high- value bits (bit 15) of the two words. The two low-value bits (bit 0) determine the color of the last pixel. Each pixel is represented by two bits, which means it can have one of four different colors. The color table is used to determine the actual color from this value. There are no special color registers for the sprites. The sprite colors are obtained from the latter half of the table, color registers 16-31. This means that sprite and playfield colors do not come into conflict unless playfields with more than 16 colors are created. The following table shows the assignment of color registers and sprites:

Sprite no. 

Sprite data 

Color register 

0&1 

transparent

COLOR17 

COLOR18 

1 1 

COLOR 19 

2&3 

transparent

COLOR21 

COLOR22 

1 1 

COLOR23 

4&5 

transparent

COLOR25 

COLOR26 

1 1 

COLOR27 

6&7 

transparent

COLOR29 

COLOR30 

1 0 

COLOR31 

Each two successive sprites have the same color registers. As in dual-playfield mode, the bit combination of two zeros does not represent a  color, but causes the pixel to be transparent. The color of anything behind this pixel is visible in its place, whether this is another sprite, a  playfield, or just the background. If three colors are not enough, two sprites can be combined with each other. The two-bit combinations of the sprites then make up a  four-bit number. Sprites can only be combined in successive even-odd pairs (i.e., no. 0  with no. 1, no. 2  with no. 3, etc.). The two data words of the higher- numbered sprite contribute the two high-order bits of the total 4-bit value. This value then serves as a  pointer to one of fifteen color registers, with the value zero meaning transparent. The color registers are the same for all four sprite pairs: COLOR16 to COLOR31.

Sprite data 

Color register 

Sprite data 

Color register 

transparent

COLOR24 

COLOR 17 

COLOR25 

COLOR18 

COLOR26 

001 1 

COLOR19 

101 1 

COLOR27 

COLOR20 

1 100 

COLOR28 

COLOR21 

COLOR29 

01 10 

COLOR22 

COLOR30 

COLOR23 

COLOR31 

The sprite DMA The Amiga sprites can be programmed very easily. Almost all the work is handled by the sprite DMA channels. The only thing needed to display a sprite on the screen is a  special sprite data list in memory. It contains almost all the data needed for the sprite. The DMA controller only needs to be told the address of this list in order for the sprite to appear. The DMA controller has a  DMA channel for each sprite. This can read only two data words in each raster line. This is why a  normal sprite is limited to a  16-pixel width and four colors. Since these two data words can be read in every line, the height of a  sprite is limited only by that of the screen window.

Construction of a  sprite data list 

A sprite data list consists of individual lines, each containing two data words. For each raster line, one of these list lines is read via DMA. It can contain either two control words to initialize the sprite, or two data words with the pixel data. The control words determine the horizontal column and the first and last line of the sprite. After the DMA controller has read these words and placed them in the appropriate registers, it waits until the electron beam reaches the starting line of the sprite. Then two words are read for each raster line and are output by Denise at the appropriate horizontal position on the screen until the last line of the sprite has been processed. The next two words in the sprite data list are again treated as control words. If both words are zero, the DMA channel ends its activity. However, it's also possible to specify a  new sprite position. The DMA controller then waits for the start line, and the process is repeated until two control words with the value zero are found as the end marker of the list.

Construction of a  sprite data list (Start =  starting address of the list in 

chip RAM):

Address 

Contents 

Start+4 

Start+8 

Start+12 

Start+4*n 

Start+4*(n+1) 

1st and 2nd data words of the 1st line of the sprite 

1st and 2nd data words of the 2nd line of the sprite 

1st and 2nd data words of the 3rd line of the sprite 

1 st and 2nd data words of the nth line of the sprite 

0,0 End of the sprite data list 

Construction of the first control word: 

Bit no.: 15 14 13 12 11 10 9       8 7       6 5       4 3       2 1        0 

Function: E7 E6 E5 E4 E3 E2 E1 E0 H8 H7 H6 H5 H4 H3 H2 H1 

Construction of the second control word: 

Bit no.: 15 14 13 12 11 10 9        8 7       6 5       4 3        2 10 

Function: L7 L6 L5 L4 L3 L2 L1 L0 AT 0       0 SHSH1 0        E8 L8 HO 

HO to H8 Horizontal position of the sprite (HSTART) 

E0 to E8 First line of the sprite (VSTART) 

L0 to L8 Last line of the sprite+1 (VSTOP) 

SHSH 1 Extra bit for the horizontal position 

AT Attach control bit 

The (starting) horizontal position and the starting and ending vertical positions of the sprite are expressed with nine bits each. These bits are divided somewhat unpractically between the two control registers. The resolution in the horizontal direction is one low-resolution pixel, while in the vertical direction it is one raster line. These values are independent of the mode of the playfield(s) and cannot be changed. The sprites are limited to the screen window (set by DIWSTRT and
DIWSTOP). If the coordinates set by the control words are outside this 

area, the sprites are only partially visible, if at all, since all points that are not within the screen window are cut off. The horizontal and vertical start positions refer to the upper left corner of the sprite. The vertical stop position defines the first line after the sprite
(i.e., the last line of the sprite +  1). The number of lines in the sprite is 

VSTOP -VSTART. 

The following example list displays a  sprite at the coordinates 180,160, approximately in the center of the screen. It has a  height of eight lines. The last line (VSTOP) is 168. If you combine both data words within a line, you get numbers between 0  and 3, which represent one of the three sprite colors or the transparent pixels. This makes the sprite easier to visualize:

0000002222000000 

0000220000220000 

0002200330022000 

0022003113002200 

0022003113002200 

0002200330022000 

0000220000220000 

0000002222000000 

In the data list the two words must be given separately:

Start : 

dew

$A05A 

$A800 

HSTART =  $B4, VSTART 

= $A0, 

dew

%0000 

0000,%0000 

0011 1100 

dc .w

%0000 

0000,%0000 

1100 0011 

dc .w

%0000 

0000,%0001 

1001 1001 

dew

%0000 

0000,%0011 

0010 0100 

dew

%0000 

0000,%0011 

0010 0100 

dew

%0000 

0000,%0001 

1001 1001 

dew

%0000 

0000,%0000 

1100 0011 

dew

%0000 

0000,%0000 

0011 1100 

dew

0,0 

End of the 

sprite data list

$A8 

The AT bit in the 2nd control word determines whether two sprites are combined. It effects only those sprites with odd numbers (sprites 1, 3, 5,
7). For example, if it is set in sprite 1, its data bits are combined with those 

of sprite 0  to make four-bit pointers to the color table. The order of the bits is then as follows:

Sprite 1  (odd number), second data word: 

Sprite 1 , first data word: 

Sprite 0  (even number), second data word: 

Sprite 0, first data word: 

Bit 3  (MSB) 

Bit 2 

Bit 1 

Bit 0  (LSB) 

If two sprites are to be combined in this manner, their positions must also match. If this is not the case, the old three-color representation is automatically re-enabled. The simplest thing to do is to write the same control words in the two sprite data lists. We'll now give an example of a sprite data list for a  fifteen-color sprite. For the sake of simplicity our sprite consists of only four lines. Again, we first visualize the sprite by superimposing the data words. The digits represent the colors of the corresponding pixels. In order to display all fifteen colors and transparent, the hexadecimal digits "A" to "F" are used.

0011111111111100 

1123456789ABCD11 

1 1EFEFEFEFEFEF1 1 

0011111111111100 

The structure of the data words can be seen from line 2:

Colors of the sprite: 

Sprite 1, data word 2: 

Sprite 1, data word 1: 

Sprite 0, data word 2: 

Sprite 0, data word 1 : 

1123456789ABCD11 

0000000011111100 

0000111100001100 

0011001100110000 

1101010101010111 

Horizontal position (HSTART) is 180. The first line of the sprite 

(VSTART) is 160, and the last line (VSTOP) is 164. 

The data list for the entire sprite looks as follows:

StartSpriteO: 

dew $A05A, SA400 HSTART=$B4, VSTART=$A0, 

dew %0011 1111 1111 1100,%0000 0000 0000 0000 dew %1101 0101 0101 0111,%0011 0011 0011 0000 dew %1101 0101 0101 0111,%0011 1111 1111 1100 dew %0011 1111 1111 1100,%0000 0000 0000 0000 dew 0,0

VSTOP=$A4, AT=0 

StartSpritel : 

dew $A05A, $A480 HSTART=$B4, VSTART=$A0, VSTOP=$A4, 

dew %0000 0000 0000 0000,%0000 0000 0000 0000 dew %0000 1111 0000 1100,%0000 0000 1111 1100 dew %0011 1111 1111 1100,%0011 1111 1111 1100 dew %0000 0000 0000 0000,%0000 0000 0000 0000 dew 0,0

AT=1 

Multiple sprites through one DMA channel 

After a  sprite has been displayed, the DMA channel is free. In the previous example, the last sprite data was read in line 163. After that the sprite DMA channel is turned off with the two zeros at the end of the data list. But as we mentioned before, it is also possible to continue using the DMA channel. To do this, simply put two new control words in place of the two zeros in the data list. The only condition is that there must be at least one line free between the first line of the new sprite and the last line of the previous one. For example, if the previous sprite extends through line 163, then the next cannot start before line 165. The reason for this is that the two control words must be read in the line in between
(164). The sprite DMA then proceeds as follows: 

Line Data through the DMA channel 

Second-last line of the 1st sprite through this channel 

Last line of the 1st sprite 

Control words of the 2nd sprite 

First line of the 2nd sprite 

Second line of the 2nd sprite 

The following example displays the three-color sprite from our first example in two different positions on the screen:

Start : 

dew dew dew dew dew dew dew dew dew

$A05A, 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

dew dew dew dew dew dew dew dew dew dew

$B096, 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

%0000 

0,0 

 First sprite through this DMA channel at line 160 ($A0) 

,-Horizontal position: 180 ($B4) 

$A800 HSTART =  $B4, VSTART =  $A0, VSTOP =  $A8 

0000 0000 0000,%0000 0011 1100 0000 

0000 0000 0000,%0000 1100 0011 0000 

0001 1000 0000,%0001 1001 1001 1000 

0011 1100 0000,%0011 0010 0100 1100 

0011 1100 0000,%0011 0010 0100 1100 

0001 1000 0000,%0001 1001 1001 1000 

0000 0000 0000,%0000 1100 0011 0000 

0000 0000 0000,%0000 0011 1100 0000 

Now comes the second sprite over this DMA channel
at line 176 ($B0), horizontal position 300 ($12C) 

$B800 HSTART =  $12C, VSTART =  $B0, VSTOP =  $B8 

0000 0000 0000,%0000 0011 1100 0000 

0000 0000 0000,%0000 1100 0011 0000 

0001 1000 0000,%0001 1001 1001 1000 

0011 1100 0000,%0011 0010 0100 1100 

0011 1100 0000,%0011 0010 0100 1100 

0001 1000 0000,%0001 1001 1001 1000 

0000 0000 0000,%0000 1100 0011 0000 

0000 0000 0000,%0000 0011 1100 0000 

End of the sprite data list 

Activating the sprites 

After a  correct data list has been constructed in the chip RAM and the desired colors have been written into the color table, the DMA controller must be told at what address the list is stored before the sprite DMA can be enabled. Each DMA channel has a  register pair in which the starting address of the data list must be written:

SPRxPT register (SPRite x  PoinTer, points to data list for sprite DMA 

channel x):

Name 

Function 

$120 

$122 

$124 

$126 

$128 

$12A 

$12C 

$12E 

$130 

$132 

$134 

$136 

$138 

$13A 

$13C 

$13E 

SPROPTH 

SPROPTL 

SPR1PTH 

SPR1PTL 

SPR2PTH 

SPR2PTL 

SPR3PTH 

SPR3PTL 

SPR4PTH 

SPR4PTL 

SPR5PTH 

SPR5PTL 

SPR6PTH 

SPR6PTL 

SPR7PTH 

SPR7PTL 

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 0  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 1  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 2  Bits 0-1 5

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 3  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 4  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 5  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 6  Bits 0-15

Pointer to the sprite data list Bits 1 6-20 

for sprite DMA channel 7 Bits 0-15 All SPRxPT registers are write-only The DMA controller uses these registers as pointers to the current address in the sprite data lists. At the start of each picture they contain the address of the first control word. With each data word read they are incremented by one word so that at the end of the picture they point to the first word after the data list. For the same sprites to be displayed in each frame, these pointers must be set back to the start of the sprite data list before each frame. As with the bit-plane pointers BPLxPT, this is most easily done by the Copper in the vertical blanking gap. The pertinent section of the Copper list might look like this:

StartSpritexH =  starting address of sprite data list for sprite x, bits 16-19 

StartSpritexL =  bits 0-15 

Copper listStart 

MOVE #StartSpriteOH, SPROPTH  Initialize sprite DMA 

MOVE #StartSpriteOL, SPROPTL  channel 0 

MOVE #StartSpritelH,SPRlPTH  Initialize sprite DMA 

MOVE #StartSpritelL,SPRlPTL  channel 1 

MOVE #StartSprite2H,SPR2PTH  Initialize sprite DMA 

MOVE #StartSprite2L,SPR2PTL ,-channel 2 

Same for channels 3  to 6 

MOVE #StartSprite7H, SPR4PTH  Initialize sprite DMA 

MOVE #StartSprite7L, SPR4PTL ,-channel 7 

 Other Copper tasks 

WAIT $FFFE End of Copper list 

There is no way to turn the sprite DMA channels on and off individually. The SPREN bit (bit 5) in the DMACON register turns the sprite DMA on for all eight sprite channels. If you don't want to use all of them, the unused channels must process empty data lists. To do this, their SPRxPT's are set to two memory words with contents of zeros. The two zeros at the end of an existing data list can be used for this. All eight SPRxPTs must always be initialized within the vertical blanking gap. Even if the data list is nothing but the two zeros, the DMA channel's
SPRxPT points to the first word after them at the end of a  frame. 

Naturally, the SPRxPT can also be initialized by the processor in the 

vertical blanking interrupt. As the last step, the sprite DMA must be enabled. As previously mentioned, this is done for all eight sprite DMA channels by using the
SPREN bit in the DMACON register. The following MOVE command 

accomplishes this:

MOVE.W #$8220,$DFF096 Set SPREN and DMAEN in DMACON register 

Moving sprites 

The values of the two control words in the sprite data list determine the position of a  sprite. To move a  sprite, these values must be changed step by step. This can be done directly by the processor when using the appropriate
MOVE commands. The control words must be modified at the right time. 

Otherwise, the following problem can occur: 

The processor modifies the first control word. Before it can change the second control word, the DMA controller reads both words. Since they no longer belong together, what appears on the screen may not make any sense. The easiest way to avoid this is to change the control words only during the vertical blanking interrupt, after the Copper has initialized the
SPRxPT). 

The sprite/playfield priority The priority of a  playfield or sprite determines whether it appears in front of, behind, or between the other screen elements. The sprite with the highest priority appears in front of all other elements. Nothing can cover it. The priority of a  sprite is determined by its number. The lower the number, the higher the priority. Also, sprite 0  has priority over all other sprites. For the playfields, a  control bit determines whether number 1  or 2 appears in front. But what is the priority of the sprites in reference to the playfields? On the Amiga it is possible to position the playfields almost anywhere between the sprites. The sprites are always handled in pairs when it comes to setting the priority of playfield vs. sprites. The pair combinations are the same as those used for fifteen-color sprites, always an even-numbered sprite with its odd successor: sprites 0  & 1, sprites 2  & 3, sprites 4  & 5, sprites 6  & 7 The four sprite pairs can be viewed as a  stack of four elements. If you look at the stack from above, the underlying elements can only be seen through holes in the overlying ones. The holes correspond to the transparent points in the bit-planes or sprites and the parts of the screen that a  sprite cannot cover because of its size. The order of elements in the stack cannot be changed. But two of the elements, namely the playfields, can be placed anywhere between the four sprite pairs. Five positions are possible for each playfield:

Position 

Order from front to back 

PLF 

SPR0&1 

SPR2&3 

SPR4&5 

SPR6&7 

SPR0&1 

PLF 

SPR2&3 

SPR4&5 

SPR6&7 

SPR0&1 

SPR2&3 

PLF 

SPR4&5 

SPR6&7 

SPR0&1 

SPR2&3 

SPR4&5 

PLF 

SPR6&7 

SPR0&1 

SPR2&3 

SPR4&5 

SPR6&7 

PLF 

The BPLCON2 register contains the priority of the playfields with respect to the sprites:

BLPCON2 $104 (write-only) 

Bit no.: 15-7 6  5 4  3 2 i 0 

Function: Gen. PF2PRI PF2P2 PF2P1 PF2P0 PF1P2 PF1P1 PF1P0 

H 

BPLCON2 =  $0003 

PF2PRI 

If this bit is set, playfield 2  appears in front of playfield 1 .

PF1P0 toPFlPl 

These three bits form a  3-bit number that determines the position of playfield 1  (all odd bit-planes) between the four sprite pairs. Values from
0 to 4  are allowed (see previous table). 

PF2P0 to PF2P2 

These three bits have the same function as bits PF1P0 to PF1P2, but for playfield 2  (all even bit-planes).

Example: 

This means that playfield 1  appears before playfield 2, PF2P0-2 =  0,
PF1P0-2 =  3. This yields the following order, from front to back: 

PLF2 SPR0&1 SPR2&3 SPR4&5 PLF1 SPR6&7 

If we look closely, we see a  paradox. The PF2PRI bit is 0, so playfield 1 should appear in front of playfield 2. The order previously shown contradicts this. The possible consequences of such a  situation depend on which of the various elements are present at a  given pixel location. When one of the sprites 0  to 5  is present between playfields 1  and 2, its priority causes it to appear in front of playfield 1. Since playfield 1  is in front of playfield 2, the sprite is visible at this point, even though it is actually behind playfield 2. In contrast, if only playfield
2 and the sprite are at a  given position, playfield 2  covers the sprite. 

This is because the playfield/playfield priority has precedence over the sprite/playfield priority. If the dual-playfield mode is not used, there is only one playfield, which is formed from both the even and odd bit-planes. The PF2PRI and PL2P0-
PL2P2 bits then have no function. 

Collisions between graphic elements 

It is often very useful to know whether two sprites have collided with each other or with the background. For example, in a  game program this might indicate that a  player had scored a  hit. When the pixels of two sprites overlap at a  certain screen position (i.e., both have a  non-transparent pixel at the same coordinates), this is treated as a  collision between the two sprites. A  collision of the playfields with each other or with a  sprite is also possible. Each recognized collision is noted in the collision data register,
CLXDAT: 

CLKDAT $00E (read-only) 

Bit no. Collision between 

Unused 

Sprite 4  (or 5) and sprite 6  (or 7) 

Sprite 2  (or 3) and sprite 6  (or 7) 

Sprite 2  (or 3) and sprite 4  (or 5) 

Sprite 0  (or 1) and sprite 6  (or 7) 

Sprite 0  (or 1) and sprite 4  (or 5) 

Sprite 0  (or 1 ) and sprite 2  (or 3) 

Playfield 2  (even bit-planes) and sprite 6  (or 7) 

Playfield 2  (even bit-planes) and sprite 4  (or 5) 

Playfield 2  (even bit-planes) and sprite 2  (or 3) 

Playfield 2  (even bit-planes) and sprite 0  (or 1 ) 

Playfield 1  (odd bit-planes) and sprite 6  (or 7) 

Playfield 1  (odd bit-planes) and sprite 4  (or 5) 

Playfield 1  (odd bit-planes) and sprite 2  (or 3) 

Playfield 1  (odd bit-planes) and sprite 0  (or 1) 

Playfield 1  and playfield 2 

While on a  sprite, any non-transparent pixel can cause a  collision we can specify which colors of the playfields are to be considered in collision detection. Moreover, it is possible to include or exclude any odd- numbered sprite from collision detection. All this can be set with the bits in the collision control register, CLXCON.

CLXCON $098 (write-only) 

Bit no. 

Name 

Function 

ENSP7 

Enable collision detection for sprite 7 

ENSP5 

Enable collision detection for sprite 5 

ENSP3 

Enable collision detection for sprite 3 

ENSP1 

Enable collision detection for sprite 1 

ENBP6 

Compare bit-plane 6  with MVBP6 

ENBP5 

Compare bit-plane 5  with MVBP5 

ENBP4 

Compare bit-plane 4  with MVBP4 

ENBP3 

Compare bit-plane 3  with MVBP3 

ENBP2 

Compare bit-plane 2  with MVBP2 

ENBP1 

Compare bit-plane 1  with MVBP1 

MVBP6 

Value for collision with bit-plane 6 

MVBP5 

Value for collision with bit-plane 5 

MVBP4 

Value for collision with bit-plane 4 

MVBP3 

Value for collision with bit-plane 3 

MVBP2 

Value for collision with bit-plane 2 

MVBP1 

Value for collision with bit-plane 1 

The ENSPx bits (ENable SPrite x) determine whether the corresponding odd-numbered sprite is regarded in collision detection. For example, if the
ENSP1 bit is set, a  collision between sprite 1  and another sprite or a 

playfield is registered. Such a  collision sets the same bit in the collision data register as for sprite 0. Therefore, it is not possible to tell by looking at the register contents whether sprite 0  or sprite 1  caused the collision.
Furthermore, collisions between sprites 0  and 1  are not detected. These 

facts should be kept in mind when selecting and using sprites. If two sprites have been combined into one fifteen-color sprite, the appropriate ENSPx bit must be set in order to have correct collision detection. For the playfields, the programmer can set which combinations of the bit- planes generate a  collision and which do not. The ENBPx bits (ENable
Bitplane x) determine which bit-planes are considered in collision 

detection. If all ENBPx bits of a  playfield are set, a  collision is possible at every pixel whose bit combination matches that of the MVBPx bits
(Match Value Bitplane x). 

The ENBPx bits determine whether the bits from plane x  are compared with the value of MVBPx. If the bits of all planes for which ENBPx is set match the corresponding MVBPx bits for a  given pixel, then this pixel can generate a  collision.

Complicated? An example makes it clearer: 

The ENBPx bits are set, as are all of the MVBPx bits. Now only those playfield pixels whose bit combinations are binary 111111 can generate a collision. If only the lower three MVBPx bits are set, then a  collision is possible only if the pixel in the playfield has the combination 000111. If a  collision is to be allowed for all pixels with the bit combinations
0001 11, 0001 10, 000100 or 000101, the MVBP bits must be 000100. The 

lower two bits should always satisfy the collision condition, so the corresponding ENBPx bits are cleared. The ENBP value is 1 1 1 100.

Examples for possible bit combinations: 

ENBPx 

MVBPx 

Collision possible with bit pattern 

111111 

111111 

111111 

111111 

111000 

111000 

111100 

1111XX 

111100,111101,111110,111111 

011111 

X00000 

000000, 100000 

000000 

Collision possible with any bit pattern 

The values of bits marked with an x  are irrelevant. If not all six bit-planes are active, the ENBPx bits of the unused planes must be set to 0. The various combinations of the ENBPx and MVBPx bits allow a  variety of different collision detection strategies. For example, the CLXCON register can be set so that sprites can collide only with the red and green pixels of the playfield, but not with other colors. Or a  collision may be possible only at the transparent pixels of playfield 1  if the underlying pixels of playfield 2  are black, etc.

Other sprite registers 

Besides the SPRxPT registers, each sprite has four additional registers. 

They are normally supplied with data automatically by the DMA controller. However, it is also possible to access them through the processor.

SPRxPOS 

SPRxCTL 

SPRxDATA 

SPRxDATB 

First control word 

Second control word 

First data word of a  line (low word) 

Second data word of a  line (high word) 

Again, x  stands for a  sprite number from 0  to 7. The addresses of these 

registers can be found in the register overview. The DMA controller writes the two control words of a  sprite direcdy into the two registers SPRxPOS and SPRxCTL. When a  value is written into the SPRxCTL register, whether by DMA or the 68030, Denise turns the sprite output off. The sprite will no longer be output to the screen. The DMA controller now waits for the line specified in VSTART. Then it writes the first two data words into the SPRxDATA and SPRxDATB registers. Now the sprite will be displayed, because writing to the SPRxDATA register causes Denise to enable the sprite output again. The desired horizontal position from the SPRxCTL and SPRxPOS registers is

11. 7 Programming the Hardware 

compared with the actual screen column, and the sprite is displayed at the correct location on the monitor. The DMA controller writes two new data words in SPRxDATA/B in each line until the last line of the sprite (VSTOP) is past. Then it fetches the next control words and places them in SPRxPOS and SPRxCTL. This turns the sprite off again until the next VSTART position is reached. If both control words were zero, the DMA controller ends the sprite DMA for the corresponding channel until the start of the next frame. At the end of the vertical blanking gap, it starts again at the current address in
SPRxPT. 

Displaying sprites without DMA 

A sprite can also be easily displayed without the DMA channel. You simply write the desired control words directly into the SPRxPOS and
SPRxCTL registers. 

Only the HSTART position and the AT bit have to contain valid values. 

VSTART and VSTOP are used only by the DMA channel. 

You can begin the sprite output in any line by writing the two data 

words into the SPRxDATA and SPRxDATB registers. Since writing to
SPRxDATA enables the sprite output, it is better to write to SPRxDATB 

first. If the contents of the two registers are not changed, they are displayed again in each line. The result is a  vertical column. To turn the sprite off again, simply write some value to SPRxPOS.

*** Sprite Demo *** 

Customchip registers 

INTENA =  $9A 

INTREQR =  $le  Interrupt request register (read) 

DMACON =  $96 DMA control register (write) 

COLOR00 =  $180, -Color palette register 0 

VPOSR =  $4 Beam position (read) 

JOY0DAT =  $A /Mouse position for port 0 

 Copper registers 

COP1LC =  $80 ,-Address of 1st Copperlist 

COP2LC =  $84 ,-Address of 2nd Copperlist 

//. The A3 000 Hardware 

COPJMPl =  $88 Jump to Copperlist 1 

C0PJMP2 =  $8a Jump to Copperlist 2 

Bitplane registers 

BPLCONO =  $100 Bitplane control register 0 

BPLCON1 =  $102 1 (Scroll values) 

BPLCON2 =  $104 2 (Spriteoplayf ield priority) 

BPL1PTH =  $OE0  Pointer to 1st bitplane 

BPL1PTL =  $0E2  

BPL1MOD =  $108 Modulo value for odd bitplanes 

BPL2MOD =  $10A Module value for even bitplanes 

DIWSTRT =  $08E  Start of screen window 

DIWSTOP =  $090 End of screen window 

DDFSTRT =  $092  Bitplane DMA start 

DDFSTOP =  $094  Bitplane DMA stop 

 Sprite registers 

SPR0PTH =  $120  Pointer to sprite data list for sprite 1 

SPR0PTL =  $122 

SPR1PTH =  $124 

SPR1PTL =  $126 

CIA-A port register A  (Mouse button) 

CIAAPRA =  $bfe001 

Exec Library Base Offsets 

OpenLibrary =  -30-522 LibName,Version/al,dO 

Forbid =  -30-102

Permit =  -30-108 

AllocMem =  -30-168 ByteSize,Requirements/dO,dl

FreeMem =  -30-180 MemoryBlock, ByteSize/al, dO 

graphics base

StartList =  38 

 Other labels 

Execbase =  4 

Planesize =  52*345 Size of bitplane 

Planewidth =  52 

CLsize =  19*4 Size of Copperlist in bytes 

Chip =  2  Request chip RAM 

Clear =  Chip+$10000  Clear previous chip RAM 

*** start program *** 

Start : 

 Request memory for bitplanes 

move.l Execbase,a6 move.l #Planesize,dO /Memory requirement of planes move.l #clear,dl jsr AllocMem(a6) Request memory move . 1 dO , Planeadr beq Ende  Error! -> End

Request memory for Copperlist 

moveq #Clsize,dO moveq #chip, dl jsr AllocMem(a6) move.l dO,CLadr beq FreePlane  Error! -> FreePlane

.•Request memory for sprite data list 

moveq #Sprsize,dO moveq #chip,dl jsr AllocMem(a6) move .1 dO , Spradr beq FreeCL
Set up Copperlist in chip RAM 

 Bitplanepointer 

move . 1 CLadr , aO move.w #bpllptl,d2 move.l Planeadr, dl bsr setadr

 Pointer to 1st sprite 

move.w #spr0ptl,d2 move . 1 Spradr , dl bsr setadr
 Remaining (unused) sprite pointers 

moveq #6,d0 move.w #sprlptl,d3 spr_set : move.l Spradr+Sprsize-4,dl move.w d3,d2 bsr setadr addq.w #4,d3 dbf dO , spr_set

move.l #$fffffffe, (aO) 

Copy sprite data list 

move.w #Sprsize/4-l,dO lea Sprstart,aO move . 1 Spradr , al spr_copy : move.l (aO)+,(al)+ dbf dO , spr_copy

.*** Main program *** 

/Disable DMA and task-switching 

jsr forbid (a6)
lea $dff000,a5 

move.w #$0300,dmacon(a5) 

 Initialize Copper 

move.l CLadr, copllc (a5) clr.w copjmpl(a5)

/Initialize playfield 

move.w #0,color00 (a5) Playfield colors

move.w #$0f00,color00+2(a5) 

move.w #$000f ,color00+34(a5) /Sprite colors 

move.w #$00ff ,color00+36(a5) 

move.w #$00f0,color00+38(a5) 

move.w #$la64,diwstrt(a5) 26,100

move.w #$39dl,diwstop(a5) 313,465 

move.w #$0028,ddfstrt(a5) 

move.w #$00d8,ddfstop(a5) 

move.w #%0001001000000000,bplcon0(a5) clr.w bplconl(a5) move.w #8,bplcon2 (a5) move.w #2,bpllmod(a5)

DMA on 

move.w #$83a0,dmacon(a5) Bitplane &  sprite DMA on 

Fill bitplanes with checkerboard pattern 

move . 1 planeadr , aO move.w #planesize/4-l,d0 Loop counter move.w #13*16,dl

move.l #$ffff0000,d2 checkerboard pattern 

move.w dl,d3 fill: move.l d2, (a0)+ subq.w #l,d3 bne.s continue swap 62  Change pattern move.w dl,d3 continue: dbf dO,fill «

Wait for raster line 16 (after Exec -interrupts) 

wait: btst #6,ciaapra Mouse button pressed? beq.s endit move.l vposr(a5),d2
and.l #$0001FF00,d2 

cmp.l #$00001000, d2 

bne.S wait

Move sprite 

move.w joy0dat(a5) ,d0 Mouse position move.w d0,dl and.w #$ff,d0 lsr.w #8,dl add.w #150, dO Add offset for null position, so add.w #30, dl  sprite always remains visible jsr setcor ,-Display sprite at position in d0,dl bra.S wait No -> continue

*** End program *** 

,-Reactivate old Copperlist 

endit: move.l #GRname,al Set parameters for OpenLibrary clr.l dO jsr OpenLibrary (a6) Open Graphics library move.l d0,a4 move.l StartList(a4) ,copllc(a5) clr.w copjmpl(a5)
move.w #$83a0,dmacon(a5) 

jsr permit (a6)

 Release memory for sprite data 

move . 1 Spradr , a 1 moveq #Sprsize,dO jsr FreeMem(a6)

,-Release memory for Copperlist 

FreeCL : 

move.l CLadr.al Set parameters for FreeMem moveq #CLsize,dO jsr FreeMem (a6)

/Release memory for bitplanes 

FreePlane: 

move . 1 Planeadr , al move.l #Planesize,dO jsr FreeMem (a6)

Ende: 

clr.l dO rts End program

 Subprograms 

setadr writes the Copper commands for initializing a  DMA address counter in the Copperlist a0 -  pointer to Copperlist (incremented by setadr) dl -  to written address (e.g. bitplane) d2 -  address of pointer register, low (e.g. bpllptl) setadr : move.w d2, (a0)+ move ptl move.w dl, (a0)+ addr bits 1-15 swap dl subq.w #2,d2 /switch to pth move.w d2,(a0)+ move pth move.w dl,(aO)+ addr bits 16-18 rts setcor writes the X,Y coordinates of the sprite to the sprite data list in the chip RAM dO,dl -  X,Y coordinates

/Address of sprite data list: Spradr 

/Height of sprite in lines: Sprhigh 

za0,d2,d3 are used internally setcor : movem.l d0-d3/a0, - (sp) move.w d0,d3 /HO bit to second control word and.w #l,d3 /Clear rest lsr.w #l,dO H1-H8 to position tnove.w d0,d2   in first controlword and.w #$ff,d2 ,-Clear E0-E7 move.w dl,dO add.l #Sprhigh,d0 Last line of sprite to dO asl.w #8,dl bcc noE8 bset #2,d3 noE8: or.w dl,d2 asl.w #8,d0 bcc noL8 bset #l,d3 noL8: or.w d0,d3 move . 1 Spradr , aO move . w  d2 , ( aO ) + move.w d3, (aO)

Set E8 in second word 

E0-E7 to first word 

Set L8 

L0-L7 to second word 

Transfer new value to memory 

movem.l (sp)+,d0-d3/a0 rts

(•Variables 

CLadr : 

Planeadr : 

Spradr : 

test: del del del del

 Constants 

GRname : de b  " graphics . 1 ibrary " , 0 

 Sprite data list 

align even

Sprstart : 

dew $a05a,$a800 

dew %0000000000000000, dew %0000000000000000, dew %0000000110000000, dew %0000001111000000, dew %0000001111000000, dew %0000000110000000, dew %0000000000000000, dew %0000000000000000,

Sproff: dew 0,0 

Sprend : 

%00000001111000000 

%00000110000110000 

%00001000110001000 

%00011001001001100 

%00011001001001100 

%00001000110001000 

%00000110000110000 

%00000001111000000 

Sprsize =  Sprend-Sprstart 

Sprhigh =   9 

end
