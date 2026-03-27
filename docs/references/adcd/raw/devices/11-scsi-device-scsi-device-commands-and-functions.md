# 11 SCSI Device / SCSI Device Commands and Functions


SCSI Device Command  Operation
-------------------  ---------
[HD_SCSICMD](../Devices_Manual_guide/node0078.html)           Issue a SCSI-direct command to a SCSI unit.


Trackdisk Device Commands Supported by the SCSI Device
------------------------------------------------------
[TD_CHANGESTATE](../Includes_and_Autodocs_2._guide/node0525.html)       Return the disk present/not-present status of a drive.
[TD_FORMAT](../Includes_and_Autodocs_2._guide/node0527.html)            Initialize one or more tracks with a data buffer.
[TD_PROTSTATUS](../Includes_and_Autodocs_2._guide/node052C.html)        Return the write-protect status of a disk.
[TD_SEEK](../Includes_and_Autodocs_2._guide/node0530.html)              Move the head to a specific track.


Exec Commands Supported by SCSI Device
--------------------------------------
CMD_READ             Read one or more sectors from a disk.
CMD_START            Restart a SCSI unit that was previously stopped with
                     CMD_STOP.
CMD_STOP             Stop a SCSI unit.
CMD_WRITE            Write one or more sectors to a disk.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)            Abort an I/O request to the SCSI device.
[AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html)           Allocate a block of memory.
[AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html)        Allocate a signal bit.
[CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)            Return the status of an I/O request.
[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)        Relinquish use of the SCSI device. All requests must

                     be complete before closing.
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)               Initiate a command and wait for completion

```c
                     (synchronous request).
```
[FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html)            Free a block of previously allocated memory.
[FreeSignal()](../Includes_and_Autodocs_2._guide/node0356.html)         Free a previously allocated signal.
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)         Obtain use of the SCSI device.  You specify the type

```c
                     of unit and its characteristics in the call to
                     OpenDevice().
```
[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)             Wait for completion of an I/O request and remove it


                     from the reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)        Create an extended [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure for use in

                     communicating with the SCSI device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)         Create a message port for reply messages from the

                     SCSI device.  Exec will signal a task when a message
                     arrives at the port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)        Delete the extended [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure created by

```c
                     [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)         Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

