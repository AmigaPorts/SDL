# E / / Game Controller Interface Specification / Mouse/Trackball


A mouse or trackball is a device that translates planar motion into pulse
trains.  Quadrature techniques are employed to preserve the direction as
well as magnitude of displacement.  The registers  [JOY0DAT and JOY1DAT](../Hardware_Manual_guide/node0038.html) 
become counter registers, with y displacement in the high byte and x in
the low byte.  Movement causes the following action:


        Up:    y decrements
        Down:  y increments
        Right: x increments
        Left:  x decrements
To determine displacement,  [JOYxDAT](../Hardware_Manual_guide/node0038.html)  is read twice with corresponding x and
y values subtracted (careful, modulo 128 arithmetic).  Note that if either
count changes by more than 127, both distance and direction become
ambiguous.  There is a relationship between the sampling interval and the
maximum speed (that is, change in distance) that can be resolved as
follows:


```c
     Velocity < Distance(max) / SampleTime

     Velocity < SQRT(DeltaX**2 + DeltaY**2) / SampleTime
```
For an Amiga with a 200 count-per-inch mouse sampling during each vertical
blanking interval, the maximum velocity in either the X or Y direction
becomes:


```c
    Velocity < (128 Counts * 1 inch/200 Counts) / .017 sec = 38 in/sec
```
which should be sufficient for most users.

   NOTE:
   -----
   The Amiga software is designed to do mouse update cycles during
   vertical blanking.  The horizontal and vertical counters are always
   valid and may be read at any time.


CONNECTOR PIN USAGE FOR MOUSE/TRACKBALL QUADRATURE INPUTS
---------------------------------------------------------

 PIN   MNEMONIC   DESCRIPTION                    HARDWARE REGISTER/NOTES
 ---   --------   -----------                    -----------------------
 1        V       Vertical pulses                JOY[0/1]DAT<15:8>
 2        H       Horizontal pulses              JOY[0/1]DAT(7:0>
 3        VQ      Vertical quadrature pulses     JOY[0/1]DAT<15:8>
 4        HQ      Horizontal quadrature pulses   JOY[0/1]DAT<7:0>
 5       UBUT*    Unused mouse button            See  [Proportional Inputs](../Hardware_Manual_guide/node010D.html#line44) .
 6       LBUT*    Left mouse button              See  [Fire Button](../Hardware_Manual_guide/node010C.html) .
 7       +5V      +5V, current limited
 8      Ground
 9       RBUT*    Right mouse button             See  [Proportional Inputs](../Hardware_Manual_guide/node010D.html#line44) .

