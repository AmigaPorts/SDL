# D / Errors / CLI Error Message Problems


Improper error messages are caused by calling exit(n) with an invalid or
missing return value n.  Assembler programmers using startup code should
jump to the startup code's _exit with a valid return value on the stack.
Programs without startup code should return with a valid value in D0.
Valid return values such as RETURN_OK, RETURN_WARN, RETURN_FAIL are
defined in <dos/[dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line198)> and <dos/[dos.i](../Includes_and_Autodocs_2._guide/node006C.html#line189)>.  Values outside of these ranges
(-1 for instance) can cause invalid CLI error messages such as "not an
object module".  Useful hint--if your program is called from a script,
your valid return value can be conditionally branched on in the script
(i.e., call program, then perform actions based on IF WARN or IF NOT
WARN).  RETURN_FAIL will cause the script to stop if a normal FAILAT value
is being used in script.

