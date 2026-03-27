# E / Explanation of I/O Connectors / Game Controller Interface Spec


The two 9-pin D-type connectors with pins (male) are used to
interface to four types of devices:


```c
    1.  Mouse or trackball, 3 buttons max.
    2.  Digital joystick, 2 buttons max.
    3.  Proportional (pot or proportional joystick), 2 buttons max.
    4.  Light pen, including pen-pressed-to-screen button.
```
The connector pin assignments are discussed in sections organized
by similar hardware and/or software operating requirements as shown
in the previous list.  Signal names follow those used elsewhere
in this appendix, when possible.


```c
    J11 is the right controller port connector ( [JOY1DAT](../Hardware_Manual_guide/node0038.html) , [POT1DAT](../Hardware_Manual_guide/node003A.html) ).
    J12 is the left controller port connector ( [JOY0DAT](../Hardware_Manual_guide/node0038.html) , [POT0DAT](../Hardware_Manual_guide/node003A.html) ).
```
   NOTE:
   -----
   While most of the hardware discussed below is directly accessible,
   hardware should be accessed through ROM kernel software. This will
   keep future hardware changes transparent to the user.

 [Mouse/Trackball](../Hardware_Manual_guide/node010A.html)        [Proportional Controllers](../Hardware_Manual_guide/node010D.html) 
 [Digital Joysticks](../Hardware_Manual_guide/node010B.html)      [Light Pen](../Hardware_Manual_guide/node010E.html) 
 [Fire Buttons](../Hardware_Manual_guide/node010C.html) 

