# 6 Input Device / Input Device and Intuition


There are several ways to receive information from the various devices
that are part of the input device. The first way is to communicate
directly with the device. This method is not recommended while the input
device task is running - which is most of the time. The second way is to
become a handler for the stream of events which the input device produces.
That method is shown above.

The third method of getting input from the input device is to retrieve the
data from the console device or from the IDCMP (Intuition Direct
Communications Message Port).   These are the preferred methods for
applications in a multitasking environment because each application can
receive juts its own input (i.e., only the input which occurs when one of
its window is active).  See the "[Intuition](../Libraries_Manual_guide/node0002.html)" chapters of Amiga ROM Kernel
Reference Manual: Libraries for more information on IDCMP messages. See
the [Console Device](../Devices_Manual_guide/node0080.html) chapter of this manual for more information on
console device I/O.

