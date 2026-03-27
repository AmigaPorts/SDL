# 27 / Introduction / Role of the Copper (Coprocessor)


The Amiga has a special-purpose coprocessor, called the Copper, that can
control nearly the entire graphics system.  The Copper can control
register updates, reposition sprites, change the color palette, and update
the blitter.  The graphics and animation routines use the Copper to set up
lists of instructions for handling displays, and advanced programmers can
create their own custom Copper lists.

