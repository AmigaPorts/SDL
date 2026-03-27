# 6 / Device Interface / Opening The Input Device


Three primary steps are required to open the input device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [IOStdReq](../Devices_Manual_guide/node00CC.html#line12) or [timerequest](../Devices_Manual_guide/node00CC.html#line29). The

```c
      I/O request created by the [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) function will be used to
      pass commands and data to the input device.
```
   *  Open the Input device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing the I/O request.

   struct MsgPort  *InputMP;   /* Message port pointer */
   struct IOStdReq *InputIO;   /* I/O request pointer */

   if (InputMP=CreatePort(0,0) )

```c
       if (InputIO=(struct IOStdReq *)
                    CreateExtIO(InputMP,sizeof(struct IOStdReq)) )
           if (OpenDevice("input.device",0L,(struct IORequest *)InputIO,0))
               printf("input.device did not open\n");
```
The above code will work for all the input device commands except for the
ones which require a time specification.  For those, the code would look
like this:

   #include <devices/timer.h>

   struct MsgPort  *InputMP;      /* Message port pointer */
   struct timerequest *InputIO;   /* I/O request pointer */

   if (InputMP=CreatePort(0,0) )

```c
       if (InputIO=(struct timerequest *)
                    CreateExtIO(InputMP,sizeof(struct timerequest)) )
           if (OpenDevice("input.device",0L,(struct IORequest *)InputIO,0))
               printf("input.device did not open\n");
```
