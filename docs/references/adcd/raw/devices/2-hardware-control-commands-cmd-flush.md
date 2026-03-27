# 2 / Hardware Control Commands / CMD_FLUSH


[CMD_FLUSH](../Includes_and_Autodocs_2._guide/node04B0.html) aborts (calls [AbortIO()](../Includes_and_Autodocs_2._guide/node04A5.html) ) all [CMD_WRITE](../Devices_Manual_guide/node0033.html) and all [ADCMD_WAITCYCLE](../Devices_Manual_guide/node0038.html)s
that are queued up for the channel or channels. It does not abort
[ADCMD_LOCK](../Devices_Manual_guide/node0031.html)s (only [ADCMD_FREE](../Devices_Manual_guide/node002F.html) clears locks).

