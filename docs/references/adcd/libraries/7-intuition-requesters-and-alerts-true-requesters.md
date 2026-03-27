---
title: 7 Intuition Requesters and Alerts / True Requesters
manual: libraries
chapter: libraries
section: 7-intuition-requesters-and-alerts-true-requesters
functions: [Request]
libraries: [intuition.library]
---

# 7 Intuition Requesters and Alerts / True Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
     [Figure 7-1: Requester Deluxe](libraries/lib-pics-7-1-pic.md) 
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
        the [Request()](libraries/7-true-requesters-creating-application-requesters.md) function.

      * The application can declare a requester as the window's
        [double menu](libraries/7-true-requesters-double-menu-requesters.md) requester, which the user can bring up with a
        double-click of the menu button (this method is rarely used).
```
 [Creating Application Requesters](libraries/7-true-requesters-creating-application-requesters.md) 
 [Requester I/O](libraries/7-true-requesters-requester-i-o.md) 
 [Rendering Requesters](libraries/7-true-requesters-rendering-requesters.md) 
 [Requester Refresh Type](libraries/7-true-requesters-requester-refresh-type.md) 
 [Requester Display Position](libraries/7-true-requesters-requester-display-position.md) 
 [Gadgets in Requesters](libraries/7-true-requesters-gadgets-in-requesters.md) 
 [Using a Requester to Block Window Input](libraries/7-true-requesters-using-a-requester-to-block-window-input.md) 
 [Double Menu Requesters](libraries/7-true-requesters-double-menu-requesters.md) 
 [IDCMP Requester Features](libraries/7-true-requesters-idcmp-requester-features.md) 

---

## See Also

- [Request — intuition.library](../autodocs/intuition.library.md#request)
