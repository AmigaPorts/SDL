---
title: 2 / ADCMD_ALLOCATE / How ADCMD_ALLOCATE Operates
manual: devices
chapter: devices
section: 2-adcmd-allocate-how-adcmd-allocate-operates
functions: []
libraries: []
---

# 2 / ADCMD_ALLOCATE / How ADCMD_ALLOCATE Operates

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command tries the first  [combination](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md) , 3, to see if
channels 0 and 1 are not being used. If they are available, the 3 is
copied into the io_Unit field and you get an allocation key for these
channels in the ioa_AllocKey field. You copy the key into other I/O blocks
for any other commands you may want to perform on these channels.

If channels 0 and 1 are being used, [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) tries the other
combinations in turn.  If all the combinations are in use, ADCMD_ALLOCATE
checks the precedence number of the users of the channels and finds the
combination that requires it to steal the channel or channels of the
lowest precedence. If all the combinations require stealing a channel or
channels of equal or higher precedence, the ADCMD_ALLOCATE request fails.
Precedence is in the ln_Pri field of the io_Message in the [IOAudio](devices/2-audio-device-device-interface.md) block
you pass to ADCMD_ALLOCATE; it has a value from -128 to 127.

