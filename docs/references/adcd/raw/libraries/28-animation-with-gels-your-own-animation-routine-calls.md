# 28 / Animation with GELs / Your Own Animation Routine Calls


The [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) and [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) structures can include pointers for your own
routines that you want the system to call.  These pointers are stored in
the AnimOb's AnimORoutine field and in the AnimComp's AnimCRoutine field,
respectively.

When [Animate()](../Libraries_Manual_guide/node03CC.html) is called, the system performs the following steps for
every [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) in the AnimKey list:


```c
    * Updates the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34)'s location and velocities.

    * Calls the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34).AnimORoutine routine if one is supplied.

    * The for each [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) of the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34):

         · If this sequence times out, switches to the new [AnimComp](../Libraries_Manual_guide/node03B9.html#line3).

         · Calls the [AnimComp](../Libraries_Manual_guide/node03B9.html#line3).AnimCRoutine if one is supplied.

         · Sets the underlying [VSprite](../Libraries_Manual_guide/node0381.html)'s x,y coordinates.
```
If you want a routine to be called, you put the address of the routine in
either [AnimComp](../Libraries_Manual_guide/node03B9.html#line3).AnimCRoutine or [AnimOb](../Libraries_Manual_guide/node03B9.html#line34).AnimORoutine member as needed.  If
no routine is to be called, you must set these fields to NULL.  Your
routines will be passed one parameter, a pointer to the AnimOb or AnimComp
it was related to.  You can use the user structure extensions discussed
earlier to hold the variables you need for your own routines.

For example, if you provide a routine such as this:


```c
    VOID MyOCode(struct AnimOb *anOb)
    {
    /* whatever needs to be done */
    }
```
Then, if you put the address of the routine in an [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) structure:


```c
    myAnimOb.AnimORoutine = MyOCode;
```
MyOCode() will be called with the address of this [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) when [Animate()](../Libraries_Manual_guide/node03CC.html)
processes this AnimOb.

