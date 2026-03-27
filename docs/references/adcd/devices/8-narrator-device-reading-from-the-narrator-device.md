---
title: 8 Narrator Device / Reading from the Narrator Device
manual: devices
chapter: devices
section: 8-narrator-device-reading-from-the-narrator-device
functions: [OpenDevice, WaitIO]
libraries: [exec.library]
---

# 8 Narrator Device / Reading from the Narrator Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All read requests to the narrator device must be matched to an associated
write request.  This is done by copying the [narrator_rb](devices/8-narrator-device-device-interface.md) structure used in
the [OpenDevice()](autodocs-2.0/narrator-device-opendevice.md) call into the voice field of the [mouth_rb](devices/8-narrator-device-device-interface.md) I/O request
structure.  You must do this after the call to OpenDevice().  Matching the
read and write requests allows the narrator device to coordinate I/O
requests across multiple uses of the device.

In pre-V37 versions of the narrator device, only mouth shape changes can
be queried from the device.  This is done by setting the mouths field of
the [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request structure (the write request) to a non-zero
value.  The write request is then sent asynchronously to the device and
while it is in progress, synchronous read requests are sent to the device
using the [mouth_rb](devices/8-narrator-device-device-interface.md) I/O request structure.  When the mouth shape has
changed, the device will return the read request to the user with bit 0
set in the sync field of the [mouth_rb](devices/8-narrator-device-device-interface.md).  The fields width and height of the
mouth_rb structure will contain byte values which are proportional to the
actual width and height of the mouth for the phoneme currently being
spoken.  Read requests sent to the narrator device are not returned to the
user until one of two things happen: either the mouth shape has changed
(this prevents the user from having to constantly redraw the same mouth
shape), or the speech has completed.  The user can check io_Error to
determine if the mouth shape has changed (a return code of 0) or if the
speech has completed (return code of ND_NoWrite).

In addition to returning mouth shapes, reads to the V37 narrator device
can also perform two new functions: word and syllable sync. To generate
word and/or syllable sync events, the user must specify several bits in
the flags field of the write request ([narrator_rb](devices/8-narrator-device-device-interface.md) structure).  The bits
are NDB_WORDSYNC and NDB_SYLSYNC, for start of word and start of syllable
synchronization events, respectively, and, of course, NDB_NEWIORB, to
indicate that the V37 I/O request is required.

NDB_WORDSYNC and NDB_SYLSYNC tell the device to expect read requests and
to generate the appropriate event(s). As with mouth shape change events,
the write request is sent asynchronously to the device and, while it is in
progress, synchronous read requests are sent to the device.  The sync
field of the [mouth_rb](devices/8-narrator-device-device-interface.md) structure will contain flags indicating which events
(mouth shape changes, word sync, and/or syllable sync) have occurred.

The returned sync field flags are:


```c
    bit 0 (0x01) -> mouth shape change event
    bit 1 (0x02) -> start-of-word synchronization event
    bit 2 (0x04) -> start-of-syllable synchronization event
```
and 1 or more flags may be set for any particular read.

As with mouth shape changes, read requests will not return until the
requested event(s) have occurred, and the user must test the io_Error
field of the [mouth_rb](devices/8-narrator-device-device-interface.md) structure to tell when the speech has completed (an
error return of  ND_NoWrite).

Several read events can be compressed into a single event.  This can occur
in two ways: first when two dissimilar events occur between two successive
read requests.  For example, a single read may return both a mouth change
and a syllable sync event.  This should not present a problem if the user
checks for all events. The second is when multiple events of the same type
occur between successive read requests.  This is of no great concern in
dealing with mouth shape changes because, presumably, mouth events are
used to drive animation, and the animation procedure will simply draw the
current mouth shape.


```c
    Watch Those Sync Events.
    ------------------------
    When word or syllable sync is desired, the narrator device may
    compress multiple sync events into a single sync event.  Missing a
    word or syllable sync may cause word highlighting (for example) to
    lose sync with the speech output.  A future version of the device
    will include an extension to the [mouth_rb](devices/8-narrator-device-device-interface.md) I/O request structure which
    will contain word and syllable counts and, possibly, other
    synchronization methods.
```
The following code fragment shows the basics of how to perform reads from
the narrator device.  For a more complete example, see the [sample program](devices/devices-dev-examples-full-narrator-c.md)
at the end of this chapter.  For this fragment, take the code of the
previous write example as a starting point.  Then the following code would
need to be added:



```c
    struct  mouth_rb  *MouthIO;     /* Pointer to read IORequest block */
    struct  MsgPort   *MouthMP;     /* Pointer to read message port    */
```
/*
 * (1) Create a message port for the read request.
 */

```c
    if (!(MouthMP = CreatePort("narrator_read", 0L)))
        BellyUp("Read CreatePort failed");
```
/*
 * (2) Create an extended IORequest of type mouth_rb.
 */

```c
    if (!(MouthIO = (struct mouth_rb *)
                     CreateExtIO(MouthMP, sizeof(struct mouth_rb))))
        BellyUp("Read CreateExtIO failed");
```
/*
 * (3) Set up the read IORequest. Do this after the call to [OpenDevice()](autodocs-2.0/narrator-device-opendevice.md).
 * We assume that the write IORequest and the OpenDevice have been done
 */

```c
    MouthIO->voice  =  *SpeakIO;
    MouthIO->voice.message.io_Message.mn_ReplyPort = ReadMsgPort;
    MouthIO->voice.message.io_Command = CMD_READ;
```
/*
 * (4) Set the flags field of the [narrator_rb](devices/8-narrator-device-device-interface.md) write request to return the
 *     desired sync events.  If mouth shape changes are required, then the
 *     mouths field of the IORequest should be set to a non-zero value.
 */


```c
    SpeakIO->mouths = 1;            /* Generate mouth shape changes */
    SpeakIO->flags = NDF_NEWIORB  | /* Indicates V37 style IORequest */
                     NDF_WORDSYNC | /* Request start-of-word sync events */
                     NDF_SYLSYNC;   /* Request start-of-syll sync events */
```
/*
 * (5) Issue asynchronous write request. The driver initiates the write
 *      request and returns immediately.
 */


```c
    SendIO(SpeakIO);
```
/*
 * (6) Issue synchronous read requests. For each request we check the sync
 *     field to see which events have occurred.  Since any combination of
 *     events can be returned in a single read, we must check all
 *     possibilities.  We continue looping until the read request returns
 *     an error of ND_NoWrite, which indicates that the write request has
 *     completed.
 */


```c
    for (DoIO(MouthIO);MouthIO->voice.message.io_Error
                             != ND_NoWrite;DoIO(MouthIO))
          {
          if (MouthIO->sync & 0x01)  DoMouthShape();
          if (MouthIO->sync & 0x02)  DoWordSync();
          if (MouthIO->sync & 0x04)  DoSyllableSync();
          }
```
/*
 *  (7) Finally, we must perform a WaitIO() on the original write request.
 */


```c
    WaitIO(SpeakIO);
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
