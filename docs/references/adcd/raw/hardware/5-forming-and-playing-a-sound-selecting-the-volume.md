# 5 / Forming and Playing a Sound / Selecting the Volume


The volume you set here is the overall volume of all the sound coming from
the audio channel. The relative loudness of sounds, which will concern you
when you combine notes, is determined by the  [amplitude](../Hardware_Manual_guide/node00D6.html#line33)  of the wave form.
There is a six-bit volume register for each audio channel. To control the
volume of sound that will be output through the selected audio channel,
you write the desired value into the register AUDxVOL, where "x" is
replaced by the channel number. You can specify values from 64 to 0. These
volume values correspond to decibel levels. At the end of this chapter is
a table showing the  [decibel value](../Hardware_Manual_guide/node00F1.html)  for each of the 65 volume levels.

For a typical output at volume 64, with maximum data values of -128 to
127, the voltage output is between +.4 volts and -.4 volts. Some volume
levels and the corresponding decibel values are shown in Table 5-2.




```c
                Table 5-2: Volume Values


          Volume  Decibel Value
          ------  -------------
            64         0         (maximum volume)
            48        -2.5
            32        -6.0
            16        -12.0      (12 db down from the volume
                                  at maximum level)
```
For any volume setting from 64 to 0, you write the value into bits 5-0 of
AUD0VOL. For example:

SETAUD0VOLUME:

```c
        LEA     CUSTOM,a0
        MOVE.W  #48,AUD0VOL(a0)
```
The decibels are shown as negative values from a maximum of 0 because this
is the way a recording device, such as a tape recorder, shows the
recording level. Usually, the recorder has a dial showing 0 as the optimum
recording level. Anything less than the optimum value is shown as a minus
quantity.

