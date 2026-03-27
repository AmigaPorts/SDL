# 28 / / Animation Types / Simple Motion Control


To produce motion of a simple object, such as a ball, the object is simply
moved relative to a background display, a little at a time.  This is
simple motion control, and can be accomplished with one [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) and one
[AnimOb](../Libraries_Manual_guide/node03B9.html#line34), by simply changing the AnimOb's position every N video frames.
The apparent speed of the object is a combination of how often it is moved
(every frame, every other frame, etc.) and how far it is moved (how much
the AnimOb's [AnX and AnY](../Libraries_Manual_guide/node03C6.html) are changed).

