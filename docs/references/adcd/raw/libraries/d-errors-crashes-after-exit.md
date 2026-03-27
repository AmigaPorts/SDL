# D / Errors / Crashes--After Exit


If this only happens when you start your program [from Workbench](../Libraries_Manual_guide/node023E.html#line76), then you
are probably [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html)ing one of the [WBStartup](../Libraries_Manual_guide/node023E.html#line5) message [wa_Locks](../Libraries_Manual_guide/node023E.html#line49), or
UnLock()ing the [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html) returned from an initial [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html) call.  If you
CurrentDir(), save the lock returned initially, and CurrentDir() back to
it before you exit. Only UnLock() locks that you created.

If you are crashing from both Workbench and CLI, and you are only crashing
after exit, then you are probably either freeing/closing something twice,
or freeing/closing something your did not actually allocate/open, or you
may be leaving an outstanding device I/O request or other wakeup request.
You must abort and WaitIO() any outstanding I/O requests before you free
things and exit (see the Autodocs for your device, and for Exec [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)
and [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)).  Similar problems can be caused by deleting a subtask that
might be in a WaitTOF().  Only delete subtasks when you are sure they are
in a safe state such as [Wait](../Libraries_Manual_guide/node02D4.html)(0L).

