# 31 Commodities Exchange Library / Signal CxObjects


A commodity can use a [sender CxObject](../Libraries_Manual_guide/node0409.html) to find out if a [CxMessage](../Libraries_Manual_guide/node0403.html) has
"visited" a [CxObject](../Libraries_Manual_guide/node0407.html), but this method unnecessarily uses system resources.
A commodity that is only interested in knowing if such a visitation took
place does not need to see a corresponding input event or a CxMessage ID.
Instead, Commodities Exchange has a CxObject that uses an Exec signal.


```c
    signalCxObj = CxObj  *CxSignal(struct Task *, LONG cx_signal);
```
[CxSignal()](../Includes_and_Autodocs_2._guide/node014F.html) sets up a signal [CxObject](../Libraries_Manual_guide/node0401.html).  When a signal CxObject receives a
[CxMessage](../Libraries_Manual_guide/node0403.html), it signals a task.  The commodity is responsible for
determining the proper task ID and allocating the signal.  Normally, a
commodity wants to be signalled so it uses [FindTask](../Libraries_Manual_guide/node02D0.html#line5)(NULL) to find it's own
task address.  Note that cx_signal from the above prototype is the signal
number as returned by [AllocSignal()](../Libraries_Manual_guide/node02D3.html#line5), not the signal mask made from that
number.  For more information on signals, see the "[Exec Signals](../Libraries_Manual_guide/node02D1.html)" chapter.

The example [Divert.c](../Libraries_Manual_guide/node0585.html) (shown a little later in this chapter) uses a signal
[CxObject](../Libraries_Manual_guide/node0401.html).

