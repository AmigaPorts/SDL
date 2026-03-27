---
title: 2 / Device Interface / Opening The Audio Device
manual: devices
chapter: devices
section: 2-device-interface-opening-the-audio-device
functions: [AllocMem, OpenDevice]
libraries: [exec.library]
---

# 2 / Device Interface / Opening The Audio Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before you can use the audio device, you must first open it with a call to
[OpenDevice()](autodocs-2.0/audio-device-opendevice.md). Four primary steps are required to open the audio device:

   *  Create a message port using [CreatePort](autodocs-2.0/amiga-lib-createport.md) Reply messages from the

      device must be directed to a message port.
   *  Allocate memory for an extended I/O request structure of type

```c
      [IOAudio](devices/2-audio-device-device-interface.md) using [AllocMem()](autodocs-2.0/exec-library-allocmem.md).
```
   *  Fill in io_Message.mn_ReplyPort with the message port created by

      CreatePort.
   *  Open the audio device.  Call OpenDevice(), passing IOAudio.


  struct MsgPort  *AudioMP;      /* Define storage for port pointer */
  struct IOAudio  *AudioIO;      /* Define storage for IORequest pointer */

  if (AudioMP = CreatePort(0,0) )

```c
      {
      AudioIO = (struct IOAudio *)
                AllocMem(sizeof(struct IOAudio), MEMF_PUBLIC | MEMF_CLEAR);
      if (AudioIO)
          {
          AudioIO->ioa_Request.io_Message.mn_ReplyPort  = AudioMP;
          AudioIO->ioa_AllocKey                         = 0;
          }

      if (OpenDevice(AUDIONAME,0L,(struct IORequest *)AudioIO,0L) )
          printf("%s did not open\n",AUDIONAME);
```
A special feature of the OpenDevice() function with the audio device
allows you to automatically allocate channels for your program to use when
the device is opened.  This is convenient since you must allocate one or
more channels before you can produce sound.

This is done by setting ioa_AllocKey to zero, setting
ioa_Request.io_Message.mn_Node.ln_Pri to the appropriate precedence,
setting io_Data to the address of a channel combination array, and setting
ioa_Request.ioa_Length to a non-zero value (the length of the channel
combination array).  The audio device will attempt to allocate channels
just as if you had sent the [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) command (see below).  If the
allocation fails, the OpenDevice() call will return immediately.

If you want to allocate channels at some later time, set the
ioa_Request.ioa_Length field of the IOAudio block to zero when you call
OpenDevice().  For more on channel allocation and the  [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md)
command, see the section on [Allocation and Arbitration](devices/2-audio-device-allocation-and-arbitration-commands.md) below.


```c
    UBYTE chans[] = {1,2,4,8};  /* get any of the four channels */

    if (AudioIO)
        {
        AudioIO->ioa_Request.io_Message.mn_ReplyPort  = AudioMP;
        AudioIO->ioa_AllocKey                         = 0;
        AudioIO->ioa_Request.io_Message.mn_Node.ln_Pri= 120;
        AudioIO->ioa_Data                             = chans;
        AudioIO->ioa_Length                           = sizeof(chans);
        }

    if (OpenDevice(AUDIONAME,0L,(struct IORequest *)AudioIO,0L) )
        printf("%s did not open\n",AUDIONAME);
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
