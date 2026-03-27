# 4 / Basic Window Structures and Functions / Window Dimensions


The initial position and dimensions of the window are defined in the
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.  These values undergo error checking before the
window is actually opened on the screen.  If the dimensions are too big,
the window will fail to open.  (Or, you can use the [WA_AutoAdjust](../Libraries_Manual_guide/node0125.html#line135) tag if
you want Intuition to move or size your window to fit.)

Maximum and minimum size values may also be defined, but are not required
If the window does not have a sizing gadget.  In setting these dimensions,
bear in mind the horizontal and vertical resolutions of the screen in
which the window will open.

The maximum dimensions of the window are unsigned values and may legally
be set to the maximum by using the value 0xFFFF, better expressed as "~0".
Using this value for the maximum dimensions allows the window to be sized
to the full screen.

 [A Display Sized Window Example](../Libraries_Manual_guide/node0109.html) 

