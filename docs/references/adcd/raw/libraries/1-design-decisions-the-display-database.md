# 1 / / Design Decisions / The Display Database


The [Release 2](../Libraries_Manual_guide/node0015.html) graphics library and the Enhanced Chip Set ([ECS](../Libraries_Manual_guide/node0017.html)) provide
programmable [display modes](../Libraries_Manual_guide/node0319.html) and enhanced [genlock](../Libraries_Manual_guide/node036C.html) capabilities.  Users with
Release 2 and ECS may wish to use your application in one of the newer
display modes.  The Release 2 display database provides information on all
of the display modes available with the user's machine and monitor.  In
addition, it provides useful information on the capabilities and aspect
ratio of each mode (DisplayInfo.Resolution.x and .y).  A new function
named [ModeNotAvailable()](../Libraries_Manual_guide/node033E.html#line5) allows you to easily check if particular modes
are available.

The [ExtNewScreen](../Libraries_Manual_guide/node00E2.html) structure used with Intuition's [OpenScreen()](../Libraries_Manual_guide/node00DF.html) function
allows you to specify new display modes with the [SA_DisplayID](../Libraries_Manual_guide/node00E5.html#line74) tag and a
longword ModeID.  The Release 2 graphics library [VideoControl()](../Libraries_Manual_guide/node036D.html) function
provides greatly enhanced [genlock](../Libraries_Manual_guide/node036C.html) capabilities for machines with [ECS](../Libraries_Manual_guide/node0017.html) and a
genlock.  Little conditional code is required to support these features.
See the [graphics library](../Libraries_Manual_guide/node0004.html) chapters and [Autodocs](../Includes_and_Autodocs_2._guide/node000E.html) for more information.

