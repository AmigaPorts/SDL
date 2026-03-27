# 2 / Hardware Control Commands / CMD_START


[CMD_START](../Includes_and_Autodocs_2._guide/node04B3.html) undoes the CMD_STOP command. Any cycles that were stopped by the
[CMD_STOP](../Devices_Manual_guide/node0039.html) command are actually lost because of the impossibility of
determining exactly where the DMA ceased. If the [CMD_WRITE](../Devices_Manual_guide/node0033.html) command was
playing two cycles and the first one was playing when [CMD_STOP](../Devices_Manual_guide/node0039.html) was issued,
the first one is lost and the second one will be played.

This command is also useful when you are playing the same wave form with
the same period out of multiple channels. If the channels are stopped when
the [CMD_WRITE](../Devices_Manual_guide/node0033.html) commands are issued, CMD_START exactly synchronizes them,
avoiding cancellation and distortion. When channels are allocated, they
are effectively started by the CMD_START command.

