# 2 / Allocation and Arbitration Commands / ADCMD_FREE


[ADCMD_FREE](../Includes_and_Autodocs_2._guide/node04A8.html) is the opposite of [ADCMD_ALLOCATE](../Devices_Manual_guide/node002A.html). When you perform ADCMD_FREE
on a channel, it does a [CMD_RESET](../Devices_Manual_guide/node0037.html) command on the hardware and "unlocks"
the channel. It also checks to see if there are other pending allocation
requests. You do not need to perform ADCMD_FREE on channels stolen from
you. If you want channels back after they have been stolen, you must
reallocate them with the same allocation key.

