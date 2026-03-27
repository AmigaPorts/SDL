---
title: 28 / / Specifying Animation Object / Setting Up Simple Motion Control
manual: libraries
chapter: libraries
section: 28-specifying-animation-object-setting-up-simple-motion
functions: [Animate]
libraries: [graphics.library]
---

# 28 / / Specifying Animation Object / Setting Up Simple Motion Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In this form of animation, you can specify objects that have independently
controllable velocities and accelerations in the X and Y directions.
Components can still sequence.

The variables that control this motion are located in the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) structure
and are called:

  * [YVel, XVel](libraries/28-animation-with-gels-animations-special-numbering-system.md)--the velocities in the y and x directions. These

```c
    values are added to the position values on each call to [Animate()](libraries/28-animation-with-gels-moving-the-objects.md)
    ([see below](libraries/28-animation-with-gels-animations-special-numbering-system.md)).
```
  * [YAccel, XAccel](libraries/28-animation-with-gels-animations-special-numbering-system.md)--the accelerations in the xa nd y directions.

```c
    These values are added to the velocity values on each call to
    [Animate()](libraries/28-animation-with-gels-moving-the-objects.md) ([see below](libraries/28-animation-with-gels-animations-special-numbering-system.md)).  The velocity values are updated before the
    position values.
```

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
