# Hardware Fundamentals

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 11.7.2 Fundamentals

As mentioned in the previous section, there are some registers that are accessed by the processor and some that are read and written via DMA.
We'll begin by discussing the former. 

Programming the chip registers 

The chip registers can be addressed directly (e.g., changing the value of the background color register). The register has the name COLOR00.
Looking in the register table, you see that it has a  register address of 

$180. 

So, we must add the base address of the register area (i.e., the address of 

the first register in the address range that the 68030 accesses). This is
$DFF000. Also, the register address of COLOROO yields $DFF180. A 

simple MOVE.W command can be used to initialize the register:

MOVE.W #value,$DFF180 /value in COLOROO 

If more than one register is accessed, it is a  good idea to store the base address in an address register and use indirect addressing with an offset. Here is an example:

LEA $DFF000,A5  store base address in A5 

MOVE.W #valuel,$180(A5) valuel in COLOROO 

MOVE.W #value2,$182(A5) value2 in COLOR01 

MOVE.W .. . etc. 

Normally the chip registers are accessed as previously shown. However, 

the registers can also be accessed as a  long word. In this case two registers are always written at once. This makes sense for the address registers, which consist of a  pair of registers holding a  single 21 -bit address, with which the entire 2048K chip RAM area can be accessed. All data for the custom chips must be in the chip RAM. Since the chips always address the memory word-wise, the lowest bit (bit 0) is irrelevant. The address register points only to even addresses. Since a  chip register is only one word (16 bits) wide, two successive registers are used to store the 21-bit memory address. The first register contains the upper 5  bits
(bits 16-20) and the second contains the lower 16 (bits 0-15). This makes 

it possible to initialize both registers with a  single long-word access.
Example: Setting the pointer for the first bit-plane to address $40000. 

BPL1PTH is the name of the first register (bits 16-20) and BPL1PTL (bits 

0-15) is the name of the second. Register address of BPL1PTH: $0E0, 

BPL1PTL =  $0E2. 

A5 contains the base address $DFF000. 

MOVE.L #$40000, $0E0(A5)  initializes BPL1PTH and BPL1PTL with the correct values.

Any given register address can never be both read from and written to. 

Most registers are write-only registers and cannot be read. This also 

includes the registers previously mentioned. Others can only be read.
Only a  few can be read and written, but these have two different register 

addresses, one for reading and one for writing. The DMA control register, which will be discussed in detail later, is such a  register. It can be written through the register address $096 (DMACON), while address $002 is used for reading (DMACONR).

DMA access 

DMA involves the direct access of a  special component, called the DMA 

controller, to the system memory. In the case of the Amiga, the DMA controller is housed in Agnus. It represents the connection between the various input/output components of the custom chips and the chip
RAM. The DMA process follows the same pattern regardless of whether 

diskette, screen or audio data is involved. A  given I/O component, such as the disk controller, needs new data or has data that it wants to store in memory. The DMA controller waits until the memory for this channel is free (not being accessed by another DMA channel or the processor) and then transfers the data to or from RAM itself. For the sake of simplicity

//. The A3000 Hardware 

there is no special transfer of the data from the I/O device to the DMA controller. It always takes place through registers. Each of these I/O components has two different types of registers. One type is the normal registers which are accessed by the processor and in which the various operating parameters are stored. The second is the data registers that contain the data for the DMA controller. For a  DMA transfer this involves simply the corresponding data register and a  RAM location.
Depending on the direction of the transfer, either a  read register is 

selected and the chip RAM is set for write, or a  write register is used and the chip RAM is set for read. Since the two can be connected through the data bus, the data are automatically routed to their destination. Data are not stored in any temporary registers. The DMA transfer adds a  third type of register: the DMA address register which holds the address or addresses of the data in RAM, depending on the needs of the I/O device. There are many central control registers that are not assigned to a  special
I/O device, but have higher-level control functions. The DMACON 

register belongs in this category. The data registers can also be written by the processor, since they are realized in the form of normal registers. However, this is not generally useful, since the DMA controller can accomplish this more quickly and efficiently.

Some I/O components do not have DMA channels. The 68030 must read 

and write their data itself. This group includes only those devices which by their nature do not deal with large quantities of data, so that DMA is not needed, such as the joystick and mouse inputs. The following DMA channels are present:

Bit-plane DMA Through this DMA channel the screen data are read 

from memory and written into the data registers of the individual bit-planes. From there they go to the bit- plane sequencers, which convert the data for output to the screen.

Sprite DMA Transfers the sprite data from the RAM to the sprite 

data registers.

Disk DMA 

Transfers data from disk to RAM or from RAM to disk. 

Audio DMA Reads digital sound data from RAM and writes it to the 

appropriate audio data registers.

Copper DMA The coprocessor (Copper) receives its command words 

through this channel.

Blitter DMA Transfers data from and to the Blitter. 

There are a  total of six DMA channels which all want to access the memory, and the processor, which naturally also wants to have the chip
RAM for itself as often as possible. To solve the problems that result from 

this, a  complex system of time multiplexing was devised in which the individual channels have defined positions. Since this is oriented to the video picture, first we must briefly discuss its construction. This section has been kept as simple as possible, since we are discussing the programming of the custom chips and not the hardware.

Construction of the video picture 

First half 

screen's lines (all odd-numbered lines are in long frame)

Complete screen 

Second half 

screen's lines (all even-numbered lines are in short frame)

Construction of the picture 

The timing of the Amiga screen output corresponds exactly to the standard of the country where the Amiga is sold, PAL for Europe and
NTSC for the US. The 8361 Agnus chip is available in an NTSC US 

version and a  PAL version for Europe. A  PAL video picture consists of
625 horizontal lines, an NTSC picture of 525 horizontal lines. Each of 

these lines is constructed from left to right. A  pause follows every line, called the horizontal blanking gap, in which the electron beam that draws the picture has time to go back from right to left. During this blanking gap the electron beam is dark so that it cannot be seen tracing back to the left side. Then the process starts over again and the next line appears. To keep the picture free of flickering, it must be continually redrawn. Since our eyes cannot discern changes above a  certain frequency, the number of pictures per second is placed above this limit. With the PAL standard, the number of individual pictures is set to 50 per second (30 per second for NTSC). But now we encounter a  problem. If all 625 lines were drawn 50 times per second, the result would be 31250 lines per second. If monitors and televisions were built to these specifications, they would not be affordably priced, so a  trick is used. On one hand, the number of pictures should not be less than 50 per second or the screen begins to flicker, while on the other hand there must be enough lines per picture. The solution is as follows: 50 pictures are displayed per second, but the 625 lines are divided into two pictures. The first picture contains all the odd lines (1,3,5...625), while the second contains all the even lines
(2,4,6...624). Two of these half-pictures (called frames) are combined to 

form the entire picture, which contains 625 lines. Naturally, the number of complete pictures per second is only half as large as the number of half-pictures, or 25 per second. The line frequency for this technique is only 15625 Hz (25x625 or 50x312.5). In spite of the high resolution of 625 lines, flickering occurs when a contour is restricted to only one line. Then it is displayed only every 25th of a  second, which is perceived by the eye as a  visible flickering. This effect can be seen on televisions (especially on the horizontal edges of surfaces), since these consist of only a  single horizontal line. The term for this technique of alternating display of even and odd lines is interlacing. Two additional terms are used to distinguish the difference between the two types of half -pictures. A  long frame is the one in which the odd lines are displayed, and the other is called a  short frame. They are called long and short frames because there is one more odd line than even and it takes slighdy longer to display the frame containing the extra line (from 1  to 625 there are 313 odd and 312 even numbers). After each frame there is a  pause before the next frame begins. This blank space between frames is called the vertical blanking gap. The picture created by the Amiga also follows this scheme, although with some deviations.

Normally the second half-picture (short frame) is somewhat delayed so 

that the even lines appear exactly between the odd lines. On the Amiga both frames are identical so that the frequency is actually
50 Hz. As a  result, the number of lines is limited to 313. This can be 

clearly seen by the vertical distance between two lines on the screen, since the frames are no longer displaced, but drawn on top of each other. To increase the number of lines, the Amiga can also create its picture in interlace mode. Then a  full 625 lines are possible on PAL systems, but the disadvantages of interlace operation must be considered. More about this later.

Construction of the Amiga screen output 

Bit-planes 

The Amiga always displays its picture in a  type of graphic mode (i.e., each point on the screen has a  corresponding representation in memory). The simplest way to build a  screen image in memory is to define a contiguous block of RAM in which a  set bit corresponds to a  point
(pixel) displayed on the monitor. This basic construction is called a 

bit-plane and is the fundamental element of all screen display in the
Amiga. A  single line on the screen will consist of a  certain number of 

words determined by the width of the picture. Since each bit represents one pixel, a  word comprises 16 pixels. For a  screen display of 320 pixels per line, 20 (320/16) words per line are needed. In a  single bit-plane, only one of two possible conditions can exist for a given bit position. The bit is either set or cleared. However, by combining several bit-planes, the possibilities are greatly expanded. The planes can be logically superimposed so that those bits having the same position within their respective planes are considered as a  unit. The first pixel on the screen is the result of combining the first bit of the first word of all the bit-planes. The value of the bit combination determines the color of the pixel on the screen. There are various ways of deriving colors from bit combinations, and we'll discuss these in more detail later.

Bit-plane structure :  320x200 pixels :  restarting address 

Column o                            16 32 •  • •           304 

Row n  + O                       n +  2 n  + 4                               n +  38

1st word 

| 2nd word 

| 3rd word 

...| 

20th word 

n +  40 n+42 n+44 n +  78

21st word j  | 22nd word 

23rd word 

• •  • 

40th word 

• 

• 

• 

• a                                      • 

• •                                      • 

• •                                      • 

n+7960 n+7962 n+7964

• •  • 

• •  • 

• •  • 

• 

• 

« 

n+7998

3980th word 

3981st word 

3982nd word 

• •  • 

4000th word 

IS 

I3|l2|l1 

9 |8 |7 |6 [5 

4 |3 |2 1 

u//

TT T i i  1 r 1 1  1 1  i i  i i  j 

Representation of bit-plane's first word in the upper-left 

corner of the visible screen

Bit-plane construction 

Different graphic resolutions 

The Amiga recognizes three different horizontal resolutions. The high resolution mode normally has 640 pixels per line, the low resolution has
320. The A3000's new Denise even permits a  1280 pixel-per-line display 

called super hi-res mode. The word "normally" means that this value can change. It is better to define the different resolutions in terms of time per pixel. A  pixel in super hi-res mode is displayed for 35 nanoseconds, in normal hi-res mode for 70 nanoseconds and in low-resolution mode for
140 nanoseconds. Comparing lo-res to hi-res, the electron beam traces 

across the screen for twice the time to produce a  single pixel. In this time it covers twice the distance, producing a  pixel that appears twice as wide in low as in high resolution.

What is more important for the programmer to know, however, is that in 

high-resolution mode only four bit-planes can be active at a  time, while in low-resolution mode up to six planes are allowed. In super hi-res mode only two bit-planes may be used. Furthermore, a  limitation of 64 colors is imposed on the color palette. This is a  consequence not of higher pixel frequency, but of certain limitations in the chip design.

Construction of a  horizontal raster line 

A raster line is a  complete horizontal line, including both the horizontal blanking gap and the visible region. This raster line serves as a  timing measure for all DMA processes, particularly for screen-associated DMAs. To understand the division of the raster line, you must know how memory access to chip RAM and the custom chip registers is distributed between the DMA controller and the processor. Accesses to these two storage areas must conform to what are called bus cycles. The bus cycles determine the timing of the chip RAM. One memory access can take place in each bus cycle. It doesn't matter whether the data is read or written. For example, if the processor wants to access the bus it gets control of the bus for one bus cycle. The DMA controller cannot access RAM again until the following cycle. A  bus cycle lasts 280 nanoseconds.
Almost four memory accesses are possible in one microsecond. 

For compatibility reasons, processor accesses to chip memory are executed according to the same scheme as in 68000-based Amiga models. This requires the 68030 to constantly insert wait states, so that the result is a  maximum of one access every 560 nanoseconds. During this time two bus cycles elapse. The 68030 can use every other bus cycle. These cycles are called even cycles. The remaining cycles, the odd cycles, are reserved exclusively for the DMA controller.

$o 

$8 

$10 

$18 

$20 

Refresh 

$28 

£3 

Disk DMA Audio DMA 

Earliest possible starting 

time for bit-plane DMAs

$30 

Data fetch start 

$38 

$40 

$48 

IL 

4 6 

LLL 

LL 

3 5 

16 low-res 

pixels

$C4 $C8 

IL 

t 6

HHt 

LL 

3 5 

16hi-res 

pixels

Data fetch stop 

$D0 

LL 

V i  H P  h b 

LL 

L|- 

HH 

HHHh r 

H| 

2|1 

$D8 

$DF 

Bus cycle up to 

$D8 is the same 

as $40-$47

3 5 

LL 

LL 

HH 

LL 

HHH 

21 X 

LL 

LL 

HH 

LL 

HH 

4 32 

HH 

LL 

LL 

Latest possible end of 

bit-plane DMAs

Legend: 

R =  Refresh cycles 

D =  Disk DMA cycles 

Ax=Audio DMA cycles, x=channel number 

Sx=Sprite DMA cycles, x=sprite number 

Lx=Low-res bit-plane DMA cycles, x=bit-plane number 

Hx=High-res bit-plane DMA cycles, x=bit-plane number 

fl

=Even bus cycles (processor or DMA) |    =Odd bus cycles (DMA only) 

Raster timing 

The figure shows the development of a  raster line over time. It takes 63.5 microseconds. This yields 227.5 bus cycles per line. Of these the first 225 can be taken by the DMA controller. The figure shows how this is done: The letters within the individual cycles represent the corresponding

DMA channels. While the DMA controller has exclusive use of the odd 

cycles, it must share the even ones with the processor. Still, DMA access always takes priority. Blitter DMA and Copper DMA always take place during even cycles. There is no defined time for these two, but once
Copper DMA access begins, it takes all the even cycles until it has 

finished its task. It has precedence over the Blitter. When the Blitter gains access, it also takes all the even cycles until it is finished. Some cycles can still be left free for the 68030. As you can see, disk, audio and sprite DMA accesses take only odd bus cycles and do not affect the speed of the processor. The four cycles designated "R" are refresh cycles. They are used to refresh the contents of the chip RAM (see the end of this section). The distribution of the bit-plane DMA is more complicated. For the first
16 pixels to be displayed on the screen, all the bit-planes must be read. 

While these 16 pixels are appearing on the screen, the bit-planes for the next 16 pixels must be read. If the lowest resolution is enabled, two pixels are output during each bus cycle. This means that the bit-planes must be read every eight bus cycles. As long as no more than four bit- planes are active, the odd cycles suffice. If five or six planes are used, two even cycles must also be used so that all the data can be read within the eight bus cycles. It's even tighter in high-resolution mode. Here four pixels are displayed per bus cycle. If only odd cycles are to be taken, no more than two hi-res planes can be active. With the maximum allowable number of four hi-res planes, all bus cycles are taken. As a result, the processor loses more than half of its free bus cycles. Its speed also decreases by the same amount, assuming that the current program is in the chip RAM, since the processor still has full- speed access to any fast RAM and to the Kickstart ROM. The times labeled as data fetch start and data fetch stop designate the start and stop of the DMA accesses for the bit-planes. They determine the width and horizontal position of the visible picture. If the bit-plane DMA starts early and ends late, more data words are read and more pixels are displayed. The normal resolution of 320 or

640 pixels per line can be varied by changing these values. If 

the data fetch start is set below $30, the bit-plane DMA channel uses cycles normally reserved for sprite DMA. Depending on the exact value of data fetch start, up to seven sprites may be lost this way.

Only sprite 0, which is generally used for the mouse pointer, 

cannot be turned off in this manner. The top line in the figure represents the division of the DMA cycles for a low-resolution screen with the normal width of 320 pixels. The start of the bit-plane DMA, data fetch start, is at $38, and the end, data fetch stop, is at $D0. The data from bit-plane number 1  is read in the cycles designated LI, the bit-plane 2  data in L2, and so on. If the corresponding bit-planes are not enabled, their DMA cycles are also omitted. The second line represents the course of a  raster line in which the data fetch points are moved outward. Up to the data fetch start everything is the same as the top line, but here the DMA starts at $28. As a  result, sprites 5  to 7  are lost. The data fetch stop position is moved to the right to the maximum value of $D8. The third line shows the distribution of the DMA cycles in a  high- resolution screen where the data fetch values match those of the first line.

No bit-plane DMA accesses occur during the vertical blanking gap. 

The DMA control register The individual DMA channels are enabled and disabled through a  central
DMA control register, DMACON. 

The DMACON register addresses are $096 (write) and $02 (read)

Bit 

Name 

Function (when set) 

SET/CLR 

Set/clear bits 

BBUSY 

Blitter busy (read only) 

BZERO 

Result of all Blitter operations is 0  (read only) 

12 and 11 

Unused 

BLTPRI 

Blitter DMA has priority over processor 

DMAEN 

Enable all DMA (for bits 0  to 8) 

BPLEN 

Enable bit-plane DMA 

COPEN 

Enable Copper DMA 

BLTEN 

Enable Blitter DMA 

SPREN 

Enable sprite DMA 

DSKEN 

Enable disk DMA 

3-0 

AUDxEN 

Enable audio DMA for sound channel x  (bit 

number corresponds to number of sound channel) The DMACON register is not written like a  normal register. You can only set or clear bits. This is determined by bit 15 of the data word written to the DMACON register. If this bit is 1, all the bits that are set in the data word are also set in the DMACON register. If bit 15 is 0, all the bits that are set in the data word are cleared in the DMACON register. The remaining bits in DMACON remain unaffected.

Bit 9, designated DMAEN, is something of a  main switch. If it is 0, all 

DMA channels are inactive, regardless of bits 0  to 8. To enable DMA you 

must set both the appropriate DMA channel bit and the DMAEN bit. Here is an example:

Only the bit-plane DMA is enabled (BPLEN =1), but without the 

DMAEN bit. The value of the DMACON register is $0100. Now you 

want to enable the disk DMA. DSKEN and DMAEN must be set and
BPLEN cleared. 

MOVE.W #$0100,$DFF096 ,-Clears the BPLEN bit (SET/CLR =  0) 

MOVE.W #$8210,$DFF096 Sets DSKEN and DMAEN (SET/CLR =  1) 

The DMACON register now contains the desired value of $0210. Bits 13 and 14 can only be read. They supply information about the status of the
Blitter, which is discussed in more detail in the Blitter section. 

Bit 10 controls the priority of the Blitter over the processor. If it is set, the
Blitter has absolute priority over the 68030. This may go so far as to 

deny the processor all access to the chip registers and chip RAM throughout the entire Blitter operation. When it is cleared, the processor gets every fourth even bus cycle from the Blitter. This prevents the processor from being held up when an operating system routine or a program in fast RAM, both of which execute at full speed, must access chip RAM, for example, to get an operating system data structure or a
68030 exception vector. 

Reading the current electron beam position 

Since all DMA timing is oriented according to the position within a  raster line, it is sometimes useful to know where on the line the electron beam is currently located. Agnus has an internal counter for this, which contains both the horizontal and vertical screen position. Two registers allow the processor access to this counter:

VHPOS $006 (read, VHPOSR) and $02C (write, VHPOSW) 

Bit no.: 15 14 13 12 11 10 9       8 7       6 5       4 3       2 1       0 

Function: V7 V6 V5 V4 V3 V2 V1 V0 H8 H7 H6 H5 H4 H3 H2 H1 

VPOS $004 (read, VPOSR) and$02A (write, VPOSW) 

Bit no.: 15 14 13 12 11 10 9 

Function: LOF 

2 1       0 

V10V9 V8 

The bits designated HI to H8 represent the horizontal beam position and correspond directly to the numbers for the individual bus cycles in the figure. They have a  precision of two low or four high-resolution pixels. The value for the horizontal position can vary between $0 and $E3 (0 to
227). The horizontal blanking gap falls in the range from $F to $35. 

The bits for the vertical position, the current screen line, span both registers. The lower bits, V0-V7, are in VHPOS, and the upper bits, V8-
V10, are in VPOS. Together they yield the number of the current screen 

line.

Lines from 0  to 312 are possible. The vertical blanking gap (the screen is 

always dark in this range) runs from line 0  to line 25. The LOF (LOng
Frame) bit indicates whether the image currently being displayed is a 

long (odd lines) or short (even lines) frame. This bit is needed only in interlace mode. Normally it is 1. The beam position can also be set, but this capability is rarely needed. The POS registers have another function in connection with a  light pen. When the lightpen input of Agnus is activated and the lightpen is held against the screen, they store its position. This means that their contents are frozen as soon as the lightpen detects the electron beam moving past its tip. The counters are released again at the end of the vertical blanking gap, line 26. To read the lightpen position, you must proceed as follows:

• Wait for line 0  (start of the vertical blanking gap). This is most easily 

done by means of the vertical blanking interrupt (see next section).

• Read the two counter registers. 

If the vertical position is between 0  and 25 (within the vertical blanking gap), no lightpen signal was received. If the value is outside this range, it represents the position of the lightpen. To conclude this section, here are some more details about the refresh cycles:

Agnus possesses an integrated 9-bit refresh counter. It can be written 

through register address $28 (be careful because the memory contents can be lost this way). At the start of each raster line, Agnus places four refresh addresses on the chip RAM address bus. This means the contents of each memory row are refreshed every four milliseconds. While the row address is being output on the chip RAM address bus,
Agnus places the addresses of certain strobe registers on the register 

address bus. These strobe signals serve to inform the other chips, Denise and Paula, of the start of a  raster line or a  picture. This is necessary because the counter for the screen position is inside Agnus and there are no lines for transmitting the synchronization signals to the other chips. There are four strobe addresses:

Addr. 

Chip 

Function 

$38 

D 

Vertical blanking gap of a  short frame 

$3A 

D 

Vertical blanking gap 

$3C 

DP 

This strobe address is created in every raster line outside the vertical blanking gap

$3E 

D 

Marker for a  long raster line (228 cycles) 

During the first refresh cycle, one of the first three strobe addresses is 

always referenced. Normally this is $3C, and within the vertical blanking gap $38 or $3A, depending on whether it is a  short or long frame. With the fourth address the situation is as follows: A  raster line has a purely computational length of 227.5 bus cycles. But since there are no half-cycles, lines alternate between 227 and 228 bus cycles. The strobe address $3E signals the 228-cycle lines and is created during the second refresh cycle.
