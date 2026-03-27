# 28 / Animation with GELs / Standard Gel Rules Still Apply


Before you use the animation system, you must have called the routine
[InitGels()](../Libraries_Manual_guide/node0378.html).  The section called "[Bob Priorities](../Libraries_Manual_guide/node03A2.html)" describes how the system
maintains the list of GELs to draw on the screen according to their
various data fields.  The animation system selectively adds GELs to and
removes GELs from this list of screen objects during the [Animate()](../Libraries_Manual_guide/node03CC.html)
routine.  On the next call to [DrawGList()](../Libraries_Manual_guide/node038C.html), the system will draw the GELs
in the list into the selected [RastPort](../Libraries_Manual_guide/node034A.html).

