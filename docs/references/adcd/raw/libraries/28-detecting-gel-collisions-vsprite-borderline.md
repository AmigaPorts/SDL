# 28 / / Detecting Gel Collisions / VSprite BorderLine


For faster collision detection, the system uses the [BorderLine](../Includes_and_Autodocs_2._guide/node00C3.html#line111) member of
the [VSprite](../Libraries_Manual_guide/node0381.html) structure. BorderLine specifies the location of the horizontal
logical-OR combination of all of the bits of the object.  It may be
compared to taking the whole object's shadow/collision mask and squishing
it down into a single horizontal line.  You provide the system with a
place to store this line.  The size of the data area you allocate must be
at least as large as the image width.

In other words, if it takes three 16-bit words to hold one line of a GEL,
then you must reserve three words for the [BorderLine](../Includes_and_Autodocs_2._guide/node00C3.html#line111).  In the VSprite
examples, the routine [makeVSprite()](../Libraries_Manual_guide/node059C.html#line89) correctly allocates and initializes
the collision mask and borderline.  For example:


```c
    WORD myBorderLineData[3];  /* reserve space for BorderLine */
                               /* for this Bob */

    myVSprite.BorderLine = myBorderLineData;  /* tell the system */
                                              /* where it is */
```
Here is a sample of an object and its [BorderLine](../Includes_and_Autodocs_2._guide/node00C3.html#line111) image:


              011000001100    Object
              001100011000
              001100011000
              000110110000
              000010100000

              011110111100    BorderLine image
Using this squished image, the system can quickly determine if the image
is touching the left or rightmost boundary of the drawing area.

To establish default [BorderLine](../Includes_and_Autodocs_2._guide/node00C3.html#line111) and [CollMask](../Libraries_Manual_guide/node03AF.html) data, call the [InitMasks()](../Libraries_Manual_guide/node03D1.html#line25)
function.

