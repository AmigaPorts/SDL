# 7 Intuition Requesters and Alerts / True Requesters


The primary function of a requester is to display information to the user
from which the user is to make a selection.  Conceptually, requesters are
similar to menus since both menus and requesters offer options to the
user.  Requesters, however, go beyond menus because they can have
customized imagery, can be placed anywhere in a window, can be activated
by the application and may have any type of gadget attached.

For instance, to select a color for a given operation using a menu could
be awkward, especially in an application that supports a large number of
colors.  In that case a requester could be used instead (see figure).


```c
     [Figure 7-1: Requester Deluxe](../Libraries_Manual_guide/node05D9.html) 
```
The ability of a true requester to block input to its parent window is
important in understanding how requesters are used.  When input is blocked
by a true requester (also known as a modal requester), the user must take
some action before the program will proceed further, such as making a
selection, correcting an error condition, or acknowledging a warning.
These are situations where a true (modal) requester is appropriate,
however, keep in mind that your application should try to be as
user-responsive as possible.  Putting up a requester merely because you
are in a phase of the program where it would be difficult to deal with
user input is bad style.  Modal requesters should be used only when the
program requires user interaction before proceeding.

True requesters can be created in a window in two different ways.


```c
      * An application can display a requester at any time by calling
        the [Request()](../Libraries_Manual_guide/node01A2.html#line12) function.

      * The application can declare a requester as the window's
        [double menu](../Libraries_Manual_guide/node01A9.html) requester, which the user can bring up with a
        double-click of the menu button (this method is rarely used).
```
 [Creating Application Requesters](../Libraries_Manual_guide/node01A2.html) 
 [Requester I/O](../Libraries_Manual_guide/node01A3.html) 
 [Rendering Requesters](../Libraries_Manual_guide/node01A4.html) 
 [Requester Refresh Type](../Libraries_Manual_guide/node01A5.html) 
 [Requester Display Position](../Libraries_Manual_guide/node01A6.html) 
 [Gadgets in Requesters](../Libraries_Manual_guide/node01A7.html) 
 [Using a Requester to Block Window Input](../Libraries_Manual_guide/node01A8.html) 
 [Double Menu Requesters](../Libraries_Manual_guide/node01A9.html) 
 [IDCMP Requester Features](../Libraries_Manual_guide/node01AA.html) 

