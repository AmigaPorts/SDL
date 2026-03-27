# Standard File Structure / Scrap Files (not currently used)


A "scrap file" is for maximum interconnectivity in getting data between
programs; the core of a clipboard function.  Scrap files may have type
"IFF " or filename extension ".IFF".

A scrap file is typically a [CAT](../Devices_Manual_guide/node01CA.html#line2)  containing alternate representations of
the same basic information.  Include as many alternatives as you can
readily generate.  This redundancy improves interconnectivity in
situations where we can't make all programs read and write super-general
formats.  [Inside Macintosh chapter "Scrap Manager".]  E.g., a
graphically-annotated musical score might be supplemented by a stripped
down 4-voice melody and by a text (the lyrics).

The originating program should write the alternate representations in
order of "preference": most preferred (most comprehensive) type to least
preferred (least comprehensive) type.  A receiving program should either
use the first appearing type that it understands or search for its own
"preferred" type.

A scrap file should have at most one alternative of any type.  (A [LIST](../Devices_Manual_guide/node01CA.html#line49) of
same type objects is OK as one of the alternatives.)  But don't count on
this when reading; ignore extra sections of a type.  Then a program that
reads scrap files can read something out of single purpose files.

