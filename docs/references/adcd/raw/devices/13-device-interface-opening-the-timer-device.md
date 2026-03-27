# 13 / Device Interface / Opening The Timer Device


Three primary steps are required to open the timer device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [timerequest](../Devices_Manual_guide/node00BF.html#line16) using

```c
      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).
```
   *  Open the timer device with one of the five timer device units. Call

```c
      [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) passing a pointer to the  [timerequest](../Devices_Manual_guide/node00BF.html#line16).
```
   struct MsgPort *TimerMP;   /* Message port pointer */
   struct timerequest *TimerIO;  /* I/O structure pointer */

     /* Create port for timer device communications */
   if (!(TimerMP = CreatePort(0,0)))
```c
       cleanexit(" Error: Can't create port\n",RETURN_FAIL);

     /* Create message block for device IO */
```
   if (!(TimerIO = (struct timerequest *)
```c
                   CreateExtIO(TimerMP)(sizeof timerequest)) )
       cleanexit(" Error: Can't create IO request\n",RETURN_FAIL);

     /* Open the timer device with UNIT_MICROHZ */
```
   if (error=OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0))

```c
       cleanexit(" Error: Can't open Timer.device\n",RETURN_FAIL);
```
The procedure for applications which only use the timer device functions
is slightly different:

   *  Declare the timer device base address variable TimerBase in the

      global data area.
   *  Allocate memory for a [timerequest](../Devices_Manual_guide/node00BF.html#line16) structure and a  [timeval](../Devices_Manual_guide/node00BF.html#line25) structure

```c
      using [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html).
```
   *  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing the allocated [timerequest](../Devices_Manual_guide/node00BF.html#line16) structure.

   *  Set the timer device base address variable to point to the timer

      device base.
   struct Library *TimerBase;  /* global library pointer */

   struct timerequest *TimerIO;
   struct timeval *time1;

     /* Allocate memory for timerequest and timeval structures */
   TimerIO=(struct timerequest *)AllocMem(sizeof(struct timerequest),
```c
                                  MEMF_PUBLIC | MEMF_CLEAR);
```
   time1=(struct timeval *)AllocMem(sizeof(struct timeval),
```c
                                  MEMF_PUBLIC | MEMF_CLEAR);
```
   if (!TimerIO | !time1)

```c
       cleanexit(" Error: Can't allocate memory for I/O structures\n",
                          RETURN_FAIL);
```
   if (error=OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0))
```c
       cleanexit(" Error: Can't open Timer.device\n",RETURN_FAIL);

     /* Set up pointer for timer functions */
```
   TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

