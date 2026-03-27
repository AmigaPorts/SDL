# The Amiga Interfaces

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

Every computer needs contact with the outside world. Because of various connections and interfaces, it's possible to connect the Amiga to virtually any external device.

### 11.5.1 The Audio Outputs

TV modulator 

1 - 

2 GND 

3 Left audio channel 

4 Composite video output 

5 GND 

6 - 

7+12V 

8 Right audio channel 

Yellow jack 

Composite video signal 

Red jack 

Left audio channel 

White jack 

Left audio channel 

The audio outputs The audio signal is available through two phono connectors on the rear of the case. The right stereo channel is the red connector and the left is the white. A  standard stereo phono cable can be used to connect these jacks to a  stereo (AUX, TAPE or CD input). The output resistance of each channel is 1  KOhm (1000 Ohms). The outputs are protected against short circuit and have 360 Ohms impedance.

### 11.5.2 The RGB Connector

/©©©©©@©©©®©©\ 

\©®©©©®©@©©©/ 

INPUT 

XCLK 

External clock frequency 

INPUT 

XCLKEN 

Switch for external clock 

OUTPUT 

R 

Analog red signal 

OUTPUT 

G 

Analog green signal 

OUTPUT 

B 

Analog blue signal 

OUTPUT 

DI 

Digital brightness signal 

OUTPUT 

DB 

Pigital blue signal 

OUTPUT 

DG 

Digital green signal 

OUTPUT 

PR 

Digital red signal 

OUTPUT 

OCSY 

Buffered composite sync signal 

IN/OUT 

HSY 

Horizontal synchronization signal 

IN/OUT 

VSY 

Vertical synchronization signal 

.GND 

OUTPUT 

-ZP 

Background indicator signal 

OUTPUT 

C1U 

Amiga C1U timer (3.58 MHz) 

GND 

GND 

GND 

GND 

GND 

-5 volts 

+12 vc 

Its 

+5 volts 

The RGB connector The RGB connector allows various RGB monitors as well as special expansions, such as a  genlock adapter, to be connected to the Amiga. To connect an analog RGB monitor like the standard Amiga monitor, the three analog RGB outputs and the CompositeSync output are used. The
RGB signal on these three lines comes from the conversion of the 

buffered RGB digital signals from Denise into suitable analog signals by means of three 4-bit digital-to-analog converters. The Composite Sync signal comes from Agnus and is formed by mixing the horizontal and vertical sync signals. All of these four lines are provided with transistor buffers and 75 Ohm series resistances. The lines DI, DB, DG and DR are provided for connecting a  digital RGB monitor. The source of the digital RGB signals is the digital RGB output from Denise. Each of the three color lines is connected to the most significant (highest) respective color line from Denise (e.g., DB to B3 from Denise). Interestingly, the intensity or brightness line DI is connected to the BO line. The four lines have 47 Ohm output resistances and TTL levels. The HSY and VSY connections on the RGB connector are provided for monitors that require separate synchronization signals. Use these lines carefully, since they are connected through 47 Ohm resistors directly to the HSY and VSY pins of Agnus. They also have TTL levels. If the genlock bit in Agnus is set (see the section on programming the hardware), these two lines become inputs. The Amiga then synchronizes its own video signal to the synchronization signals on the HSY and VSY lines. These lines also require TTL levels as input. As usual, the synchronization signals are active low, which means that the lines are normally at 5  volts. Only during the active synchronization pulse is the line at 0  volts.

Using certain control bits from Agnus, it is also possible to reverse the 

polarity of the synchronization signals (refer to Section 1 1.7).

Kickstart Versions 1.2 and later automatically recognize on reset whether 

signals are present on the two Sync lines. If so, the Amiga switches to external synchronization.

Another signal, related to genlock, is the ZD signal (Zero Detect). The 

Amiga places this signal low whenever the pixel currently being 

displayed comes from a  specified color register or bit-plane.

During the vertical blanking gaps, when VSY=0, the function of the ZD 

line changes. Then it reflects the state of the GAUD (Genlock AUDio enable) bit from Agnus register $100 (BPLCON0). This signal is used by the genlock interface to switch the sound signal. The ZD line is usually of no interest to the normal user, since it is required only by the genlock interface. The ZD signal from Denise pin 33 is buffered with a  74HC244 driver, so that the signal has TTL levels.

7 7 .5 The Amiga Interfaces 

The remaining lines of the RGB connector have nothing to do with the
RGB signal. The C1U line is a  3.58 MHz clock line and corresponds to 

the inverted CLK signal of the custom chips. The XCLK (external CLocK) and XCLKEN (external CLocKENable) lines are used to feed an external clock frequency into the Amiga. All clock signals in the Amiga are derived from a  single 28MHz clock. This
28MHz master clock can be replaced by another clock frequency on the 

XCLK input by pulling the XCLKEN low. The ground pin 13 should be 

used when using the XCLK and XCLKEN lines. It is connected directly with the ground line of the clock generation circuit. The fed-in clock should not differ greatly from the master clock (28 MHz).

### 11.5.3 The VGA Connector

© ©   © 

© © 

1 Red 

2 Green 

3 Blue 

4-8 Ground 

10-12 Ground 

13 H-Sync 

14 V-Sync 

The VGA connector The VGA connector is used for connecting IBM- VGA-compatible or multisync monitors. It carries an analog RGB signal with separate H  and
V Sync lines. Internally it is connected to the flicker fixer output. A 

switch on the rear panel of the A3000 can be set so that the flicker fixer passes the RGB signal unchanged to the VGA connector. Since the synchronization signal on the VGA connector is output only, it is not possible to connect a  genlock adapter.

### 11.5.4 The Video Slot

The A3000 video slot is closely tied to the signals on the RGB port. It consists of two 36-pin slot connectors, identical to those of the expanded IBM bus, which are arranged in line with a  Zorro expansion slot. The slots have the following pin configurations:

Rear slot (relative to rear of chassis): 

Pin 

Function 

Pin 

Function 

Reserved 

Reserved 

Left audio output 

Right audio output 

Reserved 

+5 volts 

Analog red 

+5 volts 

Ground 

+12 volts 

Analog green 

Ground 

Ground 

Composite sync, direct 

Analog blue 

/XCLKEN 

Ground 

BURST 

/C4 sync signal 

Ground 

Ground 

Horizontal sync 

BO 

Ground 

B3 

Vertical sync 

G3 

Composite sync, buffered 

R3 

/ZD (also called /PIXELSW) 

-5 volts 

Ground 

XCLK 

/C1 sync signal 

+5 volts 

Pstrobe 

## 77.5 The Amiga Interfaces

Front slot: 

Pin 

Function 

Pin 

Function 

Ground 

RO 

R1 

R2 

Ground 

GO 

G1 

G2 

Ground 

B1 

B2 

Ground 

Composite video 

TBASE 

CDAC sync signal 

POUT (Paper out) 

/C3 sync signal 

BUSY 

/LPEN 

/ACK (Acknowledge) 

SEL (Select) 

Ground 

PDO 

PD1 

PD2 

PD3 

PD4 

PD5 

PD6 

PD7 

/LED 

Ground 

Left audio unfiltered 

Audio ground 

Right audio unfiltered 

Audio ground 

Almost all these signals are carried either by the RGB port or the 

Centronics port. The rest of the signals have the following meanings: 

Left and right audio outputs: 

These two pins are connected directly to the audio sockets.

Audio left/right unfiltered: 

The audio signals on these lines have not yet gone through the low pass filter.

7*0 to R3, BO to B3 and GO to G3: 

These are the digital RGB signals from Denise, buffered through
74HCT244. 

ILPEN: 

This is the Agnus lightpen input.

/LED: 

This indicates the status of the power LED control line. It tells the genlock card whether the audio filter is on or off.

Composite video: 

In the A3000, this signal occurs at this slot only (unlike the older Amiga models, which also had a  audio jack for it). It is a  video-compatible black- and-white signal that can be used, for example, to connect the Amiga to a
TV with video input. 

TBASE: 

TBASE is the time base for the CIA-A event counter, which Kickstart 

uses as a  system clock. A  jumper can be used to determine the source of
TBASE. This jumper, called J350, connects the TBASE line either with 

the ticks from the AC electrical source (50 Hz) or with the VSync line from Agnus. Since its frequency is also 50 Hz, the jumper position is normally the same. Preferably the jumper is on the source frequency (pins
1 and 2), which is generally more constant, causing the clock to run more 

accurately.

### 11.5.5 The Centronics Interface

The Centronics interface of the Amiga is a  computer enthusiast's dream.
Any one of a  tremendous array of IBM-compatible printers can be 

connected directly to it.

Output 

/Strobe -  data ready 

I/O 

PDO, Data bit 0 

I/O 

PD1, Data bit 1 

I/O 

PD2, Data bit 2 

I/O 

PD3, Data bit 3 

I/O 

PD4, Data bit 4 

I/O 

PD5, Data bit 5 

I/O 

PD6, Data bit 6 

I/O 

PD7, Data bit 7 

Input 

/Acknowledge -  Data received 

I/O 

BUSY -  printer busy 

I/O 

Paper out 

I/O 

Select -  printer ON-LINE 

+5 volts 

Unused 

Output 

Reset/buffered reset line from Amiga 

17-25 

GND 

Internally all of the Centronics port lines (except 5  volts and Reset) are 

connected directly to the port lines of the individual CIAs. The exact assignment is as follows:

Pin no. 

Function 

CIA 

Pin 

Designation j 

Strobe 

A 

PC 

Data bit 0 

A 

PBO 

Data bit 1 

A 

PB1 

Data bit 2 

A 

PB2 

Data bit 3 

A 

PB3 

Data bit 4 

A 

PB4 

Data bit 5 

A 

PB5 

Data bit 6 

A 

PB6 

Data bit 7 

A 

PB7 

Acknowledge 

A 

FLAG 

Busy 

B 

PAO 

and

SP 

Paper out 

B 

PA1 

and

CNT 

Select 

B 

PA2 

The Centronics interface is a  parallel interface. The eight data lines carry one data byte. When the computer has placed a  valid data byte on the data lines, it clears the STROBE line to 0  for 1.4 microseconds, signaling the printer that a  valid byte is ready for it. The printer must then acknowledge this by pulling the Acknowledge line low for at least one microsecond. Once the printer has indicated receipt of the data byte, the computer can place the next one on the bus. The printer uses the BUSY line to indicate that it is occupied and cannot accept any more data at the moment. This occurs when the printer buffer is full, for example. The computer then waits until BUSY goes high again before it continues sending data. With the Paper Out line the printer tells the computer that it is out of paper. The Select line is also controlled by the printer and indicates whether it is ONLINE (selected, SEL high) or OFFLINE (unselected, SEL low). The Centronics port is well suited as a  universal interface for connecting home-built expansions like an audio digitizer or an EPROM burner, since almost all of its lines can be programmed to be either inputs or outputs.

### 11.5.6 The Serial Interface

Amiga 500/Amiga 2000 

fui iTsi nri [TTirrii rf?i [2^ I2T1 f22i fail I24I ^

DB-25 male 

Amiga 1000 

jiEDEnaiigEmmsmmmEiiL

DB-25 female 

The serial interface The serial interface has all of the usual RS-232 signal lines. In addition, there are many signals on this connector that have nothing to do with serial communications. The lines TXD, RXD, DSR, CTS, DTR, RTS and
CD belong to the RS-232 interface. The TXD and RXD lines are the 

actual serial data lines. The TXD line is the serial output from the Amiga and RXD is the input. They are connected to the corresponding lines of Paula. The DTR line tells the peripheral device that the Amiga's serial interface is in operation.

Conversely, with the DSR line the peripheral device signals the Amiga 

that its interface is ready for operation. The RTS line tells the peripheral that the Amiga wants to send serial data over the RS-232. The peripheral uses the CTS line to tell the Amiga that it is ready to receive it. The CD signal is usually used only with a  modem and indicates that a  carrier frequency is being received. These five RS-
232 control lines are connected to CIA-B, PA3-PA7 as follows: DSR- 

PA3 CTS-PA4 CD-PA5 RTS-PA6 DTR-PA7. The RI line is connected 

through a  transistor to the SEL line of the Centronics interface.

GND 

Frame Ground 

Output 

TXD 

Transmit Data 

Input 

RXD 

Receive Data 

Output 

RTS 

Request To Send 

Input 

CTS 

Clear To Send 

Input 

DSR 

Data Set Ready 

GND 

Signal Ground 

Input 

CD 

Carrier Detect 

+12 volts 

-12 volts 

Output 

AUDOUT 

left sound channel output

Unused 

Unused 

Unused 

Unused 

Unused 

Unused 

Input 

AUDIN 

right sound channel input

Unused 

Output 

DTR 

Data Terminal Ready 

Unused 

Input 

RI 

Ring Indicator 

Unused 

Unused 

Unused 

Fortunately, the RS-232 lines are routed through RS-232 drivers instead of being connected directly to the chips. Thus with the appropriate cable, this interface can be connected to almost all the common terminals and modems. Type 1488 inverting RS-232 signal-converters are used as the output drivers. They operate on current supply in the range of +12 to -12 volts. This is the range of the output signals as well. As input buffers, type 1489 A chips are used. These accept an input range of -12 to +0.5 volts as low and a  range of +3 to +25 volts as high.

According to RS-232 interface conventions, the control lines must be 

active high, whereas the data lines RXD and TXD are active low (logic 1 is represented by a  low signal). Since the drivers invert, the CIA-B port bits that correspond to the control lines are also active low. This means that a  bit with the value 0  in CIA-B sets the corresponding RS-232 control line to high. This also applies to the inputs. The remaining lines on the RS-232 connector have nothing to do with
RS-232. The AUDOUT line is connected to the left audio channel and 

has its own 1  KOhm output resistance. The AUDIN line is connected directly to the AUDR pin of Paula through a  47 Ohm resistor. Audio signals fed into the Amiga on the AUDIN line are sent along with the right sound channel from Paula over the low-pass filter to the right audio output. Nothing else is done to the signal. The INT2 line is connected directly to the INT2 input of Paula and can generate a  level 2  processor interrupt if the corresponding mask bit is set in Paula (see the section on interrupts). The E  line is connected via a buffer to the processor E  clock (see 11.2.1). A  frequency of 3.58 MHz is available on the MCLK line, but this is neither in phase with the RGB interface clock nor with the two 3.58 MHz clocks of the custom chips.
Finally, the reset signal is also available on this connector. As you might 

expect, it too is buffered.

### 11.5.7 The External Drive Connector

.IIDHimHHHHHUIElUICiL 

[23] [22] [21] [20] [19] \n\ [T7] [7?] [l?] [u] Q5], 

DB-23 female 

The external drive connector

11 J The Amiga Interfaces 

Input 

/RDY 

Disk ready signal 

Input 

/DKRD 

Read data from disk 

GND 

GND 

GND 

GND 

GND 

Output 

/MTRX 

Motor on/off 

Output 

/SEL3 

Select drive 3 

Output 

/DRES 

Disk reset (turn motors off) 

Input 

/CHNG 

Disk change 

+5 volts 

Output 

/SIDE 

Side selection 

Input 

/WPRO 

Write protect 

Input 

/TKO 

Track 0  indicator 

Output 

/DKWE 

Switch to write 

Output 

/DKWD 

Write data to disk 

Output 

/STEP 

Move read/write head 

Output 

/DIR 

Direction of head movement 

unused

Output 

/SEL2 

Select drive 2 

Input 

/INDEX 

Index signal from drive 

+12 volts 

/CHNG 

/INUSE1 

/INUSE0 

/INDEX 

/SEL0 

/SEL1 

Unused 

/MTR0 

DIR 

/STEP 

/DKWD 

/DKWE 

/TKO 

/WPRO 

/DKRD 

/SIDE 

/RDY 

All odd pins are grounded.

Power connector for the internal drive: 

+5 volts 

GND 

GND 

+12 volts 

The disk drive connection on the Amiga is compatible with the Shugart bus. It allows up to four Shugart-compatible disk drives to be connected. The four drives are selected with the four drive selection SELx signals, where x  is the number of the drive to be selected. Two of the drives are intended for internal installation in the A3000, so only the lines SEL2 and SEL3 are available on the external drive connector. The SELO and
SEL1 lines are connected to the internal drives using the internal 

connector. The following is a  description of the Shugart bus signals on the Amiga:

SELX 

The Amiga uses the SELX line to select one of the four drives. Except for the MTRX and DRES lines, all other signals are active only after a  drive has been activated with the corresponding SELX line.

MTRX 

Normally this line turns on all the drive motors. Since this is not practical 

in a  system that can have up to four drives, each drive has its own flip- flop to allow the motors to be controlled separately. A  flip-flop is an electronic component that can store a  data bit. When a  given drive's SEL line goes low, the flip-flop for this drive takes on the value of the MTRX line. The output of the flip-flop is connected to the drive's MTR line. So, for example, if the SELO line is pulled low while the MTRX line is at 0, the motor of the first internal disk drive turns on. For the internal drives these flip-flops are located right on the motherboard. Their outputs are routed via an OR gate to the MTR line of the internal floppy connector. There are separate lines for the LEDs:
INUSEO and INUSE1. An additional flip-flop is required for each external 

drive.

RDY 

When a  drive's MTR line is at 0, the RDY (ReaDY) line is used to signal the Amiga that the drive motor has reached its optimum speed and the drive is now ready for read or write accesses. If the MTR line is at 1, meaning the drive motor is turned off, the RDY line is used for a  special identification mode (see the following).

DRES 

The DRES (Drive RESet) line is connected to the standard Amiga reset and is used only to reset the motor flip-flops so that all drive motors are turned off.

DKRD 

The data from the drive selected by SELX travels over the DKRD (DisK
Read Data) line to the DKRD pin on Paula. 

DKWD 

The DKWD (DisK Write Data) line carries data from Paula's DKWD pin to the current drive, where it is then written to the diskette.

DKWE 

The DKWE (DisK Write Enable) line switches the drive from read to write. If the line is high, data is read from the diskette. If it is low, data can be written.

SIDE 

The SIDE line determines which side of a  diskette will be selected for reading or writing. If it is high, side 0  (the lower read/write head) is active. If it is low, side 1  is active.

WPRO 

The WPRO (Write PROtect) line tells the Amiga whether the inserted diskette is write-protected. If a  write-protected diskette is in the drive, the
WPRO line is 0. 

//. The A3000 Hardware 

STEP 

A rising edge on the STEP line (transition from low to high) moves the read/write head of the drive one track in or out, depending on the state of the DIR line. The STEP signal should be at 1  when the SEL line of the activated drive is set back to high or there may be problems with the diskette-change detection.

DIR 

The DIR (DIRection) line sets the direction in which the head moves when a  pulse is sent on the STEP line. Low means that the head moves in toward the center of the disk and high indicates movement out toward the edge of the disk. Track 0  is the outermost track on the disk.

TKO 

The TKO (TracK 0) line is low whenever the read/write head of the selected drive is on track 0. This allows the head to be brought to a defined position.

INDEX 

The INDEX signal is a  short pulse which the drive delivers once per revolution of the diskette, between the start and end of a  track.

CHNG 

With the CHNG (CHaNGe) line, the drive notifies the Amiga of a  diskette change. As soon as the diskette is removed from the drive, the CHNG line goes to 0. It remains at 0  until the computer issues a  STEP pulse. If there is a  diskette in the drive again by this time, CHNG jumps back to 1.
Otherwise it remains at 0, and the computer must issue STEP pulses at 

regular intervals to detect when a  diskette has again been inserted in the drive. These regular STEP pulses are the cause of the clicking noise the
Amiga drive makes when no diskette is inserted. 

INUSEO, INUSEI 

The INUSE lines exist only on the internal floppy connector. If INUSEO is pulled low, drive DFO turns its LED on. INUSEI serves the same purpose for drive DF1. To recognize whether a  drive is connected to the bus, there is a  special drive identification mode. This involves reading a  serial 32-bit data word from the drive. To start the identification, the MTR line of the drive in question must be turned on briefly and then off again (the description of the MTRX line explains how this is done). This resets the serial shift register in the drive. The individual data bits can then be read by 32 iterations of the following procedure: pull the SELX line low, read the value of the RDY line as a  data bit, then return the SELX line to high. The first bit received is the MSB (Most Significant Bit) of the data word. Since the RDY line is active low, the data bits must be inverted. The following are the standard definitions for external drives:

$0000 0000 No drive connected (00) 

$FFFF FFFF Standard Amiga 3  1/2° drive (11) 

$5555 5555 Amiga 5  1/4" drive, 2x40 tracks (01) 

As you can see, there are currently so few different identifications that only the first two bits must be read. The values in parentheses are the combinations of these two bits. As mentioned before, all the lines except DRES affect only the drive selected by SELX. Originally the MTRX line was also independent of
SELX, but the Amiga developers changed this by adding the motor flip- 

flops. All lines on the Shugart bus are active low, since the outputs in the
Amiga as well as in the drives themselves are provided with open- 

collector drivers. In the Amiga these are type 7407 drivers. The four inputs CHNG, WPRO, TK0 and RDY are connected in this order directly to PA4-PA7 of CIA-A. The eight outputs STEP, DIR, SIDE,
SELO, SEL1, SEL2, SEL3 and MTR are connected through the 

previously mentioned drivers to the internal and external drive connectors. Since these drivers are non-inverting, the bits from the CIAs are inverted. The DKRD, DKW and DKWE lines come from Paula.

Except for the MTRX line and the SEL signals, the connections to the 

internal and external floppies are the same.

Installing a  second internal drive 

As mentioned earlier, a  second internal drive can be installed in the
A3000. If you examine the connecting cable for the built-in floppy, you 

will discover a  second plug as well as an additional power supply connector. On the built-in drive, usually next to the plug for the connecting cable, there is a  switch or jumper for selecting the SELX signal to which the drive should react. This switch should be set to SEL1, since SELO is already assigned to the first built-in floppy. The drive can then be installed and the cable connected. As a  final step, the Amiga must be told that an additional drive is present. This happens using the RDY line in the special identification procedure described earlier. The circuit in the A3000 that initiates this recognition procedure for the two internal drives is connected to the RDY line by means of the J351 jumper. This jumper is located on the left, next to the rear slot for the perpendicular bus board, directly behind Denise. Simply switch it over from pins 2-3 to 1-2.

### 11.5.8 The Game Ports

Use as: 

Mouse port 

Joystick 

Paddle 

Lightpen 

Input 

V-pulse 

Up 

Unused 

Unused 

Input 

H-pulse 

Down 

Unused 

Unused 

Input 

VQ-pulse 

Left 

Left button 

Unused 

Input 

HQ-pulse 

Right 

Right button 

Unused 

I/O 

(Button 3) 

Unused 

Right port 

Button

I/O 

Button 1

Firebutton 

Unused 

LP signal 

+5 volts 

+5 volts 

+5 volts 

+5 volts 

GND 

GND 

GND 

GND 

I/O 

Button 2

Unused 

Left port 

Unused 

0 0  0 0  0 

0 0  0 B 

9-pin female 

Game port pin configuration 

The game ports Game-Ports are inputs for input devices other than the keyboard, such as a  mouse, joystick, trackball, paddle or lightpen. There are two game ports, the left one being designated as game port 0  and the right as game port 1 . The pin assignment of both ports is identical, except that the LP line is present only on game port 0. Internally the game ports are connected to CIA- A, Agnus, Denise and Paula. The individual pins are wired as follows:

Game port 1: 

No. 

Chip 

Pin 

and

Denise 

Denise 

Denise 

Denise 

Paula 

CIA-A 

Agnus 

Paula 

MOV (via multiplexer) 

MOH (via multiplexer) 

M1V (via multiplexer) 

M1H (via multiplexer) 

POY 

PA6 

POX 

Game port 2: 

No. 

Chip 

Pin 

Denise 

Denise 

Denise 

Denise 

Paula 

MOV (via multiplexer) 

MOH (via multiplexer) 

M1V (via multiplexer) 

M1 H (via multiplexer) 

P1Y ! 

CIA-A 

PA7 

and

Agnus 

Paula 

LP 

P1X 

The function of the multiplexers was explained previously. The pin assignments for the various input devices were chosen so that almost all standard joysticks, mice, paddles and lightpens can be used. The button line is usually connected to a  switch that is pressed when the lightpen touches the screen. The LP line is the actual lightpen signal, which is generated by the electronics in the pen when the electron beam passes its tip. On the A 1000, the lightpen line was connected to game port 0. This meant that you had to use a  different mouse connection or disconnect the mouse entirely in order to use a  lightpen. Because of this disadvantage, the lightpen on the A3000 is normally connected to port 1 . Jumper J352 is used to select where the lightpen will go. Use the jumper to connect pins
2 and 3, and the lightpen will go to game port 1. 

All the lines labeled button and the four directions for the joystick are active low. The various input devices contain switches that connect their inputs to ground (GND). A  high signal on the input means an open switch, while a  closed switch generates a  low.

Variable resistors (potentiometers) can be connected to the POX, POY, 

P1X and P1Y analog inputs. Their value should be 470 KOhms and they 

should be connected between the corresponding inputs and +5 volts. The two fire-button lines connected to CIA-A can naturally also be programmed as outputs. Don't overwrite the lowest bit of the port register otherwise the system crashes (PA0:OVL). The section on programming the custom chips explains how the game port lines are read. The +5 volt line on the two game ports is not connected directly to the
Amiga power supply. A  current-protection circuit is inserted in these 

lines which limits the short-term peak current to 700 mA and the operating current to 400 mA.

11.5.9 

The Zorro Bus

Configuration of the 100-pin expansion slot: Zorro II 

GND 

GND 

GND 

GND 

+5 volts 

+5 volts 

/OWN 

-5 volts 

/SLAVEn 

+12 volts 

/CFGOUTn 

CFGINn 

GND 

/C3 

CDAC 

/C1 

/OVR 

XRDY 

/INT2 

-12 volts 

A5 

/INT6 

A6 

A4 

GND 

A3 

A2 

A7 

A1 

A8 

FCO 

A9 

FC1 

A10 

FC2 

A11 

GND 

A12 

A13 

/EINT7 

A14 

/EINT5 

A15 

/EINT4 

A16 

/BERR 

A17 

/VPA 

GND 

E 

/VMA 

A18 

/RES 

A19 

/HLT 

A20 

A22 

A21 

A23 

/BRn 

GND 

/BGACK 

PD15 

/BGn 

PD14 

/DTACK 

PD13 

/R/W 

PD12 

/LDS 

PD11 

/UDS 

GND 

/AS 

PDO 

PD10 

PD1 

PD9 

PD2 

PD8 

PD3 

PD7 

PD4 

PD6 

GND 

PD5 

GND 

GND 

GND 

GND 

GND 

7MHz 

DOE 

/BUSRST 

/GBG 

/EINT1 

reserved reserved

GND 

GND 

In the previous chart "n" equals the number of expansion slots (1-4). The set of four 100-pin expansion slots, called the Zorro bus, is located on the upright-mounted board in the center of the A3000. The slots can accept all types of expansion cards. On the A2000 this usually refers to hard disk controllers and RAM expansions, but on the A3000 is more likely to mean networks, high-resolution graphic cards, etc. For this reason the bus specifications have been thoroughly revised.
Expansion slots in the A3000 can now operate in two distinct modes: 

Zorro II compatible (as in the A2000) or the new Zorro III standard. 

The Zorro II mode is based mainly on the signals of the 68000:

A0-A23 

PD0-PD15 

IPLO -  IPL2 

FCO -  FC2 

/AS, /UDS, /LDS, /R/W, 

/DTACK, A/MA, A/PA 

/RES, /HLT, /BERR, /BG, 

/BGACK, /BR, E 

Address bus (24 bits, i.e., 16 Megabyte 

address space)
Processor data bus 

Processor interrupt lines 

Function code lines from the 68000 

Bus control lines 

Miscellaneous control lines from the 68000 

The remaining signals have the following functions:

INT2andINT6: 

These two lines are connected to the Paula pins with the same names. They are used to generate a  level 2  or level 6  interrupt.

CD AC, IC3, /CI, 7M and 28M: 

These are the various Amiga clock signals. The clock signals CCK and
CCKQ are generated by Agnus and serve as base clock signals for 

Agnus, Denise, Paula and the chip RAM. 

13 5     7 

2 4    6 8 

79 81 83 85 

80 82 84 86 

86-pin printed circuit connector 

(Amiga 500/Amiga 1000) 

Pin configuration of the expansion port 

/OVR 

With /OVR low the DTACK signal produced by Gary can be disabled for
the memory range from $200000 to $9FFFFF. 

IXRDY 

This signal serves a  similar purpose to /OVR. If /XRDY is pulled low less than 60 nanoseconds after /AS, Gary delays the /DTACK signal until
/XRDY again goes high. This allows the use of slow expansion cards that 

cannot respond without wait states.

/BUSRES 

This is a  buffered reset signal. While the Amiga can also be reset from an expansion card with the RES circuit, the /BUSRES line is intended only for resetting the card itself. Normally you would not want to reset the
Amiga from a  card, and should therefore only use the /BUSRES line. 

ISLAVEn 

Every slot has its own /SLAVE line. An expansion card must set /SLAVE to low as soon as it recognizes an address that is valid for it, so that the data and address buffers can be correctly switched. If more than one card sets /SLAVE to low, Gary generates a  bus error. The same holds true if a card outside the ranges $200000-$B7FFFF and $E80000-$EFFFFF has
/SLAVE set to low. 

ICFG1N and ICFGOUT 

The /CFGOUT (ConFiG-OUT) line of one slot is always connected to the
/CFGIN (ConFiG-IN) line of the next. Each card is configured as soon as 

the /CFGIN line of its slot is low. When the autoconfiguration of a  card is complete, it sets its /CFGOUT output to low to allow configuration of the card in the next slot to proceed.

DOE 

This signal comes from Buster and tells the active expansion card that it may activate its data drivers. This prevents data collisions.

IBRn, IBGn and IBGACK 

With these lines a  card can take over the bus, in effect becoming the
DMA controller. The ability to do this is required, for example, by a  fast 

network card. Bus control is assumed as follows: the card pulls /BR low
->, the processor responds with /BG ->, the card pulls /BGACK low and 

returns /BR to high. It now owns the bus until it returns /BGACK to high.

What happens, though, if two cards pull /BR low at the same instant? To 

avoid problems, each slot has its own /BR and /BG signals. If more than one slot activates its /BR signal, Buster sees the slot with the lowest number (the one nearest the coprocessor slot) first, and passes the /BR on to the 68030. The /BG response is returned by Buster to this same slot, which becomes bus master and pulls /BGACK low. The other slots that have their /BR lines low must wait until the one currently active has finished its DMA.

/OWN 

A card must pull this line low when it has assumed the role of bus master as previously described. This is necessary to reverse the direction of the data or address buffer, since the bus master generating the addresses is now on the other side of the buffer.

IGBG 

This is the original /BG from the processor.

//. The A3000 Hardware 

The interrupt lines /EINT1, IEINT4, IEINT5 and IEINT7 These lines generate the corresponding level interrupts. Unlike the /INT2 and /INT6 lines of the expansion port, they cannot be disabled using
Paula. 

Also on the Zorro bus are the different operating voltages of the A3000:
+/- 5  and 12 volts. 

The previous description of the pin configuration and functions refers to operation of the expansion bus in Zorro II mode. The A3000 also recognizes a  different type of bus protocol, the new Zorro III standard. When you insert an expansion card into the A3000, the expansion library contained in Kickstart, using the autoconfiguration information on the expansion, checks to see whether it is a  Zorro II or a  Zorro III card. If the library recognizes a  Zorro II card, for example, one developed also for the A2000 circuitry, the bus behaves as previously described, that is, compatible to the A2000 expansion slots. If the card is determined to be a  Zorro III card, the Amiga operating system assigns it an address outside the Amiga's former 16-Megabyte address space. The bus controller treats processor accesses to addresses within the first 16 Meg as Zorro II, and beyond that as Zorro III.

How does the Zorro III standard differ from Zorro II? 

Zorro III is a  completely new concept. Although the same 100-pin slots 

are used, the assignments of many of the lines have changed. The essential features of Zorro III are as follows:

• A  full 32 bits for data and address bus 

The Zorro III bus is a  32-bit bus system, fully supporting the capabilities of the 68030. Since a  slot's 100 pins are not sufficient for both data and address lines (2 x  32), these lines are multiplexed. To initiate an access, the Amiga places the 32 address bits on the bus. Then, using a  specific control signal, it tells the Zorro III expansion card to store this address. After that the address lines serve as data lines. Address bits 0-7 are not multiplexed, but rather remain stable throughout the access process.

Asynchronous bus control 

The speed of the old Zorro II bus was limited by the timing of the
68000. Bus transfer could not execute faster than a  68000 memory 

access at a  clock frequency of 7.14 MHz. The Zorro III timing is asynchronous, so the speed does not depend on how fast the
Amiga or card hardware may be (of course there are models with far 

higher clock frequencies than previously thought possible).

Enhanced interrupt capabilities 

In the Zorro III bus, expansions can finally fully utilize the interrupt capabilities of the 68030, meaning that a  card can use its own interrupt vectors (see the section on 68030).
