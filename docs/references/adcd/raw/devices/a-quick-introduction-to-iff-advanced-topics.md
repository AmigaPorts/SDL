# A Quick Introduction to IFF/ Advanced Topics


CAT, LIST, and PROP

Sometimes you want to put several "files" into one, such as a picture
library. This is what CAT is for.  It "concatenates" FORM and LIST chunks.


          +--------------------+
          |                    |
          |   "CAT "           |  concatenation
          |                    |
          +--------------------+
          |   48160            |  48160 data bytes
          +--------------------+
          |                    |
          |   "ILBM"           |  This concatenation contains FORMs ILBM
          |                    |
          |  +--------------+  |
          |  |  "FORM"      |  |  A FORM ILBM
          |  |--------------|  |
          |  |   24070      |  |
          |  |--------------|  |
          |  |  "ILBM"      |  |
          |  |--------------|  |
          |  |  ....        |  |
          |  +--------------+  |
          |                    |
          |  +--------------+  |
          |  |  "FORM"      |  |  Another FORM ILBM
          |  |--------------|  |
          |  |   24070      |  |
          |  |--------------|  |
          |  |  "ILBM"      |  |
          |  |--------------|  |
          |  |  ....        |  |
          |  +--------------+  |
          |                    |
          +--------------------+
This example CAT holds two ILBMs. It can be shown outline-style:

  CAT ILBM
  ..FORM ILBM   \
  ....BMHD      | a complete FORM ILBM picture
  ....CMAP      |
  ....BODY      /
  ..FORM ILBM
  ....BMHD
  ....CMAP
  ....BODY

Sometimes you want to share the same color map across many pictures. LIST
and PROP do this:

  LIST ILBM
  ..PROP ILBM   default properties for FORMs ILBM
  ....CMAP      an ILBM CMAP chunk (there could be a BMHD chunk here, too)
  ..FORM ILBM
  ....BMHD      (there could be a CMAP here to override the default)
  ....BODY
  ..FORM ILBM
  ....BMHD      (there could be a CMAP here to override the default)
	....BODY

A LIST holds PROPs and [FORM](../Devices_Manual_guide/node01C7.html#line52)s (and occasionally LISTs and CATs).  A PROP
[ILBM](../Devices_Manual_guide/node01AC.html) contains default data (in the above example, just one [CMAP](../Devices_Manual_guide/node01B0.html) chunk) for
all FORMs ILBM in the LIST.  Any FORM may override the PROP-defined
default with its own [CMAP](../Devices_Manual_guide/node01B0.html).  All PROPs must appear at the beginning of a
LIST.  Each FORM type standardizes (among other things) which of its
chunks are "property chunks" (may appear in PROPs) and which are "data
chunks" (may not appear in PROPs).

