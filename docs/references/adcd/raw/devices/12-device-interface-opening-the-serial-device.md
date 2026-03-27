# 12 / Device Interface / Opening The Serial Device


Three primary steps are required to open the serial device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type IOExtSer using

```c
      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html). CreateExtIO() will initialize the I/O request to point
      to your reply port.
```
   *  Open the serial device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node04D4.html), passing the I/O request.

   struct MsgPort  *SerialMP;          /* Define storage for one pointer */
   struct IOExtSer *SerialIO;         /* Define storage for one pointer */

   if (SerialMP=CreatePort(0,0) )

```c
       if (SerialIO=(struct IOExtSer *)
              CreateExtIO(SerialMP,sizeof(struct IOExtSer)) )
           SerialIO->io_SerFlags=SERF_SHARED;  /* Turn on SHARED mode */
           if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0) )
               printf("%s did not open\n",SERIALNAME);
```
During the open, the serial device pays attention to a subset of the flags
in the io_SerFlags field.  The flag bits, [SERF_SHARED](../Devices_Manual_guide/node00A7.html#line20) and [SERF_7WIRE](../Devices_Manual_guide/node00A7.html#line57), must
be set before open.  For consistency, the other flag bits should also be
properly set.  Full descriptions of all flags will be given later.

The serial device automatically fills in default settings for all
parameters - stop bits, parity, baud rate, etc.  For the default unit, the
settings will come from Preferences.  You may need to change certain
parameters, such as the baud rate, to match your requirements. Once the
serial device is opened, all characters received will be buffered, even if
there is no current request for them.

