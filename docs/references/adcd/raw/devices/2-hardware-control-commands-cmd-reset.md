# 2 / Hardware Control Commands / CMD_RESET


[CMD_RESET](../Includes_and_Autodocs_2._guide/node04B2.html) restores all the audio hardware registers. It clears the attach
bits, restores the audio interrupt vectors if the programmer has changed
them, and performs the [CMD_FLUSH](../Devices_Manual_guide/node0036.html) command to cancel all requests to the
channels. CMD_RESET also unstops channels that have had a [CMD_STOP](../Devices_Manual_guide/node0039.html)
performed on them. [CMD_RESET](../Devices_Manual_guide/node0037.html) does not unlock channels that have been
locked by [ADCMD_LOCK](../Devices_Manual_guide/node0031.html).

