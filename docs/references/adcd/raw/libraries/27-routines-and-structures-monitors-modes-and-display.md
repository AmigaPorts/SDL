# 27 / Routines and Structures / Monitors, Modes and Display Database


The Release 2 graphics library supports a variety of new video monitors,
and new programmable video modes not available in older versions of the
operating system.  Inquiries about the availability of these modes, their
dimensions and currently accessible options can be made through a database
indexed by the same key information used to open Intuition screens.  This
design provides a good degree of compatibility with existing software,
between differently equipped hardware platforms and for both static and
dynamic data storage.

The Release 2 software may be running on A1000 computers which will not
have ECS, on A500 computers which may not have the latest ECS upgrade, and
on A2000 computers which generally have the latest ECS but may not have a
multi-sync monitor currently attached.  This means that there are
compatibility issues to consider--what should happen when a required ECS
or monitor resource is not available for the desired mode.

Here are the compatibility criteria, in a simplified fashion:

Requires Release 2, and ECS Chips only

```c
    SuperHires mode (35nS pixel resolutions).  This allows for very high
    horizontal resolutions with the new ECS chip set and a standard NTSC
    or PAL monitor.  (SuperHires has twice as much horizontal resolution
    as the old Hires mode.)
```
Requires Release 2, ECS Chips, and appropriate monitor

```c
    Productivity mode.  This allows for flicker-free 640 x 480 color
    displays with the addition of a multi-sync or bi-sync 31 Khz monitor.
    (Productivity mode conforms, in a general way, to the VGA Mode 3
    Standard 8514/A.)
```
Requires Release 2 (or the V35 of graphics.library under 1.3)
and appropriate monitor only

```c
    A2024 Scan Conversion.  This allows for a very high resolution
    grayscale display, typically 1008x800, suitable for desktop
    publishing or similar applications.  A special video monitor is
    required (the monitor also supports the normal Amiga modes in
    greyscale).
```
Requires Release 2 but not ECS Chips or appropriate monitor

    Display database inquiries.  This allows for programmers to determine
    if the required resources are currently available for the requested
    mode.
In addition, there are fallback modes (which do not require Release 2)
which resort to some reasonable display when a required resource is not
available.

 [New Monitors](../Libraries_Manual_guide/node0336.html) 
 [New Modes](../Libraries_Manual_guide/node0337.html) 
 [Mode Specification, Screen Interface](../Libraries_Manual_guide/node0338.html) 
 [Mode Specification, ViewPort Interface](../Libraries_Manual_guide/node0339.html) 
 [Coexisting Modes](../Libraries_Manual_guide/node033A.html) 
 [ModeID Identifiers](../Libraries_Manual_guide/node033B.html) 
 [The Display Database and the DisplayInfo Record](../Libraries_Manual_guide/node033C.html) 
 [Accessing the DisplayInfo](../Libraries_Manual_guide/node033D.html) 
 [Mode Availability](../Libraries_Manual_guide/node033E.html) 
 [Accessing the MonitorSpec](../Libraries_Manual_guide/node033F.html) 
 [Mode Properties](../Libraries_Manual_guide/node0340.html) 
 [Nominal Values](../Libraries_Manual_guide/node0341.html) 
 [Preference Items](../Libraries_Manual_guide/node0342.html) 
 [Run-Time Name Binding of Mode Information](../Libraries_Manual_guide/node0343.html) 
 [Relase 2 Custom ViewPort Example](../Libraries_Manual_guide/node059B.html) 

