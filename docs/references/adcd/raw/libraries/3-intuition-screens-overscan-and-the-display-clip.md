# 3 Intuition Screens / Overscan and the Display Clip


Screens may be larger or smaller than the defined display area (overscan
rectangle or display clip).  When a screen is smaller than the display
area, the display clip acts as a "container" for the screen.  The screen
may be moved anywhere within the display clip.  When a screen is larger
than the display area, the display clip acts as a "window" into the
screen.  The screen may be moved so that different parts are visible.
Each dimension of the screen is independent and may be larger than, the
same as, or smaller than the dimensions of the display clip.

The system is very flexible in its specification of screen size.  Unless
an application fixes its screen size with hard coded values, it should be
prepared to handle the possibility that the user has changed the default
overscan presets or the default monitor (NTSC/PAL).

Use the constants STDSCREENHEIGHT and STDSCREENWIDTH with the [SA_Width](../Libraries_Manual_guide/node00E5.html#line54) and
[SA_Height](../Libraries_Manual_guide/node00E5.html#line54) tags to open a screen the same size as the display clip.  These
constants will work with any of the preset overscan values set with
[SA_Overscan](../Libraries_Manual_guide/node00E5.html#line247), and with custom overscan values set with [SA_DClip](../Libraries_Manual_guide/node00E5.html#line257).

 [Preset Overscan Values](../Libraries_Manual_guide/node00F0.html) 

