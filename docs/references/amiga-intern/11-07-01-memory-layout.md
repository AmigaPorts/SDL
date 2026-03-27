# The Memory Layout

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

The previous sections involved closer looks at the hardware structure of the Amiga. The following pages show how the three custom chips are programmed. Now we'll begin an introduction to software, especially concerning the creation of graphics and sound. To successfully program the Amiga at the machine level, you must know the memory layout and the addresses of the individual hardware registers.

### 11.7.1 The Memory Layout

The first figure shows the normal memory configuration of the Amiga as it appears after booting. The entire address range of the 68030 comprises
4 gigabytes (addresses from 0  to $FFFFFFFF). However, this huge 

address space is not uniformly allocated. In the lower 16 megabytes, space is at a  premium because this is where all the system components that existed in the A2000 are located. The remainder is used for the internal fast RAM, the new chips, including the SCSI DMA controller, and the Zorro III expansions area.

RAM 

In the Amiga there is a  distinction between chip RAM and fast RAM. The chip RAM is used by the custom chips, Agnus, Denise and Paula, to store graphics and sound data. One megabyte of this RAM comes factory-installed, and sockets for adding a  second megabyte are included. The internal fast RAM is available only to the processor, the SCSI DMA chip and any expansion cards. Agnus cannot access it.

Using the new 4-megabit RAM chips, the Amiga can be upgraded to a 

maximum of 1 6 megabytes of internal RAM. When equipping the A3000 with RAM, first you must decide whether to use 1-Mbit or 4-Mbit RAM chips. The two types cannot be mixed. The jumper J852 selects the chip capacity:

J852 connecting pins 2  and 3: 1  Mbit, organized as 256 K  x 4 

J852 connecting pins 1  and 2: 4  Mbit, organized as 1  M x  4 

If you are upgrading with 4-Mbit RAM chips, the eight factory-installed chips must be removed. However, they can be used to expand the chip
RAM. 

The RAM is organized in four banks of eight chips each. The socket assignments of the banks are as follows:

BankO: 

U850 -  U857 or U850D -  U857D 

Bankl: 

U858 -  U865 

Bank 2: 

U866 -  U873 

Bank 3: 

U874-U881 

$01000000 

$00F00000 

$00E80000 

$00000000 

$00B80000 

$00A00000 

$00200000 

$00000000 

ROM 

Area For 

Autocontiguration 

Custom chips 

Zorro I 

Area For Expansion 

Zorro II 

Area for 

Memory Expansion 

Chip-RAM 

Zorro III 

Expansion area 

Fast RAM 

Amiga 3000 

Register area 

$80000000 

$10000000 

$08000000 

$01000000 

$00000000 

RAMIROM allocation in the Amiga 

The following types of RAM chips can be used: xx4256-80 (1 Mbit) or xx4400-80 (4 Mbit) P-mounted (these are the upright as opposed to the flush-mounted DIL chips). For greater speed, static-column RAM chips can also be used: xx4258-
80 or xx4402-80. 

These enable the 68030 CPU to operate in burst mode, supplying the internal cache with new data at a  rate faster than that of normal data access (this mode is turned on by the SETCPU command in the CLI). The base address of fast RAM with a  1 megabyte configuration is
$07F00000. As memory is added, the base address shifts down 

accordingly (e.g., $07D00000 with 4  megabytes). 

The CIAs

Details about the CIAs can be found in Section 11.3. The following are 

the addresses of the individual registers:

CIA-A 

CIA-B 

Name 

Function 

$BFE001 

$BFD000 

PA 

Port register A 

$BFE101 

$BFD100 

PB 

Port register B 

$BFE201 

$BFD200 

DDRA 

Data direction register A 

$BFE301 

$BFD300 

DDRB 

Data direction register B 

$BFE401 

$BFD400 

TALO 

Timer A  low byte 

$BFE501 

$BFD500 

TAHI 

Timer A  high byte 

$BFE601 

$BFD600 

TBLO 

Timer B  low byte 

$BFE701 

$BFD700 

TBHI 

Timer B  high byte 

$BFE801 

$BFD800 

E. LSB 

Event counter bits 0-7 

$BFE901 

$BFD900 

E.MID 

Event counter bits 8-1 5 

$BFEA01 

$BFDA00 

E. MSB 

Event counter bits 1 6-24 

$BFEB01 

$BFDB00 

— 

Unused 

$BFEC01 

$BFDC00 

SP 

Serial port register 

$BFED01 

$BFDD00 

ICR 

Interrupt control register 

$BFEE01 

$BFDE00 

CRA 

Control register A 

$BFEF01 

$BFDF00 

CRB 

Control register B 

The custom chips The various custom chip registers occupy a  510-byte area. Each register is 2  bytes (one word) wide. All registers are on even addresses. The base address of the register area is at $DFF000. The effective address of a  register is then $DFF000 +  register address. The following list shows the names and functions of the individual chip registers. Most of the register descriptions are unfamiliar now since we haven't discussed the functions of the registers, but this list will give you an overview and will later serve as a  reference. There are four types of registers: r (Read) This register can only be read. w (Write) This register can only be written. s (Strobe) An access to a  register of this type causes a  one-time action to occur in the chip. The value of the data bus (i.e., the word to be written to the register) is irrelevant. These registers are usually accessed only by Agnus. er (Early Read) A register designated as early read is a  DMA output register. It contains the data to be written into the chip RAM through DMA. There are two such registers (DSKDATR and BLTDDAT -  output registers for the disk and the Blitter). They are accessed only by the DMA controller in Agnus, when their contents are written into the chip RAM. The processor cannot access these registers.

A,D,P 

These three letters represent the three chips Agnus, Denise and Paula. They indicate in which chip the given register is found. It is also possible for a  register to be located in more than one chip. On such a  write access, the value is then written into two or even all three chips. This is the case when the contents of a  given register are needed by more than one chip. For the programmer it is unimportant where the registers are located. The entire area can be treated as one custom chip. The programmer needs to know only the address and function of the desired register. p,d A lowercase "d" means that this register is accessible only by the DMA controller. Registers preceded by a  lowercase "p" are used only by the processor or the Copper. If both letters precede a  register, it means that it is usually accessed by the DMA, but also by the processor from time to time.

Number of registers: 227 

Registers are normally accessed only by the DMA controller: 54 

Base address of the register area: $DFF000 

Name 

Reg.addr. 

Chip 

R/W 

p/d

Function 

BLTDDAT 

A 

er d

Blitter output data (from Blitter to RAM) 

D MACON R 

AP 

P 

Read DMA control register 

VPOSR 

A 

P 

MSB of vertical position 

VHPOSR 

A 

P 

Vertical and horizontal beam position 

DSKDATR 

P 

er d

Disk read data (from disk to RAM) 

JOYODAT 

00A 

D 

P 

Joystick/mouse position game port 0 

JOY1 DAT 

OOC 

D 

P 

Joystick/mouse position game port 1 

CLXDAT 

00E 

D 

P 

Collision register 

ADKCONR 

P 

P 

Read audio/disk control register 

POTODAT 

P 

P 

Read potentiometer game port 0 

POT1DAT 

P 

P 

Read potentiometer game port 1 

POTGOR 

P 

P 

Read pot. port data 

SERDATR 

P 

P 

Read serial port and status 

DSKBYTR 

01A 

P 

P 

Read disk data byte and status 

INTENAR 

01C 

P 

P 

Read interrupt enable 

INTREQR 

01 E 

P 

P 

Read interrupt request 

DSKPTH 

A 

w

P 

Disk DMA address bits 16-20 

DSKPTL 

A 

w

P 

Disk DMA address bits 1-15 

DSKLEN 

P 

w

P 

Disk DMA block length 

DSKDAT 

P 

w d

Disk write data (from RAM to disk) 

REFPTR 

A 

w d

Refresh counter 

VPOSW 

02A 

A 

w

P 

Write MSB of vertical beam position 

VHPOSW 

02C 

A 

w

P 

Write vertical and horizontal beam position 

COPCON 

02E 

A 

w

P 

Copper control register 

SERDAT 

P 

w

P 

Write serial data and stop bits 

SERPER 

P 

w

P 

Serial port control register and baud rate 

POTGO 

P 

w

P 

Write pot. port data and start bit 

JOYTEST 

D 

w

P 

Write in both mouse counters 

STREQU 

D 

s d

Horizontal sync with VB and equal frame 

STRVBL 

03A 

D 

s d

Horizontal sync with vertical blank 

STRHOR 

03C 

DP 

s d

Horizontal synchronization signal 

STRLONG 

03E 

D 

s d

Long horizontal line marker 

The following registers can be accessed by Copper when COPCON =  1.

Name 

Reg.addr. 

Chip 

R/W 

p/d

Function 

BLTCONO 

A 

w

P 

Blitter control register 0 

BLTCON1 

A 

w

P 

Blitter control register 1 

BLTAFWM 

A 

w

P 

Mask for first data word from A 

BLTALWM 

A 

w

P 

Mask for last data word from A 

BLTCPTH 

A 

w

P 

Address of source data C  bits 16-20 

BLTCPTL 

04A 

A 

w

P 

Address of source data C  bits 1-15 

BLTBPTH 

04C 

A 

w

P 

Address of source data B  bits 16-20 

BLTBPTL 

04E 

A 

w

P 

Address of source data B  bits 1-15 

BLTAPTH 

A 

w

P 

Address of source data A  bits 16-20 

BLTAPTL 

A 

w

P 

Address of source data A  bits 1-15 

BLTDPTH 

A 

w

P 

Address of destination data D  bits 1 6-20 

BLTDPTL 

A 

w

P 

Address of destination data D  bits 1-15 

BLTSIZE 

A 

w

P 

Start bit and size of Blitter window 

BLTCONOL 

05A 

A 

w

P 

Like BLTCONO, bits 0-7 

BLTSIZEV 

05C 

A 

w

P 

Width of Blitter window 

BLTSIZEH 

05E 

A 

w

P 

Height of Blitter window 

BLTCMOD 

A 

w

P 

Blitter modulo for source data C 

BLTBMOD 

A 

w

P 

Blitter modulo for source data B 

BLTAMOD 

A 

w

P 

Blitter modulo for source data A 

BLTDMOD 

A 

w

P 

Blitter modulo for destination data D 

— 

Unused 

— 

06A 

Unused 

— 

06C 

Unused 

— 

06E 

Unused 

BLTCDAT 

A 

w d

Blitter source data register C 

BLTBDAT 

A 

w d

Blitter source data register B 

BLTADAT 

A 

w d

Blitter source data register A 

— 

Unused 

— 

Unused 

— 

07A 

Unused 

DENISEID 

07C 

D 

r

P 

Chip identification from Denise 

DSKSYNC 

07E 

P 

w

P 

Disk sync pattern 

The following registers can always be written by the Copper.

Name 

Reg.addr. 

Chip 

R/W 

p/d

Function 

COP1LCH 

A 

w

P 

Address of 1st Copper list bits 16-20 

COP1LCL 

A 

w

P 

Address of 1st Copper list bits 1-15 

COP2LCH 

A 

w

P 

Address of 2nd Copper list bits 16-20 

COP2LCL 

A 

w

P 

Address of 2nd Copper list bits 1-15 

COPJMP1 

A 

s

P 

Jump to start of 1st Copper list 

COPJMP2 

08A 

A 

s

P 

Jump to start of 2nd Copper list 

COPINS 

08C 

A 

w d

Copper command register 

DIWSTRT 

08E 

A 

w

P 

Upper left corner of display window 

DIWSTOP 

A 

w

P 

Lower right corner of display window 

DDFSTRT 

A 

w

P 

Start of bit-plane DMA (horiz. pos.) 

DDFSTOP 

A 

w

P 

End of bit-plane DMA (horiz. pos.) 

Name 

Reg.addr. 

Chip 

R/W 

p/d

Function 

DMACON 

ADP 

w p

Write DMA control register 

CLXCON 

D 

w p

Write collision control register 

INTENA 

09A 

P 

w p

Write interrupt enable 

INTREQ 

09C 

P 

w p

Write interrupt request 

ADKCON 

09E 

P 

w p

Audio, disk and UART control register 

AUDOLCH 

0A0 

A 

w p

Address of audio data bits 16-20 

AUDOLCL 

0A2 

A 

w p On sound channel 0, bits 1-15

AUDOLEN 

0A4 

P 

w p

Channel 0  length of audio data 

AUDOPER 

0A6 

P 

w p

Channel 0  period duration 

AUDOVOL 

0A8 

P 

w p

Channel 0  volume 

AUDODAT 

OAA 

P 

w d

Channel 0  audio data (to D/A converter) 

— 

OAC 

Unused 

— 

OAE 

Unused 

AUD1LCH 

0B0 

A 

w p

Address of audio data bits 16-20 

AUD1LCL 

0B2 

A 

w p On sound channel 1, bits 1-15

AUD1LEN 

0B4 

P 

w p

Channel 1  length of audio data 

AUDI PER 

0B6 

P 

w p

Channel 1  period duration 

AUDI VOL 

0B8 

P 

w p

Channel 1  volume 

AUDI DAT 

OBA 

P 

w d

Channel 1  audio data (to D/A converter) 

— 

OBC 

Unused 

— 

OBE 

Unused 

AUD2LCH 

OCO 

A 

w p

Address of audio data bits 16-20 

AUD2LCL 

0C2 

A 

w p On sound channel 2, bits 1-15

AUD2LEN 

0C4 

P 

w p

Channel 2  length of audio data 

AUD2PER 

0C6 

P 

w p

Channel 2  period duration 

AUD2VOL 

0C8 

P 

w p

Channel 2  volume 

AUD2DAT 

OCA 

P 

w d

Channel 2  audio data (to D/A converter) 

— 

OCC 

Unused 

— 

OCE 

Unused 

AUD3LCH 

ODO 

A 

w

P 

Address of audio data bits 1 6-20 

AUD3LCL 

0D2 

A 

w

P 

On sound channel 3, bits 1-15

AUD3LEN 

0D4 

P 

w

P 

Channel 3  length of audio data 

AUD3PER 

0D6 

P 

w

P 

Channel 3  period duration 

AUD3VOL 

0D8 

P 

w p

Channel 3  volume 

AUD3DAT 

ODA 

P 

w d

Channel 3  audio data (to D/A converter) 

— 

ODC 

Unused 

— 

ODE 

Unused 

BPL1PTH 

OEO 

A 

w

P 

Address of bit-plane 1, bits 16-20 

BPL1PTL 

0E2 

A 

w

P 

Address of bit-plane 1 , bits 1-15 

BPL2PTH 

0E4 

A 

w

P 

Address of bit-plane 2, bits 16-20 

BPL2PTL 

0E6 

A 

w

P 

Address of bit-plane 2, bits 1-15 

BPL3PTH 

0E8 

A 

w

P 

Address of bit-plane 3, bits 16-20 

BPL3PTL 

OEA 

A 

w

P 

Address of bit-plane 3, bits 1-15 

BPL4PTH 

OEC 

A 

w

P 

Address of bit-plane 4, bits 16-20 

BPL4PTL 

OEE 

A 

w

P 

Address of bit-plane 4, bits 1-15 

BPL5PTH 

OFO 

A 

w

P 

Address of bit-plane 5, bits 16-20 

BPL5PTL 

0F2 

A 

w

P 

Address of bit-plane 5, bits 1-15 

BPL6PTH 

0F4 

A 

w

P 

Address of bit-plane 6, bits 16-20 

BPL6PTL 

0F6 

A 

w

P 

Address of bit-plane 6, bits 1-15 

— 

0F8 

Unused 

Name 

Reg.addr. 

Chip 

R/W p/d Function 

— 

OFA 

— 

OFC 

— 

OFE 

BPLCONO 

AD 

w p

BPLCON1 

D 

w p

BPLCON2 

D 

w p

BPLCON3 

D 

w p

BPL1MOD 

A 

w p

BPL2MOD 

10A 

A 

w p

— 

10C 

— 

10E 

BPL1DAT 

D 

w d

BPL2DAT 

D 

w d

BPL3DAT 

D 

w d

BPL4DAT 

D 

w d

BPL5DAT 

D 

w d

BPL6DAT 

11A 

D 

w d

— 

11C 

— 

11E 

SPROPTH 

A 

w

P 

SPROPTL 

A 

w

P 

SPR1PTH 

A 

w

P 

SPR1PTL 

A 

w

P 

SPR2PTH 

A 

w

P 

SPR2PTL 

12A 

A 

w

P 

SPR3PTH 

12C 

A 

w

P 

SPR3PTL 

12E 

A 

w

P 

SPR4PTH 

A 

w

P 

SPR4PTL 

A 

w

P 

SPR5PTH 

A 

w

P 

SPR5PTL 

A 

w

P 

SPR6PTH 

A 

w

P 

SPR6PTL 

13A 

A 

w

P 

SPR7PTH 

13C 

A 

w

P 

SPR7PTL 

13E 

A 

w

P 

SPROPOS 

AD 

w dp

SPROCTL 

AD 

w dp

SPRODATA 

D 

w dp

SPRODATB 

D 

w dp

SPR1POS 

AD 

w dp

SPR1CTL 

14A 

AD 

w dp

SPR1DATA 

14C 

D 

w dp

SPR1DATB 

14E 

D 

w dp

SPR2POS 

AD 

w dp

SPR2CTL 

AD 

w dp

SPR2DATA 

D 

w dp

SPR2DATB 

D 

w dp

SPR3POS 

AD 

w dp

SPR3CTL 

15A 

AD 

w dp

SPR3DATA 

15C 

D 

w dp

Unused 

Unused 

Unused 

Bit-plane control register 0 

Control register 1  (scroll values) 

Control register 2  (priority control) 

Control register 3 

Bit-plane modulo for uneven planes 

Bit-plane modulo for even planes 

Unused 

Unused 

Bit-plane 1  data (to RGB output) 

Bit-plane 2  data (to RGB output) 

Bit-plane 3  data (to RGB output) 

Bit-plane 4  data (to RGB output) 

Bit-plane 5  data (to RGB output) 

Bit-plane 6  data (to RGB output) 

Unused 

Unused 

Sprite data 0, bits 16-18 

Sprite data 0, bits 1-15 

Sprite data 1 , bits 16-18 

Sprite data 1, bits 1-15 

Sprite data 2, bits 16-18 

Sprite data 2, bits 1-15 

Sprite data 3, bits 16-18 

Sprite data 3, bits 1-15 

Sprite data 4, bits 16-18 

Sprite data 4, bits 1-15 

Sprite data 5, bits 16-18 

Sprite data 5, bits 1-15 

Sprite data 6, bits 16-18 

Sprite data 6, bits 1-15 

Sprite data 7, bits 16-18 

Sprite data 7, bits 1-15 

Sprite 0  start position (vert, and horiz.) 

Sprite 0  control reg. and vertical stop 

Sprite 0  data register A  (to RGB output) 

Sprite 0  data register B  (to RGB output) 

Sprite 1  start position (vert, and horiz.) 

Sprite 1  control reg. and vertical stop 

Sprite 1  data register A  (to RGB output) 

Sprite 1  data register B  (to RGB output) 

Sprite 2  start position (vert, and horiz.) 

Sprite 2  control reg. and vertical stop 

Sprite 2  data register A  (to RGB output) 

Sprite 2  data register B  (to RGB output) 

Sprite 3  start position (vert, and horiz.) 

Sprite 3  control reg. and vertical stop 

Sprite 3  data register A  (to RGB output) 

Name 

Reg.addr. 

Chip 

R/W 

p/d

Function 

SPR3DATB 

15E 

D 

w dp

Sprite 3  data register B  (to RGB output) 

SPR4P0S 

AD 

w dp

Sprite 4  start position (vert, and horiz.) 

SPR4CTL 

AD 

w dp

Sprite 4  control reg. and vertical stop 

SPR4DATA 

D 

w dp

Sprite 4  data register A  (to RGB output) 

SPR4DATB 

D 

w dp

Sprite 4  data register B  (to RGB output) 

SPR5P0S 

AD 

w dp

Sprite 5  start position (vert, and horiz.) 

SPR5CTL 

16A 

AD 

w dp

Sprite 5  control reg. and vertical stop 

SPR5DATA 

16C 

D 

w dp

Sprite 5  data register A  (to RGB output) 

SPR5DATB 

16E 

D 

w dp

Sprite 5  data register B  (to RGB output) 

SPR6P0S 

AD 

w dp

Sprite 6  start position (vert, and horiz.) 

SPR6CTL 

AD 

w dp

Sprite 6  control reg. and vertical stop 

SPR6DATA 

D 

w dp

Sprite 6  data register A  (z. RGB output.) 

SPR6DATB 

D 

w dp

Sprite 6  data register B  (to RGB output) 

SPR7P0S 

AD 

w dp

Sprite 7  start position (vert, and horiz.) 

SPR7CTL 

17A 

AD 

w dp

Sprite 7  control reg. and vertical stop 

SPR7DATA 

17C 

D 

w dp

Sprite 7  data register A  (to RGB output) 

SPR7DATB 

17E 

D 

w dp

Sprite 7  data register B  (to RGB output) 

COLOROO 

D 

w p

Color palette register 0  (color table) 

COLOR01 

D 

w p

Color palette register 1  (color table) 

COLOR02 

D 

w p

Color palette register 2  (color table) 

COLOR03 

D 

w p

Color palette register 3  (color table) 

COLOR04 

D 

w p

Color palette register 4  (color table) 

COLOR05 

18A 

D 

w p

Color palette register 5  (color table) 

COLOR06 

18C 

D 

w p

Color palette register 6  (color table) 

COLOR07 

18E 

D 

w p

Color palette register 7  (color table) 

COLOR08 

D 

w p

Color palette register 8  (color table) 

COLOR09 

D 

w p

Color palette register 9  (color table) 

COLOR10 

D 

w p

Color palette register 10 (color table) 

COLOR11 

D 

w p

Color palette register 1 1 (color table) 

COLOR12 

D 

w p

Color palette register 12 (color table) 

COLOR13 

19A 

D 

w p

Color palette register 13 (color table) 

COLOR14 

19C 

D 

w p

Color palette register 14 (color table) 

COLOR15 

19E 

D 

w p

Color palette register 15 (color table) 

COLOR 16 

1A0 

D 

w p

Color palette register 16 (color table) 

COLOR 17 

1A2 

D 

w p

Color palette register 17 (color table) 

COLOR 18 

1A4 

D 

w p

Color palette register 18 (color table) 

COLOR19 

1A6 

D 

w p

Color palette register 19 (color table) 

COLOR20 

1A8 

D 

w p

Color palette register 20 (color table) 

COLOR21 

1AA 

D 

w p

Color palette register 21 (color table) 

COLOR22 

1AC 

D 

w p

Color palette register 22 (color table) 

COLOR23 

1AE 

D 

w p

Color palette register 23 (color table) 

COLOR24 

1B0 

D 

w p

Color palette register 24 (color table) 

COLOR25 

1B2 

D 

w p

Color palette register 25 (color table) 

COLOR26 

1B4 

D 

w p

Color palette register 26 (color table) 

COLOR27 

1B6 

D 

w p

Color palette register 27 (color table) 

COLOR28 

1B8 

D 

w p

Color palette register 28 (color table) 

COLOR29 

1BA 

D 

w p

Color palette register 29 (color table) 

COLOR30 

1BC 

D 

w p

Color palette register 30 (color table) 

COLOR31 

1BE 

D 

w p

Color palette register 31 (color table) 

HTOTAL 

1C0 

A 

w p

Clock count per line (VARBEAM=1) 

Name 

Reg.addr. Chip R/W p/d Function 

HSSTOP 

1C2 

A 

w p

H-sync stop position 

HBSTRT 

1C4 

A 

w p

H-blank start position 

HBSTOP 

1C6 

A 

w p

H-blank stop position 

VTOTAL 

1C8 

A 

w p

Number of lines per picture 

VSSTOP 

1CA 

A 

w p

V-sync stop line 

VBSTRT 

1CC 

A 

w p

V-blank start line 

VBSTOP 

1CE 

A 

w p

V-blank stop line 

SPRHSTRT 

1D0 

A 

w p

UHRES sprite start line 

SPRHSTOP 

1D2 

A 

w p

UHRES sprite stop line 

BPLHSTRT 

1D4 

A 

w p

UHRES bit-plane start line 

BPLHSTOP 

1D6 

A 

w p

UHRES bit-plane stop line 

HHPOSW 

1D8 

A 

w p

Write DUAL-mode column counter 

HHPOSR 

1DA 

A 

r p

Read DUAL-mode column counter 

BEAMCONO 

1DC 

A 

w p

Raster beam control register 

HSSTRT 

1DE 

A 

w p

H-sync start position 

VSSTRT 

1E0 

A 

w p

V-sync start position 

HCENTER 

1E2 

A 

w p

H-pos. of V-sync in interlace mode 

DIWHIGH 

1E4 

A,D 

w p

Screen window, upper bits for start/stop 

BPLHMOD 

1E6 

A 

w p

UHRES bit-plane modulo 

SPRHPTH 

1E8 

A 

w p

UHRES sprite pointer (bits 16-20) 

SPRHPTL 

1EA 

A 

w p

UHRES sprite pointer (bits 0-15) 

BPLHPTH 

1EC 

A 

w p

UHRES bit-plane pointer (bits 16-20) 

BPLHPTL 

1EE 

A 

w p

UHRES bit-plane pointer (bits 0-15) 

The registers 1 F0 to 1 FC are unoccupied

ROM 

The figure on page 771 shows the ROM area as it appears after booting. The 512K of ROM at $00F80000 contains the Amiga Kickstart. This configuration can change. After a  reset, the 68030 fetches the address of the first instruction from memory location 4, called the reset vector. If the memory configuration could not be changed, the 68000 would fetch the reset vector from chip RAM, which is at address 4. Since the contents of this location are undefined at start-up, the processor would jump to some random address and the system would crash. The solution to this is as follows: The chip that is responsible for the memory configuration has an input that is connected to the lowest port line of CIA-A (PA0). This OVL
(Memory Overlay) line is normally at 0, and the memory configuration 

corresponds to the figure. After a  reset, the port line automatically goes high, causing the ROM area at $00F80000 to $00FFFFFF to be mapped into the range from 0  to $7FFFF. This means that address 4  (the reset vector) then corresponds to address $F80004. Here the 68030 finds a valid reset address, which tells it to jump to the Kickstart program. In the course of the reset routine the OVL line is set to 0  and the normal memory configuration returns.

You must be very careful when experimenting with this line. If the 

program that tries to set the OVL line is running in chip RAM, the result can be catastrophic, because the program more or less switches itself out of the memory range and the processor lands somewhere in the Kickstart, which takes the place of the chip RAM after the switch. Since the final version of the operating system was not yet ready when the first A3000's were manufactured, the Kickstart had to be booted from the hard disk. In place of the Kickstart, a  boot program was placed in
ROM. After the Kickstart was loaded to fast RAM, it would be 

transferred to $0OF800O0 with the 68030's PMMU.
