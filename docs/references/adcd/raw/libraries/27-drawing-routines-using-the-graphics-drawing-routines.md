# 27 / Drawing Routines / Using the Graphics Drawing Routines


This section shows you how to use the Amiga drawing routines. All of these
routines work either on their own or along with the windowing system and
layers library.  For details about using the layers and windows, see the
chapters on "[Layers Library](../Libraries_Manual_guide/node03E2.html)" and "[Intuition](../Libraries_Manual_guide/node00FE.html) Windows".


```c
    Use WaitBlit().
    ---------------
    The graphics library rendering and data movement routines generally
    wait to get access to the blitter, start their blit, and then exit.
    Therefore, you must [WaitBlit()](../Libraries_Manual_guide/node0368.html) after a graphics rendering or data
    movement call if you intend to immediately deallocate, examine, or
    perform order-dependent processor operations on the memory used in
    the call.
```
As you read this section, keep in mind that to use the drawing routines,
you need to pass them a pointer to a [RastPort](../Libraries_Manual_guide/node034A.html).  You can define the
RastPort directly, as shown in the sample program segments in preceding
sections, or you can get a RastPort from your [Window](../Libraries_Manual_guide/node0121.html) structure using code
like the following:


```c
    struct Window *window;
    struct RastPort *rastPort;

    window = OpenWindow(&newWindow);  /*  You could use OpenWindowTags() */
    if (window)
        rastPort = window->RPort;
```
You can also get the [RastPort](../Libraries_Manual_guide/node034A.html) from the [Layer](../Libraries_Manual_guide/node03E4.html) structure, if you are not
using Intuition.

 [Drawing Individual Pixels](../Libraries_Manual_guide/node0356.html) 
 [Reading Individual Pixels](../Libraries_Manual_guide/node0357.html) 
 [Drawing Ellipses and Circles](../Libraries_Manual_guide/node0358.html) 
 [Drawing Lines](../Libraries_Manual_guide/node0359.html) 
 [Drawing Patterned Lines](../Libraries_Manual_guide/node035A.html) 
 [Drawing Multiple Lines with a Single Command](../Libraries_Manual_guide/node035B.html) 
 [Area-fill Operations](../Libraries_Manual_guide/node035C.html) 
 [Ellipse and Circle-fill Operations](../Libraries_Manual_guide/node035D.html) 
 [Flood-fill Operations](../Libraries_Manual_guide/node035E.html) 
 [Rectangle-fill Operations](../Libraries_Manual_guide/node035F.html) 

