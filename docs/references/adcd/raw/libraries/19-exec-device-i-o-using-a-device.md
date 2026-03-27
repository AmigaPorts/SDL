# 19 Exec Device I/O / Using a Device


Once a device has been opened, you use it by passing the I/O request to
it.  When the device processes the I/O request, it acts on the information
the I/O request contains and returns a reply message, i.e., the I/O
request, to the message port when it is finished.  The I/O request is
passed to a device using one of three functions, [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) and
[BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html).  They take only one argument: the I/O request you wish to pass
to the device.

  * [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) is a synchronous function.  It will not return until the

```c
    device has finished with the I/O request.  DoIO() will wait, if
    necessary, for the request to complete, and will remove ([GetMsg()](../Libraries_Manual_guide/node02F2.html))
    any reply message from the message port.
```
  * [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) is an asynchronous function.  It can return immediately, but

```c
    the I/O operation it initiates may take a short or long time. SendIO
    is normally used when your application has other work to do while the
    I/O request is being acted upon, or if your application wishes to
    allow the user to cancel the I/O. Using SendIO() requires that you
    wait on or check for completion of the request, and remove the
    completed request from the message port with [GetMsg()](../Libraries_Manual_guide/node02F2.html).
```
  * [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html) is commonly used to control the QuickIO bit when sending an

```c
    I/O request to a device.  When the QuickIO flag ([IOF_QUICK](../Includes_and_Autodocs_2._guide/node0094.html#line45)) is set in
    the I/O request, a device is allowed to take certain shortcuts in
    performing and completing a request.  If the request can complete
    immediately, the device will not return a reply message and the
    QuickIO flag will remain set.  If the request cannot be completed
    immediately, the QUICK_IO flag will be clear.  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) normally
    requests QuickIO; [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) does not.
```
An I/O request typically has three fields set for every command sent to a
device.  You set the command itself in the [io_Command](../Includes_and_Autodocs_2._guide/node0094.html#line28) field, a pointer to
the data for the command in the [io_Data](../Includes_and_Autodocs_2._guide/node0094.html#line28) field, and the length of the data
in the [io_Length](../Includes_and_Autodocs_2._guide/node0094.html#line28) field.


```c
    SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
    SerialIO->IOSer.io_Data     = ReadBuffer;
    SerialIO->IOSer.io_Command  = CMD_READ;
    SendIO((struct IORequest *)SerialIO);
```
Commands consist of two parts (separated by an underscore, all in upper
case): a prefix and the command word.  The prefix indicates whether the
command is an Exec or device specific command.  All Exec standard commands
have "CMD" as the prefix.  They are defined in the include file
<exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html#line49)>.



             Table 19-2: Standard Exec Device Commands

            CMD_READ   CMD_START  CMD_UPDATE  CMD_CLEAR
            CMD_WRITE  CMD_STOP   CMD_FLUSH   CMD_RESET
You should not assume that a device supports all standard Exec device
commands.  Always check the documentation before attempting to use one of
them.  Device-specific command prefixes vary with the device.




```c
             Table 19-3: System Device Command Prefixes

        Device     Prefix                       Example
        ------     ------                       -------
        [Audio](../Devices_Manual_guide/node001A.html)      [ADCMD](../Includes_and_Autodocs_2._guide/node0038.html#line25)                        ADCMD_ALLOCATE
        [Clipboard](../Devices_Manual_guide/node0065.html)  [CBD](../Includes_and_Autodocs_2._guide/node0048.html#line27)                          CBD_POST
        [Console](../Devices_Manual_guide/node0080.html)    [CD](../Includes_and_Autodocs_2._guide/node0050.html#line22)                           CD_ASKKEYMAP
        [Gameport](../Devices_Manual_guide/node00AE.html)   [GPD](../Includes_and_Autodocs_2._guide/node0039.html#line22)                          GPD_SETCTYPE
        [Input](../Devices_Manual_guide/node00CA.html)      [IND](../Includes_and_Autodocs_2._guide/node0049.html#line18)                          IND_SETMPORT
        [Keyboard](../Devices_Manual_guide/node00FC.html)   [KBD](../Includes_and_Autodocs_2._guide/node0059.html#line18)                          KBD_READMATRIX
        [Narrator](../Devices_Manual_guide/node0113.html)   no device specific commands  -
        [Parallel](../Devices_Manual_guide/node000E.html)   [PDCMD](../Includes_and_Autodocs_2._guide/node004A.html#line92)                        PDCMD_QUERY
        [Printer](../Devices_Manual_guide/node003E.html)    [PRD](../Includes_and_Autodocs_2._guide/node0052.html#line30)                          PRD_PRTCOMMAND
        [SCSI](../Devices_Manual_guide/node0073.html)       [HD](../Includes_and_Autodocs_2._guide/node0043.html#line67)                           HD_SCSICMD
        [Serial](../Devices_Manual_guide/node009A.html)     [SDCMD](../Includes_and_Autodocs_2._guide/node004B.html#line94)                        SDCMD_BREAK
        [Timer](../Devices_Manual_guide/node00BD.html)      [TR](../Includes_and_Autodocs_2._guide/node0053.html#line41)                           TR_ADDREQUEST
        [Trackdisk](../Devices_Manual_guide/node00DC.html)  [TD](../Includes_and_Autodocs_2._guide/node005B.html#line73) and [ETD](../Includes_and_Autodocs_2._guide/node005B.html#line97)                   TD_MOTOR/ETD_MOTOR
```
Each device maintains its own I/O request queue.  When a device receives
an I/O request, it either processes the request immediately or puts it in
the queue because one is already being processed. After an I/O request is
completely processed, the device checks its queue and if it finds another
I/O request, begins to process that request.

 [Synchronous Vs. Asynchronous Requests](../Libraries_Manual_guide/node02A0.html)    [I/O Request Completion](../Libraries_Manual_guide/node02A1.html) 

