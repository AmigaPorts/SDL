---
title: 2 Audio Device / Audio Allocation and Arbitration
manual: devices
chapter: devices
section: 2-audio-device-audio-allocation-and-arbitration
functions: []
libraries: []
---

# 2 Audio Device / Audio Allocation and Arbitration

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The first command you send to the audio device should always be
[ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md).  You can do this when you open the device, or at a later
time.  You specify the channels you want in the ioa_Data field of the
[IOAudio](devices/2-audio-device-device-interface.md) block. If the allocation succeeds, the audio device will return
the channels that you now own in the lower four bits of the
ioa_Request.io_Unit field of your [IOAudio](devices/2-audio-device-device-interface.md) block. For instance, if the
io_Unit field equals 5 (binary 0101) then you own channels 2 and 0.  If
the io_Unit field equals 15 (binary 1111) then you own all the channels.

When you send the [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) command, the audio device will also
return a unique allocation key in the ioa_AllocKey of the [IOAudio](devices/2-audio-device-device-interface.md) block.
You must use this allocation key for all subsequent commands that you send
to the audio device.  The audio device uses this unique key to identify
which task issued the command.  If you do not use the correct allocation
key assigned to you by the audio device when you send a command, your
command will be ignored.

When you request a channel with [ADCMD_ALLOCATE](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md), you specify a precedence
number from -128 to 127 in the ioa_Request.io_Message.mn_Node.ln_Pri field
of the IOAudio block. If a channel you want is being used and you have
specified a higher precedence than the current user, ADCMD_ALLOCATE will
"steal" the channel from the other user. Later on, if your precedence is
lower than that of another user who is performing an allocation, the
channel may be stolen from you.

If you set the precedence to 127 when you open the device or raise the
precedence to 127 with the [ADCMD_SETPREC](devices/2-allocation-and-arbitration-commands-adcmd-setprec.md) command, no other tasks can steal
a channel from you. When you have finished with a channel, you must
relinquish it with the [ADCMD_FREE](devices/2-allocation-and-arbitration-commands-adcmd-free.md) command to make it available for other
users.

The following table shows suggested precedence values.


                SUGGESTED PRECEDENCES FOR CHANNEL ALLOCATION
   Predecence                   Type of Sound
   ----------                   -------------

```c
     127          Unstoppable. Sounds first allocated at lower precedence,
                  then set to this to the highest level.

     90 - 100     Emergencies.  Alert, urgent situation
                  that requires immediate action.

     80 - 90      Annunciators.  Attention, bell (CTRL-G).

     75           Speech. Synthesized or recorded speech (narrator.device).

     50 - 70      Sonic cues.  Sounds thatprovide information that is not
                  provided by graphics. Only the beginning of each sound
                  (enough to recognize it) should be at this level;the rest
                  should be set to sound effects level.

    -50 - 50      Music program.  Musical notes in music-oriented program.
                  The higher levels should be used for the attack portions
                  of each note.

    -70 - -50     Sound effects.  Sounds used in conjunction with graphics.
                  More important sounds should use higher levels.

    -100 - -80    Background. Theme music and restartable background
                  sounds.

    -128          Silence. Lowest level (freeing the channel completely
                  is preferred).
```
If you attempt to perform a command on a channel that has been stolen from
you by a higher priority task, an AUDIO_NOALLOCATION error is returned and
the bit in the ioa_Request.io_Unit field corresponding to the stolen
channel is cleared so you know which channel was stolen.

If you want to be warned before a channel is stolen so that you have a
chance to stop your sound gracefully, then you should use the [ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md)
command after you open the device.  This command is also useful for
programs which write directly to the audio hardware.  For more on
[ADCMD_LOCK](devices/2-allocation-and-arbitration-commands-adcmd-lock.md), see the section below.

