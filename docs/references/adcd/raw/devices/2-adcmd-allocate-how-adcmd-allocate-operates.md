# 2 / ADCMD_ALLOCATE / How ADCMD_ALLOCATE Operates


The [ADCMD_ALLOCATE](../Includes_and_Autodocs_2._guide/node04A6.html) command tries the first  [combination](../Devices_Manual_guide/node002A.html#line15) , 3, to see if
channels 0 and 1 are not being used. If they are available, the 3 is
copied into the io_Unit field and you get an allocation key for these
channels in the ioa_AllocKey field. You copy the key into other I/O blocks
for any other commands you may want to perform on these channels.

If channels 0 and 1 are being used, [ADCMD_ALLOCATE](../Includes_and_Autodocs_2._guide/node04A6.html) tries the other
combinations in turn.  If all the combinations are in use, ADCMD_ALLOCATE
checks the precedence number of the users of the channels and finds the
combination that requires it to steal the channel or channels of the
lowest precedence. If all the combinations require stealing a channel or
channels of equal or higher precedence, the ADCMD_ALLOCATE request fails.
Precedence is in the ln_Pri field of the io_Message in the [IOAudio](../Devices_Manual_guide/node001E.html#line9) block
you pass to ADCMD_ALLOCATE; it has a value from -128 to 127.

