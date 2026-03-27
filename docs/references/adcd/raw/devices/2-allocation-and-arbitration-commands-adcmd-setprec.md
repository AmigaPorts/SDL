# 2 / Allocation and Arbitration Commands / ADCMD_SETPREC


This command changes the precedence of an allocated channel. As an example
of the use of [ADCMD_SETPREC](../Includes_and_Autodocs_2._guide/node04AB.html), assume that you are making the sound of a
chime that takes a long time to decay. It is important that user hears the
chime but not so important that he hears it decay all the way. You could
lower precedence after the initial attack portion of the sound to let
another program steal the channel. You can also set the precedence to
maximum (127) if you do not want the channel(s) stolen from you.

