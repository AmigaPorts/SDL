# D / Errors / Crashes--Workbench Only


If you are crashing near the first DOS call, either your stack is too
small or your startup code did not [GetMsg()](../Libraries_Manual_guide/node02F2.html) the [WBStartup](../Libraries_Manual_guide/node023E.html#line5) message from the
process message port.  If your program crashes during execution or during
your exit procedure only when started from Workbench, and your startup
opens no stdio window or NIL: file handles for WB programs, then make sure
you are not writing anything to stdout ([printf()](../Includes_and_Autodocs_2._guide/node0162.html), etc.) when started from
WB (argc==0).  See also "[Crashes--After Exit](../Libraries_Manual_guide/node053C.html)".

