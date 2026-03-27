# The Blitter

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 11.7.8 The Blitter

What is a  Blitter? The name Blitter stands for "block image transferor.
This is the main task of the Blitter: moving and copying data blocks in memory this usually involves graphics data. The Blitter can also perform logical operations on multiple memory areas and write the result back into memory. It accomplishes these tasks very quickly. Simple data moves proceed at speeds of up to 16 million pixels per second. In addition, the Blitter can fill surfaces and draw lines. The combination of these two capabilities enables the drawing of any type of filled polygon. The operating system uses the Blitter for almost all graphic operations. It handles the text output, draws gadgets, moves windows, etc. In addition, it is used to decode data from the diskette, which shows that the many- faceted capabilities of the Blitter are not limited to graphics.

Using the Blitter to copy data 

The Blitter always follows the same procedure when copying data: One to three memory areas and the data sources are combined together using the selected logical operation and the result is written back into memory. The spectrum ranges from simple copying to complex combinations of multiple data areas. The addresses of the source data areas, named A, B and C, and the destination area D  can be anywhere in the chip RAM
(fromOto$lFFFFF). 

The Blitter supports "rectangular memory areas." The memory, like a bit-map, is divided into columns and rows. It is also possible to process small areas inside a  large bit-map by using what are called modulo values.
You may recall that such modulo values are also used in playfields, to 

define bit-planes that are wider than the screen window. The following steps are necessary to start a  Blitter operation:

• Select the Blitter mode: Copy data. 

• Select the source data areas (not all three sources have to be used) 

and the destination area.

• Select the logical operation. 

Define other operating parameters (scrolling, masking, address 

direction).

• Define the window in which the Blitter operation is to take place 

and start the Blitter.

Defining the Blitter window 

You may wonder why we're starting with a  discussion of the last step. 

Actually, the definition of the desired window is the basis of all the other 

settings. But when the Blitter is programmed, this value is not written to the appropriate register until the end, because that is what starts the
Blitter. For that reason, this point also appears last in the previous list. 

However, you must understand the Blitter window concept in order to understand the other values. The Blitter window is the area of memory that is to be processed by the
Blitter operation. It is constructed like a  bit-plane (i.e., divided into rows 

(lines) and columns) where a  column corresponds to one word (two 

bytes). The number of words in the window is equal to the product of the rows and columns: R*C. Since the desired memory area is divided into rows and columns, the
Blitter is very well suited for processing bit-planes. 

However, linear memory areas can also be accessed. The division into rows and columns simply makes the programming easier. Actually, the individual lines reside at contiguous addresses in memory. For small data fields that are not divided into rows and columns, it is also possible to set the window width or height to 1. The Blitter processes the Blitter window line by line. The Blitter operation begins with the first word of the first line and ends with the last word of the last line. The BLTSIZE register contains the window size:

BLTSIZE $058 (write-only) 

Bit no.: 15 14 13 12 11 10 9       8 7       6 5       4 3       2 i 6 — 

Function: H9 H8 H7 H6 H5 H4 H3 H2 H1 HO W5 W4 W3 W2 W1 WO 

H0-H9 These ten bits represent the height of the Blitter window in 

lines. The window can have a  height between 1  and 1024 lines (210 =  1024). A  height of 1024 lines is selected by setting the height value to 0. For all other values the height corresponds directly to the number of lines. A  height of 0 lines is not possible.

WO These six bits represent the width of the window. The 

width can vary between 1  and

-W5 64 words (2^ =  64). In terms of graphic pixels, this can be 

up to 1024 pixels. As with the height, the maximum width is set by making the width value =  0. The following formula is applied to the height and width to derive the necessary BLTSIZE value: BLTSIZE =  Height*64 +  Width. It must be modified somewhat when using the two extremes (Height =
1024 and Width =  64): 

BLTSIZE =  (Height AND $3FF) *64 +  (Width AND $3F) 

The BLTSIZE register should always be the last register initialized. The
Blitter is automatically started when a  value is written to BLTSIZE. 

The Blitter can also process larger windows with the built-in ECS chips of the A3000. For this, the two new registers BLITSIZV and BLITSIZH are used:

BLITSIZV 

BLITSIZH 

$5C 

$5E 

Number of lines in Blitter window (15 bits) 

Number of words per line (1 1 bits), start Blitter 

Since BLITSIZH starts the Blitter, BLITSIZV must be written first.

Source and destination data areas 

During a  Blitter operation, data are combined together from completely 

different areas of memory. Even though the Blitter window defines the number and organization of data words to be processed, the positioning of this window within the three source areas and the destination area must still be specified. For example, suppose that you want the Blitter to copy a  small rectangular graphic, stored somewhere in chip RAM, into the screen

//. The A3000 Hardware 

memory. For this simple task there is only one source area. The selection of the Blitter window is easy. The entire graphic is to be copied, so the width and height of the Blitter window correspond to that of the graphic in memory.

So that the Blitter also knows where this graphic can be found, you write 

the address of the first word of the top line into the appropriate register. But how is the destination area defined? The graphic is to be copied into the screen memory, which means that it must be transferred into the current bit-plane. (For the sake of simplicity, the graphic and the screen memory are each assumed to consist of a  single bit-plane.) But the bit- plane is wider than the small graphic. If the Blitter were to copy the graphic directly into the bit-plane, the result would not appear as desired. In addition to the address of the destination area, the Blitter must also know its width. This information is communicated by a  modulo value. The modulo value is added to the address pointer after each line of the
Blitter window is processed. The words that are not affected are skipped 

and the pointer indicates the start of the next line. The source and destination areas have independent modulo registers so that they can have different widths. The following figure illustrates our example. The graphic consists of five lines, each ten words wide. The numbers represent the corresponding word addresses relative to the initial address of the graphic. The bit-plane has dimensions of ten lines by twenty words. How do we choose the
Blitter window, starting addresses and modulo values? 

The Blitter window must correspond to the graphic, since the latter is to be copied completely. The height of the window is five lines and the width is ten words. The value that must be written to the BLTSIZE
register is 330 (5*64 +  10) or hexadecimal $014A. 

The starting address of the source data is equal to the address of the first word of the graphic. Since the line width of the graphic is equal to the line width of the Blitter window, the modulo value for the source is 0.

Graphic 

00 02 04 06 08 

1012141618 

20 222426 28 

30 32 3436 38 

40 42 444648 

Bit-plane 

186. 

Graphic copied 

into bit-plane

00 02 

20 22 

16 18 

36 38 

40 42 

56 58 

60 62 

76 78 

80 82 

96 98 

100 102 

120 122 

L04 

116 118 

136 138 

i.241

140 142 

152 154 

156 158 

160 162 

172 174 

176 178 

180 182 

192 194 

196 198 

Plane copy principle 

The modulo value must now be calculated for the destination area. To do this, simply take the difference between the actual line width and that of the Blitter window. In our example, this is 20 words minus 10 words: The modulo value for the destination area is 10 words. Modulo values must be specified in bytes in the Blitter modulo registers. Modulo value =  modulo in words *

2. 

Finally, the Blitter needs the starting address of the destination data. This 

determines the bit-plane position to which the graphic is copied, and is equal to the starting address of the bit-plane, and the address of the word at which the upper left corner of the graphic is to be placed. In our figure this is the address of the bit-plane and 24.

How does the Blitter operation proceed? 

After the addresses and modulo values have been defined and the
BLTSIZE initialized, the Blitter begins copying the data. It fetches the 

word at the starting address of the source data and stores it at the destination address. Then it adds one word to both addresses and copies the next word. This is repeated Until the number of words per line set in BLTSIZE have been processed. Before the Blitter continues with the next line, it adds the modulo values to the address pointers so that the next line starts at the right address. After all lines have been copied, the Blitter turns off and waits for its next job. After a  Blitter operation, the address registers contain the address of the last word, 2, and the modulo value. The address registers are called BLTxPT, where x  represents one of the three sources A, B, C  or the destination area D. Like other address registers, they occur in pairs, with one for bits 0-15 and one for bits 16-
20: 

Reg. 

Name 

Function 

BLTCPTH 

Starting address of Bits 16-20 

04A 

BLTCPTL 

source data area C  Bits 0-15

04C 

BLTBPTH 

Starting address of Bits 16-20 

04E 

BLTBPTL 

source data area B  Bits 0-15

BLTAPTH 

Starting address of Bits 16-20 

BLTAPTL 

source data area A  Bits 0-15

BLTDPTH 

Starting address of Bits 16-20 

BLTDPTL 

destination data area D  Bits 0-15 Each of the four areas has its own modulo register:

BLTCMOD 

BLTBMOD 

BLTAMOD 

BLTDMOD 

Modulo value for source C 

Modulo value for source B 

Modulo value for source A 

Modulo value for destination D 

Copying with ascending or descending addresses 

In our example the Blitter worked with ascending addresses (i.e., it started at the starting address and incremented until reaching the ending address). The ending address is logically higher than the starting address. However, there is a  case in which such addressing leads to errors: the copying of a  memory area to a  higher address, where the source and destination areas partially overlap. Here is an example:

Result: 

Address 

Source data 

Destination data 

Desired 

Actual 

Source 1 

Source2 

Source3 

Source4 

Destl 

Sourcel 

Sourcel 

Source5 

Dest2 

Source2 

Source2 

Dest3 

Source3 

Source3 

Dest4 

Source4 

ISourcel ! 

Dest5 

Source5 

!Source2! 

The five source data words are to be written to the address of the destination data. If the Blitter begins by copying Sourcel to the desired destination address (Destl), it overwrites Source4 before the data there can be copied. This is because Source4 and Destl have the same address
(the two areas overlap). The same thing happens with Source5 and 

Dest2. 

When the Blitter reaches the address of Source4, it finds Sourcel instead.
Sourcel (not Source4) ends up in Dest4, and Source2 (not Source5) ends 

up in Dest5. Source4 and Source5 are lost. To solve this problem, the Blitter has a  descending address mode and the ascending mode. In this mode it starts at the addresses in BLTxPT and decrements these values by 2  bytes after each word is copied. Also, the modulo value is subtracted instead of added. The ending address lies before the starting address. This must naturally be considered when initializing the BLTxPTs.
Normally these are set to the upper left corner of the Blitter window in 

the given data area (A, B, C  or D). In descending mode the addressing is backwards. Correspondingly, BPLxPT must point to the lower right corner. The modulo and BLTSIZE values are identical to those for the ascending mode. In general, the following statements can be made regarding mode selection:

1. 

No overlap between source and destination areas: 

Either ascending or descending mode both work correctly in this 

case.

2. Source and destination areas overlap partially, and the destination is 

before the source:

Only ascending mode works correctly. 

3. Source and destination areas overlap partially, and the destination is 

after the source (see example):

Only descending mode works correctly. 

Selecting the logical operations 

As previously mentioned, there are three source data areas associated with the destination area. The logical operations are always performed on a bit basis so that the destination bit D  must be obtained from the data bits A, B  and C. The Blitter recognizes 256 different operations. These take place in two steps:

1. Eight different boolean equations are applied to the three source 

data bits. Each of these yields a  1 from a  different combination of A
BandC. 

2. The eight results of the previous equations are selectively combined 

with a  logical OR. The result is the destination bit D. The term "boolean equation" refers to a  mathematical expression representing a  combination of logical operations. This type of computation is called boolean algebra, after the English mathematician
George Boole (1815 to 1864). The explanations of the logical functions 

of the Blitter can be understood without a  knowledge of boolean algebra, but the boolean equations are nevertheless included. There are eight possible combinations of three bits. Each of the eight equations is true for one of them (its result is 1). By using the eight control bits LFO to LF7 you can select whether the result of the equation has any effect on the formation of D. All result bits whose corresponding

LFx bit is 1  are combined with a  logical OR function. An OR function 

means that the result will be 1  if at least one of the input bits is 1. In other words, a  logical OR returns a  0 only if all inputs are 0. With the eight LFx bits you can choose which combinations of the three input bits A, B  and C  will cause the output bit D  to be 1. The term for the eight boolean input equations is "minterm." The following table gives an overview of the input combinations for each LFx bit. In the Minterm row, a  lowercase letter represents a  logical inversion of the corresponding input bit. Normally this is indicated with a  bar over the letter. The Input bits row contains the bit combination for which the corresponding equation is true. The order of the bits is A  B C.

LF7 

LF6 

LF5 

LF4 

LF3 

LF2 

LF1 

LF0 

Minterm: 

Input bits: 

ABC 

ABc 

AbC 

Abe 

aBC aBc abC abc

Selecting the individual minterms is easy. For each input combination for 

which the output bit D  should be 1, set the corresponding LFx bit. In our first example we simply copy the source data from A  directly to D. The B  and C  sources are not used. Which minterms must be selected for this?

D can be 1  only when A  = 1. Only the upper four terms LF4 to LF7 come 

into play, since A  = 1  only for these terms. Since B  does not play a  role, we choose a  term in which B  is 1  and a  term in which B  is 0, but which are otherwise identical. Now B  has no effect on D  because the remainder of the equation is unchanged for both values of B  and its result depends only on this remainder. The same holds true for C. If we look at the table of input combinations, we see that LF4 to LF7 must be activated. Then the result depends only on A, since for any combination of B  and C, one of these four equations is always true for A  = 1, and D  is 1. If A  = 0, all four are false and D  = 0. If you're familiar with boolean algebra, you can obtain the appropriate minterms yourself. The required expression is A  = D. Since B  and C  are always present in the Blitter, they must be integrated into the equation as well:

|A*(b+B)*(c+C)=D 

The term x+X is always true (equal to 1) and is used when the result D  is independent of the value of X. To get the required minterms simply multiply it out:

1. A*(b+B)*(c+C)=D 

2. (A*b+A*B)*(c+C)=D 

3. A*b*c+A*B*c+A*b*C+A*B *C=D 

or without the AND operators:

Abc+ABc+AbC+ABC=D 

Now we only need to set the LFx bits of the corresponding minterms.
Boolean algebra has helped us to arrive at our goal. Here are some 

examples of common Blitter operations and the corresponding LFx bit settings:

• Invert a  data area: a  =D. 

Required LFx combination: 00001 111. 

Boolean algebra: a  = D 

a*(b+B)*(c+C) =  D

(ab+aB)*(c+Q =  D 

abc+aBc+abC+aBC =  D

Copy a  graphic to a  bit-plane without changing the bit-plane's 

contents. This corresponds to logically ORing the graphic A  and the bit-plane B: A  + B  = D.

Required LFx combination: 11111 100. 

Boolean algebra: A  + B  = D 

A(b+B)(c4€)+B(a+A)(c+Q =  D 

(Ab+AB)(c+Q+(Ba+BA)(c+C) =  D 

Abc+ABc+AbC+ABC+Bac+BAc+BaC+BAC =  D 

Abc+ABc+AbC+ABC+aBc+aBC =  D 

Here are the rules for determining the LFx bits needed:

1. Determine which of the eight ABC combinations should cause D  to 

bel.

2. Set the LFx bits for these combinations. 

3. If all three sources aren't needed, you must select all combinations in 

which the unused bits occur and in which the desired bits have the proper value.

Shifting the input values 

For some tasks the Blitter's limitation to word boundaries can cause trouble. For example, you may want to shift a  certain area within a  bit- map by a  few bits (i.e., by only a  portion of a  word). Or perhaps you want the Blitter to write a  graphic at specific screen coordinates that don't match a  word boundary. In order to handle this problem, the Blitter has the capability to shift the data words from sources A  and B  to the right by up to 15 bits. This allows it to move the data to any desired bit position. All bits that are pushed out to the right by the shift operation move into the free bits in the next word. The entire line is shifted bit by bit. A  device called a  barrel shifter is used inside the Blitter to shift the words. It requires no additional time for the shift operation, regardless of how many bits are moved. Adding a  shift of the data does not limit the Blitter's speed in any way.

Example for shifting data by three bits: 

Before:

Data word 1 

00011111 10011100 

Data word 2 

0001010101111111 

Data word 3 

11100001 11100101 

After:

Data word 1 

xxx00011 11110011

Data word 2 

1000001010101111 

Data word 3 

11111100 00111100 

The three xxx bits depend on the previous data word, from which they are shifted out.

Masking 

It is possible to use the Blitter to copy a  graphic whose borders are not on word boundaries from screen memory. Data that is to the left of the graphic but within the first data word should not be copied along with the graphic itself. To make this possible, the Blitter can apply a  mask to the first and last data words of a  line. This means that you can choose which bits of these words should be copied. Undesired data can be erased from the edges of the line.

Only source A  can be masked in this manner. Two registers contain the 

masks for the two edges. A  bit is copied in the Blitter operation only if it is set in the mask register. All others are cleared.

$044 BLTAFWM BLiTter source A  First Word Mask 

Mask for the first data word in the line. 

$046 BLTALWM BLiTter source A  Last Word Mask 

Mask for the last data word in the line. 

Bits 0-15 contain the corresponding mask bits. For example, "1
represents a  set bit, "." for a  cleared bit:

Column 1 

11111111 

111111 1111 

11 11 

11 1 

11 1 

11 11 

111111 1111 

11111111 

Graphic data in the bit-plane: 

Column 2 

1111111111111111 

11 1111 

1111 Ill 

11111 11 

11111 11 

1111 Ill 

11 1111 

1111111111111111 

Column 3 

1 11 

1111 1111 

11111 1111111 

1111111111111111 

1111111111111111 

11111 1111111 

1111 1111 

1 11 

FirstWordMask : 

0000000011111111 

LastWordMask : 

1111110000000000 

Column 1 

11111111 

11111111 

Column 3 

11111 

111111.. . 

111111. .. 

11111 

Result: 

Column 2 

1111111111111111 

11 1111 

1111 Ill 

11111 11 

11111 11 

1111 Ill 

11 1111 

1111111111111111 

By masking out the unwanted picture elements at the edges, you get the desired graphic.

Note: When the width of the Blitter window is only one word 

(BLTSIZE width =  1) both masks come together. They 

both operate on the same input word. Only the input bits whose mask bits are set in both masks are allowed through. The Blitter control registers The Blitter has two control registers, BLTCON0 and BLITCON1. The following Blitter control bits are found in these two registers:

BLTCONO $040 

Bit no. Name Function 

ASH3 

ASH2 

ASH1 

ASHO 

USEA 

USEB 

USEC 

USED 

LF7 

LF6 

LF5 

LF4 

LF3 

LF2 

LF1 

LFO 

ASHO-3 contain the shift distance 

for the input data from source A
ASHO-3 =  0 means no shift 

Enables the DMA channel for source A 

Enables the DMA channel for source B 

Enables the DMA channel for source C 

Enables the DMA channel for destination D 

Selects minterm ABC (bit comb, of ABC: 111) 

Selects minterm ABc (bit comb, of ABC: 110) 

Selects minterm AbC (bit comb, of ABC: 101) 

Selects minterm Abe (bit comb, of ABC: 100) 

Selects minterm aBC (bit comb, of ABC: 01 1 ) 

Selects minterm aBc (bit comb, of ABC: 010) 

Selects minterm abC (bit comb, of ABC: 001) 

Selects minterm abc (bit comb, of ABC: 000) 

BLTCON1 $042 

Bit no. 

Name 

Function 

BSH3 

BSH0-3 contain the shift distance 

BSH2 

for the input data from source B

BSH1 

BSH0-3 =  0 means no shift 

BSH0 

1-5 

Unused 

EFE 

Exclusive Fill Enable 

IFE 

Inclusive Fill Enable 

FCI 

Fill Carry In 

DESC 

DESC =  1 switches to descending mode 

LINE 

LINE =  1 activates the line mode 

The LINE bit switches the Blitter into its line-drawing mode. If you want to copy data with the Blitter, LINE must be 0.

Ascending or descending addresses can be selected with the DESC bit. If 

DESC =  0, the Blitter works in ascending mode if DESC =  1, it works in 

descending mode. The EFE and IFE bits activate the surface-filling mode of the Blitter. They must both be 0  for the Blitter to operate in the normal mode. The
FCI bit is used only in the fill mode. 

The Blitter DMA The data from the source areas A, B  and C  and the output data D  are read from or written to memory through four DMA channels. This Blitter
DMA can be enabled for all channels with the BLTEN bit (bit 6) of the 

DMACON register. The Blitter has four data registers for its DMA 

transfers:

Addr. 

Name 

Function 

BLTDDAT 

Output data D 

BLTCDAT 

Data register for source C 

BLTBDAT 

Data register for source B 

BLTADAT 

Data register for source A 

The DMA controller reads the needed input values from memory and writes them to the data registers. When the Blitter has processed the input data, BLTDDAT contains the result. The DMA controller then transfers the contents of BLTDDAT to the chip RAM. The DMA transfer through these four registers can be enabled and disabled by using the four USEx bits. For example, USEA =  0 disables the DMA channel for data register A. The Blitter continues to access the value in BLTADAT, so with each new word from the active sources the same word is fetched from source A. For this reason unused sources must have USEx set to 0  and must be prevented from affecting the result by the appropriate selection of minterms. However, the same word is always read when the DMA channel is disabled. For example, you can fill the memory with a  repeating pattern that has been written directly into
BLTxDAT 

In addition to BLTEN, three other bits in the DMACON register pertain to the Blitter:

BitlOBLTPRI 

This bit was already explained in the Fundamentals section (11.7.2). If it is 1, the Blitter has absolute priority over the processor.

Bit 14 BBUSY (read-only) 

BBUSY signals the status of the Blitter. If it is 1, it is currently performing 

an operation.

//. The A3000 Hardware 

After the Blitter window is set in BLTSIZE the Blitter begins its DMA and sets BBUSY until the last word of the Blitter window has been processed and written back into memory. It then ends its DMA and clears BBUSY. At the same time BBUSY is cleared, the B litter-finished bit in the interrupt request register is also set.

Bit 13 BZERO 

The BZERO bit indicates whether all the result bits of a  Blitter operation were 0. In other words, BZERO is set when none of the operations performed on any of the data words resulted in a  1 . One use of this bit is to perform collision detection. The minterms are set so that D  is 1  only if the two sources are also 1. If the graphics in both sources intersect at least one point, the result is 1 and BZERO is cleared. At the end of the Blitter operation you can determine whether or not a  collision occurred. USED is set to 0  in this application so that the output data aren't written to memory.

Using the Blitter to fill surfaces 

What does it mean to "fill a  surface"? The Blitter understands a  surface to 

be a  two-dimensional area of memory to be filled with points. Normally this surface belongs to a  graphic or a  bit-plane. In order to fill a  surface, the Blitter must recognize its boundaries. You need a  definition of a  boundary line that the Blitter can understand.
Many fill functions exist in most drawing programs and also in Amiga- 

BASIC with the PAINT command. 

These functions cause an area of the screen to be filled, starting with some initial point, until the program encounters a  boundary line. This allows the painting of completely arbitrary surfaces, assuming that they are enclosed by a  continuous line. The Blitter is not able to perform such a complex fill operation. It only works line by line and fills the free space between two set bits which mark the boundaries of the desired surface. The following examples show how the Blitter fill operation works:

Correct fill operation: 

Before: After:

## 1.1 Ill

1 1 111111111 

. .  1 1 1111111111111 . . 

.1 1...1 1 111111. ..111111. 

.1 1...1 1 111111... 111111. 

. .1 1 1111111111111. . 

1 1 111111111 

. .1 1 1111111111111. . 

Incorrect operation due to improper border bits: 

Before: After:

. .  .111 11111111111111. 

111.. -Ill 111111111 

. .11.. .111. .  .11 11111111111111. . .11. . 

.1 1...1 1 111111... 111111. 

.1 1...1 1 111111... 111111. 

. .11. .  .111. .  .11 11111111111111. .  .11. . 

1 1 111111111 

. .1111111111111 1111111111111111111. . 

In the first example, the surface is bounded properly for the Blitter and filled correctly. However, in example 2, a  closed boundary line is drawn around the figure. If you try to fill such a  graphic with the Blitter, chaos results. The reason for this is the algorithm that the Blitter uses. It is extremely simple. The Blitter starts at the right side of the line. As it proceeds to the left, it uses the Fill Carry bit (FC) to determine whether an output bit must be set. The output bit corresponds to the value of the FC bit, which normally (as in our example) starts out as 0. When the Blitter encounters an input bit that is set, the value of the FC bit changes (from 0  to 1  in our example). This causes subsequent output bits to have the new value (now 1), until another set bit is encountered in the input. Then the FC bit will be switched again (back to 0). In this way the area between two set bits is always filled. As you can see from the second example, the fill logic gets confused by an odd number of set bits. The FCI bit (Fill Carry In) in BLTC0N1 determines the initial value of the
FC bit. If FCI is cleared, everything proceeds as previously described. 

But if FCI =  1, the Blitter starts to fill from the edge until it encounters the first set input bit. The fill procedure is then reversed.

Example of the effect of the FCI bit: 

Output graphic 

1 1 

...1 1.. 

..1 1.1 1. 

-.1 1.1 1. 

...1 1.. 

1 1 

FCI=0 

...1111111... 

.11111111111. 

111111.111111 

111111.111111 

.11111111111. 

. . .1111111. .. 

FCI=1 

1111111 111111 

11111 1111 

1111 111 111 

1111 111 111 

11111 1111 

1111111 111111 

In the examples up to now, the input bits (the boundaries of the surface) have been retained in the filled graphic. This is always the case when the fill mode is activated by setting the ICE bit (Inclusive fill Enable) in the
BLTCON1 register. 

In contrast to this is the ECE mode (Exclusive fill Enable), which is enabled by setting the bit with this name in BLTCON1. In this mode the boundary bits at the left edge of a  filled surface (whenever the fill carry bit changes from 1  to 0) are not retained in the output picture. This causes all surfaces to be one pixel narrower. Only in the ECE mode is it possible to get surfaces with a  width of only one bit. It is impossible in the ICE mode because the definition of a  surface, however narrow, requires at least two boundary bits, both of which will appear in the output.

Difference between ICE and ECE modes: 

Output graphic 

11 11 

1. .  .1 1.1 

.. .1. ..11..1. .1. .1 

1 11.. .11.. .1 

..1 1 

1 1. 

1...1...11.. 

ICE 

11 11 

11111 111 

...111111111.. 1111 

111111111111111111 

..1111111111111111 

1111111111111. 

11111. ..11.. 

ECE 

1 1 

1111. ....11 

1111. 111. ..Ill 

.1111111.1111.1111 

...111111111111111 

111111111111. 

1111 1.. 

Bit wise operation of the different fill operations: 

Input pattern: 11010010 

FCI =  0 

FCI =  1 

Bit no. 

Input bit 

FC ICE ECE 

FC ICE ECE 

- 

11010010 

FC=FCI 

FC=FCI 

0 0              0 

1 1              1 

1 10 10 

0 11 01 

1 110 110 

0 011 001 

1 1110 1110 

0 0011 0001 

0 11110 01110 

1 10011 10001 

0 011110 001110 

1 110011 110001 

1 1011110 1001110 

0 1110011 0110001 

0 11011110 01001110 

1 11110011 10110001 

FC=FCI means that the FC bit assume 

BLTCON1 at the start of the fill operation. 

How is a  Blitter fill operation started? The Blitter can perform this fill 

operation in addition to an ordinary copy procedure. It is enabled by setting either the ICE bit or the ECE bit in BLTCON1 depending on the desired mode. The Blitter forms the output data D  from the three sources
A, B  and C  and the selected minterms as usual. If neither of the two fill 

modes is active, the Blitter writes this data directly to its output data register (BLTDDAT, $000). From there the data is written to memory via
DMA if USED =  1. 

In the fill mode, the output data D  is used as input data for the fill circuit. The result of the fill operation is then written into the output data register
BLTDDAT. 

The following steps are needed to perform a  fill operation:

Select the BLTxPT, BLTxMOD and minterms so that the output 

data D  contains the correct boundary bits for the surface to be filled.

• Select descending mode (the Blitter fills from right to left and this 

works only when the words are referenced with descending addresses).

• Select the desired fill mode: set ICE or ECE set or clear FCI as 

desired.

LINE =  0 (Line mode off). 

Set BLTSIZE to the size of the graphic to be filled. 

The Blitter now begins the fill procedure. When it is done, it sets
BLTBUSY to 0  as usual. The speed of the Blitter is not limited by 

activating the fill mode. The Blitter can fill surfaces at a  maximum speed of 16 million pixels per second. The major application of the fill mode is in drawing filled polygons. The desired polygon is drawn in an empty memory area using line mode and then filled very rapidly by the Blitter.

Using the Blitter to draw lines 

The Blitter is an extremely versatile tool. In addition to its excellent capabilities for copying data and filling surfaces, it has a  powerful mode for drawing lines. Like the other Blitter modes, the line mode is extremely fast: up to a  million pixels per second.

What exactly is "drawing lines"? When a  line is drawn, two points are 

connected to each other by a  continuous series of points. Since the resolution of a  computer graphic is limited, the optimal points cannot always be chosen. The actual pixels may lie slightly above or below the intended ideal line. Such a  line usually resembles a  staircase. The higher the resolution, the smaller the steps, but they can never be completely eliminated.

Example of a  line in a  computer graphic: 

The two points are connected by a  line

1. .  . 111. 

Ill 

Ill 

.1 Ill 

The Blitter can draw lines up to a  length of 1024 pixels. Unfortunately, you cannot specify the coordinates of the two endpoints. Like solid surfaces, lines must be defined in a  style recognizable to the Blitter.

First, the Blitter needs to know the octants in which the line is located. 

The coordinate system is divided into eight parts you'll find that the octants are found in many graphic processors.

\0 

0 / 

E 

\ 

SUDsO 

SULsl 

AULsl 

" ii ii 

Q _l _l 

3 3  3 

« to < 

/ 

SUD=1 

SULsl 

AUL=1 

©X 

y®

SUDsl 

SULsl 

AULsO 

SUD=1 

SUL=0 

AUL=1 

©y 

\© 

(X axis) 

SUD=1 

SULsO 

AULsO 

SUDsO 

SUL=1 

AULsO 

SUDsO 

SULsO 

AULsO 

\H 

'B 

(Y axis) 

0\ 

D 

o- number of octants values of SUD/SUL/AUL bits

Blitter octants 

The figure shows this division. The starting point of the line is located at the origin of the coordinate system (the intersection of the X  and Y axes). The end point is located in one of the eight octants, according to its coordinates. The number of this octant can be determined with three logical comparisons. XI and Yl are the coordinates of the start point and
X2 and Y2 are those of the end point: 

If XI is less than X2, the end point is in octant 0, 1, 6  or 7, while if XI is greater than X2, it is in 2, 3, 4 or 5. If XI and X2 are equal, it is on the Y axis. Then all eight octants are possible.

Similarly: If Yl is less than Y2, possible octants of the end point are 0, 1, 2 

and 3, and if Yl is greater than Y2, the octants are 4, 5, 6  and 7. If Yl =
Yl, all are possible. 

For the last comparison we need the X  and Y  differences: DeltaX =  1X2-
XII, DeltaY =  IY2-Y1I. If DeltaX is greater than DeltaY, the end point can 

be located in octant 0, 3, 4  or 7. If DeltaX is less than DeltaY, it is in octant 1 , 2, 5 or 6. For DeltaX =  DeltaY, all octants.

Ay 

Ending point 

B(x v  y 2) 

Starting point 

A(x v  y 2) 

Ax 

Selection of start and end points 

The end point is located in the octant that occurred in all three comparisons. If a  point is on the border between two octants, it doesn't matter which is chosen. The digits in the "Code" column correspond to the circled numbers in the figure. The Blitter needs a  combination of three bits, depending on the octant in which the end point of the line is located. The bits are called
SUD (Sometimes Up or Down), SUL (Sometimes Up or Left) and AUL 

(Always Up or Left). 

"Code" is the 3-bit number formed by these bits (SUD =  MSB and AUL 

= LSB). 

When programming the line you must first determine the octant of the end point and then write the corresponding code value into the Blitter.

Selecting the correct octant: 

Point coordinates Octant Code Point coordinates 

Y1 <= Y2 

X1 <£ X2 

DeltaX >= DeltaY 

Y1<=Y2 

X1 <= X2 

DeltaX <= DeltaY 

Y1 <= Y2 

X1 >= X2 

DeltaX <= DeltaY 

Y1 <= Y2 

X1>=X2 

DeltaX >= DeltaY 

Octant 

Code 

Y1 >= Y2 

X1 >= X2 

DeltaX >= DeltaY 

Y1 >= Y2 

X1>=X2 

DeltaX <= DeltaY 

Y1 >= Y2 

X1 <= X2 

DeltaX <= DeltaY 

Y1 >= Y2 

X1 <= X2 

DeltaX >= DeltaY 

Lines with patterns 

When drawing a  line, the Blitter uses a  mask to determine whether the points of the line should be set, cleared, or given a  pattern. The mask is 16 bits wide, so the pattern repeats every 16 points. The relationship between the pattern and the appearance of the line can best be understood with a  couple of examples:

=0, "1" =  1, A  = start point and B  = end point) 

Output picture: Mask =  "1111111111111111": 

. .1111 

1111. . 

.. .111 

B. 

111... 

11. 

111... 

...111 

..A 

..11111111.. 

11111111 11B 

.. .111 11111. 

.11 11.11. 

11 Ill 11 

11 111 11 

.11111 11. 

.11111 111... 

All... .11111111

Zero bits in the mask cause line points to be cleared: 

Output picture: Mask =  "0000000000000000": 

.. 11111111111111111.. B 

..11111111111111111.. 

..11111111111111111.. 

. .11111111111111111. . 

. .11111111111111111. . 

. .11111111111111111. . 

..11111111111111111. . 

A. 11111111111111111. . 

..11111111111111111. 

. .11111111111111 

..111111111111.. 111. 

. .111111111. . .11111. 

. .111111. . .11111111. 

. .1111.. 11111111111. 

..1.. .1111111111111. 

A.. 1111111111111111. 

If we combine ones and zeros in the mask, the line takes on a  pattern:
Mask =  "1111111000111000 

.Allllll. 

.111. 

.111111. 

.111.. .11. 

.11111. 

.111. . .111. 

.1111. ..B 

Drawing boundary lines 

In the section on filling surfaces with the Blitter, we explained that the boundary lines of these surfaces can only be one pixel wide. If these lines are drawn with the Blitter, it's possible that several line points lie on the same horizontal line. To prevent this, the Blitter can be made to draw lines with only one point per raster line:

Normal line: 

.........1111.. ....... 4, 

..:. lilt :...... .. . 

Line with one point/raster line: 

1... 

. :.!.. .......... -." : r :- '  -'•■'-■ 

The definition of slope

So the Blitter knows where to draw the line, it needs a  Blitter-style 

definition of the slope of the line. This slope is formed from the results of three terms, all based on the DeltaX and DeltaY values, as explained in the section on octants (DeltaY and DeltaX represent the width and height of the rectangle for which the line forms a  diagonal).

First the two values must be compared with each other to find the 

larger/smaller of the two. The smaller delta is called Sdelta and the larger one is called Ldelta. Then the three expressions required by the Blitter are as follows:

1. 2*Sdelta 

2. 2*Sdelta -  Ldelta 

3. 2*Sdelta -  2*Ldelta 

Also, the Blitter has a  SIGN flag which must be set to 1  if 2*Sdelta <
Ldelta. 

Register functions in line mode 

The Blitter uses the same registers when drawing lines as it does when copying data (it doesn't have any more), but the functions change:

BLTAPTL The value of the expression "2*Sdelta-Ldelta" must be 

written into BLTAPTL.

BLTCPT&BLTDPT 

These two register pairs (BLTCPTH and BLTCPTL,
BLTDPTH and BLTDPTL) must be initialized with the 

start address of the line. This is the address of the word in which the start point of the line is located.

BLTAMOD The value of the expression 

be stored in BLTAMOD.

BLTBMOD "2*Sdelta

"2*Sdelta-2*Ldelta" must 

BLTCMOD &  BLTDMOD 

The width of the entire picture in which the line is to be drawn must be stored in these two modulo registers. As usual, this takes the form of an even number of bytes. With a  normal bit-plane of 320 pixels (40 bytes) in the
X direction, the value for BLTCMOD or BLTDMOD 

= 40. 

BLTSIZE The width (bits 0  to 5) must be set to 2. The height (bits 

6 to 15) contains the length of the line in pixels. A 

height of 0  indicates a  line length of 1024 pixels. The correct line length is always the value of Ldelta.

Drawing a  line is started by writing to the BLTSIZE 

register. Therefore, it should be the last register initialized.

BLTADAT This register must be initialized to $8000. 

BLTBDAT BLTBDAT contains the mask with which the line is 

drawn.

BLTAFWM $FFFF is stored in this mask register. 

BLTCON0 

Bit no. 

Name 

Function 

START3 

The 4-bit value START0-3 contains the position of the start point

START2 

of the line within the word

START1 

at the start address of the line (BLTCPTVBLTDPT)

START0 

The four lower bits of the X  coordinate of the start point

USEA =  1 

This combination of the USEx bits is necessary

USEB =  0 

for the line mode

USEC =  1 

USED =  1 

LF7 

The LFx bits must be initialized with $CA toO

LF0 

(D =  aC +  AB) 

BLTC0N1 

Bit no. 

Name 

Function 

Texture3 

This is the value for shifting the mask.

Texture2 

Normally TextureO-3 is set to StartO-3. 

Texturel 

The pattern in the mask register BLTBDAT

TextureO 

then starts with the first point of the line.

11-7 =  0 

Unused, always set to 0. 

SIGN 

If 2*Sdelta<Ldelta, set SIGN to 1 .

... 

Unused, always set to 0. 

SUL 

These three bits must be initialized

SUD 

with the SUL7SUD/AUL code

AUL 

of the corresponding octant.

SING =  1 

Draw lines with only one point per raster line. 

LINE =  1 

Put the Blitter in line drawing mode. 

A numerical example:

You want to draw a  line in a  bit-plane. The bit-plane is 320 by 200 pixels 

large and lies at address $40000. The starting point of the line has the coordinates X=20 and Y=185. The end point lies at X=210 and Y=35.
(The coordinates are in relation to the upper left corner of the bit-plane.) 

DeltaX =  190, DeltaY =  150. 

1st step: Find the octant of the end point 

To do this, the three comparisons discussed earlier are performed the result: XI <  X2, Yl >  Y2 and DeltaX >  DeltaY. This yields octant number
7 and a  value for the SUD/SUL/AUL code of 4. 

2nd step: Address of the starting point 

This is calculated as follows: starting address of bitplane +  (number of lines -  Yl -  1) *  bytes per line +
2*(X1/16) 

The fractional portion of the division is ignored. After inserting the values:

$40000 +  (200-185-l)*40 +  2 =  $40232 

this value is placed in BLTCPT and BLTDPT. The number of bytes per line is also written to the BLTCMOD and BLTDMOD registers.

3rd step: Starting point of the line in STARTO-3 

Required calculation: XI AND $F. Numerically: 

STARTO-3 =  20 AND $F =  4 

4th step: Values for BLTAPTL, BLTAMOD andBLTBMOD 

DeltaY <  DeltaX, meaning that Sdelta =  DeltaY and Ldelta =  DeltaX. 

BLTAPTL =  2*Sdelta-Ldelta =  2*150-190 =  110 

BLTAMOD =  2*Sdelta-2*Ldelta =  2*150-2*190 =  -80 

BLTBMOD =  2*Sdelta =  300 

2*Sdelta>Ldelta 

Therefore SIGN =  0.

5th step: Length of the line for BLTS1ZE 

Length =  Ldelta =  DeltaX =  190. 

The value of the BLTSIZE register is calculated from the usual formula:
Length*64 +  Width. Width must always be set to 2  when drawing lines. 

BLTSIZE =  DeltaX*64+2 =  12162 or $2F82. 

6th step: Combining the values for the two BLTCONx registers 

The START value must be stored in the correct position in BLTCONO, in addition to $CA for the LFx bits and 101 1 for USEx. In our example, this
results in $ABCA. 

BLTCON1 contains the code for the octant and the control bits. We 

want to draw our line normally, so SING =  0. LINE must naturally be 1 .
SIGN was already calculated and is 0  in this example. Together this 

makes $0011. 

In assembly language the initialization of the registers might look like this:

LEA $DFF000,A5 

MOVE.L #$40232, BLTCPTH(A5) 

MOVE.L #$40232, BLTDPTH(A5) 

MOVE.W #40, BLTCMOD(A5) 

MOVE.W #40, BLTDMOD(A5) 

MOVE.W #110, BLTAPTL(A5) 

,-Base address of the custom chips to A5 

 Start address to BLTCPT 

and BLTDPT

 Width of bitplane to BLTCMOD 

and BLTDMOD

MOVE.W #-80, BLTAMOD(A5) 

MOVE.W #300, BLTBMOD(A5) 

MOVE.W #$ABCA, BLTCON0(A5) 

MOVE.W #$11, BLTCONKA5) 

MOVE.W #12162, BLTSIZE(A5) Now the blitter starts 

drawing the line

Other drawing modes 

Up to now we always used $CA as the value for the LFx bits. This 

causes the points on the line to be set or cleared according to the mask, while the other points remain unchanged. But other combinations of LFx are also useful. To understand this, you must know how the LFx bits are interpreted in the line mode: The Blitter can only address memory by words. In line mode the input data enters the Blitter through source channel C. The mask is stored in the B  register. The A  register determines which point in the word read is the line point. It always contains exactly one set bit, which is shifted by the Blitter to the correct position. The normal LFx value of $CA causes all bits, for which the A  bit is 0, to be taken directly from source C. However, if A  is 1, the destination bit is taken from the corresponding mask bit. If you know how the LFx bits are used, you can choose other drawing modes. For example, $4A causes all the line points to be inverted. The Blitter DMA cycles As we explained in the section on fundamentals, the Blitter uses only even bus cycles. Since it has priority over the 68030, it is interesting to know how many cycles are left for the processor. This depends on the number of active Blitter DMA channels (A, B, C  and D). The following table shows the course of a  Blitter operation for all fifteen possible combinations of active and inactive Blitter DMA channels. The letters A,
B, C  and D  represent the corresponding DMA channels. Behind them, 

the digit 1  represents the first data word of the Blitter operation, the digit
3 for the last word, and the digit 2  for all words in between. A  dashed 

line (--) indicates that this bus cycle is not used by the Blitter.

Usage of even bus cycles by the Blitter: 

Comments: 

The table is only valid if the following conditions are fulfilled:

1. The Blitter is not disturbed by Copper or bit-plane DMA accesses. 

2. The Blitter is running in normal mode (neither drawing lines nor 

filling surfaces).

3. The BLITPRI bit in the DMACON register is set and the Blitter has 

absolute priority over the 68030.

Active DMA channels Usage of even bus cycles 

None 

B 

B 

B 

A 

A 

A 

A 

A 

A 

A 

A 

C 

C 

D 

C 

C 

DO -- Dl -- D2 —  -- -- -- -- —  -- — 

CO —  CI —  C2 -- -- -- —  — —  — — 

CO -- -- CI DO -- C2 Dl —  D2 -- —  — 

BO -- —  Bl —  — B2 -- -- —  -- -- -- 

BO -- -- Bl DO -- B2 Dl -- D2 -- -- -- 

BO CO -- Bl CI -- B2 C2 -- -- -- -- -- 

BO CO -- -- Bl CI DO -- B2 C2 Dl —  D2 

AO -- Al -- A2 -- -- — —  — 

AO -- Al DO A2 Dl —  D2 —  — -- -- — 

AO CO Al CI A2 C2 — 

AO CO -- Al CI DO A2 C2 Dl —  D2 —  — 

AO BO —  Al Bl -- A2 B2 —  -- —  — — 

AO BO -- Al Bl DO A2 B2 Dl -- D2 -- -- 

AO BO CO Al Bl CI A2 B2 C3 -- —  — -- 

AO BO CO -- Al Bl CI DO A2 B2 B3 Dl D2 

Explanations: 

As you can see, the output data DO doesn't get to RAM until the Al, Bl and CI data have been read. This results from the pipelining in the
Blitter. Pipelining means that the data is processed in multiple stages in 

the Blitter. Each stage is connected to the output of the preceding one and the input of the next. The first stage gets the input data (for example,
AO, BO and CO), processes it and passes it on to the second stage. While 

it is being further processed in that stage, the next input data is fed into the input stage (Al, Bl and CI). When the first data reaches the output stage, the Blitter has long since read the next data. Two data pairs are always at different processing stages in the Blitter at any given time during a  Blitter operation. The table also allows the processing time of a  Blitter operation to be calculated. Every microsecond the Blitter has two bus cycles available. If it's moving a  64K block (32768 words) from A  to D, it needs 2*32768 cycles. But if the same block is combined with source C, a  total of
3*32768 cycles are needed, because two input words must be read for 

each output word produced. The table also shows that the Blitter is not capable of using every bus cycle even if only one DMA channel is active.

Sample programs 

Program 1: Drawing lines with the Blitter 

This program can be used as a  universal routine for drawing lines with the Blitter. It shows how the necessary values can be calculated. The program is quite simple: At the start of the program the memory is requested and the Copper list is constructed. The only new part is the OwnBlitter routine. As its name indicates, it can be used to gain control of the Blitter. Correspondingly, there is a  call to DisownBlitter at the end of the program so that the
Blitter returns to the control of the operating system. 

The program uses only one hi-res bit-plane, with standard dimensions of
640 x  256 pixels. In the main loop, the program draws lines that go from 

one side of the screen through the center of the screen to the other side. When a  screen has been filled in this manner, the program shifts the mask used to draw the lines and starts over again.

Comments: 

The coordinate specifications in the program start from point 0,0 in the upper left corner of the screen and are not mathematical coordinates, as were used in the previous discussions. This means that when comparing the Y  values, the greater/less than sign is reversed.

*** Lines with the Blitter 

 Custom chip register 

INTENA =  $9A 

DMACON =  $96 

DMACONR =  $2 

COLOR00 =  $180 

Interrupt enable register (write) 

DMA-Control register (write) 

DMA-Control register (read) 

Color palette register 

11, The A3000 Hardware 

VHPOSR =  $6 

 Pos i  t ion ( r ead ) 

Copper Register 

C0P1LC =  $80  Address of 1st. Copper-List 

COP2LC =  $84 Adderss of 2nd. Copper-List 

C0PJMP1 =  $88 Jump to Copper-List 1 

C0PJMP2 =  $8a Jump to Copper-List 2 

Bitplane Register 

BPLCON0 

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

$0EO 

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

Bitplane control register 0 

1 (Scroll value) 

2 (SpriteoPlayfield Priority) 

Pointer to 1st . bitplane 

Modulo value for odd Bit-Planes 

Modulo value for even Bit-Planes 

Start of screen window 

End of screen window 

Bit-Plane DMA Start 

Bit-Plane DMA Stop 

Blitter Register 

BLTCON0 

= 

$40 

BLTC0N1 

= 

$42 

BLTCPTH 

= 

$48 

BLTCPTL 

= 

$4a 

BLTBPTH 

= 

$4c 

BLTBPTL 

= 

$4e 

Blitter control register 

Blitter control register 

 Pointer to source C 

(Pointer to source B 

0 (ShiftA,Usex,LFx) 

1 (ShiftB,misc. Bits) 

BLTAPTH =  $50  Pointer to source A 

BLTAPTL =  $52 

BLTDPTH 

= 

$54 

BLTDPTL 

= 

$56 

BLTCMOD 

= 

$60 

BLTBMOD 

= 

$62 

BLTAMOD 

= 

$64 

BLTDMOD 

= 

$66 

BLTSIZE 

= 

$58 

BLTCDAT 

= 

$70 

BLTBDAT 

= 

$72 

BLTADAT 

= 

$74 

BLTAFWM 

= 

$44 

.•Pointer to target data D 

Modulo value for source C 

Modulo value for source B 

Modulo value for source A 

Modulo value for target D 

HBlitter window width/height 

 Source C  data register 

/Source B  data register 

Source A  data register 

Mask for first data word from source A 

11. 7 Programming the Hardware 

BLTALWM =  $46 Mask for first data word from source B 

CIA-A Port register A  (Mouse key) 

CIAAPRA =  $bfe001 

Exec Library Base Offsets 

OpenLibrary =  -30-522 LibName,Version/al,dO 

Forbid =  -30-102

Permit =  -30-108 

AllocMem =  -30-168 ByteSize, Requirements/d0,dl

FreeMem =  -30-180 MemoryBlock, ByteSize/al,d0 

/Graphics Library Base Offsets 

OwnBlitter =  -30-426 

DisownBlitter =  -30-432 

graphics base

StartList =  38 

other Labels

Execbase =  4 

Planesize =  80*200 

Planewidth =  80 

Bitplane size: 80 Bytes by 200 lines 

CLsize =  3*4 

Chip =  2 

Clear =  Chip+$10000 ,-Clear Chip-RAM first 

The Copper-List contains 3  commands
/allocate Chip-RAM 

*** Initialization *** 

Start : 

Allocate memory for bit plane move.l Execbase, a6 move.l #Planesize,d0 Memory requirement for bit plane move.l #clear,dl jsr AllocMem (a6)  Allocate memory move .1 dO , Planeadr beq Ende  Error I  -> End

/Allocate memory for Copper-List 

moveq #Clsize,dO moveq #chip,dl jsr AllocMem(a6) move .1 dO , CLadr beq FreePlane

 Error! -> FreePlane 

 Create Copper-List 

move.l dO,aO move . 1 Planeadr , dO

.•Address of Copper-List from aO 

/Address of Bitplane 

move.w tbpllpth, (a0)+  First Copper command in RAM swap dO move.w dO, (a0)+ Hi-Word of Bit plane address in RAM move.w #bpllptl, (a0)+  second command in RAM swap dO move.w dO,(aO)+ Lo-Word of Bitplane address in RAM
move.l #$fffffffe, (aO) End of Copper-List 

.•Allocate Blitter 

move . 1 #GRname , al clr.l dO jsr OpenLibrary (a6) move.l a6,-(sp) move.l d0,a6 move.l a6,-(sp) jsr OwnBlitter (a6)

ExecBase from the Stack 

GraphicsBase from a6 

and from the Stack
Take over Blitter 

*** Main program *** 

DMA and Task-Switching off 

move.l 4 (sp) ,a6 jsr forbid (a6)

lea $dff000,a5 

move.w #$03e0,dmacon(a5) 

Copper initialization 

move . 1 CLadr , copl lc ( a5 ) clr.w copjmpl(a5)

ExecBase to a6 

 Task-Switching off 

Set color 

move.w #$0000,color00 (a5)  Black background 

move.w #$OfaO,colorOO+2(a5) Yellow line

Playfield initialization 

move.w #$2081#diwstrt(a5) 20,129 

move.w #$20cl,diwstop(a5) 20,449 

move.w #$003c,ddfstrt(a5) .-Normal 

move.w #$00d4,ddfstop(a5) 

move.w #%1001001000000000,bplcon0(a5) clr.w bplconl(a5) clr.w bplcon2(a5) clr.w bpllmod(a5) clr.w bpl2mod(a5)

Hires Screen 

DMA on 

move.w #$83C0,dmacon(a5) 

Draw lines 

 Determine start values: 

move . 1 Planeadr , aO move.w #Planewidth,al move.w #255, a3 move.w #639, a4
move.w #$0303, d7 

Constant parameter for DrawLine 

into correct register

Size of Bitplane in Register 

 Start pattern 

Loop: rol.w #2,d7 

move.w d7,a2

 Shift pattern 

.•Pattern in register for DrawLine 

clr.w d6
LoopX : 

/Clear loop variable 

clr.w dl move.w a3,d3 move.w d6,d0 move.w a4,d2 sub.w d6,d2

Yl =  0 

Y2 =  255 

XI =  Loop variable 

X2 =  639-Loop variable 

bsr DrawLine addq.w #4,d6 cmp.w a4,d6 ble . s LoopX

.•Increment loop variable 

Test if greater than 639 

if not. continue loop clr.w d6
LoopY : 

.•Clear loop variable 

move.w a4,d0 X1 =  639 clr.w d2 X2 =  0 move.w d6,dl Y1 =  loop variable move.w a3,d3 sub.w d6,d3 Y2 =  255-loop variable bsr DrawLine Draw line addq.w #2,d6 /Increment loop variable cmp.w a3,d6 Is loop variable greater than 255? ble.s LoopY if not, continue loop btst #6,ciaapra Mouse key pressed? bne Loop No, continue

*** End program *** 

Wait till blitter is ready- 

Wait: btst #14,dmaconr (a5) 

bne Wait

/Activate old Copper-List 

move.l (sp)+,a6 Get GraphicsBase from Stack move.l StartList (a6) ,copllc(a5) clr.w copjmpl(a5) /Activate Startup-Copper-List

move.w #$8020,dmacon(a5) 

jsr DisownBlitter (a6) /Release blitter move.l (sp)+,a6 ExecBase from Stack jsr Permit (a6) /Task Switching on

/Release memory for Copper-List 

move.l CLadr.al /Set parameter for FreeMem moveq #CLsize,dO jsr FreeMem(a6) /Release memory

/Release Bitplane memory 

FreePlane : 

move.l Planeadr,al move.l #Planesize,dO jsr FreeMem (a6)

Ende: 

clr.l dO rts

 Program end 

.•Variables 

CLadr: del 0 

Planeadr : dc . 1 0 

/Address of Copper-List 

 Address of Bitplane 

/Constants 

GRname: dc.b "graphics. library", 0 

align even

*** DrawLine Routine *** 

DrawLine draws a  line with the Blitter. 

The following parameters are used: dO =  XI X-coordinate of Start points dl =  Yl Y-coordinate of Start points

62 =  X2 X-coordinate of End points 

d3 =  Y2 Y-coordinate of End points aO must point to the first word of the bitplane al contains bitplane width in bytes a2 word written directly to mask register d4 to d6 are used as work registers

DrawLine : 

/Compute the lines starting address 

move . 1 al,d4 mulu dl,d4 moveq

#-$10, 

d5 and.w d0,d5 lsr.w

#3,d5 

add.w d5,d4 add.l a0,d4

/Width in work register 

/Yl *  Bytes per line 

/No leading characters: $f0 

/Bottom four bits masked from XI 

/Remainder divided by 8 

/Yl *  Bytes per line +  Xl/8 

/plus starting address of the Bitplane 

/d4 now contains the starting address 

/of the line 

/Compute octants and deltas 

clr.l d5 sub.w dl,d3 roxl.b #l,d5 tst.w d3 bge.s y2gyl

/Clear work register 

/Y2-Y1 DeltaY from D3 

/shift leading char from DeltaY in d5 

/Restore N-Flag 

/When DeltaY positive, goto y2gyl 

neg.w d3 y2gyl: sub.w d0,d2 roxl . b

#l,d5 

tst .w d2 bge.s x2gxl neg.w d2 x2gxl : move.w d3,dl sub.w d2,dl bge.s dygdx exg d2,d3 dygdx: roxl.b #l,d5

DeltaY invert (if not positive) 

X2-X1 DeltaX to D2 

Move leading char in DeltaX to d5 

/Restore N-Flag 

When DeltaX positive, goto x2gxl

 DeltaX invert (if not positive) 

DeltaY to dl 

DeltaY-DeltaX 

When DeltaY >  DeltaX, goto dygdx

.•Smaller Delta goto d2 

d5 contains results of 3  comparisons move.b 0ctant_table(pc,d5) ,d5 get matching octants add.w d2,d2  Smaller Delta *  2

Test, for end of last blitter operation 

WBlit: btst #14,dmaconr(a5) BBUSY-Bit test 

bne.s WBlit Wait until equal to 0 move.w d2,bltbmod(a5) 2* smaller Delta to BLTBMOD sub.w d3,d2 2* smaller Delta -  larger Delta bge.s signnl When 2* small delta >  large delta to signal or.b #$40,d5 Sign flag set signnl: move.w d2,bltaptl (a5) 2*small delta-large delta in BLTAPTL sub.w d3,d2 2* smaller Delta -  2* larger Delta move.w d2,bltamod(a5) to BLTAMOD

.•Initialization other info 

move.w #$8000,bltadat(a5) 

move.w a2,bltbdat (a5) move.w #$ff f f ,bltafwm(a5)
and.w #$000f,d0  

ror.w #4,d0

or.w #$0bca,d0  

move.w dO,bltconO (a5) move.w d5,bltconl(a5) move.l d4,bltcpth(a5) move.l d4,bltdpth(a5) move.w al,bltcmod(a5) move.w al,bltdmod(a5)

Mask from a2 in BLTBDAT 

bottom 4  Bits from XI to STARTO-3
USEx and LFx set 

Octant in Blitter 

Start address of line to 

BLTCPT and BLTDPT 

Width of Bitplane in both 

Modulo Registers 

,-BLTSIZE initialization and Blitter start 

lsl.w #6,d3

 LENGTH *    64 

addq.w #2,d3 plus (Width =  2) move.w d3,bltsize(a5) rts

,-Octant table with LINE =1: 

The octant table contains code values for each octant, shifted to the correct position

Octant_table : 

dc.b 0

*4+l 

yl<y2. xl<x2 , dx<dy =  0kt6 dc.b 4

*4+l 

yl<y2, xl<x2. dx>dy =  0kt7 dc.b 2

*4+l 

yi<y2, xl>x2 , dx<dy =  0kt5 dc.b 5

*4+l 

yl<y2, xl>x2 , dx>dy =  0kt4 dc.b 1

*4+l 

yl>y2, xl<x2, dx<dy =  Oktl dc.b 6

*4+l 

yl>y2, xl<x2 , dx>dy =  OktO dc.b 3

*4+l 

yl>y2, xl>x2, dx<dy =  0kt2 dc.b 7

*4+l 

yl>y2, xl>x2 , dx>dy =  0kt3 end

Program 2: Filling surfaces with the Blitter 

This program is very similar to the first program. It shows how you can create colored polygons by drawing border lines and filling them with the Blitter. Since most of it is identical to the first program, we've only printed the parts that must be changed in program 1  to create program 2. The first part that must be changed starts at the comment "Draw lines
***" and ends at the comment "*** End program ***." This area must 

be replaced by the section in the following listing labeled "Part 1. Also, the old octant table at the end of the program must be replaced with the new one following the heading "Part 2." The new octant table is required because, when filling surfaces, the Blitter needs boundary lines with only one pixel per line. In the new octant table, the LINE bit and the SING bit are set. The program labeled "Part 1" draws two lines and then fills the area between them with the Blitter. Then it waits for the mouse button to be clicked.

*** Filling surfaces with the blitter *** 

Part 1: 

Draw filled triangle 

Set starting value 

Draw line 

move.l Planeadr,aO move.w #Planewidth,al
move.w #$ffff,a2 

* Draw border lines * 

Line from 320,10 to 600,200 

move.w #320, dO move.w #10, dl move.w #600, d2 move.w #200, d3 bsr . L drawl ine

Line from 319,10 to 40,200 

move.w #319,d0 move.w #10, dl move.w #40, d2 move.w #200, d3 bsr.L drawline ,-Draw line

* Fill surface * 

Wait until blitter has drawn last line 

Wline: btst #14,dmaconr (a5) Test BBUSY 

bne.S Wline

Set constant parameters for 

the LineDraw routine

,-Mask to $FFFF -> no pattern 

add.l #Planesize-2,a0
move.w #$09f0,bltcon0(a5) 

move.w #$000a,bltconl(a5) 

move.w #$f fff ,bltafwm(a5)
move.w #$ffff ,bltalwm(a5) 

move.l a0,bltapth(a5) move.l a0,bltdpth(a5) move.w #0,bltamod(a5) move.w #0,bltdmod(a5) move.w #$ff*64+40,bltsize(a5)

Wait for mouse button 

 Address of last word 

USEA and D, LFx: D  = A 

 Inclusive Fill plus Descending 

Set first and last word mask 

/Address of last word of bit- 

plane to address register
No modulo 

 Start blitter 

end: btst #6,ciaapra bne.S end

End of Part 1. 

Mouse button pressed? 

No -> continue 

Part 2: 

 Octant table with SING =1 and LINE =1 : 

Octanttable : 

dc.b

*4+3 

yl<y2, xl<x2 , dx<dy =  Oct 6 dc.b

*4+3 

yl<y2, xl<x2 , dx>dy =  0ct7 dc.b

*4+3 

yl<y2, xl>x2, dx<dy =  Oct 5 dc.b

*4+3 

yl<y2, xl>x2 , dx>dy =  Oct 4 dc.b

*4+3 

yl>y2, xl<x2 , dx<dy =  Octl dc.b

*4+3 

yl>y2, xl<x2 , dx>dy =  OctO dc.b 3  *4+3 yl>y2, xl>x2, dx<dy =  Oct2 dc.b 7  *4+3 yl>y2, xl>x2, dx>dy =  Oct3
