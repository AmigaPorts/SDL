# cd.device/CD_INFO



   NAME

       CD_INFO -- Return information/status of device
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_INFO
       io_Data         pointer to [CDInfo](../Includes_and_Autodocs_3._guide/node05E4.html#line132) structure
       io_Length       sizeof(struct CDInfo)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual       length of data transferred
```
   FUNCTION


       This command returns current configurations and status of the device
       driver.
   EXAMPLE


```c
       struct [CDInfo](../Includes_and_Autodocs_3._guide/node05E4.html#line132) Info;

       ior->io_Command = CD_INFO;               /* Retrieve drive info.    */
       ior->io_Data    = (APTR)Info;            /* Here's where we want it */
       ior->io_Length  = sizeof(struct CDInfo); /* Return whole structure  */
       DoIO(ior);

       if (!ior->io_Error) {                    /* Command succeeded       */

           if (Info.Status & CDSTSF_PLAYING) printf("Audio is playingn");
           else                              printf("Audio not playingn");
           }
```
   NOTES

   BUGS

   SEE ALSO

```c
       [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
```
