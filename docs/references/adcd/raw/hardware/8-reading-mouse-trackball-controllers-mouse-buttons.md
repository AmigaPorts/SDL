# 8 / / Reading Mouse/Trackball Controllers / Mouse Buttons


There are two buttons on the standard Amiga mouse. However, the control
circuitry and software support up to three buttons.

   *  The left button on the Amiga mouse is connected to  [CIAAPRA](../Hardware_Manual_guide/node012E.html) 

```c
      ($BFE001). Port 1 uses bit 6 and port 2 uses bit 7. A logic
      state of 1 means "switch open." A logic state of 0 means "switch
      closed." (See  [Appendix F](../Hardware_Manual_guide/node012E.html)  for more information.)
```
   *  Button 2 (right button on Amiga mouse) is connected to pin 9 of

```c
      the  [controller ports](../Hardware_Manual_guide/node017D.html) , one of the proportional pins.  See
       [Digital Input/Output on the Controller Port](../Hardware_Manual_guide/node018B.html)  for details.
```
   *  Button 3, when used, is connected to pin 5, the other

```c
      proportional  [controller input](../Hardware_Manual_guide/node017D.html) .
```
