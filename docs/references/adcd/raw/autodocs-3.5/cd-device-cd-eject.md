# cd.device/CD_EJECT



   NAME

```c
       CD_EJECT -- [Open](../Includes_and_Autodocs_3._guide/node0196.html) or close the CD's drive door
```
   IO REQUEST

```c
       io_Command      CD_EJECT
       io_Data         NULL
       io_Length       requested state of drive door (0 == close, 1 == open)
       io_Offset       0
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual       previous state of drive door
```
   FUNCTION

       This command causes the CD-ROM drive's door to open or close.
       The desired state of the drive door is placed in io_Length.  The
       previous state of the drive door is returned in io_Actual.
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

