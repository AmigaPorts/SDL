# II-65: Writing a UserShell


by Randell Jesup


One of the features of Release 2.0 is that the OS allows the user to
change the system default shell, or the UserShell.  Any time the user
opens a shell with NewShell, executes a script, RUNs a command, or
indirectly calls System() with SYS_UserShell, the OS will call the
UserShell instead of the BootShell (by default the system sets up the
BootShell as the UserShell).

Creating UserShells is not easy, and requires doing a fairly large number
of things for no apparent reason (the reasons are there, they're just not
obvious to the outsider).  This article will attempt to give you the
information you need in order to create a usable, system-friendly
UserShell.

 [Initialization](../AmigaMail_Vol2_guide/node0072.html) 
 [A Word About the Shell's I/O Handles](../AmigaMail_Vol2_guide/node0073.html) 
 [The Main Shell Loop](../AmigaMail_Vol2_guide/node0074.html) 
 [Finding a Program](../AmigaMail_Vol2_guide/node0075.html) 
 [Running a Program](../AmigaMail_Vol2_guide/node0076.html) 
 [Cleanup](../AmigaMail_Vol2_guide/node0077.html) 
 [Installing the New User Shell](../AmigaMail_Vol2_guide/node0078.html) 
 [Credits](../AmigaMail_Vol2_guide/node0079.html) 

 [myshell.c](../AmigaMail_Vol2_guide/node0179.html) 

