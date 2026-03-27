# Additional Info / How Amiga HALFBRITE mode works


This one is simpler.  In HALFBRITE mode, the Amiga interprets the bit in
the last plane as HALFBRITE modification.  The bits in the other planes
are treated as normal color register numbers (RGB values for each color
register is specified in the CMAP chunk).  If the bit in the last plane is
set (1), then that pixel is displayed at half brightness.  This can
provide up to 64 absolute colors.

