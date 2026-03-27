# Custom Chips and the Amiga

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

## 11.4 Custom Chips and the Amiga

The key component of every Amiga system, besides the processor, is the unit formed by Commodore's own specially developed custom chips,
Agnus, Denise and Paula. In the course of the Amiga's development, 

Agnus and Denise have undergone several revisions. The versions used 

•   in the Amiga 3000 are called 8372B, 8373 and 8364. These custom chips 

handle sound generation, screen display, processor-independent diskette access and much more. These tasks are not strictly divided up among the chips so that one is in charge of sound generation, one of graphics and another of diskette operation, which is usually the case with such devices. Instead most tasks are shared among the chips, so that graphics display, for example, is accomplished by two chips working together. Although the three chips could have been combined into one, it would be more expensive to produce such a  complex circuit than the three separate chips.

Other special components are also needed to control a  system as complex 

as the Amiga 3000. These include a  revised Buster chip for controlling the expansion slots, a  revised Gary as system controller, a  newly developed 32-bit DMA controller for the SCSI interface (needed by the hard disk), a  Western Digital SCSI interface chip, a  controller chip for the
FastRAM and a  component named Amber as core of the built-in flicker 

fixer. Before we explain how Agnus, Denise, Paula, and the other special components work, first we'll discuss the structure of the Amiga 3000.

### 11.4.1 Basic Structure of the Amiga

o and from hterf&CM

0 0 

The structure of the 68030 A simple computer system normally consists of a  processor, the ROM with the operating system, a  certain amount of RAM, and at least one peripheral component for data input and output. All components are connected to the address and data bus. The processor controls the system and only it can place addresses on the bus and thus read or write data to and from various system components, such as RAM. It also controls bus control signals like the R/W line. Every system also contains control circuits like an address decoder, which activates certain components based on values on the address bus. Now let's discuss the Amiga. As you can see from the above diagram, the structure of the Amiga deviates somewhat from what we described. On the left side you see the 68030 microprocessor, whose data and address lines are connected directly to the two 8520 CIAs, the Kickstart ROM, the real-time clock and the DMA controller. The Gary chip manages the control lines so that the 68030 can access all these different components. It informs the 68030, for example, whether it must perform a  16- or a  32- bit access to a  particular address. A new chip called Ramsey takes over the management of RAM
(configured with full 32-bit addresses, of course), with the capability of 

handling up to 16 Megabytes of fast RAM. This RAM can be accessed

by the DMA controller or DMA-capable expansion cards as well as by the processor. The four expansion slots are connected to the processor address and data lines with a  set of drivers. These drivers are controlled by the
A3000's Fat Buster chip, an enhanced version of the A2000's Buster. 

This chip also controls bus allocation on DMA access. When the SCSI controller or an expansion card wants to access RAM directly, first it must get permission to use the processor's bus lines. Buster manages these requests and communicates with the CPU, granting the appropriate
DMA controller permission to use the bus as soon as the CPU frees it. 

On the right side of the diagram we find the three custom chips Agnus,
Denise and Paula, and the chip RAM, which are all connected to a 

common data bus. However, this data bus is separated from the processor data bus by a  buffer, which can either connect the processor data bus to the chip data bus or can separate the two. The three custom chips are connected to each other through the address register bus, which is directed by Agnus. Since the chip RAM has a  much larger address range than the custom chips and also requires multiplexed addresses, there is a separate chip RAM address bus. Multiplexed addresses implies that the
RAM chips used in the Amiga have an address range of 2*8 addresses 

(256K) and in order to access all the addresses of a  chip, 18 address lines 

are needed. But the actual chips are very small, and such a  large number of address lines would require a  very large enclosure. To get around this problem, something called multiplexed addressing was introduced. The package has only nine address lines first the upper nine bits of the address and then the lower nine are applied to these lines. The chip stores the upper nine and then, when the lower nine are applied to the address lines, it has the 18 address bits that it needs.

Why are these two buses separated? The reason is that the various 

input/output devices need a  constant supply of data. For example, the data for individual dots on the screen must be read from the RAM fifty times per second, since a  television picture according to the PAL standard is refreshed at the rate of fifty times per second. A high-resolution graphic on the Amiga can require more than 64K of screen memory. This means that per second 50 x  64K access must be applied to memory. This is nearly 2  million memory accesses per second. If the processor had to perform this task, it would be hopelessly overloaded. Such a  high data rate would leave even the 68030 little time for anything else. Furthermore, the Amiga can perform digital sound output and diskette accesses in addition to the graphics, all without using the CPU. The solution lies in the use of another processor that performs all these memory accesses itself. Such a  processor is also called a
DMA (Direct Memory Access) controller, and the A3000 has two of 

them, the SCSI-DMA chip and Agnus. While the SCSI chip is needed only to speed up data transfer between
RAM and the SCSI interface, Agnus has more numerous and varied 

capabilities. However, Agnus can access only the chip RAM. Agnus contains not only the DMA controller, but also the RAM controller for the chip RAM. This is why Agnus is also connected to the chip RAM address bus. The processor can access chip RAM only by using Agnus. The other chips, Denise and Paula, and also the remainder of Agnus, are constructed like standard peripheral chips. They have a  certain number of registers which can be read or written by the processor (or the DMA controller). The individual registers are selected through the register address bus. It has eight lines, so 256 different states are possible. There is no special chip selection. If the address bus has the value 255 or $FF, so that all lines are high, no register is selected. If a  valid register number is on these lines, then the chip containing the selected register recognizes this and activates it. This task is performed in the individual chips by the register address decoders. The fact that the selection of a  register depends only on its register address and not on the chip in which it is located means that two registers in two different chips can be written with the same value if they have the same register address. This capability is used for some of the registers that contain data needed by more than one chip. Each chip register can be either a  read register or a  write register.
Switching between read and write by means of a  special R/W line, like in 

the 8520, is not possible. The register address alone determines whether a read or write address is taking place. Registers that can be both read and written are realized by having write access go to one register address and read access to another. This property is more clearly shown in the list of chip registers. Since Agnus contains the DMA controller, it can also access the custom chip registers itself by outputting an address on the register address bus.

One obvious problem is still unresolved. There is only one data bus and 

one address bus, which both the processor and the DMA controller want to access. A  bus can be controlled by only one bus controller at a  time. If two chips tried to place an address on the bus simultaneously, there would be a  problem known as bus contention, leading to a  system crash. Therefore the chips must share access to the bus by taking turns.
Naturally each would like to have the bus for itself as often as possible. 

This problem is solved by the Amiga on three levels:

First, both normally continuous buses are divided on the Amiga into two 

parts. One (on the left in the diagram) connects all the components that are usually accessed only by the processor. (Although the SCSI controller and expansion cards can also access RAM on the processor's behalf, these DMA accesses usually take place only when needed, for example, when accessing a  SCSI hard disk, which reduces processor speed.) When the 68030 accesses one of these components, Gary uses the buffers to break the connections of the processor address and data buses to the chip address and data buses. This way both the processor and Agnus, each on its own side, can access the bus undisturbed. This gives the processor quick access to the operating system and to its RAM. This RAM connected directly to the processor data and address bus is called fast RAM, since the processor can always access it without slowing down, if it has the bus at that moment.

Secondly, bus accesses from Agnus and from the processor are nested, so 

that normally even on accesses to chip RAM or chip registers, a  68000 does not have to be delayed. For such an access the buffers connect the two systems again. As a  third and final solution, the processor can wait until Agnus has finished its DMA accesses and the bus is free again. This occurs only when very high graphics resolutions have been selected or the Blitter is being used. Agnus, Denise and Paula were originally drafted for an
Amiga with a  68000 processor. Despite certain revisions for the A3000, 

they have some problems working with the 68030. Nesting the accesses to chip RAM on an Amiga with the 68000 enables alternating access so the processor does not have to wait. The A3000's 68030, however, accesses memory with substantially higher speed, while Agnus's clock frequency remains unchanged. The result is that the A3000's CPU must insert wait cycles when it wants to access chip RAM.

Another disadvantage of the custom chips is their limitation to a  16-bit 

wide data bus. While the A3000 manages chip RAM as true 32-bit RAM, special buffers are required for RAM access by Agnus to ensure that access proceeds to the correct half of the chip RAM data bus.

### 11.4.2 The Structure of Agnus

The 2  Meg version of Agnus in the A3000 is also called Super Agnus. All clock generation for the custom chips is integrated in Fat Agnus.
Only the 28 MHz base clock must be supplied. Agnus also assumes the 

management of chip RAM, generating the necessary RAS and CAS signals together with the multiplexed RAM addresses. Agnus can manage chip RAM on its own. But since the A3000's developers wanted to endow it with true 32-bit chip RAM access, a  conversion process was necessary to utilize the 16-bit wide data bus. Since Agnus is still used in the older Amiga models, other chips were connected to Agnus for this purpose, instead of being integrated into it.

Agnus's main responsibility is all of the DMA control. Each of the six 

possible DMA sources has its own control logic. They are all connected to the chip RAM address generator as well as the register address generator. These address generators create the RAM address of the desired chip RAM location and the register address of the destination register. In this manner the DMA logic units supply the appropriate chip registers with data from the RAM or write the contents of a  given register into RAM. Also connected to the chip RAM address generator is the refresh counter, which creates the refresh signals necessary for the operation of the dynamic RAM chips.

Agnus controls the synchronization of the individual DMA accesses. The 

fundamental reference for this is a  screen line. In each screen line, 255 memory accesses take place, which Agnus allocates among the individual
DMA channels and the 68030. Since it always needs the current row 

and column positions for this, Agnus also contains the raster and column counters. These counters for the beam position also create the horizontal and vertical synchronization signals, which signal to the monitor the start of a  new line (H-sync) and a  new picture (V-sync). The horizontal and vertical synchronization signals can also be fed in from outside Agnus

and then control the internal raster line and column counters. This allows the video picture of the Amiga to be synchronized to that of another source, such as a  video recorder. Called a  genlock, this is easily accomplished on the Amiga. (Simply stated, synchronizing two video pictures means that the individual raster lines and the individual pictures of the two signals start at the same time.)

Two other important elements in Agnus are the Blitter and the Copper 

coprocessor. The Blitter is a  special circuit that can manipulate or move areas of memory. It can be used to relieve the 68030 of some work, since it can perform these operations faster than the processor can. In addition, the Blitter is capable of drawing lines and filling surfaces. The Copper is a simple coprocessor. Its programs, called Copper lists, contain only three different commands. The Copper can change various chip registers at predetermined points in time. The following are the functions of the individual pins:

Data bus: D0-D15 

The 16 data lines are connected directly to the chip RAM data bus.
Internally all of the chip registers are connected through a  buffer to the 

bus.

Processor address bus: A1-A20 

These inputs are connected with the address lines of the 68030 and are used by Agnus when the CPU accesses chip RAM or one of the chip registers.

CPU bus signals: _LDS,_UDS,_R/W and _AS 

These signals inform Agnus about, among other things, the validity of processor addresses.

Register address bus: RGA1-RGA8 (ReGister Address) 

On a  DMA access Agnus selects the appropriate chip register over the register address bus. If the _REGEN line is low, meaning the processor is accessing a  chip register, Agnus transfers the CPU-referenced register address to the register address bus. With a  value of $FF on the register address bus (all lines high), this is inactive. The address lines for the dynamic RAM: DRA0-DRA9 (Dynamic RAM
Address) 

Agnus always generates the multiplexed addresses for the chip RAM. On 

a DMA access these originate from one of the internal address counters, the processor signals access to RAM (_RAMEN low), and Agnus simply switches the addresses through to chip RAM. Agnus can address 2  Meg of chip RAM (2x10 address lines for 20 address bits, 220 gives an area of roughly 1  million addresses, but since the chip RAM for Agnus has a width of 16 bits, the memory available to Agnus is 2  Meg). The chip RAM control lines: _RAS,_CASU,_CASL,_WE The _RAS and _CAS signals activate the dynamic RAM chips. The _WE line determines whether Agnus is writing data to chip RAM or reading from it. The bus control signals: _RAMEN, _REGEN, BLITS, _BUT These four lines are connected to Gary. With the _BLIT line Agnus tells
Gary that it will take over the bus on the next bus cycle. This line always 

takes precedence over a  processor bus request. If Agnus requires the bus for several consecutive bus cycles, the 68030 must wait. The _RAMEN (RAM ENable) and _REGEN (REGister ENable) inform
Agnus that the processor wants to access chip RAM or a  chip register. 

The BLITS signal (BLITter Slow down) signals Agnus that the processor is waiting for access. Depending on the internal status, Agnus gives up the bus to the processor for a  cycle. The control signals: RES, 1NT3, DMAL The RES signal (RESet) is connected directly to the system reset line and returns Agnus to a  predefined start-up state. The INT3 line (INTerrupt at level 3) is an output and is connected directly to the Paula line with the same name. Agnus uses this line to inform the interrupt logic in Paula that a  component in Agnus has generated an interrupt.

The DMAL line (DMA Request Line) also connects Agnus to Paula only this time the connection occurs in the opposite direction. Paula uses this line to tell Agnus to perform a  DMA transfer. The synchronization signals: HSY, VSY, CSY and LP

Normally the synchronization signals for the monitor appear on the HSY 

(Horizontal SYnc) and VSY (Vertical SYnc) lines. The signal on the CSY 

(Composite SYnc) line is the sum of HSY and VSY and is used to 

connect to monitors that need a  combined signal, as well as the circuit that creates the video signal, the video mixer. The LP line (Light Pen) is an input line for connecting a  light pen. The content of the raster counter register is stored when a  negative transition occurs on this pin. The HSY and VSY lines can also be used as inputs and thus allow Agnus to be externally synchronized (genlock). The clock lines: 28 MHz, 7  MHz, CCK, CCKQ, CDAC The 28 MHz signal forms the base clock for Agnus. The two 7-MHz signals, 7  MHz and _CDAC, and the two 3.5-MHz signals, CCK and
CCKQ, are produced from it. These four serve as clock signals for Denise, 

Paula and a  few other chips. 

### 11.4.3 The Structure of Denise

^J 

c r

CM 

=1 

"1 

c

*o 

H 

L 

<o 

J 

c u

0) 

J 

J 

c c

(D 

O 

J 

L_ 

J 

c c

Note: The arrows show the direction of the signal. 

A line above a  signal means the signal is active when low (0=active).

-► B2 

-►B1 

Denise 

In general, the function of Denise can be described as graph generation. The first part of this task is already accomplished by Agnus. Agnus fetches the current graphic data from the chip RAM and writes them to the registers responsible for the bit level manipulations in Denise. It does the same for the sprite data. Denise always contains all graphic and sprite

data for 16 pixels, since a  bit always corresponds to one pixel on the screen and the data registers all have a  width of one word, or 16 bits. These data must be converted into the appropriate RGB representation by Denise. First, the graphic data are converted from a  parallel 16-bit representation to a  serial data stream by means of the bit-level sequencer. Since a  maximum of six bit levels are possible, this function block is repeated six times. The serial data streams from the individual bit-level sequencers are now combined into a  maximum 6-bit wide data stream.

Collision 

control

Coif si on 

detector logic rCT

Chip 

control

Mouse 

counter
WY 

Bit plane 

sequencer

Bit plane 

A' \ 

Priority 

f— .i v  Priority
I j  control 

I \        register 

J Tn 

Sprite 

sequencer

Sprite 

Color 

lookup

^R03 

3 ~\ Q03 

11 ^B03 

Sprite 

control

Horiz. 

sync n zs: i=x

Internal data bus 

Register address decoder 

1 i    i i 

Sprite 

horiz. position

2Z2S1 

Bui* I BURST 

generator I

Block circuit diagram of Denise 

The priority control logic selects the valid data for the current pixel based on its priority from among the graphic data from the bit-level sequencers and the sprite data from the sprite sequencers. According to this data the color decoder selects one of the 32 color registers. The value of this register is then output as a  digital RGB signal. If the Hold-And-Modify
(HAM) or the Extra-Half-Bright (EHB) mode is selected, the data from 

the color register is modified accordingly before it leaves the chip. The data from the sequencers is also fed into the collision-control logic. As its name implies, this checks the data for a  collision between the bit levels and the sprites and places the results of this test into the collision register.

//. The A3000 Hardware 

The last function of Denise has nothing to do with the screen display.
Denise also contains the mouse counter, which contains the current X 

and Y  positions of the mice. Here is a  functional description of Denise's pins: The data bus: D0-D15 The 16 data bus lines are, like those of Agnus, connected to the chip data bus.

Register address bus: RGA1-RGA8 

The register address bus is a  pure input on Denise. The register address decoder selects the appropriate internal register with the help of the value on the register address bus. The clock inputs: CCK and 7M

Denise's timing is regulated by the CCK signal. The CCK pin is 

connected to the CCK pin on Agnus. The clock signal on the 7M line (7
Megahertz) has a  frequency of 7.15909 MHz. The Denise chip needs this 

additional frequency to output the individual pixels because the pixel frequency is greater than the 3.58 MHz of the CCK signal. A  pixel at the lowest resolution (320 pixels/line) has exactly the duration of a  7M clock signal. In high-resolution mode (640 pixels/line) two pixels are output per 7M cycle, one on each edge of its signal. The output signals: R0-3,
GO-3, B0-3, ZD and BURST. 

The lines R0-3, GO-3 and B0-3 represent the RGB outputs of Denise.
Denise outputs the corresponding values digitally. Each of the three 

color components is represented by four bits. This allows 16 values per component and 16x16x16 (4096) total colors. After they leave Denise, the three color signals run through a  buffer and then through three digital-to-analog converters to transform them into an analog RGB signal, which is then fed to the RGB port. The last output signal of Denise is the ZD signal (Zero Detect or background indicator). It is always low when a  pixel is being displayed in the background color (i.e., when its color comes from color register number 0). This signal is used in the genlock adapter for switching

between the external video signal (ZD=0) and the Amiga's video signal
(ZD=1). The ZD signal is also available on the RGB port. 

The mouse/ joystick inputs: MOH, M1H, MOV, M1V These four inputs correspond directly to the mouse inputs of the two game ports (or joystick connectors). Since the Amiga has two game ports, it must actually have eight inputs. Apparendy only four pins were free on
Denise so Commodore used the following method to read all the inputs: 

The eight input lines of the two game ports go to a  switch, which connects the four lines of either the front or the back port to the four inputs on Denise. This switching is performed in synchronization with
Denise's clock, so that Denise can internally distribute the four lines to 

two registers, one for each game port. The section on interfaces contains more information about the game ports.

### 11.4.4 The Structure of Paula

•4 — ► P0T1X 

ANAGND 

NOTE: 

The arrows show the direction of the signal. A line above a  signal means the signal is active when low (Osactive).

Paula 

Paula's tasks fall mainly in the I/O area, namely the diskette I/O, the serial 

I/O, the sound output and reading the analog inputs. In addition, Paula 

handles all interrupt control. All the interrupts that occur in the system run through this chip. From the fourteen possible interrupt sources, Paula creates the interrupt signals for the 68030. Interrupts on levels 1-6 are

generated on the 68030's IPL lines. Paula gives the programmer the possibility to allow or prohibit each of the fourteen interrupt sources. The disk data transfer and the sound output are performed using DMA. Since, in these two functions, Agnus does not know when the next data word is ready for a  DMA transfer, Paula has a  DMAL line, which it can use to tell Agnus when a  DMA access is needed. The serial communication is handled by a  UART (Universal
Asynchronous Receive Transmit) component inside Paula. 

The function of the UART, the four audio channels and the analog ports are described later in the section on programming the custom chips. The following is a  description of the pin functions:

DKRD 

DMAL 

TFCTT- 

INT3 - 

jFTTCT-
1FDT- 

IPL1 ■
IPL2 •

CCK - 

CCKQ - 

RES - 

RGA1-8 

00-15 

Block circuit diagram of Paula 

Data bus: DO-15 

As with the other chips, connected to the chip data bus.

//. The A3000 Hardware 

Register address bus: RGA 1-8 

As with Denise. The clock signals and reset: CCK, CCKQ and RES

Paula contains the same clock signals as Agnus. The reset line RES 

returns the chip to a  defined start-up state.

DMA request: DMAL 

With this line Paula signals Agnus that a  DMA transfer is needed.

Audio outputs: AUDL andAUDR 

The outputs AUDL and AUDR (AUDio Left and AUDio Right) are analog outputs on which Paula places the sound signals it generates.
AUDL carries the internal sound channels 0  and 3, and AUDR the 

channels 1  and 2. The serial interface lines: TXD andRXD

RXD (Receive Data) is the serial input to the UART, and TXD (Transmit 

Data) is the serial output. These lines have TTL levels, which means that 

their input/output voltages range from 0  to 5  volts. An additional level converter subsequently creates the +12/-5 volts for the Amiga's serial
RS232 interface. 

The analog inputs: POTOX, POTOY, POT1X, POT1Y The inputs POTOX and POTOY are connected to the corresponding lines from game port 0, and POT1X and POT1Y are connected to port 1.
Paddles or analog joysticks can be connected to these inputs. These 

input devices contain variable resistors, called potentiometers, which lie between +5 volts and the POT inputs. Paula can read the values of these resistors and place them in internal registers. The POT inputs can also be configured as outputs through software. Unfortunately the sampling rate is only 50 Hz (the screen repeat frequency). Therefore it is not possible, for example, to use a  VCR (Voltage Controlled Resistor) to digitize music and speech.

The disk lines: DKRD, DRWD, DKWE

Through the DKRD lines (DisK ReaD) Paula receives the read data from 

the diskette. The DKWD line (DisK Write) is the output for data to the disk drive. The DKWE line (DisK Write Enable) serves to switch the drive from read to write. The interrupt lines: 1NT2, 1NT3, INT6 and 1PL0, IPL1 , IPL2

Paula receives instructions through the three INT lines to create an 

interrupt on the appropriate level. The INT2 line is normally the one connected to the CIA-A 8520. This line is also connected to the expansion port and the serial interface. If it is low, Paula creates an interrupt on level 2, provided that an interrupt at this level is allowed. The INT3 line is connected to the corresponding output from Agnus and the INT6 line to CIA-B and the expansion port. All other interrupts occur within the I/O components in Paula. The IPL0-IPL2 lines (Interrupt Pending Level) are connected directly to the corresponding processor lines. Paula uses these to create a  processor interrupt at a  given level.
