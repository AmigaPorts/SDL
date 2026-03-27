---
title: 28 / Animation with GELs / Animations Special Numbering System
manual: libraries
chapter: libraries
section: 28-animation-with-gels-animations-special-numbering-system
functions: [Animate]
libraries: [graphics.library]
---

# 28 / Animation with GELs / Animations Special Numbering System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Velocities and accelerations can be either positive or negative. The
system treats the velocity, acceleration and Ring values as fixed-point
binary fractions, with the decimal point at position 6 in the word.  That
is: vvvvvvvvvv.ffffff where v stands for actual values that you add to the
x or y ([AnX, AnY](libraries/28-specifying-the-animation-object-position-of-an-animob.md)) positions of the object for each call to [Animate()](libraries/28-animation-with-gels-moving-the-objects.md), and
f stands for the fractional part.  By using a fractional part, you can
specify the speed of an object in increments as precise as 1/64th of an
interval.

If you set the value of [XVel](libraries/28-animation-with-gels-animation-data-structures.md) at 0x0001, it will take 64 calls to the
[Animate()](libraries/28-animation-with-gels-moving-the-objects.md) routine before the system will modify the object's x coordinate
position by a step of one. The system constant ANFRACSIZE can be used to
shift values correctly.  So if you set the value to (1 << ANFRACSIZE), it
will be set to 0x0040, the value required to move the object one step per
call to Animate(). The system constant ANIMHALF can be used if you want
the object to move every other call to Animate().

Each call you make to [Animate()](libraries/28-animation-with-gels-moving-the-objects.md) simply adds the value of [XAccel](libraries/28-animation-with-gels-animation-data-structures.md) to the
current value of [XVel](libraries/28-animation-with-gels-animation-data-structures.md), and [YAccel](libraries/28-animation-with-gels-animation-data-structures.md) to the current value of [YVel](libraries/28-animation-with-gels-animation-data-structures.md), modifying
these values accordingly.

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
