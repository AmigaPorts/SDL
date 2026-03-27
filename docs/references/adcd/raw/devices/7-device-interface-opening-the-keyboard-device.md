# 7 / Device Interface / Opening The Keyboard Device


Three primary steps are required to open the keyboard device:

   *  Create a message port using the [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) function.

   *  Create an extended I/O request structure using the [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)

```c
      function. CreateExtIO() will initialize the I/O request with your
      reply port.
```
   *  Open the keyboard device. Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing the I/O request.


struct MsgPort  *KeyMP;         /* Pointer for Message Port */
struct IOStdReq *KeyIO;         /* Pointer for I/O request */

if (KeyMP=CreatePort(NULL,NULL))
  if (KeyIO=(struct IOStdReq *)CreateExtIO(KeyMP,sizeof(struct IOStdReq)))

```c
    if (OpenDevice( "keyboard.device",NULL,(struct IORequest *)KeyIO,NULL))
        printf("keyboard.device did not open\n");
```
