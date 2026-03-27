# 28 / Using Bobs / Changing Bobs


The following characteristics of Bobs can be changed dynamically between
calls to [DrawGList()](../Libraries_Manual_guide/node038C.html):

  * To change the location of the Bob in the [RastPort](../Libraries_Manual_guide/node034A.html) drawing area,

```c
    adjust the X and Y values in the [VSprite](../Libraries_Manual_guide/node0381.html) structure associated with
    this Bob.
```
  * To change a Bob's appearance, the pointer to the [ImageData](../Libraries_Manual_guide/node039C.html) in the

```c
    associated [VSprite](../Libraries_Manual_guide/node0381.html) structure may be changed.  Note that a change in
    the ImageData also requires a change or recalculation of the
    [ImageShadow](../Libraries_Manual_guide/node039F.html), using [InitMasks()](../Libraries_Manual_guide/node03D1.html#line25).
```
  * To change a Bob's colors modify the [PlanePick](../Libraries_Manual_guide/node03A0.html), [PlaneOnOff](../Libraries_Manual_guide/node03A1.html) or [Depth](../Libraries_Manual_guide/node039D.html#line10)

```c
    parameters in the [VSprite](../Libraries_Manual_guide/node0381.html) structure associated with this Bob.
```
  * To change a Bob's display priorities, alter the [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html)

```c
    pointers in the [Bob](../Libraries_Manual_guide/node0398.html) structure.
```
  * To change the Bob into a paintbrush, specify the [SAVEBOB](../Libraries_Manual_guide/node039A.html#line4) flag in the

```c
    [Bob.Flags](../Libraries_Manual_guide/node039A.html) field.

    Changes Are Not Immediately Seen.
    ---------------------------------
    Neither these nor other changes are evident until [SortGList()](../Libraries_Manual_guide/node038B.html#line7) and
    then [DrawGList()](../Libraries_Manual_guide/node038C.html) are called.
```
