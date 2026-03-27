# 18 / What is a Library? / Relationship of Libraries to Devices


A device is a software specification for hardware control based on the
[Library](../Libraries_Manual_guide/node0292.html) structure.  The structures of libraries and devices are so similar
that the routine [MakeLibrary()](../Libraries_Manual_guide/node0297.html) is used to construct both.

Devices require the same initial four code vectors as a library, but must
have two additional code vectors for beginning and terminating special
device I/O commands. The I/O commands that devices are expected to
perform, at minimum, are shown in the "[Exec Device I/O](../Libraries_Manual_guide/node029F.html)" chapter.  An
[example device](../Devices_Manual_guide/node0159.html) is listed in the Amiga ROM Kernel Reference Manual: Devices.

