# D / Errors / Performance Loss--On A3000


If your program has "Enforcer hits" (i.e., illegal references to memory
caused by improperly initialized pointers), this will cause Bus Errors.
The A3000 bus error handler contains a built-in delay to let the bus
settle.  If you have many enforcer hits, this could slow your program down
substantially.

