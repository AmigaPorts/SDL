# 28 / / Animation Types / Sequenced Drawing


To make the ball appear to rotate is a little more complex.  To produce
apparent movement within the image, sequencing is used.  This is done by
having a stack of [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)'s that are laid down one after the other, a
frame at a time.  The stack can be arranged in a circular list for
repeating movement.  So, when you combine a sequence of drawings using
AnimComps with simple motion control using an [AnimOb](../Libraries_Manual_guide/node03B9.html#line34), you can perform more
complex animations such as having a rotating ball bounce around.

