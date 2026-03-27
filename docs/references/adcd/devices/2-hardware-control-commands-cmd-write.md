---
title: 2 / Hardware Control Commands / CMD_WRITE
manual: devices
chapter: devices
section: 2-hardware-control-commands-cmd-write
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 2 / Hardware Control Commands / CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a single-channel command and is the main command for making
sounds. You pass the following to [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md):

   *  A pointer to the waveform to be played (must start on a word boundary

```c
      and must be in memory accessible by the custom chips, MEMF_CHIP)
```
   *  The length of the waveform in bytes (must be an even number)

   *  A count of how many times you want to play the waveform

If the count is 0, [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) will play the waveform from beginning to end,
then repeat the waveform continuously until something aborts it.

If you want period and volume to be set at the start of the sound, set the
WRITE command's ADIOF_PERVOL flag. If you do not do this, the previous
volume and period for that channel will be used. This is one of the flags
that is cleared by [DoIO()](autodocs-2.0/exec-library-doio.md) and [SendIO()](autodocs-2.0/exec-library-sendio.md). The ioa_WriteMsg field in the
IOAudio block is an extra message field that can be replied to at the
start of the [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md). This second message is used only to tell you when
the CMD_WRITE command starts processing, and it is used only when the
ADIOF_WRITEMESSAGE flag is set to 1.

If a [CMD_STOP](devices/2-hardware-control-commands-cmd-stop.md) has been performed, the [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) requests are queued up.
The CMD_WRITE command does not make its own copy of the waveform, so any
modification of the waveform before the CMD_WRITE command is finished may
affect the sound. This is sometimes desirable for special effects. To
splice together two waveforms without clicks or pops, you must send a
separate, second CMD_WRITE command while the first is still in progress.
This technique is used in double-buffering, which is described below.

By using two waveform buffers and two [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) requests you can compute a
waveform continuously. This is called double-buffering. The following
describes how you use double-buffering.

   1. Compute a waveform in memory buffer A.

   2. Issue [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) A with io_Data pointing to buffer A.

   3. Continue the waveform in memory buffer B.

   4. Issue [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) B with io_Data pointing to Buffer B.

   5. Wait for [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) A to finish.

   6. Continue the waveform in memory buffer A.

   7. Issue [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) A with io_Data pointing to Buffer A.

   8. Wait for [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) B to finish.

   9. Loop back to step 3 until the waveform is finished.

  10. At the end, remember to wait until both [CMD_WRITE](autodocs-2.0/audio-device-cmd-write.md) A and B are

      finished.

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
