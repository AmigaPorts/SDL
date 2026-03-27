# D / Errors / Device-related Problems


Device-related problems may caused by: improperly initialized port or I/O
request structures (use [CreatePort()](../Libraries_Manual_guide/node02EC.html) and [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)); use of a
too-small I/O request (see the device's <[.h](../Includes_and_Autodocs_2._guide/node0000.html)> files and Autodocs for
information on the required type of I/O request); re-use of an I/O request
before it has returned from the device (use the debugging tool IO_Torture
to catch this); failure to abort and wait for an outstanding device
request before exiting; waiting on a signal/port/message allocated by a
different task.

