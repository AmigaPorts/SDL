# Playfields

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 11.7.5 Playfields

The screen output of the Amiga consists of two basic elements: sprites and playfields. In this section we'll discuss the structure and programming of all types of playfields. The playfield is the basis of the normal screen display. It consists of one to six bit-planes. A  playfield is a graphic screen that is built up from a  variable number of individual memory areas (the bit-planes). The Amiga provides various ways to display playfields:

Between 2  and 4096 colors simultaneously in one picture. 

• Resolutions of 16 by 1  to 736 by 568 pixels. 

• Two completely independent playfields are possible. 

• Smooth scrolling in both directions. 

All these capabilities can be divided into two groups.

1. Combining the bit-planes to achieve the colors of the individual 

pixels (displaying the bit pattern from the bit-planes).

2. Determining the form, size and position of the playfields(s). 

The various display options By using from 1  to 6  bit-planes, you are using the corresponding number of bits to represent each pixel. This value must then be converted into one of 4096 colors, since each pixel can naturally have only one color. The Amiga creates its colors by mixing the component colors, red, green and blue. Each of these three components can have 16 different intensity levels. This results in 4096 color shades (16*16*16 =  4096). Storing a color value requires four bits per component, or 12 bits per color. If you wanted to allow one of 4096 colors for each pixel, you would need 12 bits per pixel. But a  maximum of six bits is possible. Therefore, the six bits must be converted into one of the 4096 possible colors for the visible point. The color palette A color palette or color table is used to do this. On the Amiga this contains 32 entries, each of which can hold a  12-bit color value. The value of the first color register COLOR00 is used for the background color and the border color.

1st color choice from color table 

S-blt number from blt-plane= 

pointer to color table

Color table 

°E 

<I> 

0 in Bii-pi^rr 

COLOR 00 

COLOR 01 

COLOR 02 

COLOR 03 

COLOR 04 

COLOR 05 

COLOR 06 

COLOR 07 

0 1 ■    I tit II ■,„■„■,,„» * 

.POLOR 08 

1| I    I I    I I    I IBM-Plan, 3 

0| I    I I    I I    I I  Bl,.„.an. S 

1 iBIwSTT 

if

Pixel appears 

in COLOR 05 mr

Visible 

screen

Color selection 

Color palette registers 0-31 (COLOR00 to COLOR31) are write-only: 

Register addr. 

Color palette register 

$180 

COLOR00 

$182 

COLOR01 

etc.

$1BE 

COLOR31 

Structure of a  table element: 

Bit: 

COLORxx: 

15 14 13 12 11 10 9 

x x        x x        R3 R2 R1

8 7       6 5       4 3        2 1 

R0 G3 G2 G1 GO B3 B2 B1 

BO 

R0-R3 

G0-G3 

B0-B3 

4-bit value for the red component 

4-bit value for the green component 

4-bit value for the blue component 

The four bits labeled "x" are not used. The value obtained from the bit-planes is used as a  pointer to a  table element. Since there are only 32 of these color table registers, a  maximum of five bit-planes can be combined in this mode. The bit from the lowest- numbered bit-plane supplies the LSB of the table entry. The bit from the highest-numbered bit-plane supplies the MSB. This method of obtaining the color from a  table allows a  maximum of 32 colors in a  picture, but these colors can be selected from a  total of 4096. In high-resolution mode only four planes can be active at one time (16 colors is the limit). In this display mode it doesn't matter how many planes are combined. Some registers may simply remain unused:

Number of bit-planes Colors 

Color registers used 

COLOR00 

COLOR00 

COLOR00 

COLOR00 

COLOR00 

COLOR01 

COLOR03 

COLOR07 

COLOR15 

COLOR31 

The extra half-bright mode In low-resolution mode a  maximum of six bit-planes can be used. This yields a  range of values of 2^ or 0  to 63. However, there are only 32 color registers available. The extra half-bright mode uses a  special technique to get around this. The lower five bits (bits 0  to 4  from planes 1 to 5) are used as the pointer to a  color register. The contents of this color register is output directly to the screen if bit 5  (from bit-plane 6) is 0. If this bit is 1, each component of the color value is divided by 2  before being sent to the screen.

Dividing by 2  means that the bits of the three color components are 

shifted one bit to the right, which amounts to a  binary halving. The intensity of each component is then only half as great, but the proportions of the three components remains constant. The same color will be displayed on the screen, but only half as bright.

Example: 

Bitno.: 5  43210 

Value from bit-plane: 10 010 0 

Yields table entry no. 8  (binary 01000 is 8), COLOR08 contains the 

following value (color: orange):

R3 

R2 Rl R0 G3 G2 Gl GO 

110 0         110 

B3 

B2 

Bl 

BO 

Since bit 5  = 1, the values are shifted by 1  bit:

R3 

R2 Rl RO G3 G2 Gl GO 

1110 0         11 

B3 

B2 

Bl 

BO 

This value still corresponds to orange, but now it's only half as bright. By selecting appropriate color values for the 32 registers, it is possible for each pixel to take on one of 64 possible colors in the extra half-bright mode. The color registers store the bright colors, which can then be dimmed by setting bit 5. The hold-and-modify mode This mode allows the display of all 4096 colors in one picture. Like the extra half-bright mode, it is possible only at low-resolution, since all six bit-planes are required. In this mode the colors in a  normal picture seldom make extreme changes from pixel to pixel. Usually smooth transitions from bright to dark or dark to bright are needed. In the hold-and-modify mode, called HAM for short, the color of the previous pixel is modified by the one that follows it. This is responsible for the fine gradations of shading that can be achieved (e.g., by incrementing the blue component by one step with each successive pixel). The limitation is that only one component can change at a  time
(i.e., only the red, blue or green intensity can be affected from one pixel 

to the next). To get a  smooth transition from dark to light, all three color components must change for many color mixes. In the HAM mode this can be accomplished only by setting one of the components to the desired value at each pixel. This requires three pixels. By comparison, the color of a  pixel can also be changed directly by fetching one of 16 colors from the color table. How is the value from the bit-planes interpreted in
HAM mode? 

The upper two bits (bits 4  and 5  from bit-planes 5  and 6) determine the use of the lower four bits (bit-planes 1  to 4). If bits 4  and 5  are 0, the remaining four bits are used as a  pointer to one of the color palette registers as usual. This allows 16 colors to be selected directly. With a non-zero combination of bits 4  and 5, the color of the last pixel (to the left of the current one) is taken, two of the three color components are held constant, while the third is replaced by the lower four bits of the current pixel. The top two bits select the component to be changed. This sounds more complicated than it is. The following table explains the use of the various bit combinations:

Bit no.: 

5 4        3 

Function 

C3 

C2 

C1 

CO 

Bits CO to C3 are used as a  pointer to one of the color 

registers in the range of COLOR00 to COLOR15. This is identical to normal color selection.

B3 

B2 

B1 

BO 

The red and green values of the last (left) pixel are used for the current pixel. The old blue value is replaced by the value in BO to B3.

R3 

R2 

R1 

RO 

The blue and green values of the last pixel are used for the current pixel. The old red value is replaced by the value in RO to R3.

G3 

G2 

G1 

GO 

The blue and red values of the last pixel are used for the current pixel The old green value is replaced by the value in GO to G3. The border color (COLOR00) is used as the color of the previous pixel for the first pixel on a  line. The dual playfield mode The previously described modes use only one playfield. The dual playfield mode allows two completely independent playfields to be displayed simultaneously. It's as though there are two screens superimposed on each other on the same monitor. They can (almost) be used completely independently of each other. This is especially interesting for games. For example, a  telescope effect can be produced very easily. The front playfield is filled with black pixels all except for a  hole in the middle through a  section of the second playfield can be seen. Each of the two playfields gets half the active bit-planes for its display.
Playfield 1  is formed from the odd planes, playfield 2  from the even ones. 

If an odd number of bit-planes is being used, playfield 1  has one more available to it than playfield 2.

2nd color choice in Dual Playfield mode 

... ,         _._.,_„ ,  Color table 

Value from odd bit-plane ICOLOH 00 1 

ra o •* ~~

Playfield 1  color 

from COLOR 01

Playfield 2 

color from
COLOR 11 

Priority switch: H 

no transparent playfield exists, the color with the highest priority Is displayed The dual playfield principle The color selection in dual playfield mode is performed as usual: The value belonging to a  pixel from all the odd bit-planes (playfield 1) or all the even planes (playfield 2) is used as a  pointer to an entry in the color table. Since each playfield can consist of a  maximum of three planes, a maximum of eight colors are possible. For playfield 1, the lower eight entries of the color table are used (COLOR00 to COLOR07). For playfield 2, an offset of 8  is added to the value from the bit-planes, which puts its colors in positions 8  to 15 (COLOR08 to COLOR15). If a  pixel has a  value of 0, it is made transparent. This means that screen elements lying behind it can be seen. This can be the other playfield, sprites or simply the background (COLOR00). The dual playfield mode can also be used in the high-resolution mode. Each playfield has only four colors in this mode. The division of the color registers doesn't change, but the upper four registers of each playfield are unused (playfield 1: COLOR04 to 07, playfield 2: COLOR12 to 15).

Division of the bit-planes in dual playfield mode: 

Bit-planes 

Planes in playfield 1 

Planes in playfield 2 

Plane 1 

none

Plane 1 

Plane 2 

Planes 1  and 3 

Plane 2 

Planes 1  and 3 

Planes 2  and 4 

Planes 1,3 and 5 

Planes 2  and 4 

Planes 1 , 3 and 5 

Planes 2, 4 and 6 

Color selection in dual playfield mode: 

Playfield 1 

Playfield 2 

Planes 5, 3 

1 Color reg. 

Planes 6, 

4, 2 Color reg. 

Transparent 

Transparent 

COLOR01 

COLOR09 

01 0 

COLOR02 

COLOR10 

01 1 

COLOR03 

01 1 

COLOR11 

COLOR04 

1 00 

COLOR12 

COLOR05 

COLOR13 

1 1  0 

COLOR06 

1 1  0 

COLOR14 

1 1  1 

COLOR07 

1 1  1 

COLOR15 

Construction of the playfields 

As previously mentioned, a  playfield consists of a  given number of bit-planes. What do these bit-planes look like? We said earlier that they were conceived as continuous areas of memory, in which a  screen line was represented by a  number of words depending on the screen width. In the normal case this is 20 words for low resolution (320 pixels divided by 16 pixels per word) and 40 (640/16) for high resolution. The following steps are needed to determine the exact construction of the playfield:

Define the desired screen size 

Set the bit-plane size 

Select the number of bit-planes 

Initialize the color table 

Set the desired mode (hi-res, lo-res, HAM, etc.) 

• Construct the Copper list 

• Initialize the Copper 

• Activate the Copper and bit-plane DMA 

Setting the screen size 

The Amiga allows the upper left corner and the lower right corner of the visible area of the playfields to be set anywhere. This allows the picture position and size to be varied. The resolution is one raster line vertically and one low-resolution pixel horizontally. Two registers contain the values. DIWSTRT (Display Window STaRT) sets the horizontal and vertical start positions of the screen window (i.e., the line and column where the display of the playfield begins).

DIWSTOP (Display Window STOP) contains the end position +  1. This 

refers to the first line/column after the playfield. If the playfield extends up to 250 lines, 251 must be given as the DIWSTOP value. The border color is displayed outside the visible area (this corresponds to the background color and comes from the COLOR00 register).

DIWSTRT $08E (write-only) 

Bit no.: 1514131211109 8       7 6       5 4       3 2       1 0 

V7 V6 V5 V4 V3 V2 V1 VO H7 H6 H5 H4 H3 H2 H1 HO 

DIWSTOP $90 (write-only) 

Bitno.: 15 14 13 12 1 1 10 9   8 7   6 5   4 3   2 1   0 

V7 V6 V5 V4 V3 V2 V1 VO H7 H6 H5 H4 H3 H2 H1 HO 

The start position stored in DIWSTRT is limited to the upper left quadrant of the screen, lines and columns 0  to 255, since the missing MSB's, V8 and H8, are assumed to be 0. The same applies to the horizontal end position, only here H8 is assumed to be 1, which places it in the range of column 256 to 458. A  different method is used for the vertical end position. Positions less and greater than row 256 should be possible. The
MSB of the vertical end position, V8, is created by inverting the V7 bit. 

This makes an end position in the range of lines 128 to 312 possible. For end positions from 256 to 312, you set V7 to 0  and V8 to 1. If V7 is 1, V8 will be 0, indicating a  position between 128 and 255. The normal screen window has an upper left comer position of horizontal 129 and vertical 41 (129,41) and a  lower right corner position of 448,296. DIWSTOP must be set at 449,297. The corresponding hexadecimal values for DIWSTRT and DIWSTOP are $2981 and $29C1. With these values the normal Amiga screen of 640 by 256 pixels (or 320 by 256) is centered in the middle of the monitor.

Why isn't the whole screen area used? There are several reasons for this. 

First, a  normal monitor does not display the entire picture. Its visible 

range normally begins a  few columns or lines after the blanking gap. In addition, a  picture tube is not rectangular. If the screen window was set as high and wide as the monitor tube, the corners of the tube would hide part of the picture.

Another limitation on the DIWSTRT and DIWSTOP values is imposed by 

the blanking gaps. The vertical gap is in the range of lines 0  to 25. This limits the visible vertical area to lines 26 to 312 ($1A to $138). The horizontal blanking gap lies between columns 30 to 106 ($1E to $6A).
Visible horizontal positions begin at column 107 ($6B). 

After the position of the screen window has been set, the start and end of the bit-plane DMA must be set as well. Proper timing of the reading of data from the bit-planes is required to ensure that the pixels will appear at the desired time on the screen. Vertically, this isn't a  problem. Screen
DMA begins and ends in the lines established by DIWSTRT and 

DIWSTOP as the boundaries of the screen window. 

Horizontally, it is somewhat more complicated. In order for a  pixel to be 

displayed on the screen, the current words of all bit-planes are required by the electronics. For six bit-planes in low resolution, this takes eight bus cycles. For high resolution, four cycles are required. (Remember: In one bus cycle, two low-resolution or four high-resolution pixels are displayed.) In addition, the hardware needs a  half bus cycle before the data can appear on the screen. Therefore, the bit-plane DMA must begin exactly

## 8.5 cycles (17 pixels) before the start of the screen window (4.5 cycles or

9 pixels in high resolution). 

The bus cycle of the first bit-plane DMA in the line is stored in the
DDFSTRT (Display Data Fetch STaRT) register, and that of the last in 

DFFSTOP (Display Data Fetch STOP): 

DDFSTRT $092 (write-only), DDFSTOP $094 (write-only) 

Bit no.: 15 13 12 11 10 9       8 7       6 5       4 3       2 1       0 

Function: x       x x      x x       x x       H8 H7 H6 H5 H4 H3 x       x 

The resolution is eight bus cycles in lo-res mode (with H3 always 0) and four in hi-res mode. H3 serves as the lowest bit. The reason for the limited resolution lies in the division of the bit-plane DMA. In lo-res mode, each bit-plane is read once every eight bus cycles, so the DDFSTRT value must be an integral multiple of eight (HI to H3 =  0). The same applies to hi-res mode, except that the bit-planes are read every four bus cycles (HI and H2 =  0). Regardless of the resolution, the difference between
DIWSTRT and DIWSTOP must always be divisible by eight, since the 

hardware always divides the lines into sections of eight bus cycles. Even in hi-res mode the bit-plane DMA is performed for eight bus cycles beyond DIWSTOP, so that 32 points are always read. The correct values for DIWSTRT and DIWSTOP are calculated as follows:

Calculation of DDFSTRT and DDFSTOP in lo-res mode: 

HStart =  Horizontal start of screen window 

DDFSTRT =  (HStart/2 -  8.5) AND $FFF8 

DDFSTOP =  DDFSTRT +  (pixels per line/2 -  8) 

For HStart =  $81 and 320 pixels per line this gives:

DDFSTRT =  ($81/2 -  8.5) AND $FFF8 =  $38 

DDFSTOP =  $38 +  (320/2 -  8) =  $D0 

Calculation of DDFSTRT and DDFSTOP in hi-res mode: 

DDFSTRT =  (HStart/2 -  4.5) AND $FFFC 

DDFSTOP =  DDFSTRT +  (pixels per line/4 -  8) 

For HStart =  $81 and 640 pixels per line this gives:

DDFSTRT =  (S81/2 -  4.5) AND $FFFC =  $3C 

DDFSTOP =  $3C +  (640/4 -  8) =  $D4 

DDFSTRT may not be less than $18 and DDFSTOP may not be greater 

than $D8. A  DDFSTRT value less than $28 does not make sense, since pixels would then have to be displayed during the horizontal blanking gap, which is not possible (except in scrolling). Since the DMA cycles of bit-planes and sprites overlap with DDFSTRT positions less than $34, some sprites may not be visible, depending on the value of DDFSTRT.

Moving the screen window 

If you want to move the screen window horizontally by using DIWSTRT and STOP, it may occur that the difference between DIWSTRT and
DDFSTRT is not exacdy 8.5 bus cycles (17 pixels), since DFFSTRT can 

only be set in steps of eight bus cycles. In such a  case, a  part of the first data word would disappear into the invisible area to the left of the screen window. To prevent this, it is possible to shift the data to the right before sending it to the screen, so that it matches the start of the screen window. The section on scrolling explains how this is done.

Setting bit-map addresses 

The values in DDFSTRT and DDFSTOP determine how many data words are displayed per line. The start address must now be set for each bit-map so that the DMA controller can find pixel data. Twelve registers contain these addresses. A  pair of registers, BPLxPTH and BPLxPTL, is used for each bit-plane. Together they are referred to as simply BPLxPT (Bit- plane x  Pointer).

Addr. 

Name 

Function 

$0E0 

BPL1PTH 

Start address of 

Bits 16-20 

$0E2 

BPL1PTL 

bit-plane 1

Bits 0-15 

$0E4 

BPL2PTH 

Start address of 

Bits 16-20 

$0E6 

BPL2PTL 

bit-plane 2

Bits 0-15 

$0E8 

BPL3PTH 

Start address of 

Bits 16-20 

$OEA 

BPL3PTL 

bit-plane 3

Bits 0-15 

$OEC 

BPL4PTH 

Start address of 

Bits 16-20 

$OEE 

BPL4PTL 

bit-plane 4

Bits 0-15 

$0F0 

BPL5PTH 

Start address of 

Bits 16-20 

$0F2 

BPL5PTL 

bit-plane 5

Bits 0-15 

$0F4 

BPL6PTH 

Start address of 

Bits 16-20 

$0F6 

BPL6PTL 

bit-plane 6

Bits 0-15 

The DMA controller does the following when displaying a  bit-plane: The bit-plane DMA remains inactive until the first line of the screen window is reached (DIWSTRT). Now it gets the data words from the various bit- planes at the column stored in DFFSTRT. It uses BPLxPT as a  pointer to the data in the chip RAM. After each data word is read, BPLxPT is incremented by one word. The words read go to the BPLxDAT registers. These registers are used only by the DMA channel. When all six
BPLxDAT registers have been provided with the corresponding data 

words from the bit-planes, the data goes bit by bit to the video logic in
Denise, which selects one of the 4096 colors, depending on the color 

mode chosen, and then outputs this to the screen. When DFFSTOP is reached, the bit-plane DMA pauses until DFFSTRT for the next line, then the process is repeated until the last line of the screen window (DIWSTOP) is displayed. The BPLxPT now points to the first word after the bit-plane. But since the BPLxPT should point to the first word in the bit-plane by the next picture, it must be set back to this value. The Copper takes care of this quickly and easily. A  simple Copper list for a  playfield with four bit- planes looks like this:

AddrPlanexH =  Address of bitplane x, 

AddrPlanexL =  Address of bitplane x, 

MOVE #AddrPlanelH,BPLlPTH 

MOVE #AddrPlanelL,BPLlPTL 

MOVE #AddrPlane2H,BPL2PTH 

MOVE #AddrPlane2L,BPL2PTL 

MOVE #AddrPlane3H,BPL3PTH 

MOVE #AddrPlane3L,BPL3PTL 

bits 16-20 bits 0-15 initialize pointer to bitplane initialize pointer to bitplane initialize pointer to bitplane

MOVE #AddrPlane4H,BPL4PTH 

MOVE #AddrPlane4L, BPL4PTL 

WAIT ($FF,$FE) 

initialize pointer to bitplane 4

End of Copper list (wait for 

.•impossible screen position) 

Resetting the BPLxPT is absolutely necessary. If you don't use a  Copper 

list, this must be done by the processor in the vertical blanking interrupt.

Scrolling and extra-large playfields 

The previous playfields were always the same size as the screen. However, it would often be useful to have a  large playfield in memory, not all of which is visible on the screen at one time, but which can be smoothly scrolled in all directions. This is easily done on the Amiga. The following sections illustrate this in both the X  and Y  directions.

Bit-plane 

- Width :40 words height: 400 lines 

n n+2 n+4 n+78 n+80 n+82 n+84 n+158 n+160 n+162 n+164 n+166 S                              |n+202 n+238

BPL*PT=n+164 

Modulo=40 bytes (20 words) 

Visible screen area: 

Width :20 words height: 200 lines 

BPL*PT+80 

moves the visible screen area 1  line down n+16080|n+16082 n+16084| |n+16122| A scroll value from 0  to 1 5 moves the visible screen area 0  to 1 5 pixels to the left

BPL*PT+2 moves the visible screen area 1  word to 

the right n+31920 n+31998 n^Starting address of the bit-plane Total size of bit-plane: 32,000 bytes

Scrolling 

Extra-tall playfields and vertical scrolling 

Vertical scrolling is very easy to do. The necessary bit-planes are placed 

in memory as usual, but this time they contain more lines than the screen. With a  standard window height of 256 lines, for example, a  double- height playfield is simply 512 lines in memory. In order to move the screen window smoothly over this extra-tall playfield, you change the values of BPLxPT. If you want the screen window to show lines 100 to
356, the BPLxPT pointer must be set to the first word of the 100th line. 

With a  screen width of 320 pixels, each line occupies 20 words (40 bytes) in memory. Multiplying by 100 lines gives an address of 4000.
Add this to the starting address of the playfield, and you have the desired 

value for BPLxPT. To scroll the playfield in the screen window, simply change this value by one or more lines with each picture, depending on the scroll speed desired. Since the BPLxPT can only be changed outside the visible area, a  Copper list is used. You can change the values in the
Copper list, and the Copper automatically writes them to the BPLxPT 

registers at the right time. You just have to be careful not to change the
Copper list while the Copper is accessing its commands. Otherwise the 

processor might change one word of the address while the Copper is reading it and the Copper gets the wrong address.

Extra-wide playfields and horizontal scrolling 

Special registers exist for horizontal scrolling and extra-wide playfields 

(all write-only): 

$108 BPL1MOD Modulo value for the odd bit-planes 

$10A BPL2MOD Modulo value for the even bit-planes 

BPLCON1 $102 

Bit no: 15-8 7  6 5  4 3  2 1  0 

Function: Unused P2H3 P2H2 P2H1 P2H0 P1H3 P1H2 P1H1 P1H0 

P1 HO -  P1 H3 Position of the even planes (four bits) 

P2H0 -  P2H3 Position of the odd planes (four bits) 

The modulo values from the BPLxMOD registers allow (so to speak) rectangular memory areas. This principle is used often in the Amiga hardware. Inside a  large memory area, which is divided into rows and columns, a  smaller area of specified height and width can be defined.
Let's say that the large memory area, in this case our playfield, is 640 

pixels wide and 256 high. This gives us 256 lines of 40 words (80 bytes) each. The smaller area corresponds to the screen window and has the normal size of 320 x  200 pixels, or only 20 words per line. The problem is that when a  line is output, BPLxPT is incremented by 20 words. But in order to get the next line of your playfield, it must be incremented by 40 words. After each line, another 20 words must be added to BPLxPT. The

Amiga can take care of this automatically. The difference between the 

two different line lengths is written into the modulo-register. After a  line is output, this value is automatically added to the BPLxPT.

Width of playfield: 80 bytes (40 words). 

• Width of screen window: 40 bytes (20 words). 

• Modulo value needed: 40 bytes (The modulo value must always be 

an even number of bytes).

• Start =  start address of the first line of the playfield. 

Output of the 1st line: 

Word: 0  1 2  3 ... 19 

BPLxPT: Start Start+2 Start+4 Start+6 ... Start+38 

After the last word is output, BPLxPT is incremented by 1  word:

BPLxPT =  Start+4 0 

After the end of the line, the modulo value is added to BPLxPT:

BPLxPT =  BPLxPT +  modulo BPLxPT =  Start+40 +  40 =  Start+80 

Output of the 2nd line: 

Word: 0  12 3  ... 19 

BPLxPT: Start+80 Start+82 Start+84 Start+86 ... Start+118 

This example shows the left half of the large bit-map being displayed in the screen window. To start at a  different horizontal position, simply add the desired number of words to the start value of BPLxPT and keep the modulo value the same. The initial values are as previously shown. The only difference is that
BPLxPT is not at Start, but at Start+40, so the right half of the large 

playfield is displayed.

Output of the 1st line: 

Word: 0  1 2  3 ... 19 

BPLxPT: Start+40 Start+42 Start+44 Start+46 ... Start+78 

After the last word is output:

BPLxPT =  Start+80 

Now the modulo value is added to BPLxPT:

BPLxPT =  BPLxPT+modulo BPLxPT =  Start+80 +  40 =  Start+120 

Output of the 2nd line: 

Word: 0  1 2  3 ... 19 

BPLxPT: Start+120 Start+122 Start+124 Start+126 ... Start+158 

Separate modulo values can be set for the odd and even bit-planes. This 

allows two different sized playfields in the dual-playfield mode. If this mode is not being used, set both BPLxMOD registers to the same modulo value. The screen can be moved horizontally in steps of 16 pixels with the
BPLxPT and BPLxMOD registers. Fine scrolling in single pixel steps is 

possible with the BPLCON1 register. The lower four bits contain the scroll value for the even planes, bits 4  to 7  for the odd planes. This scroll value delays the output of the pixel data read for the corresponding planes. If it is zero, the data is output exactly 8.5 (in hi-res, 4.5) bus cycles after the DDFSTRT position otherwise it appears up to 15 pixels later, depending on the scroll value. So, the picture is shifted to the right within the screen window by the value in BPLCON1.

Smooth scrolling of the screen contents to the right can be accomplished 

by incrementing the value of BPLCON1 from 0  to 15 and then setting it back to 0  while decrementing the BPLxPT by one word as previously described.

Left scrolling can be accomplished by decrementing the scroll value from 

15 to 0  and then incrementing BPLxPT by one word. BPLCON1 should 

be changed only outside the visible area. This can be done during the vertical blanking interrupt or the Copper can be used. The value in the
Copper list can be changed at any time and will be written to the 

BPLCON1 register during the vertical blanking gap. 

When the BPLCON1 value is used to shift the picture to the right, excess pixels on the left are correctly eliminated from view, but no new ones can appear on the right until new pixel data has been read. To do this, the
DDFSTRT value must be set ahead of its normal start by 8  bus cycles (4 

cycles in hi-res). The DDFSTRT value is calculated as usual from the desired screen window and then decremented by 8  (or 4). From the normal DDFSTRT value of $38 we get $30 (sprite 7  is lost). The extra word read is normally not visible. But when the scroll value is other than zero, its pixels appear in the free positions at the left edge of the screen window. If the window is 320 pixels wide, 21, instead of the usual 20, data words are now read per line. This must be considered when calculating the bit-planes and modulo values. The screen window can also be placed at any desired horizontal position by using the scroll value. If the difference between DIWSTRT and
DFFSTRT is more than 17 pixels, you simply shift the read data to the 

right by the amount over 17. The interlace mode Although the interlace mode doubles the number of displayable lines, its programming technique differs from that of the normal display mode only by a  different modulo value and a  new Copper list. As explained earlier, in interlace mode the odd and even lines are displayed in alternate pictures. To allow an interlace playfield to be represented normally in memory, the modulo value is set equal to the number of words per line. After a  line is output, the length of a  line is added again to BPLxPT, which amounts to skipping over the next line. In each picture only every other line is displayed. Now the BPLxPT only needs to be set to the first or second line of the playfield, depending on the frame type, so that only the even or the odd lines will be shown. In a  long frame BPLxPT is set to line 1  (odd lines only) in a  short frame it is set to line 2  (even lines only). The Copper list for an interlace playfield is somewhat more complicated, because two lists are needed. There is one for each frame type, so for each picture, we alternate between them:

/. The A3000 Hardware 

Copper list for an interlaced playfield: 

Linel =  address of first line of bitplane. 

Line2 =  address of second line of bitplane. 

Copper 1: 

MOVE #LinelHi , BPLxPTH set pointer for BPLxPT to the 

MOVE #LinelLo, BPLxPTL ,-address of the first line 

other Copper commands
MOVE #Copper2Hi , C0P1LCH set address of Copper list 

MOVE #Copper2Lo,C0PlLCL to Copper2 

WAIT ($FF,$FE) end of 1st Copper list 

Copper2: 

MOVE #Line2Hi, BPLxPTH ,-set pointer for BPLxPT to the 

MOVE #Line2Lo, BPLxPTL address of the second line 

other Copper commands
MOVE #CopperlHi,COPlLCH set address of Copper list 

MOVE #CopperlLo,COPlLCL to Copperl 

WAIT ($FF,$FE) end of 2nd Copper list 

The Copper alternates its Copper list after each frame by loading the address of the other list into C0P1LC at the end of a  command list. This address is automatically loaded into the program counter of the Copper at the start of the next frame. The interlace mode should be initialized carefully so that the Copper list for odd lines is actually processed within a long frame:

Set COP 1LC to Copperl . 

Set the LOF-bit (bit 15) in the VPOS register ($2A) to 0. This 

ensures that the first frame, after interlace mode is enabled, is a  long frame and therefore suited to Copperl. The LOF bit is inverted with each frame in interlace mode. If it is set to 0, it changes to 1  at the start of the next frame. The first frame is sure to be a  long frame.

• Interlace mode on. 

• Wait for first line of next picture (line 0). 

• Copper DMA on. 

All other register functions remain unchanged in interlace mode. All line specifications (such as in DIWSTRT) always refer to the line number within the current frame (0 -  3 1 1 for a  short frame and 0  - 312 for a  long frame). If the interlace mode is enabled without changing other registers, a faint flickering is noticeable because the lines of the frames are now displaced from each other, even though both frames contain the same graphics data. When doubly-large bit-planes and the appropriate modulo values are set up with suitable Copper lists so that different data is displayed in each frame, then the desired doubling in the number of lines is noticed. The interlace mode now results in a  stronger flickering since each line is displayed only once every two frames, thus being refreshed 25 times per second. This flickering can be reduced to a  minimum by selecting the lowest possible contrast (intensity difference) between colors displayed. It is more difficult for the human eye to distinguish changes at low contrast. The control registers There are three control registers for activating the various modes:
BPLCON0 to BPLCON2. BPLCON1 contains the scroll value. The other 

two are constructed as follows:

BPLCON0 $100 

Bit no. 

Name 

Function 

HIRES 

High-resolution mode on (HIRES =  1) 

BPU2 

The three BPUx bits comprise a  3-bit number

BPU1 

which contains the number

BPUO 

of bit-planes used (0 to 6).

HOMOD 

Hold-and-modify on (HOMOD =  1) 

DBPLF 

Dual playfield on (DBPLF =  1 ) 

COLOR 

Video output color (COLOR =  1) 

GAUD 

Genlock audio on (GAUD =  1) 

— 

Unused 

SHRES 

Super hi-res on 

5-4 

... 

Unused 

LPEN 

Activate lightpen input (LPEN =  1) 

LACE 

Interlace mode on (LACE =  1) 

ERSY 

External synchronization on (ERSY =  1) 

BPLCON30N 

Bit-plane control register 3  on 

HIRES 

The HIRES bit enables the high-resolution display mode (hi-res, 640 pixels/line).

BPL0-BPL2 

These three bits form a  3-bit number which selects the number of active bit-planes. Only values between 0  and 6  are allowed.

HOMOD andDBPLF 

These two bits select the corresponding modes. They cannot both be active at the same time. The extra-half-bright mode is automatically activated when all six bit-planes are enabled and neither HOMOD nor
DBPLF is selected. 

LACE 

When the LACE bit is set, the LOF-frame bit in the VPOS register is inverted at the start of each new frame, causing the desired alternation between long and short frames.

SHRES 

Super-hi-res mode is enabled with this bit. This mode was introduced 

with the new ECS custom chips of the A3000.

COLOR 

The COLOR bit turns the color burst output of Agnus on. Only when
Agnus delivers this color burst signal can the video mixer create a  color 

video signal. Otherwise it is black and white. The RGB output is not affected by this.

ERSY 

The ERSY bit switches the connections for the vertical and horizontal synchronization signals from output to input. This allows the Amiga picture to be synchronized by external signals. The genlock interface uses this bit to be able to mix the Amiga's picture with another video image. The GAUD bit is also provided for the genlock interface.

BPLCON30N 

This activates the new ECS chip's BPLCON3 register.

BPLC0N2 $104 

Bit no.: 15-7 6  5 4  3 2  10 

Function: Gen. PF2PRI PF2P2 PF2P1 PF2P0 PF1P2 PF1P1 PF1P0 

PF2P0-PF2P2 and PF1P0-PF1P2 determine the priority of the sprites in 

relation to the playfields (see the next section).

PF2PRI: If this bit is set, the even planes have priority over (appear 

before) the odd planes. It has a  visible effect only in dual playfield mode.

Activating the screen display 

The upper bits of the BPLCON2 register contain more control bits for genlock use. After alfthe registers have been loaded with the desired values, the DMA channel for the bit-planes must be enabled and, if the Copper is used
(which is normally the case), its DMA channel must also be enabled. The 

following MOVE command accomplishes this by setting the DMAEN,
BPLEN and COPEN bits in the DMA control register DMACON: 

MOVE.W #$8310,$DFF096 

Sample programs 

Program 1: Extra-half-bright demo 

This program creates a  playfield with the standard dimensions 320 by
256 pixels in lo-res mode. Six bit-planes are used so the extra-half-bright 

mode is activated automatically. At the beginning the program allocates the memory needed. Since the addresses of the individual bit-planes are not known until this time, the Copper list is not copied from the program, but created directly in the chip RAM. It contains only the commands for setting the BPLxPT registers. To show you something of the 64 possible colors, the program draws
16x1 6-pixel blocks in all colors at random positions. The VHPOS register 

is used as a  random-number generator.

//. The A3000 Hardware 

*** Demo for the Extra-Half bright -Mode *** 

 CustomChip-Register 

INTENA =  $9A  Interrupt-Enable-Register (write) 

DMACON =  $96 DMA-Control register (write) 

COLOR00 =  $180 Color palette register 0 

VHPOSR =  $6 Ray position (read) 

 Copper Register 

COP1LC =  $80 

COP2LC =  $84 

COPJMP1 =  $88 

COPJMP2 =  $8a 

Address of 1. Copperlist 

/Address of 2. Copperlist 

Jump to Copperlist 1 

Junip to Copperlist 2 

Bitplane Register 

BPLCONO 

= 

$100 

BPLCON1 

= 

$102 

BPLCON2 

= 

$104 

BPL1PTH 

= 

$0E0 

BPL1PTL 

= 

$0E2 

BPL1MOD 

= 

$108 

BPL2MOD 

= 

$10A 

DIWSTRT 

= 

$08E 

DIWSTOP 

= 

$090 

DDFSTRT 

= 

$092 

DDFSTOP 

= 

$094 

Bitplane Control register 0 

1 (Scrollw value) 

2 (SpriteoPlayfield Priority) 

 Number of 1. Bitplane 

Modulo-Value for odd Bit-Planes 

 ModulO -Value for even Bit-Planes 

/Start of the screen windows 

End of the screen windows 

 Bit -Plane DMA Start 

 Bit-Plane DMA Stop 

CIA-A Port register A  (Mouse key) 

CIAAPRA =  $bfe001 

Exec Library Base Offsets 

OpenLibrary =  -30-522 

Forbid =  -30-102
Permit =  -30-108 

AllocMem =  -30-168
FreeMem =  -30-180 

/graphics base 

StartList =  38 

 LibName , Vers ion/al , dO 

ByteSize,Requirements/dO,dl 

MemoryBlock,ByteSize/al,dO 

other Labels

Execbase 

Planesize 

CLsize 

Chip 

Clear 

= 4 

= 40*200 

= 13*4 

= 2 

= Chip+$10000 

Size of Bitplane: 40 Bytes by 200 lines 

The Copperlist with 13 commands

 Chip-RAM request 

clear previous Chip-RAM

*** Initialize programm *** 

Start : 

 Request memory for the Bitplanes 

move.l Execbase, a6 move.l #Planesize*6,dO move.l #clear,dl jsr AllocMem(a6) move .1 dO , Planeadr beq Ende

/Memory size of all Planes 

.-Memory to be with filled with nulls 

 Request memory 

Address of the first memory Plane 

 Error! -> Ende 

Request memory for Copperlist 

moveq #Clsize,d0 Size of the Copperlist moveq ichip, dl jsr AllocMem(a6) move .1 dO , CLadr beq FreePlane

 Build Copperlist 

moveq #5,d4 move .1 dO , aO move.l Planeadr, dl move.w #bpllpth,d3

MakeCL: move.w d3,(a0)+ 

addq.w #2,d3 swap dl move.w dl, (a0)+ move.w d3, (a0)+ addq.w #2,d3 swap dl move.w dl, (a0)+ add.l #planesize,dl dbf d4 , MakeCL

move.l #$fffffffe, (aO) 

 Error! -> Free RAM for Bitplanes 

6 Planes =  6 loops to run through 

Address of the Copperlist to aO 

first Register to d3

BPLxPTH ins RAM 

next Register

 Hi-word of the Plane address in RAM 

BPLxPTL ins RAM 

/next Register 

Lo-word of the Plane address in RAM 

/Address of the next Plane calculated 

/End of Copperlist 

*** Main programm *** 

DMA and Task switching off 

jsr forbid (a6)
lea $dff000,a5 

move.w #$03e0,dmacon(a5) 

Copper initialization 

move.l CLadr,copllc(a5) clr.w copjmpl(a5)

Color table with different color fills 

Value for color register 

first color moveq #31, dO lea color00(a5) ,al moveq #l,dl
SetTab: 

move.w dl, (al)+ mulu #3,dl dbf dO , SetTab

 Color in color register 

/calculate next color 

 Standard value for 

screen window and BitplaneDMA

Playfield initialization 

move.w #$3081,diwstrt(a5) 

move.w #$30cl,diwstop(a5) 

move.w #$0038,ddfstrt(a5) 

move.w #$00d0,ddfstop(a5) 

move.w #%0110001000000000,bplcon0(a5) 6 Bitplanes clr.w bplconl(a5) no Scrolling clr.w bplcon2(a5) .-Priority makes no difference clr.w bpllmod(a5) Modulo for all Planes equals Null clr.w bpl2mod(a5)

DMA on 

move.w #$8380,dmacon(a5) 

Bitplane modification 

moveq #40,d5 clr.l d2

Loop: clr.l dO 

move . w vhposr (a5 ) , dO
and.w #$3ffe,d0 

cmp.w #$2580, dO 

bcs Continue

 Bytes per line 

 Begin with color 0 

,- Random value to dO 

/Unnecessary Bits masked out 

 Large as Plane? 

When not ,  then continue and.w #$lffe,dO else erase upper bit

Continue: move.l Planeadr,a4  Address of the l.Bitplane to a4 

add.l d0,a4  Calculate address of the Blocks moveq #5,d4 /Number for Bitplanes move.l d2,d3  Color in work register

Block: 

clr.l dl lsr #l,d3 negx.w dl moveq #15, dO move .1 a4 , a3 one Bit of color number in X-Flag use dl to adjust X-Flag

16 lines per Block 

 Block address in working register 

Fill: 

move.w dl, (a3) add.l d5,a3 dbf dO,Fill

Word in Bitplane 

compute next line add.l #Planesize,a4 dbf d4, Block next Bitplane addq.b #l,d2 btst #6,ciaapra bne Loop next color mouse key pressed? no -> then continue

*** End programm *** 

/Activate old Copperlist 

move . 1 #GRname , a 1 clr.l dO jsr OpenLibrary (a6) move.l d0,a4 move.l StartList(a4) ,copllc(a5) /Address of Startlist clr.w copjmpl(a5)

Set parameter for OpenLibrary 

.•Graphics Library open 

move.w #$8060,dmacon(a5) 

jsr permit (a6)

Free memory for Copperlist 

reenable DMA

 Task-Switching on 

move .1 CLadr , a 1 moveq #CLsize,dO jsr FreeMem(a6)

Set parameter for FreeMem 

Free memory 

Free memory for Bitplanes 

FreePlane : 

move.l Planeadr.al move.l #Planesize*6,dO jsr FreeMem(a6)

Ende: 

clr.l dO rts

 Program 

end

Variables 

CLadr : dc 

1 0 

Planeadr : dc 

1 0 

/Constants 

GRname: dc.b 

"graphics 

library", 0

 Program end 

end

Program 2: Dual play field &  smooth scrolling 

This program uses several effects at once. First it creates a  dual-playfield screen with one low-resolution bit-plane per playfield. Then it enlarges the screen window so that no borders can be seen. Finally, it scrolls playfield 1  horizontally and playfield 2  vertically. The usual routines for memory allocation and release, etc. are used at the start and end, as in the previous example.

Both playfields are filled with a  checkerboard pattern of 16x16 pixel 

blocks. The main loop of the program, which performs the scrolling, first waits for a line within the vertical blanking gap, in which the operating system has already processed any interrupt routines and the Copper has set the
BPLxPT's. Then it increments the vertical scroll counter, calculates the 

new BPLxPT for playfield 2, and writes it to the Copper list. The horizontal scroll position results from separating the lower four bits of the scroll counter from the rest. The lower four bits are written into the
BPLCON1 register as the scroll value for playfield 1, and the 5th bit is 

used to calculate the new BPLxPT, which is copied to the Copper list.

Both the horizontal and vertical scroll counters are incremented from 0  to 

31 and then reset to 0. This is sufficient for a  smooth scrolling effect, 

since the pattern used for the playfields repeats every 32 pixels.

*** Dual-Playfield &  Scroll Demo *** 

 CustomChip-Register 

INTENA =  $9A  Interrupt-Enable-Register (write) 

INTREQR =  $le  Interrupt-Request-Register (read) 

DMACON =  $96  DMA-Control register (write) 

COLOR00 =  $180 /Color palette register 0 

VPOSR =  $4 half line position (read) 

 Copper Register 

COP1LC =  $80 ,-Address of 1. Copperlist 

COP2LC =  $84 ,-Address of 2. Copperlist 

COPJMP1 =  $88 Jump to Copperlist 1 

COPJMP2 =  $8a Jump to Copperlist 2 

Bitplane Register 

BPLCON0 =  $100 Bitplane control register 0 

BPLCON1 =  $102 1 (Scroll value) 

BPLCON2 =  $104 2 (SpriteoPlayf ield Priority) 

BPL1PTH =  $0E0  Pointer to 1. Bitplane 

BPL1PTL =  $0E2  

BPL1MOD =  $108 Modulo-Value for odd Bit-Planes 

BPL2MOD =  $10A Module-value for even Bit-Planes 

DIWSTRT =  $08E  Start of screen windows 

DIWSTOP =  $090 End of screen windows 

DDFSTRT =  $092  Bit-Plane DMA Start 

DDFSTOP =  $094  Bit-Plane DMA Stop 

CIA-A Port register A  (Mouse key) 

CIAAPRA =  $bfe001 

Exec Library Base Offsets 

OpenLibrary =  -30-522 LibName,Version/al,dO 

Forbid =  -30-102

Permit =  -30-108 

AllocMem =  -30-168 ByteSize,Requirements/dO,dl

FreeMem =  -30-180 MemoryBlock, ByteSize/al.dO 

graphics base

StartList =  38 

,-Misc Labels 

Execbase =  4 

Planesize =  52*345 

Planewidth =  52 

CLsize =  5*4 

Chip =  2 

Clear =  Chip+$10000 

*** Pre-programm *** 

Start : 

/Request memory for Bitplanes 

Size of the Bitplane 

The Copper list contains 5  commands

/request Chip-RAM 

clear previous Chip-RAM move.l Execbase, a6 move.l #Planesize*2,dO move.l #clear,dl jsr AllocMem(a6) move .1 dO , Planeadr beq Ende memory size of the Planes
.•Request memory 

 Error! -> End 

/Request memory for the Copperlist 

moveq #Clsize,dO moveq #chip,dl jsr AllocMem(a6) move .1 dO , CLadr beq FreePlane

 Build Copperlist 

moveq #l,d4 move .1 dO , aO move . 1 Planeadr , dl move . w #bpl lpth , d3

MakeCL: move.w d3, (aO) + 

addq.w #2,d3 swap dl move.w dl, (a0)+ move.w d3, (a0)+ addq.w #2,d3 swap dl

 Error! -> Free memory for the Planes 

two Bitplanes move.w dl, (a0) + add.l #planesize,dl

 Address of the next Plane 

dbf d4,MakeCL

move.l #$fffffffe, (aO) 

*** Main prograram *** 

DMA and Task switching off 

jsr forbid (a6)
lea $dff000,a5 

move.w #$01e0,dmacon(a5) 

End of the Copperlist 

Copper initialization 

move . 1 CLadr , copl lc ( a5 ) clr.w copjmpl(a5)

Playfield initialization 

move.w #0,color00 (a5)

move.w #$0f00,color00+2(a5) 

move.w #$000f ,color00+18(a5) 

move.w #$la64,diwstrt (a5)

move.w #$39dl,diwstop(a5) 

move.w #$0020,ddfstrt(a5) 

move.w #$00d8,ddfstop(a5) 

move.w #%0010011000000000,bplcon0(a5) Dual-Playfield and clr.w bplconl(a5)  Scroll to start on 0 clr.w bplcon2(a5) Playfield 1  or Playfield 2 move.w #4,bpllmod(a5) Modulo on 2  Words move.w #4,bpl2mod(a5)

26,100 

313,465 

read one extra word

,-DMA on 

move.w #$8180,dmacon(a5) 

Bitplanes filled with checker pattern 

move.l planeadr.aO move.w #planesize/2-l,d0 move.w #13*16, dl
move.l #$ffff0000,d2 

move.w dl,d3 fill: move.l d2,(a0)+ subq.w #l,d3 loop value
Height =  16 Lines 

checker pattern bne.s continue swap d2 move.w dl,d3 continue: dbf dO,fill pattern change

Playfields scroll 

clr.l dO clr.l dl move . 1 CLadr , al move . 1 Planeadr , aO

.•vertical Scroll position 

/horizontal Scroll position 

/Address of the Copperlist 

/Address of the first Bitplane 

/Wait on Raster line 16 (for the Exec-Interrupts) 

wait : move . 1 vposr ( a5 ) , d2
and.l #$0001FF00,d2 

cmp.l #$00001000,d2 

bne.s wait

/read Position 

/horizontal Bits masked 

/wait on line 16 

/Playfield 1  vertical scroll 

addq . b

#2,d0 

cmp.w

#$80, dO 

bne.S novover clr.l dO novover move . 1 d0,d2 lsr.w

#2,d2 

mulu

#52, d2 

add.l a0,d2 add.l

#Planesize,d2 

move.w d2,14(al) swap d2 move.w d2,10(al)

/raise vertical Scroll value 

/already 128 (4*32)? 

/Then back to 0 

/copy scroll value 

/copy divided by 4  s 

/Number Bytes per line *  Scroll position 

/plus Address of first Plane 

/plus Plane size 

/give End address for Copperlist 

/Playfield 2  horizontal scroll 

addq . b

#l,dl 

cmp.w

#$80, dl 

bne.S nohover clr.l dl nohover move . 1 dl,d2 lsr.w

move . 1 d2,d3 and.w

#$FFF0,d2 

sub.w d2,d3

/raise horizontal Scroll value 

/already 128 (4*32) 

/then back to 0 

/copy scroll value 

/copy divided by 4 

/copy Scroll position 

/lower 4  Bit masked 

/lower 4  Bit in d3 isolated 

move.w d4,bplconl(a5) last Value in BPLCON1 move.w d3,d4 new scroll value to d4 lsr.w #3,d2 /new Address for Copperlist add.l a0,d2 /calculate move.w d2,6(al) and write in Copperlist swap d2 move.w d2,2 (al) btst #6,ciaapra Mouse key pressed? bne.s wait N0 -> continue

 * *  * Check programm *  * * 

/Activate old Copperlist 

move.l #GRname,al Set parameter for OpenLibrary clr.l dO jsr OpenLibrary (a6) /Graphics Library open move .1 dO , a4 move.l StartList (a4) , copllc(a5) clr.w copjmpl(a5)

move.w #$83e0,dmacon(a5) 

jsr permit (a6) /Task-Switching permitted

/Free memory used by Copperlist 

move.l CLadr.al /Set parameter for FreeMem moveq #CLsize,dO jsr FreeMem (a6) /Free memory

/Free memory used by Bitplanes 

FreePlane : 

move . 1 Planeadr , al move.l #Planesize*2,dO jsr FreeMem (a6)

Ende: 

clr.l dO rts /Program ends

/Variables 

CLadr: del 0 

Planeadr : dc . 1 0 

test: del 0

/Constants 

GRname: dc.b "graphics. library" , 0 

end
.•Program end 

