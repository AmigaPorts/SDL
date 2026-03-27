# 28 / / Specifying Animation Object / Setting Up Simple Motion Control


In this form of animation, you can specify objects that have independently
controllable velocities and accelerations in the X and Y directions.
Components can still sequence.

The variables that control this motion are located in the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) structure
and are called:

  * [YVel, XVel](../Libraries_Manual_guide/node03CF.html)--the velocities in the y and x directions. These

```c
    values are added to the position values on each call to [Animate()](../Libraries_Manual_guide/node03CC.html)
    ([see below](../Libraries_Manual_guide/node03CF.html)).
```
  * [YAccel, XAccel](../Libraries_Manual_guide/node03CF.html)--the accelerations in the xa nd y directions.

```c
    These values are added to the velocity values on each call to
    [Animate()](../Libraries_Manual_guide/node03CC.html) ([see below](../Libraries_Manual_guide/node03CF.html)).  The velocity values are updated before the
    position values.
```
