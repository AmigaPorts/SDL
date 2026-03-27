# 6 / Setting Up Menus / Submitting and Removing Menu Strips


Once the application has set up the proper menu structures, linked them
into a list and attached the list to a window, the menu system completely
handles the menu display.  The menu strip is submitted to Intuition and
attached to the window by calling the function [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html).


```c
    BOOL SetMenuStrip( struct Window *window, struct Menu *menu );
```
[SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html) always returns TRUE.  This function can also be used to
attach a single menu strip to multiple windows by calling SetMenuStrip()
for each window ([see below](../Libraries_Manual_guide/node0185.html)).

Any menu strip attached to a window must be removed before the window is
closed.  To remove the menu strip, call [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html).


```c
    void ClearMenuStrip( struct Window *window );
```
The menu example below demonstrates how to use these functions with a
simple menu strip.

