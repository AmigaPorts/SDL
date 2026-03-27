# 2 / Allocation and Arbitration Commands / ADCMD_ALLOCATE


This command gives your program a channel to use and should be the first
command you send to the audio device.  You specify the channels you want
by setting a pointer to an array in the ioa_Data field of the [IOAudio](../Devices_Manual_guide/node001E.html#line9)
structure.  This array uses a value of 1 to allocate channel 0, 2 for
channel 1, 4 for channel 2, and 8 for channel 3. For multiple channels,
add the values together.  For example, if you want to allocate all
channels, use a value of 15.

If you want a pair of stereo channels and you have no preference about
which of the left and right channels the system will choose for the
allocation, you can pass a pointer to an array containing 3, 5, 10, and
12. Channels 1 and 2 produce sound on the left side and channels 0 and 3
on the right side. The table below shows how this array corresponds to all
the possible combinations of a right and a left channel.


```c
                     POSSIBLE CHANNEL COMBINATIONS
                                                           Decimal
     Channel 3    Channel 2    Channel 1    Channel 0      Value of
      (right)       (left)      (left)       (right)    Allocation Mask
     ---------    ---------    ---------    ---------   ---------------
         0            0            1            1              3
         0            1            0            1              5
         1            0            1            0              10
         1            1            0            0              12
```
 [How ADCMD_ALLOCATE Operates](../Devices_Manual_guide/node002B.html)                [ADCMD_ALLOCATE Examples](../Devices_Manual_guide/node002D.html) 
 [The ADIOF_NOWAIT Flag](../Devices_Manual_guide/node002C.html)                      [The Allocation Key](../Devices_Manual_guide/node002E.html) 

