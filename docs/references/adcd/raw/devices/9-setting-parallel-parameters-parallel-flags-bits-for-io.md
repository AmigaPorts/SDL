# 9 / Setting Parallel Parameters / Parallel Flags (Bits for io_ParFlags)


The flags shown in the following table can be set to affect the operation
of the parallel device.  Note that the default state of all of these flags
is zero.  The flags are defined in the include file devices/[parallel.h](../Includes_and_Autodocs_2._guide/node004A.html).

```c
                        PARALLEL FLAGS (io_ParFlags)

    Flag Name           Effect on Device Operation
    ---------           --------------------------
```
   PARF_EOFMODE         Set this bit if you want the parallel


```c
                        device to check I/O characters against io_TermArray
                        and terminate the I/O request immediately if an
                        end-of-file character has been encountered.
                        Note:  This bit can be set and reset directly in
                        the user's [IOExtPar](../Devices_Manual_guide/node0010.html#line7) block without a call to
                        [PDCMD_SETPARAMS](../Includes_and_Autodocs_2._guide/node04F4.html).
```
   PARF_ACKMODE         Set this bit if you want to use ACK handshaking.

   PARF_FASTMODE        Set this bit if you want to use

                        high-speed mode for transfers to high-speed
                        printers.  This mode will send out data as long as
                        the BUSY signal is low. The printer must be
                        able to raise the BUSY signal within three
                        microseconds or data will be lost. Should only be
                        used when the device has been opened for exclusive
                        -access.
   PARF_SLOWMODE        Set this bit if you want to use slow

                        -speed mode for transfers to very slow printers.
                        Should not be used with high-speed printers.
   PARF_SHARED          Set this bit if you want to allow other

```c
                        tasks to simultaneously access the parallel port.
                        The default is exclusive access. If someone already
                        has the port, whether for exclusive or shared
                        access, and you ask for exclusive access, your
                        [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) call will fail (must be modified
                        before [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)).
```
