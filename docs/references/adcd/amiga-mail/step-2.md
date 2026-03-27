---
title: Step 2
manual: amiga-mail
chapter: amiga-mail
section: step-2
functions: []
libraries: []
---

# Step 2

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The otag file contains a tag list that describes the typeface.  All
of these tags are defined in <diskfont/diskfonttag.h> as either level
1, level 2, or level 3 outline tags.  Level 1 tags are required to be
present in an otag file.  Level 2 and 3 tags are optional.  See the
include file for more information on the tag levels.

The first tag of the otag file is always OT_FileIdent.  Its value is
the size of the otag file.  This tag is here to verify the validity
of the otag file.  If the first tag is not OT_FileIdent, or the
OT_FileIdent tag value is not the size of the otag file, the otag
file is invalid, so don't attempt to use it.  If the file is valid,
copy the entire file into a buffer.

The tags from the otag file have a special OT_Indirect bit.  If this
bit is set, the tag's value is an indirect reference to data defined
elsewhere in the otag file.  The tag's value is the offset to the
data (in bytes) from the beginning of the otag file.  For example,
the otag file fonts:CGTimes.otag that is on the 2.04 Release disks
contains the tag OT_Family (0x80009003), which has its OT_Indirect
bit set.  The value of the OT_Family tag is 195, meaning that the
data for it--the NULL terminated string ``CG Times''--is located 195
bytes into the otag file.

Of course, if an application read the file fonts:CGTimes.otag into a
memory buffer, the ``CG Times'' string would be 195 bytes from the
beginning of the buffer.  The OT_Family tag must point to the
absolute address of its data, so when an application loads an otag
file into memory, it has to resolve the indirection of the
OT_Indirect tags in memory.  The application can do this by adding
the buffer address to each OT_Indirect tag value.

