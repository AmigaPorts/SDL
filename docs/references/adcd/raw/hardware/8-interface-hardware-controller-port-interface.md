# 8 Interface Hardware / Controller Port Interface


Each Amiga has two  [nine-pin connectors](../Hardware_Manual_guide/node0109.html)  that can be used for input or
output with a variety of controllers.  Usually, the  [nine-pin connectors](../Hardware_Manual_guide/node0109.html) 
are used with a mouse or joystick but they will also accept input from
light pens, paddles, trackballs, and other popular input devices.

Figure 8-1 shows one of the two connectors and the corresponding face-on
view of a standard controller plug, while table 8-1 gives the pin
assignments for some typical controllers.

```c
     [Figure 8-1: Controller Plug and Computer Connector](../Hardware_Manual_guide/node02E4.html) 


                  Table 8-1: Typical Controller Connections

                       Mouse,
                     Trackball,  Proportional      X-Y
                      Driving     Controller   Proportional
```
  Pin    Joystick    Controller     (Pair)       Joystick    Light Pen
  ---    --------    ----------  ------------  ------------  ---------
  1      Forward     V-pulse       ---           Button 3**  ---

  2      Back        H-pulse       ---           ---         ---

  3      Left        VQ-pulse      Left button   Button 1    ---

  4      Right       HQ-pulse      Right button  Button 2    ---

  5*     ---         Middle        Right POT     POT X       Pen pressed

                     button**                                to screen
  6*     Button 1    Left button   ---           ---         Beam trigger

  7      ---         +5V           +5V           +5V         +5V

  8      GND         GND           GND           GND         GND

  9*     Button 2**  Right button  Left POT      POT Y       Button 2**




                *  These pins may also be configured as outputs
                ** These buttons are optional
 [Registers Used with the Controller Port](../Hardware_Manual_guide/node017E.html) 
 [Reading Mouse/Trackball Controllers](../Hardware_Manual_guide/node017F.html) 
 [Reading Digital Joystick Controllers](../Hardware_Manual_guide/node0183.html) 
 [Reading Proportional Controllers](../Hardware_Manual_guide/node0184.html) 
 [Reading a Light Pen](../Hardware_Manual_guide/node0189.html) 
 [Digital I/O on the Controller Port](../Hardware_Manual_guide/node018B.html) 

