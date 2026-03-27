# D / Errors / Crashes--Only on 68040


Because of the instruction pipelining of the 68040, it is very difficult
to recover from a bus error.  If your program has an "Enforcer hit" (i.e.,
an illegal reference to memory), the resulting 68040 processor bus error
will probably crash the machine.  Use Enforcer  (on an '030) to track down
your problems, then correct them.

