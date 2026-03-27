---
title: 8 / Device Interface / Opening The Narrator Device
manual: devices
chapter: devices
section: 8-device-interface-opening-the-narrator-device
functions: [AllocMem, OpenDevice]
libraries: [exec.library]
---

# 8 / Device Interface / Opening The Narrator Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the narrator device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [narrator_rb](devices/8-narrator-device-device-interface.md).  The

```c
      [narrator_rb](devices/8-narrator-device-device-interface.md) structure is created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function.
```
   *  Open the narrator device.  Call [OpenDevice()](autodocs-2.0/narrator-device-opendevice.md) passing the I/O request.



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
the user's [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request structure.  In order to maintain
backwards compatibility with older versions of the narrator device, a
mechanism was needed for the device to ascertain whether it was being
opened with a V37 or pre-V37 style I/O request structure. The pad field in
the pre-V37 [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request structure (which no one should have
ever touched!) has been replaced by the flags field in the V37 [narrator_rb](devices/8-narrator-device-device-interface.md)
structure, and is our path to upward compatibility.  The device checks to
see if a bit is set in this flags field.  This bit must be set before
opening the device if V37 or later features of the narrator device are to
be used.  There are two defined constants in the include file, NDB_NEWIORB
and NDF_NEWIORB. NDB_NEWIORB specifies the bit which must be set in the
flags field, NDF_NEWIORB is the field definition of the bit (1 <<
NDB_NEWIORB).

Once the device is opened, the [mouth_rb](devices/8-narrator-device-device-interface.md) (read) I/O request structure can
be set up.  Each [CMD_READ](autodocs-2.0/narrator-device-cmd-read.md) request must be matched with an associated
[CMD_WRITE](autodocs-2.0/narrator-device-cmd-write.md) request.  This is necessary for the device to match the various
sync events with a particular utterance.  The read I/O request structure
is easily set up as follows:

   *  Create a read message port using the [CreatePort()](autodocs-2.0/amiga-lib-createport.md) function.

   *  Allocate memory for the [mouth_rb](devices/8-narrator-device-device-interface.md) extended I/O request structure using

```c
      [AllocMem()](autodocs-2.0/exec-library-allocmem.md).
```
   *  Copy the [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request structure used to open the device

```c
      into the voice field of the [mouth_rb](devices/8-narrator-device-device-interface.md) I/O request structure. This will
      set the fields necessary for the device to make the correct
      correspondence between read and write requests.
```
   *  Copy the pointer to the read message port returned from [CreatePort()](autodocs-2.0/amiga-lib-createport.md)

```c
      into the voice.message.io_Message.mn_ReplyPort field of the [mouth_rb](devices/8-narrator-device-device-interface.md)
      structure.
```
The following code fragment, in conjunction with the [OpenDevice()](autodocs-2.0/narrator-device-opendevice.md) code
fragment above, shows how to set up the [mouth_rb](devices/8-narrator-device-device-interface.md) structure:


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

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
