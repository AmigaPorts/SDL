---
title: cd.device/CD_INFO
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-info
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_INFO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_INFO -- Return information/status of device
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_INFO
       io_Data         pointer to [CDInfo](autodocs-3.5/include-devices-cd-h.md) structure
       io_Length       sizeof(struct CDInfo)
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual       length of data transferred
```
   FUNCTION


       This command returns current configurations and status of the device
       driver.
   EXAMPLE


```c
       struct [CDInfo](autodocs-3.5/include-devices-cd-h.md) Info;

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
       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
