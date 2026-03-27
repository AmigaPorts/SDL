# 12 / / Using Separate Read And Write Tasks


In some cases there are advantages to creating a separate [IOExtSer](../Devices_Manual_guide/node009C.html#line7) for
reading and writing.  This allows simultaneous operation of both reading
and writing.  Some users of the device have separate tasks for read and
write operations. The sample code below creates a separate reply port and
request for writing to the serial device.


struct IOExtSer *SerialWriteIO;
struct MsgPort  *SerialWriteMP;

/*
 * If two tasks will use the same device at the same time, it is
 * preferred use two OpenDevice() calls and SHARED mode.  If exclusive
 * access mode is required, then you will need to copy an existing
 * IORequest.
 * Remember that two separate tasks will require two message ports.
 */

SerialWriteMP = CreatePort(0,0);
SerialWriteIO = (struct IOExtSer *)

```c
                CreateExtIO( SerialWriteMP,sizeof(struct IOExtSer) );
```
if (SerialWriteMP && SerialWriteIO )


```c
    {

    /* Copy over the entire old IO request, then stuff the
     * new Message port pointer.
     */

    CopyMem( SerialIO, SerialWriteIO, sizeof(struct IOExtSer) );
    SerialWriteIO->IOSer.io_Message.mn_ReplyPort = SerialWriteMP;

    SerialWriteIO->IOSer.io_Command  = CMD_WRITE;
    SerialWriteIO->IOSer.io_Length = -1;
    SerialWriteIO->IOSer.io_Data = (APTR)"A poet's food is love and fame";
    DoIO(SerialWriteIO);
    }
```
   Where's OpenDevice()?
   ---------------------
   This code assumes that the [OpenDevice()](../Includes_and_Autodocs_2._guide/node04D4.html) function has already been
   called.  The initialized read request block is copied onto the new
   write request block.

