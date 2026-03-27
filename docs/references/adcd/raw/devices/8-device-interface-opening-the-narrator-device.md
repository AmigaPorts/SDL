# 8 / Device Interface / Opening The Narrator Device


Three primary steps are required to open the narrator device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [narrator_rb](../Devices_Manual_guide/node0115.html#line17).  The

```c
      [narrator_rb](../Devices_Manual_guide/node0115.html#line17) structure is created by the [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) function.
```
   *  Open the narrator device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node04C8.html) passing the I/O request.



```c
    struct MsgPort *VoiceMP;
    struct narrator_rb *VoiceIO;

    if (VoiceMP = CreatePort("speech_write",0))
        if (VoiceIO = (struct narrator_rb *)
                        CreateExtIO(VoiceMP,sizeof(struct narrator_rb));
            if (OpenDevice("narrator.device", 0, VoiceIO, 0))
                    printf("narrator.device did not open\n");
```
When the narrator device is first opened, it initializes certain fields in
the user's [narrator_rb](../Devices_Manual_guide/node0115.html#line17) I/O request structure.  In order to maintain
backwards compatibility with older versions of the narrator device, a
mechanism was needed for the device to ascertain whether it was being
opened with a V37 or pre-V37 style I/O request structure. The pad field in
the pre-V37 [narrator_rb](../Devices_Manual_guide/node0115.html#line17) I/O request structure (which no one should have
ever touched!) has been replaced by the flags field in the V37 [narrator_rb](../Devices_Manual_guide/node0115.html#line17)
structure, and is our path to upward compatibility.  The device checks to
see if a bit is set in this flags field.  This bit must be set before
opening the device if V37 or later features of the narrator device are to
be used.  There are two defined constants in the include file, NDB_NEWIORB
and NDF_NEWIORB. NDB_NEWIORB specifies the bit which must be set in the
flags field, NDF_NEWIORB is the field definition of the bit (1 <<
NDB_NEWIORB).

Once the device is opened, the [mouth_rb](../Devices_Manual_guide/node0115.html#line47) (read) I/O request structure can
be set up.  Each [CMD_READ](../Includes_and_Autodocs_2._guide/node04C3.html) request must be matched with an associated
[CMD_WRITE](../Includes_and_Autodocs_2._guide/node04C7.html) request.  This is necessary for the device to match the various
sync events with a particular utterance.  The read I/O request structure
is easily set up as follows:

   *  Create a read message port using the [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) function.

   *  Allocate memory for the [mouth_rb](../Devices_Manual_guide/node0115.html#line47) extended I/O request structure using

```c
      [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html).
```
   *  Copy the [narrator_rb](../Devices_Manual_guide/node0115.html#line17) I/O request structure used to open the device

```c
      into the voice field of the [mouth_rb](../Devices_Manual_guide/node0115.html#line47) I/O request structure. This will
      set the fields necessary for the device to make the correct
      correspondence between read and write requests.
```
   *  Copy the pointer to the read message port returned from [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)

```c
      into the voice.message.io_Message.mn_ReplyPort field of the [mouth_rb](../Devices_Manual_guide/node0115.html#line47)
      structure.
```
The following code fragment, in conjunction with the [OpenDevice()](../Includes_and_Autodocs_2._guide/node04C8.html) code
fragment above, shows how to set up the [mouth_rb](../Devices_Manual_guide/node0115.html#line47) structure:


```c
    struct  MsgPort   *MouthMP;
    struct  mouth_rb  *MouthIO;

    if (MouthMP = CreatePort("narrator_read", 0))
      if (!(MouthIO = (struct mouth_rb *)
                 AllocMem(sizeof(struct mouth_rb),MEMF_PUBLIC|MEMF_CLEAR)))
          {
          /* Copy I/O request used in OpenDevice */
          MouthIO->voice = *VoiceIO;
          /* Set port */
          MouthIO->voice.message.io_Message.mn_ReplyPort=MouthMP;
          }
      else
          printf("AllocMem failed\n");
    else
        printf("CreatePort failed\n");
```
