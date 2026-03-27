# 28 / Animation with GELs / Adding Animation Objects


Use the routine [AddAnimOb()](../Includes_and_Autodocs_2._guide/node040E.html) to add animation objects to the controlled
object list.  This routine will link the [PrevOb](../Libraries_Manual_guide/node03CA.html) and [NextOb](../Libraries_Manual_guide/node03CA.html) pointers to
chain all the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34)s that the system is controlling.


```c
    struct RastPort myRPort;
    struct AnimOb myAnimOb;
    struct AnimOb *animKey;  /* Must be initialized with InitAnimate() */

    AddAnimOb(&myAnimOb, &animKey, &myRPort);
```
