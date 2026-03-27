# D / Errors / Crashes--Subtasks, Interrupts


If part of your code runs on a different stack or the system stack, you
must turn off compiler stack-checking options.  If part of your code is
called directly by the system or by other tasks, you must use long
code/long data or use special compiler flags or options to assure that the
correct base registers are set up for your subtask or interrupt code.

