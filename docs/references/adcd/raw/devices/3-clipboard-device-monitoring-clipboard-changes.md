# 3 Clipboard Device / Monitoring Clipboard Changes


Some applications require notification of changes to data on the
clipboard. Typically, these applications will need to do some processing
when this occurs. You can set up such an environment through the
[CBD_CHANGEHOOK](../Includes_and_Autodocs_2._guide/node04D9.html) command. CBD_CHANGEHOOK allows you to specify a hook to be
called when the data on the clipboard changes.

For example, a show clipboard utility would need to know when the data on
the clipboard is changed so that it can display the new data.  The hook it
would specify would read the new clipboard data and display it for the
user.

You specify a hook for the clipboard device by initializing a Hook
structure and then passing an IOClipReq to the device with [CBD_CHANGEHOOK](../Includes_and_Autodocs_2._guide/node04D9.html)
set in io_Command, 1 set in io_Length, and the address of the Hook
structure set in io_Data.


```c
    ULONG HookEntry ();            /* Declare the hook assembly function */
    struct IOClipReq *ClipIO;      /* Declare the IOClipReq */
    struct Hook *ClipHook;         /* Declare the Hook */

    /* Prepare the hook */
    ClipHook->h_Entry = HookEntry; /* C intrfce in asmbly rout. HookEntry*/
    ClipHook->h_SubEntry = HookFunc;/* Call function when Hook activated */
    ClipHook->h_Data = FindTask(NULL);/* Set pointer to current task */

    ClipIO->io_Data = (char *) ClipHook;/* Point to hook struct */
    ClipIO->io_Length = 1;              /* Add hook to clipboard */
    ClipIO->io_Command = CBD_CHANGEHOOK;
    DoIO(clipIO);
```
The above code fragment assumes that an assembly language routine
HookEntry() has been coded:


```c
    ; entry interface for C code
    _HookEntry:
            move.l  a1,-(sp)            ; push message packet pointer
            move.l  a2,-(sp)            ; push object pointer
            move.l  a0,-(sp)            ; push hook pointer
            move.l  h_SubEntry(a0),a0   ; fetch C entry point ...
            jsr     (a0)                ; ... and call it
            lea     12(sp),sp           ; fix stack
            rts
```
It also assumes that the function HookFunc() has been coded.  One of the
example programs at the end of this chapter has hook processing in it.
See the include file utility/[hooks.h](../Includes_and_Autodocs_2._guide/node012D.html) and The Amiga ROM Kernel Reference
Manual: [Libraries](../Libraries_Manual_guide/node04A2.html) for further information on hooks.

You remove a hook by passing an [IOClipReq](../Devices_Manual_guide/node0067.html#line5) to the device with the address
of the Hook structure set in io_Data, 0 set in io_Length and
[CBD_CHANGEHOOK](../Includes_and_Autodocs_2._guide/node04D9.html) set in io_Command.


```c
    ClipIO->io_Data = (char *) ClipHook;  /* point to hook struct */
    ClipIO->io_Length = 0;                /* Remove hook from clipboard */
    ClipIO->io_Command = CBD_CHANGEHOOK;
    (DoIO (clipIO))
```
You must remove the hook or it will continue indefinitely.

 [Caveats For CBD_CHANGEHOOK](../Devices_Manual_guide/node0071.html) 

