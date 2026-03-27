# 2 / Hardware Control Commands / CMD_STOP


This command stops the current write cycle immediately. If there are no
[CMD_WRITE](../Devices_Manual_guide/node0033.html)s in progress, it sets a flag so any future CMD_WRITEs are queued
up and do not begin processing (playing).

