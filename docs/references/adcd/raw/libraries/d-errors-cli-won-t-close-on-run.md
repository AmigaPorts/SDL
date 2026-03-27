# D / Errors / CLI Won't Close on RUN


A CLI can't close if a program has a [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html) on the CLI input or output
stream ("*").  If your program is RUN >NIL: from a CLI, that CLI should be
able to close unless your code or your compiler's startup code explicitly
opens "*".

