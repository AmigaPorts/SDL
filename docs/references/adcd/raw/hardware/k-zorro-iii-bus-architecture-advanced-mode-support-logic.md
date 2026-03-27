# K / Zorro III Bus Architecture / Advanced Mode Support Logic


The Zorro III bus provides support for some more advanced operations that
weren't generally handled correctly on the Zorro II bus.  Amiga computers
have traditionally been supporting features that the more mainstream
personal computers haven't.  High speed DMA transfers and expansion
coprocessors such as the Bridge Cards have been with the Amiga since the
early days, and high performance main system CPUs with cache memory are
now becoming common.  The Zorro II bus never properly or easily supported
such devices; the Zorro III bus attempts to make support of cache and
coprocessor both possible and relatively straightforward.  Other new
features are covered in later sections.

 [Bus Locking](../Hardware_Manual_guide/node02A8.html)      [Cache Support](../Hardware_Manual_guide/node02A9.html) 

