# D / Errors / Out-of-Sync Response to Input


Caused by failing to handle all received signals or all possible messages
after a [Wait()](../Libraries_Manual_guide/node02D4.html) or [WaitPort()](../Libraries_Manual_guide/node02F1.html#line9) call.  More than one event or message may
have caused your program to awakened.  Check the signals returned by
Wait() and act on every one that is set.  At ports which may have more
than one message (for instance, a window's IDCMP port), you must handle
the messages in a while(msg=GetMsg(...)) loop.

