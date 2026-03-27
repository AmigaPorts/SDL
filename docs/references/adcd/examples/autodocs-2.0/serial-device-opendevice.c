/* Source: ADCD 2.1
 * Section: serial-device-opendevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/serial-device-opendevice.md
 */

    If 7-wire handshaking is specified, a timeout "feature" is enabled.
    If the device holds off the computer for more than about 30-60
    seconds, the device will return the write request with the error
    SerErr_TimerErr.  Don't depend on this, however.  If you want a
    timeout, set up the timer.device and wait for either timer, or serial
    IO to complete.

    On open, the serial.device allocates the misc.resource for the
    serial port.  It does not return it until the serial.device is
    expunged from memory.  It should return it when no more openers
    exist.   This code can force a specified device to try and
    expunge.  Of course, if the device is in use nothing will happen:

      #include "exec/types.h"
      #include "exec/execbase.h"
      #include "proto/exec.h"

      void FlushDevice(char *);
      extern struct [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line35) *SysBase;

      void main()
      {
              FlushDevice("serial.device");   /* or parallel.device */
      }

      /*
       * Attempts to flush the named device out of memory.
       * If it fails, no status is returned; examination of
       * the problem will reveal that information has no
       * valid use after the [Permit()](../Includes_and_Autodocs_2._guide/node0369.html).
       */
      void FlushDevice(name)
      char  *name;
      {
      struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) *result;

          Forbid();
          if( result=(struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) *)FindName(&SysBase->DeviceList,name) )
              RemDevice(result);
          Permit();
      }
