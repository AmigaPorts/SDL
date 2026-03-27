# 19 / / I/O Request Completion / Ending Device Access


After the device is closed, you must deallocate the I/O request memory.
The exact method you use depends on how you allocated the memory in the
first place.  For [AllocMem()](../Libraries_Manual_guide/node02A7.html) you call [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11), for [CreateExtIO()](../Libraries_Manual_guide/node04B0.html#line6) you
call [DeleteExtIO()](../Libraries_Manual_guide/node04B0.html#line6), and for [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html) you call [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html).
If you allocated the I/O request memory at compile time, you naturally
have nothing to free.

Finally, you must delete the message port you created.  You delete the
message port by calling [DeleteMsgPort()](../Libraries_Manual_guide/node02ED.html#line26) if you used [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39), or
[DeletePort()](../Libraries_Manual_guide/node02ED.html) if you used [CreatePort()](../Libraries_Manual_guide/node02EC.html).

Here is the checklist for gracefully exiting:

  * Abort any outstanding I/O requests with [AbortIO()](../Libraries_Manual_guide/node02A2.html#line30).

  * Wait for the completion of any outstanding or aborted I/O

```c
    requests with [WaitIO()](../Libraries_Manual_guide/node02A0.html#line48).
```
  * Close the device with [CloseDevice()](../Libraries_Manual_guide/node02A2.html#line9).

  * Release the I/O request memory with either [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html),

```c
    [DeleteExtIO()](../Libraries_Manual_guide/node04B0.html#line6) or [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11) (as appropriate).
```
  * Delete the message port with [DeleteMsgPort()](../Libraries_Manual_guide/node02ED.html#line26) or [DeletePort()](../Libraries_Manual_guide/node02ED.html).

