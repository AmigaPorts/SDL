# 3 / Device Interface / Closing The Clipboard Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to
[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).


```c
    CloseDevice(ClipIO);
```
When the last task closes a clipboard unit with CloseDevice(), the
contents of the unit may be copied to a disk file in CLIPS: so that the
clipboard device can be expunged.

