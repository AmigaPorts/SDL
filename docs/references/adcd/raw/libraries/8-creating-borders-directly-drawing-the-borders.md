# 8 / Creating Borders / Directly Drawing the Borders


Borders may be directly drawn by the application by calling the function
[DrawBorder()](../Includes_and_Autodocs_2._guide/node020F.html).


```c
    void DrawBorder( struct RastPort *rp, struct Border *border,
                     long leftOffset, long topOffset );
```
The rp argument is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) into which the border should
be drawn.  This rastport may come from a [Window](../Libraries_Manual_guide/node0121.html) or [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure.

The border argument is a pointer to a list of [Border](../Libraries_Manual_guide/node01C1.html) structures which are
to be rendered.  The list may contain a single Border structure.

The leftOffset and topOffset arguments are the external component, or base
position, for this list of [Border](../Libraries_Manual_guide/node01C1.html)s.  The [LeftEdge](../Libraries_Manual_guide/node01C1.html#line15) and [TopEdge](../Libraries_Manual_guide/node01C1.html#line15) values of
each Border structure are added to these to determine the Border position.

Borders may also be indirectly drawn by attaching them to gadgets, menus
or requesters.

