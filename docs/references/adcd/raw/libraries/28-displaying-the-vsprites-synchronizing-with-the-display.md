# 28 / / Displaying the VSprites / Synchronizing with the Display


To synchronize application functions with the display, call the system
function [WaitTOF()](../Includes_and_Autodocs_2._guide/node048B.html). WaitTOF() holds your task until the vertical-blanking
interval (blank area at the top of the screen) has begun.  At that time,
the system has retrieved the current Copper instruction list and is ready
to allow generation of a new list.


```c
    WaitTOF();
```
[WaitTOF()](../Includes_and_Autodocs_2._guide/node048B.html) takes no arguments and returns no values.  It simply suspends
your task until the video beam is at the top of field.

