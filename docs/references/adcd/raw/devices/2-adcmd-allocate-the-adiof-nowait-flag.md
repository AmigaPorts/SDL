# 2 / ADCMD_ALLOCATE / The ADIOF_NOWAIT Flag


If you need to produce a sound right now and otherwise don't want to
allocate, set the ADIOF_NOWAIT flag to 1. This will cause the command to
return an IOERR_ALLOCFAILED error if it cannot allocate any of the
channels. If you are producing a non-urgent sound and you can wait, set
the ADIOF_NOWAIT flag to 0. Then, the [IOAudio](../Devices_Manual_guide/node001E.html#line9) block returns only when you
get the allocation. If ADIOF_NOWAIT is set to 0, the audio device will
continue to retry the allocation request whenever channels are freed until
it is successful. If the program decides to cancel the request,
[AbortIO()](../Includes_and_Autodocs_2._guide/node04A5.html) can be used.

