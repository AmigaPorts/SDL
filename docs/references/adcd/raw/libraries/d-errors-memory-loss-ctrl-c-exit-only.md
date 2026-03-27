# D / Errors / Memory Loss--Ctrl-C Exit Only


You have Amiga-specific resources opened or allocated and you have not
disabled your compiler's automatic Ctrl-C handling (causing all of your
program cleanups to be skipped).  Disable the compiler's Ctrl-C handling
and handle Ctrl-C ([SIGBREAKF_CTRL_C](../Libraries_Manual_guide/node028A.html#line8)) yourself.

