# 27 / / Monitors, Modes and the Display Database / New Modes


In V1.3 and earlier versions of the OS, the mode for a display was
determined by a 16 bit-value specified either in the [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field
(for displays set up with the graphics library) or in the
[NewScreen.ViewModes](../Includes_and_Autodocs_2._guide/node00DD.html#line303) field (for displays set up with Intuition).  Prior to
Release 2, it was sufficient to indicate the mode of a display by setting
bits in the ViewPort.Modes field.  Furthermore, programs routinely made
interpretations about a given display mode based on bit-by-bit testing of
this 16-bit value.




```c
             Table 27-4: ViewPort Modes Used in 1.3


    Bit      Name    1.3 ViewPort Modes
    ---      ----    ------------------
    15       [HIRES](../Libraries_Manual_guide/node0327.html#line25)           RP
    14       [SPRITE](../Libraries_Manual_guide/node0327.html#line47)          DC
    13       VPHIDE          DC        R = respected by 1.3
    12       reserved        IP        I = ignored by 1.3
    11       [HAM](../Libraries_Manual_guide/node0327.html#line43)             RP        D = dynamic
    10       [DUALPF](../Libraries_Manual_guide/node0327.html#line14)          RP        C = cleared on write by 1.3
    9        reserved        IP            IFF writers
    8        GENAUD          IC        P = preserved on write by 1.3
    7        [EHB](../Libraries_Manual_guide/node0327.html#line54)             RP            IFF writers
    6        [PFBA](../Libraries_Manual_guide/node0327.html#line19) (PF2PRI)   RP
    5        reserved        IP
    4        reserved        IP
    3        reserved        IP
    2        [LACE](../Libraries_Manual_guide/node0327.html#line36)            RP
    1        GENVID          IC
    0        reserved        IP
```
Considering all the possible new mode combinations and the need for future
expansion, it is clear that the 16-bit mode specification used in 1.3
needs to be extended.  Also, the specification of a mode needs to be
separated from its interpretation.  Furthermore, since modes can be
grouped by the special monitor or physical device needed for the display,
it is also beneficial to make provisions to support additional monitors
and their modes in the future.

The approach taken in Release 2 is to introduce a new 32-bit display mode
specifier called a ModeID.  The upper half of this specifier is called the
monitor part and the lower half is informally called the mode part.  There
is a correspondence between the monitor part and the monitor's operating
modes (referred to as virtual monitors or [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26)s after a system data
structure).

For example, the A2024 monitor, PAL and NTSC are all different virtual
monitors--the actual, physical monitor may be able to support more than
one of these virtual types.  Another new concept in Release 2 is the
default monitor.  The default monitor, represented by a zero value for the
ModeID monitor part, may be either PAL or NTSC depending on a jumper on
the motherboard.

Compatibility considerations--especially for [IFF](../Libraries_Manual_guide/node0428.html) files and their CAMG
chunk--have dictated very careful choices for the bit values which make up
the mode part of the 32-bit ModeIDs.  For example, the ModeIDs
corresponding to the older, 1.3 display modes have been constructed out of
a zero in the monitor part and the old 16-bit [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) bits in the
lower part (after several extraneous bits such as [SPRITES](../Libraries_Manual_guide/node0327.html#line47) and VP_HIDE are
cleared).

There are other such coincidences, but steps for compatibility with old
programs notwithstanding, there is a new rule:


    Programmers shall never interpret ModeIDs on a bit-by-bit basis.
For example, if the [HIRES](../Libraries_Manual_guide/node0327.html#line25) bit is set it does not mean the display is 640
pixels wide because there can also be a doubling of the beam scan rate
under Release 2.   Programs should not attempt to interpret modes directly
from the [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field.  The Release 2 graphics library provides a
suitable substitute for this information through its new display database
facility (explained below).

Likewise, under Release 2, the Mode of a [ViewPort](../Libraries_Manual_guide/node032B.html#line59) is no longer set
directly.  Instead it is set indirectly by associating the ViewPort with
an abstract, 32-bit ModeID via the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) function.

These 32-bit ModeIDs have been carefully designed so that their lower 16
bits, when passed to graphics in the [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field, provide some
degree of compatibility between different systems.  Older V1.3 programs
will continue to work within the new scheme.  (They will, however, not
gain the benefits of the new modes and monitors available.)




```c
       Table 27-5: Extended ViewPort Modes Used in Release 2


    Bit      Name    Release 2 ViewPort Modes
    ---      ----    ------------------------
    15       MDBIT9             RP
    14       SPRITE             DC
    13       VPHIDE             DC           R = respected by Release
    12       [EXTEND](../Libraries_Manual_guide/node0327.html#line58)             RP           I = ignored by Release 2
    11       MDBIT8             RP           D = dynamic
    10       MDBIT7             RP           C = cleared on write by
    9        MDBIT6             RP               Release 2 IFF writers
    8        reserved           IC           P = preserved on write by
    7        MDBIT5             RP               Release 2 IFF writers
    6        PF2PRI             RP
    5        MDBIT4             RP
    4        MDBIT3             RP
    3        MDBIT2             RP
    2        MDBIT1             RP
    1        reserved           IC
    0        MDBIT0             RP
```
Refer to the example program, [WBClone.c](../Libraries_Manual_guide/node059B.html), at the end of this section for
examples on opening Release 2 [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s using the new ModeID specification.

