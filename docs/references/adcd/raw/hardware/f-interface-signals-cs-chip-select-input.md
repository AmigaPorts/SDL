# F / / Interface Signals / CS - chip-select input


The CS input controls the activity of the 8520.  A low level on CS while
02 is high causes the device to respond to signals on the  [R/W](../Hardware_Manual_guide/node014F.html)  and address
( [RS](../Hardware_Manual_guide/node0150.html) ) lines.  A high on CS prevents these lines from controlling the 8520.
The CS line is normally activated (low) at 02 by the appropriate address
combination.

