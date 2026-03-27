# 28 / / Animation Types / Ring Motion Control


Making a worm appear to crawl is similar to the rotating ball.  There is
still a stack of [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)s that are sequenced automatically, and one
controlling [AnimOb](../Libraries_Manual_guide/node03B9.html#line34).  But each AnimComp image is drawn so that it appears
to move relative to an internal point that remains stationary throughout
the stack.  So instead of the AnimOb's common reference point moving in
each frame, you tell the system how far to move only at the end of each
AnimComp sequence.


```c
     [Figure 28-5: Ring Motion Control](../Libraries_Manual_guide/node05F5.html) 
```
As illustrated in the figure at left, the sequence of events for Ring
Motion Control look like this:


    Draw AnimComp1, Draw AnimComp2, Draw AnimComp3, Move AnimOb,
    Draw AnimComp1, Draw AnimComp2, Draw AnimComp3, Move AnimOb,
    Draw AnimComp1...
