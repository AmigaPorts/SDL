# 1 / / Design / DOS System(), CreateNewProc(), and CON: Enhancements


If your program currently uses the 1.3 AmigaDOS [Execute()](../Includes_and_Autodocs_2._guide/node029E.html) or [CreateProc()](../Includes_and_Autodocs_2._guide/node028E.html)
functions, then it is definitely worth conditional code to use their V37
replacements when running under [Release 2](../Libraries_Manual_guide/node0015.html).  The [System()](../Includes_and_Autodocs_2._guide/node0304.html#line10) function of
Release 2 allows you to pass a command line to AmigaDOS as if it had been
typed at a Shell window.  System() can run synchronously with return
values or asynchronously with automatic cleanup and it also sets up a
proper stdio environment when passed a DOS filehandle for SYS_Input and
NULL for SYS_Output.  In combination with enhanced Release 2 CON:
features, System() can provide a suitable execution environment on either
Workbench or a custom screen.  The [CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html) function provides
additional control and ease in process creation.

CON: input and output in custom Intuition screens and windows is now
supported.  New options in the [Release 2](../Libraries_Manual_guide/node0015.html) console handler (CON:) provide
the ability to open a CON: on any public Intuition screen, or to attach a
CON: to an existing Intuition window.  Additional options can add a close
gadget or create an AUTO console window which will only open if accessed
for read or write.  Add conditional code to use these system-supported
methods when running under Release 2 or later versions of the OS.  Note
that additional CON: option keywords can be easily removed under 1.3 at
runtime by terminating the CON: string with NULL after the window title.
Consult The AmigaDOS Manual by Bantam Books for additional information on
Release 2 CON: and DOS features.

