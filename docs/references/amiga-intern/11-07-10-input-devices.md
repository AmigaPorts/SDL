# Mouse, Joystick and Paddles

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 11.7.10 Mouse, Joystick and Paddles

Mouse, joystick and paddles ~  all of these can be connected to the 

Amiga. We'll go through them in order, together with the corresponding 

registers. The pin assignment of the game ports, to which all of these input devices are connected, can be found in the section on interfaces.
Let's start with the mouse: 

The mouse The mouse is the most-often used input device. It's an important device for using the user-friendly interfaces of the Amiga. But how does it work and how is the mouse pointer on the screen created and moved? If you turn over the mouse, you'll see a  rubber-coated metal ball that turns when the mouse is moved. These rotations of the ball are transferred to two shafts, situated at right angles to each other so that one turns when the mouse is moved along the X  axis and the other when the mouse is moved along the Y  axis. If the mouse is moved diagonally, both shafts rotate corresponding to the X  and Y  components of the mouse movement. Unfortunately, rotating shafts don't help the Amiga when it wants to determine the position of the mouse. The mechanical movement must be converted into electrical signals. A wheel with holes around its circumference is attached to the end of each shaft for this purpose. When it rotates it repeatedly breaks a  beam of light in an optical coupler. The signal that results from this is amplified and sent out over the mouse cable to the computer. Now the Amiga can tell when and at what speed the mouse is moved. But it still doesn't know in what direction (i.e., left or right, forward or backward). A little trick solves this problem. Two optical couplers are placed on each wheel, set opposite each other and offset by half a  hole. If the disk rotates in a  given direction, one light beam is always broken before the other. If the direction is reversed, the order of the two signals from the optical coupler changes accordingly. This allows the Amiga to determine the direction of the movement. Therefore, the mouse returns four signals, two per shaft. They are called
Vertical Pulse, Vertical Quadrature Pulse, Horizontal Pulse and Horizontal 

Quadrature Pulse. 

The next figure shows the phase relationship of the horizontal pulse (H) and horizontal quadrature pulse (HQ) signals, but it also holds for the vertical signals. It's easy to see how H  and HQ differ from each other depending on the direction of movement. The Amiga performs logical operations on these two signals to obtain two new signals, XO and XI.
XI is an inverted HQ, and XO arises from an exclusive OR of H  and HQ 

(i.e., XO is 1  whenever H  and HQ are at different levels). 

With these two signals the Amiga controls a  6-bit counter which counts up or down on XI depending on the direction. Together with XO and XI an 8-bit value is formed which represents the current mouse position. If the mouse is moved right or down, the counter is incremented. If the mouse is moved left or up, it is decremented.

Denise contains four such counters, two per game port, since a  mouse 

can be connected to each one. They are called JOYDATO and JO YD ATI:

JOY0DAT$00A -  JOY1DAT$OOC 

(mouse on game port 0) -  (mouse on game port 1) 

Bit no.: 15 14 13 12 11 10 9       8 7       6 5       4 3 2 1 0 

Function: Y7 Y6 Y5 Y4 Y3 Y2 Y1 Y0 X7 X6 X5 X4 X3 X2X1X0 

Both registers are read-only. 

YO-7 Counter for vertical mouse movements (Y direction) 

HO-7 Counter for horizontal mouse movements (X direction) 

The mouse creates two hundred count pulses per inch, or about 79 per centimeter, which means that the limit of the mouse counter is soon reached. Eight bits yield a  count range from 0  to 255. Moving the mouse over four centimeters overflows the counters. This can occur when counting up (the counter jumps from 255 to 0) as well as counting down
(the counter jumps from 0  to 255). Therefore, the count registers must be 

read at given intervals to see if an overflow or underflow has occurred.

1 . Right movement 

h_I~

2. Left movement 

»_T~ 

HQ 

XO 

X1 

j — i r

Truth tables for XO and X1: 

H HO 

XO 

0 0 

0 1 

1 0 

1 1 

~1_ 

HQ |C1 

The mouse signals The operating system usually does this during the vertical blanking interrupt. This is based on the assumption that the mouse is not moved more than 127 count steps between two successive reads. The new counter state is compared with the last value read. If the difference is greater than 127, then the counter overflowed and the mouse was moved right or down. If it's less than -127, an underflow occurred corresponding to a  mouse movement left or up.

Old New 

Actual 

Under-/ 

counter state counter state

Difference 

mouse movement

Overflow 

100 200 

-100 

+100 

No 

200 100 

+100 

-100 

No 

50 200 

-150 

-105 

Underflow 

200 50 

+150 

+105 

Overflow 

Difference =  old counter state - 

new counter state If an underflow occurred, the actual mouse movement is calculated as follows:

1 -255 -  difference, or in numbers: -255 -  (50-200) =  -105 | 

For an overflow:

|255 -  difference, or in numbers: 255 -  (200-50) =  +105 | 

A positive mouse movement corresponds to a  movement right or up, a negative value to left or down. The mouse counters can also be set through software. A  value can be written to the counter through the JOYTEST register. JOYTEST operates on both game ports simultaneously, meaning that the horizontal and vertical counters of both mouse counters are initialized with the same value (JOY0DAT =  JOY1DAT).

JOYTEST $036 (write-only) 

Bit no.: 15 14 13 12 11 10 9       8 7        6 5       4 3       2 1        0 

Function: Y7 Y6 Y5 Y4 Y3 Y2 xx xx X7 X6 X5 X4 X3 X2 xx xx 

As you can see, only the high-order six bits of the counters can be affected. This makes sense when you remember that the lower two bits are taken directly from the mouse signals and aren't in an internal memory location that can be changed. The joysticks When you look at the pin-out of the game ports, you see that the four direction lines for the joysticks occupy the same lines as those for the mouse. Therefore, it seems reasonable that they can also be read with the same registers. In fact, the joystick lines are processed exactly like the mouse signals (i.e., each pair of lines is combined into the X0 and XI or
Y0 and Yl bits). 

The joystick position can be determined from these four bits:

Joystick right 

Joystick left 

Joystick backward 

Joystick forward 

X1 =  1 (bit 1  JOYxDAT) 

Y1 =  1 (bit 9  JOYxDAT) 

X0 EOR X1 =  1 (bits 0  and 1  JOYxDAT) 

Y0 EOR Y1 =  1 (bits 8  and 9  JOYxDAT) 

In order to detect whether the joystick has been moved backward or forward, you must take the exclusive OR of X0 and XI or Y0 and Yl, respectively. If the result is 1 , the joystick is in the position. The following assembly language routine reads the joystick on game port 1:

Test Joystick: 

MOVE.W $DFF00C, DO 

BTST #1, DO 

BNE RIGHT 

BTST #9, DO 

BNE LEFT 

MOVE.W D0,D1 

LSR.W #1,D1 

EOR.W D0,D1 

BTST #0, Dl 

BNE BACK 

BTST #8, Dl 

BNE FORWARD 

BRA MIDDLE 

Move JOY1DAT to DO 

Test bit no. 1 

Set? If so, joystick right 

Test bit no. 9 

Set? If so, joystick left 

Copy DO to Dl 

Move Yl and XI to position of Y0 and XO 

 Exclusive OR: Yl EOR Y0 and XI EOR XO 

Test result of XI EOR XO 

 Equal 1? If so, joystick backward 

Test result of Yl EOR Y0 

 Equal 1? If so, joystick forward 

,-Joystick is in middle position 

The exclusive OR operation is performed as follows in this program: A copy of the JOY 1  DAT register (previously moved to DO) is placed in
Dl and is shifted one bit to the right. Now XI in Dl and XO in DO have 

the same bit position, as do Yl and Y0. An EOR between DO and Dl exclusive ORs Y0 with Yl and XO with XI. Then all you have to do is test the result in Dl with the appropriate BTST commands. This program does not support diagonal joystick positions. The paddles The Amiga has two analog inputs per game port, to which variable resistors called potentiometers can be connected. These have in each position a  given resistance, which can be determined by the hardware in
Paula. A  paddle contains such a  potentiometer which can be set with a 

knob. Analog joysticks also work this way. One potentiometer for the X and one for the Y  direction determine the joystick position exactly.

Two registers contain the four 8-bit values of the analog inputs, 

POTODAT for game port 0  and POT1DAT for game port 1 : 

POT0DAT$012 POT1DAT$014 

Bit no.: T5 14" 13 12 TT 10 9        8 1       6 5       4 3       2 1        <T~
Function: Y7 Y6 Y5 Y4 Y3 Y2 Y1 YO X7 X6 X5 X4 X3 X2 X1 XO 

Both registers are read-only. 

How is the resistance measured? Since a  computer can process only 

digital signals, it needs a  special circuit to convert any analog signals it wants to work with. On the Amiga the value of external resistance is determined as follows: The potentiometers have a  maximum resistance of 470 kilo Ohms
(±10%). One side is connected to the +5-volt output and the other to 

one of the four paddle inputs of the game ports. These lead internally to the corresponding inputs of Paula and to one of four capacitors connected between the input and ground. The measurement is started by means of a  special start bit. Paula pulls all paddle inputs briefly to ground, discharging the capacitors. At this time the counters in the POTxDAT registers are also cleared. After this the counters increment by one with each screen line, while the capacitors are slowly recharged through the resistors. When the capacitor voltage exceeds a  given value, the corresponding counter is stopped. The counter state corresponds exactly to the size of the resistance. Small resistances yield low counter values, greater ones yield higher values. The start bit is located in the POTGO register:

POTGO $034 (write-only) -  POTGOR $016 (read-only) 

Bit no. Name 

Function 

OUTRY 

DATRY 

OUTRX 

DATRX 

OUTLY 

DATLY 

OUTLX 

DATLX 

7-1 

START 

Switch game port 1  POTY to output 

Game port 1  POTY data bit 

Switch game port 1  POTX to output 

Game port 1  POTX data bit 

Switch game port 0  POTY to output 

Game port 0  POTY data bit 

Switch game port 0  POTX to output 

Game port 0  POTX data bit 

Unused 

Discharge capacitors, begin measurement 

A write access to POTGO clears both POTxDAT registers.

Normally you set the START bit to 1  in the vertical blanking gap. Then 

while the picture is being displayed, the capacitors charge up, reach the set value and stop the counters. The valid potentiometer readings can then be taken from the POTxDAT registers in the next vertical blanking gap. The four analog inputs can also be programmed as normal digital input/output lines. The corresponding control and data bits are found together with the START bit in the POTGO register. Each line can be individually set to an output with the OUTxx bits (OUTxx =  1). This separates them from the control circuit of the capacitors and causes the value in the DATxx bit of POTGO to be output over them. Reading a
DATxx bit in POTGOR always returns the current state of the line. The 

following must be noted if the analog ports are used as outputs: Since the four analog ports are internally connected to the capacitors for resistance measurement (47 nF), it can take up to 300 microseconds for the line to assume the desired level due to the charging/discharging of the capacitor required. The input device buttons Each of the three input devices mentioned so far has one or more buttons. The following table shows which registers contain the status of the mouse, paddle and joystick buttons:

Game port 0: 

Left mouse button 

Right mouse button 

(Third mouse button 

Joystick fire button 

Left paddle button 

Right paddle button 

CIA-A, parallel port A, port bit 6        ~~ 

POTGOR, DATLY 

POTGOR, DATLX) 

CIA-A, parallel port A, port bit 6 

JOYODAT, bit 9  (1 =  button pressed) 

JOYODAT, bit 1  (1 =  button pressed) 

Game port 1 : 

Left mouse button 

Right mouse button 

(Third mouse button 

Joystick fire button 

Left paddle button 

Right paddle button 

CIA-A, parallel port A, port bit 7 

POTGOR, DATRY 

POTGOR, DATRX) 

CIA-A, parallel port A, port bit 7 

JOY1DAT, bit 9  (1 =  button pressed) 

JOY1DAT, bit 1  (1 =  button pressed) 

Unless otherwise indicated, all bits are active-zero, meaning 0  = button 

pressed.
