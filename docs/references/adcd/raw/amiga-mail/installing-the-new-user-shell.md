# Installing the New User Shell


After you have compiled your creation, you need to put its seglist on the
resident list under the name ``shell''.  Adding it to the resident list is
a simple:


    Resident shell <shell-file> SYSTEM
Now anything that calls the user shell (like NewShell, Execute(), and
System()) will call your shell.  Note that under 2.04, the Shell icon
actually runs sys:System/CLI, which calls the BootShell (the default
UserShell) and not the current UserShell.

If you need to restore the BootShell as the UserShell, compile and run the
program [RestoreShell.c](../AmigaMail_Vol2_guide/node017A.html) at the end of this article

