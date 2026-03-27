---
title: cd.device/CD_MOTOR
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-motor
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_MOTOR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_MOTOR -- control the on/off state of a drive motor.
   FUNCTION

       This command gives control over the spindle motor.  The motor may be
       turned on or off.

       If the motor is just being turned on, the device will delay the
       proper amount of time to allow the drive to come up to speed.
       Turning the motor on or off manually is not necessary, the device does
       this automatically if it receives a request when the motor is off.
   IO REQUEST INPUT

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_MOTOR
       io_Length       the requested state of the motor, 0 to turn the motor
                       off, and 1 to turn the motor on.
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
       io_Actual - if io_Error is 0 this contains the previous state of the
                   drive motor.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
