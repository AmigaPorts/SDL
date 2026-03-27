# clipboard.device/CBD_CHANGEHOOK



   NAME
	CBD_CHANGEHOOK -- Add or remove a clip change hook

   FUNCTION
	CBD_CHANGEHOOK allows specification of a hook to be called
	when the data on the clipboard has changed.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Unit		preset by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
	io_Command	CBD_CHANGEHOOK
	io_Length -     0 to remove, 1 to install this hook
	io_Data -       struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, the clip change hook

   HOOK ENVIRONMENT

```c
       hook message - a [ClipHookMsg](../Includes_and_Autodocs_3._guide/node05E9.html#line62), as defined in [devices/clipboard.h](../Includes_and_Autodocs_3._guide/node05E9.html)
           chm_Type - 0, indicating that the message has the
               following fields:
           chm_ClipID - the clip ID of the clip triggering the change
       hook object - io_Unit
```
