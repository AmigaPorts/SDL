# cd.device/CD_MOTOR



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
       io_Device       preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Unit         preset by the call to [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
       io_Command      CD_MOTOR
       io_Length       the requested state of the motor, 0 to turn the motor
                       off, and 1 to turn the motor on.
```
   IO REQUEST RESULT

```c
       io_Error - 0 for success, or an error code as defined in
                  [<devices/cd.h>](../Includes_and_Autodocs_3._guide/node05E4.html)
       io_Actual - if io_Error is 0 this contains the previous state of the
                   drive motor.
```
