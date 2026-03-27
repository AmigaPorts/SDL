/* Source: ADCD 2.1
 * Section: intuition-library-queryoverscan
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-queryoverscan.md
 */

    DisplayID -- A 32-bit identifier for a display mode, as
      defined in [graphics/displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html).

      NOTE: If you only intend to use one of the four standard
      overscan dimensions as is, and open your screen to exactly
      the DisplayClip dimensions, you can specify one of
      the OSCAN_ values in the [ExtNewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line345) tag SA_StdDClip,
      and specify STDSCREENWIDTH and STDSCREENHEIGHT as the
      dimensions to more easily open up an overscanned screen
      (or use no [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) in [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html) and accept
      the default standard screen dimensions).

    Rect -- pointer to a [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) structure which this function
      will fill out with its return values.  Note that to convert
      a rectangle to a screen "Height" you do (MaxY - MinY + 1), and
      similarly for "Width."  The rectangle may be passed directly
      to [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html) as a DisplayClip region (SA_DClip).
