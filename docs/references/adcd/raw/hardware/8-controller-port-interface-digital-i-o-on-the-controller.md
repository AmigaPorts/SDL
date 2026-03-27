# 8 / Controller Port Interface / Digital I/O On The Controller Port


The Amiga can read and interpret many different and nonstandard
controllers. The control lines built into the POTGO register (address
$DFF034) can redefine the functions of some of the  [controller port](../Hardware_Manual_guide/node017D.html)  pins.

Table 8-4 is the POTGO register bit description. POTGO ($DFF034) is the
write-only address for the pot control register. POTGOR (formerly POTINP)
($DFF016) is the read-only address for the pot control register. The
pot-control register controls a four-bit bidirectional I/O port that
shares the same four pins as the four pot inputs.




```c
     Table 8-4: POTGO ($DFF034) and POTGOR ($DFF016) Registers

       Bit
       Number  Name    Function
       ------  ----    --------
       15      OUTRY   Output enable for bit 14 (1=output)
       14      DATRY   data for port 2, pin 9
       13      OUTRX   Output enable for bit 12
       12      DATRX   data for port 2, pin 5
       11      OUTLY   Output enable for bit 10
       10      DATLY   data for port 1, pin 9 (right  [mouse button](../Hardware_Manual_guide/node0180.html) )
       09      OUTLX   Output enable for bit 8
       08      DATLX   data for port 1, pin 5 (middle  [mouse button](../Hardware_Manual_guide/node0180.html) )
       07-01   X       chip revision identification number
       00      START   Start pots (dump capacitors, start counters)
```
Instead of using the pot pins as variable-resistive inputs, you can use
these pins as a four-bit input/output port.  This provides you with two
additional pins on each of the two  [controller ports](../Hardware_Manual_guide/node017D.html)  for general purpose
I/O.

If you set the output enable for any pin to a 1, the Amiga disconnects the
potentiometer control circuitry from the port, and configures the pin for
output.  The state of the data bit controls the logic level on the output
pin.  This register must be written to at the POTGO address, and read
from the POTGOR address. There are large capacitors on these lines, and
it can take up to 300 microseconds for the line to change state.

To use the entire register as an input, sensing the current state of the
pot pins, write all 0s to POTGO.  Thereafter you can read the current
state by using read-only address POTGOR.  Note that bits set as inputs
will be connected to the proportional counters (See the description of the
START bit in POTGO).

These lines can also be used for button inputs.  A button is a normally
open switch that shorts to ground.  The Amiga must provide a pull-up
resistance on the sense pin.  To do this, set the proper pin to output,
and drive the line high (set both OUT... and DAT... to 1).  Reading
POTGOR will produce a 0 if the button is pressed, a 1 if it is not.

The joystick fire buttons can also be configured as outputs.   [CIAADDRA](../Hardware_Manual_guide/node012E.html) 
($BFE201) contains a mask that corresponds one-to-one with the data read
register,  [CIAAPRA](../Hardware_Manual_guide/node012E.html)  ($BFE001). Setting a 1 in the direction position makes
the corresponding bit an output.  See Appendix F for more details.

