# 5 / / Proportional Gadget Components / The Body Variables


The HorizBody and VertBody variables describe the standard increment by
which the [pot variables](../Libraries_Manual_guide/node015B.html) change and the relative size of the [knob](../Libraries_Manual_guide/node015A.html) when
[auto-knob](../Libraries_Manual_guide/node015A.html#line16) is used.  The increment, or typical step value, is the value
added to or subtracted from the internal knob position when the user clicks
in the [container](../Libraries_Manual_guide/node0159.html) around the knob.  For example, a [proportional](../Libraries_Manual_guide/node0153.html) gadget for
color mixing might allow the user to add or subtract 1/16 of the full value
each time, thus the body variable should be set to MAXBODY / 16.

Body variables are also used in conjunction with the [auto-knob](../Libraries_Manual_guide/node015A.html#line16) (described
above) to display for the user how much of the total quantity of data is
displayed.  Additionally, the user can tell at a glance that clicking in
the [container](../Libraries_Manual_guide/node0159.html) around the [knob](../Libraries_Manual_guide/node015A.html) will advance the position by an amount
proportional to the size of the knob.

For instance, if the data is a fifteen line text file, and five lines are
visible in the display, then the body variable should be set to one third
of MAXBODY.  In this case, the [auto-knob](../Libraries_Manual_guide/node015A.html#line16) will fill one third of the
[container](../Libraries_Manual_guide/node0159.html), and clicking in the container ahead of the [knob](../Libraries_Manual_guide/node015A.html) will advance
the position in the file by one third.

For a [slider](../Libraries_Manual_guide/node0157.html), the body variables are usually set such that the full
percentage increment is represented.  This is not always so for a
[scroller](../Libraries_Manual_guide/node0156.html).  With a scroller, some overlap is often desired between
successive steps.  For example, when paging through a text editor, one or
two lines are often left on screen from the previous page, making the
transition easier on the user.

The two body variables may be set to the same or different increments.
When the user clicks in the [container](../Libraries_Manual_guide/node0159.html), the [pot variables](../Libraries_Manual_guide/node015B.html) are adjusted by
an amount derived from the body variables.

