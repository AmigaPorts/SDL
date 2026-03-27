# 4 / / Refreshing Intuition Windows / Smart Refresh


If a window is of the Smart Refresh type, then the system will not only
preserve those pixels which are actually on-screen, but it will save all
obscured pixels that are within the current window's size. The system will
refresh those parts of the window revealed by changes in the overlapping
with other windows on the screen, without involving the application.
However, any part of the window revealed through the sizing of the window
must be redrawn by the application.  Again, Intuition will notify the
application through the [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) event.

Because the obscured areas are kept in off-screen buffers, Smart Refresh
windows are refreshed faster than Simple Refresh windows are, and often
without involving the application.  Of course, for the same reason, they
use more display memory.

