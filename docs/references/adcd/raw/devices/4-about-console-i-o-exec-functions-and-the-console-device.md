# 4 / About Console I/O / Exec Functions And The Console Device


The various Exec functions such as [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html), [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) and
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html) operate normally. The only caveats are that [CMD_WRITE](../Devices_Manual_guide/node008A.html) may cause
your application to wait internally, even with SendIO(), and a task using
[CMD_READ](../Devices_Manual_guide/node008F.html) to wait on a response from a console is at the user's mercy.  If
the user never reselects that window, and the console response provides
the only wake-up call, that task will sleep forever.

