# D / Errors / Memory Loss--Workbench Only


Commonly, this is caused by a failure of your code to unload after you
exit.  Make sure that your code is being linked with a standard correct
startup module, and do not use the [Exit](../Includes_and_Autodocs_2._guide/node029F.html)(n) function to exit your program.
This function will bypass your startup code's cleanup, including its
[ReplyMsg()](../Libraries_Manual_guide/node02F2.html) of the [WBStartup](../Libraries_Manual_guide/node023E.html#line5) message (which would signal Workbench to
unload your program from memory).  You should exit via either exit(n)
where n is a valid DOS error code such as RETURN_OK (<dos/[dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line198)>), or via
final "}" or return.  Assembler programmers using startup code can JMP to
_exit with a long return value on stack, or use the RTS instruction.

