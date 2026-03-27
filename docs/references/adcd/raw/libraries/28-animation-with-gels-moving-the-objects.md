# 28 / Animation with GELs / Moving the Objects


When you have defined all of the structures and have established all of
the links, you can call the [Animate()](../Includes_and_Autodocs_2._guide/node0415.html) routine to move the objects.
Animate() adjusts the positions of the objects as described above, and
calls the various subroutines ([AnimCRoutines](../Libraries_Manual_guide/node03CD.html) and [AnimORoutines](../Libraries_Manual_guide/node03CD.html)) that you
have specified.

After the system has completed the [Animate()](../Includes_and_Autodocs_2._guide/node0415.html) routine, some GELs may have
been moved, so the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list order may possibly be incorrect.
Therefore, the list must be re-sorted with [SortGList()](../Libraries_Manual_guide/node038B.html#line7) before passing it
to a system routine.

If you are using collision detection, you then perform [DoCollision()](../Libraries_Manual_guide/node03D1.html#line16).
Your collision routines may also have an effect on the relative position
of the GELs.  Therefore, you should again call [SortGList()](../Libraries_Manual_guide/node038B.html#line7) to assure that
the system correctly orders the objects before you call [DrawGList()](../Libraries_Manual_guide/node038C.html). When
you call DrawGList(), the system renders all the GELs it finds in the
[GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list and any changes caused by the previous call to [Animate()](../Includes_and_Autodocs_2._guide/node0415.html) can
then be seen.

This is illustrated in the following typical call sequence:


```c
    struct AnimOb **myAnimKey;
    struct RastPort *rp;
    struct ViewPort *vp;

    /* ... setup of graphics elements and objects */

    Animate(myAnimKey, rp);       /* "move" objects per instructions */
    SortGList(rp);                /*  put them in order */
    DoCollision(rp);              /*  software collision detect/action */
    SortGList(rp);                /*  put them back into right order */
    DrawGList(vp, rp);            /*  draw into current RastPort */
```
