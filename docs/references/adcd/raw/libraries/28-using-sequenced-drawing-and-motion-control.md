# 28 / / / Using Sequenced Drawing and Motion Control


If you are using Ring Motion Control, you will probably set the velocity
and acceleration variables to zero.  For instance, consider the example of
a person walking.  With Ring Motion Control, as each foot falls it is
positioned on the ground exactly where originally drawn.  If you included
a velocity value, the person's foot would not be stationary with respect
to the ground, and the person would appear to "skate" rather than walk.
If you set the velocity and acceleration variables at zero, you avoid this
problem.

When the system activates a new [AnimComp](../Libraries_Manual_guide/node03B9.html#line3), it checks the [Flags](../Libraries_Manual_guide/node03B9.html#line12) field to see
if the [RINGTRIGGER](../Libraries_Manual_guide/node03C8.html) bit is set.  If so, the system adds [RingYTrans](../Libraries_Manual_guide/node0370.html) and
[RingXTrans](../Libraries_Manual_guide/node03B9.html#line48) to [AnY and AnX](../Libraries_Manual_guide/node03C6.html) respectively.

