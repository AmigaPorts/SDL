# 2 / Hardware Control Commands / ADCMD_PERVOL


[ADCMD_PERVOL](../Includes_and_Autodocs_2._guide/node04AA.html) lets you change the volume and period of a [CMD_WRITE](../Devices_Manual_guide/node0033.html) that is
in progress. The change can take place immediately or you can set the
ADIOF_SYNCCYCLE flag to have the change occur at the end of the cycle.
This is useful to produce vibratos, glissandos, tremolos, and volume
envelopes in music or to change the volume of a sound.

