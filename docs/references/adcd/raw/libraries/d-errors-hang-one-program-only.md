# D / Errors / Hang--One Program Only


Program hangs are generally caused by [Wait()](../Libraries_Manual_guide/node02D4.html)ing on the wrong signal bits,
on the wrong port, on the wrong message, or on some other event that will
never occur.  This can occur if the event you are waiting on is not
coming, or if one task tries to Wait(), [WaitPort()](../Libraries_Manual_guide/node02F1.html#line9), or [WaitIO()](../Libraries_Manual_guide/node02A0.html#line48) on a
signal, port, or window that was created by a different task.  Both
WaitIO() and WaitPort() can call Wait(), and you cannot Wait() on another
task's signals.  Hangs can also be caused by verify deadlocks. Be sure to
turn off all Intuition verify messages (such as [MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6)) before calling
[AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21) or doing disk access.

