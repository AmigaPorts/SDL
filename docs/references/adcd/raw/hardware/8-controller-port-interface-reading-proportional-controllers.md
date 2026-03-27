# 8 / Controller Port Interface / Reading Proportional Controllers


Each of the game  [controller ports](../Hardware_Manual_guide/node017D.html)  can handle two variable-resistance
input devices, also known as proportional input devices. This section
describes how the positions of the proportional input devices can be
determined. There are two common types of proportional controllers:  the
"paddle" controller pair and the X-Y proportional joystick. A paddle
controller pair consists of two individual enclosures, each containing a
single resistor and fire-button and each connected to a common
 [controller port](../Hardware_Manual_guide/node017D.html)  input connector. Typical connections are shown in Figure
8-4.

    LEFT PADDLE                          RIGHT PADDLE

          resistive element                    resistive element

     ____/\  /\  /\  /\  /\____           ____/\  /\  /\  /\  /\____
    |      \/  \/  \/  \/                |      \/  \/  \/  \/
    |+5           ^                      |+5           ^
    |             |_ _ _ _ _ _           |             |_ _ _ _ _ _
                              |                                    |
  pin 7                     pin 9      pin 7                     pin 9



    |                         |          |                         |
    |<- - - fire button - - ->|          |<- - - fire button - - ->|
    |                         |          |                         |
  pin 8                     pin 3      pin 8                     pin 3




                Figure 8-4: Typical Paddle Wiring Diagram
In an X-Y proportional joystick, the resistive elements are connected
individually to the X and Y axes of a single controller stick.

 [Reading Proportional Controller Buttons](../Hardware_Manual_guide/node0185.html) 
 [Interpreting Proportional Controller Position](../Hardware_Manual_guide/node0186.html) 
 [Proportional Controller Registers](../Hardware_Manual_guide/node0187.html) 
 [Potentiometer Specifications](../Hardware_Manual_guide/node0188.html) 

