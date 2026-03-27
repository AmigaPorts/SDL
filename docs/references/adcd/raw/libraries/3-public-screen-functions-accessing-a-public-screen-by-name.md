# 3 / Public Screen Functions / Accessing a Public Screen by Name


The main calls for accessing an existing [public screen](../Libraries_Manual_guide/node00E6.html) are [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34)
and [UnlockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34).  To use these functions you need to know the name
of the public screen you want to access.  If you do not know the name of
the public screen or if you are not sure, you can lock the default public
screen with LockPubScreen(NULL).


```c
    struct Screen *LockPubScreen( UBYTE * )
     VOID        UnlockPubScreen( UBYTE * , struct Screen *)
```
These calls enable the application to determine that a [public screen](../Libraries_Manual_guide/node00E6.html)
exists, and to ensure its continued existence while opening a window on
it.  This function also serves as an improvement over the old
[GetScreenData()](../Libraries_Manual_guide/node00FC.html#line20) function from V34 by returning a pointer to the [Screen](../Libraries_Manual_guide/node00DE.html#line6)
structure of the locked screen so that its attributes can be examined.

Be sure to unlock the [public screen](../Libraries_Manual_guide/node00E6.html) when done with it.  Note that once a
window is open on the screen the program does not need to hold the screen
lock, as the window acts as a lock on the screen.  The pointer to the
screen structure is valid as long as a lock on the screen is held by the
application, or the application has a window open on the screen.

Locks should not be held without reason.  Holding unnecessary locks on
screens may prevent the user from closing a [public screen](../Libraries_Manual_guide/node00E6.html) that has no
apparent activity.  Keep in mind that as long as you have a window open on
a public screen, the window acts as a lock preventing the screen from
closing.

Shown here is a simple example of how to find the [Workbench public screen](../Libraries_Manual_guide/node00E8.html)
using [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) and [UnlockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34).


```c
     [pubscreenbeep.c](../Libraries_Manual_guide/node05B5.html) 
```
