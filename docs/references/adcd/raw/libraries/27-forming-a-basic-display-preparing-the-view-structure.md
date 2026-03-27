# 27 / / Forming a Basic Display / Preparing the View Structure


The following code prepares the [View](../Libraries_Manual_guide/node032B.html#line51) structure for further use:


```c
    InitView(&view);      /* Initialize the View.          */
    view.Modes |= LACE;   /* Only interlaced, 1.3 displays */
                          /* require this                  */
```
For Release 2 applications, a [ViewExtra](../Libraries_Manual_guide/node032C.html#line16) structure must also be created
with [GfxNew()](../Libraries_Manual_guide/node032C.html#line22) and associated with this [View](../Libraries_Manual_guide/node032B.html#line51) with [GfxAssociate()](../Libraries_Manual_guide/node032C.html#line22) as shown
in the example programs [RGBBoxes.c](../Libraries_Manual_guide/node059D.html) and [WBClone.c](../Libraries_Manual_guide/node059B.html).


```c
    /* Form the ModeID from values in <displayinfo.h> */
    modeID=DEFAULT_MONITOR_ID | HIRESLACE_KEY;

    /* Make the ViewExtra structure */
    if( vextra=GfxNew(VIEW_EXTRA_TYPE) )
        {
        /* Attach the ViewExtra to the View */
        GfxAssociate(&view , vextra);
        view.Modes |= EXTEND_VSTRUCT;

        /* Initialize the MonitorSpec field of the ViewExtra */
        if( monspec=OpenMonitor(NULL,modeID) )
            vextra->Monitor=monspec;
        else
            fail("Could not get MonitorSpec\n");
        }
     else fail("Could not get ViewExtra\n");
```
