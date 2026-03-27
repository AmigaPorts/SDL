# 28 / Animation with GELs / Animations Special Numbering System


Velocities and accelerations can be either positive or negative. The
system treats the velocity, acceleration and Ring values as fixed-point
binary fractions, with the decimal point at position 6 in the word.  That
is: vvvvvvvvvv.ffffff where v stands for actual values that you add to the
x or y ([AnX, AnY](../Libraries_Manual_guide/node03C6.html)) positions of the object for each call to [Animate()](../Libraries_Manual_guide/node03CC.html), and
f stands for the fractional part.  By using a fractional part, you can
specify the speed of an object in increments as precise as 1/64th of an
interval.

If you set the value of [XVel](../Libraries_Manual_guide/node03B9.html#line46) at 0x0001, it will take 64 calls to the
[Animate()](../Libraries_Manual_guide/node03CC.html) routine before the system will modify the object's x coordinate
position by a step of one. The system constant ANFRACSIZE can be used to
shift values correctly.  So if you set the value to (1 << ANFRACSIZE), it
will be set to 0x0040, the value required to move the object one step per
call to Animate(). The system constant ANIMHALF can be used if you want
the object to move every other call to Animate().

Each call you make to [Animate()](../Libraries_Manual_guide/node03CC.html) simply adds the value of [XAccel](../Libraries_Manual_guide/node03B9.html#line46) to the
current value of [XVel](../Libraries_Manual_guide/node03B9.html#line46), and [YAccel](../Libraries_Manual_guide/node03B9.html#line46) to the current value of [YVel](../Libraries_Manual_guide/node03B9.html#line46), modifying
these values accordingly.

