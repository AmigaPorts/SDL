---
title: AIFF.doc / AIFF / Storage of AIFF on Apple and Other Platforms
manual: devices
chapter: devices
section: aiff-doc-aiff-storage-of-aiff-on-apple-and-other-platforms
functions: []
libraries: []
---

# AIFF.doc / AIFF / Storage of AIFF on Apple and Other Platforms

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On a Macintosh, the FORM AIFF, is stored in the data fork of an Audio IFF
file. The Macintosh file type of an Audio IFF file is 'AIFF'.  This is the
same as the formType of the FORM AIFF.  Macintosh applications should not
store any information in Audio IFF file's resource fork, as this
information may not be preserved by all applications.  Applications can
use the Application Specific Chunk, defined later in this document, to
store extra information specific to their application.

Audio IFF files may be identified in other Apple file systems as well.  On
a Macintosh under MFS or HFS, the FORM AIFF is stored in the data fork of
a file with file type 'AIFF'.  This is the same as the formType of the
FORM AIFF.

On an operating system such as MS-DOS or UNIX, where it is customary to
use a file name extension, it is recommended that Audio IFF file names use
'.AIF' for the extension.

On an Apple II, FORM AIFF is stored in a file with file type $D8 and
auxiliary type $0000.  Versions 1.2 and earlier of the Audio IFF standard
used file type $CB and auxiliary type $0000.  This is incorrect; the
assignment listed in this document is the correct assignment.

On the Apple IIGS stereo data is stored with right data on even channels
and left data on odd channels.  Some portions of AIFF do not follow this
convention.  Even where it does follow the convention, AIFF usually uses
channel two for right data instead of channel zero as most Apple IIGS
standards do.  Be prepared to interpret data accordingly.

