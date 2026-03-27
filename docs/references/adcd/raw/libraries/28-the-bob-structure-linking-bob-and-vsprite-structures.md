# 28 / / The Bob Structure / Linking Bob and VSprite Structures


The [VSprite](../Libraries_Manual_guide/node0381.html) and [Bob](../Libraries_Manual_guide/node0398.html) structures must point to one another, so that the
system can find the entire GEL.  The structures are linked with statements
like this:


```c
    myBob.BobVSprite = &myVSprite;
    myVSprite.VSBob  = &myBob;
```
Now the system (and the application program) can go back and forth between
the two structures to obtain the various [Bob](../Libraries_Manual_guide/node0398.html) variables.

