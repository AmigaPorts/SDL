# 7 / Amiga Reset Handling / Ending A Reset Task (KBD_RESETHANDLERDONE)


This command tells the system that your reset handling code has completed.
If you are the last outstanding reset handler, the system will reset after
this call.


    Can't Stop, Got No Brakes.
    --------------------------
    After 10 seconds, the system will reboot, regardless of outstanding
    reset handlers.
Here is an example program that installs a reset handler and either waits
for the reboot or for the user to close the window. If there was a reboot,
the window will close and, if executed from the shell, it will display a
few messages. If the user closes the window, the handler is removed and
the program exits cleanly.


```c
     [Key_Reset.c](../Devices_Manual_guide/node019F.html) 
```
