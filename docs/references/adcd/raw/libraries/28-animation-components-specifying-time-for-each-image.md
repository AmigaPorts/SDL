# 28 / / Animation Components / Specifying Time for Each Image


The [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) members [Timer](../Includes_and_Autodocs_2._guide/node00C3.html#line176) and [TimeSet](../Includes_and_Autodocs_2._guide/node00C3.html#line183) are used to specify how long the
system should keep each sequential image on the screen.

When the system makes an animation component active, it copies the value
you have put in the [TimeSet](../Includes_and_Autodocs_2._guide/node00C3.html#line183) member into the [Timer](../Includes_and_Autodocs_2._guide/node00C3.html#line176) member.  As the
animation proceeds, the system decrements Timer; as long as it is greater
than zero, then that [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) remains active.  When the Timer value
reaches zero, the system makes the next AnimComp in the sequence active,
and the process repeats.

If you initialize the value in [TimeSet](../Includes_and_Autodocs_2._guide/node00C3.html#line183) to zero, the system will not
sequence this component at all (and Timer will remain zero).

