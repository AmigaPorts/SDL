# 5 / Setting and Reading the Controller Type / Setting The Controller Type


You set the type of gameport controller by passing an I/O request to the
device with [GPD_SETCTYPE](../Includes_and_Autodocs_2._guide/node04BD.html) set in io_Command, 1 set in io_Length and the
address of the byte variable describing the controller type set in io_Data.

The gameport device is a shared device; many tasks may have it open at any
given time. Hence, a high level protocol has been established to prevent
multiple tasks from reading the same unit at the same time.

 [Three Step Protocol for Using the Gameport Device](../Devices_Manual_guide/node00BB.html) 

