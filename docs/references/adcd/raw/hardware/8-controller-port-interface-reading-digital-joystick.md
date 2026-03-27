# 8 / Controller Port Interface / Reading Digital Joystick Controllers


Digital joysticks contain four directional switches.  Each switch can be
individually activated by the control stick.  When the stick is pressed
diagonally, two adjacent switches are activated.  The total number of
possible directions from a digital joystick is 8.  All digital joysticks
have at least one fire button.

Digital joystick switches are of the normally open type.  When the
switches are pressed, the input line is shorted to ground.  An open switch
reads as "1", a closed switch as "0".

Reading the joystick input data logic states is not so simple, however,
because the data registers for the joysticks are the same as the counters
that are used for the  [mouse or trackball](../Hardware_Manual_guide/node0180.html)  controllers. The joystick
registers are named  [JOY0DAT and JOY1DAT](../Hardware_Manual_guide/node0038.html) .

Table 8-3 shows how to interpret the data once you have read it from these
registers. The true logic state of the switch data in these registers is
"1 = switch closed."


   Data Bit                  Interpretation
   --------                  --------------
      1            True logic state of "right" switch.
      9            True logic state of "left"  switch.
   1 (XOR) 0       You must calculate the exclusive-or of bits 1 and 0
                     to obtain the logic state of the "back" switch.
   9 (XOR) 8       You must calculate the exclusive-or of bits 9 and 8


                     to obtain the logic state of the "forward" switch.
   Table 8-3: Interpreting Data from  [JOY0DAT and JOY1DAT](../Hardware_Manual_guide/node0038.html) 


The fire buttons for ports 0 and 1 are connected to bits 6 and 7 of
 [CIAAPRA](../Hardware_Manual_guide/node012E.html)  ($BFE001).  A 0 here indicates the switch is closed.

Some, but not all, joysticks have a second button.  We encourage the use
of this button if the function the button controls is duplicated via the
keyboard or another mechanism.  This button may be read in the same manner
as the right  [mouse button](../Hardware_Manual_guide/node0182.html) .


```c
     [Figure 8-3: Joystick to Counter Connections](../Hardware_Manual_guide/node02E5.html) 
```
