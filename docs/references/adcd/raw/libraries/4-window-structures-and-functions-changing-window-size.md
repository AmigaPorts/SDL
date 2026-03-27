# 4 / Window Structures and Functions / Changing Window Size Limits


To change the sizing limits after the window has been opened, call
[WindowLimits()](../Includes_and_Autodocs_2._guide/node0263.html) with the new values.

   BOOL WindowLimits( struct Window *window, long widthMin, long heightMin,

```c
                      unsigned long widthMax, unsigned long heightMax );
```
To maintain the current dimension, set the corresponding argument to 0.
Out of range numbers are ignored.  If the user is currently sizing the
window, new limits take effect after the user releases the select button.

