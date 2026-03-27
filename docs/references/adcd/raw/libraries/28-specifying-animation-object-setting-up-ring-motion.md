# 28 / / Specifying Animation Object / Setting Up Ring Motion Control


To make a given component trigger a move of the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) you set the
[RINGTRIGGER](../Includes_and_Autodocs_2._guide/node00C3.html#line44) bit of that [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)'s [Flags](../Libraries_Manual_guide/node03B9.html#line12) field. When the system software
encounters this flag, it adds the values of [RingXTrans](../Libraries_Manual_guide/node03B9.html#line48) and [RingYTrans](../Libraries_Manual_guide/node03B9.html#line48) to
the [AnX and AnY](../Libraries_Manual_guide/node03C6.html) values of the controlling AnimOb.  The next time you
execute [DrawGList()](../Libraries_Manual_guide/node038C.html), the drawing sequence will use the new position.

You usually set [RINGTRIGGER](../Includes_and_Autodocs_2._guide/node00C3.html#line44) in only one of the animation components in a
sequence (the last one); however, you can use this flag and the
translation variables any way you wish.

