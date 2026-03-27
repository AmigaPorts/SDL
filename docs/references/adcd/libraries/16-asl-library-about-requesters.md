---
title: 16 ASL Library / About Requesters
manual: libraries
chapter: libraries
section: 16-asl-library-about-requesters
functions: []
libraries: []
---

# 16 ASL Library / About Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Requesters are temporary sub-windows used for confirming actions or
selecting options.  The most common type of requester is a file requester
which is used to pick a file name for a load or save operation.

Under 1.3 (V34) and earlier versions of the Amiga operating system there
was limited support for requesters.  Intuition provides simple requesters
which can be used to request responses such as OK or Cancel from the user.
More elaborate Intuition requesters can be created by adding additional
features such as string gadgets, however the result of this is that each
application writer develops their own style of requester.  Hence, the
asl.library has been added to Release 2 of the Amiga operating system to
make requesters more consistent.  With asl.library, requesters are also
much easier to create and take less memory.


    The ASL Library Requires Release 2.
    -----------------------------------
    The asl.library requires Release 2 of the Amiga operating system, so
    only applications running under Release 2 and later versions of the
    Amiga OS can call its functions.
Requesters are very flexible and can be used for many different purposes.
The Release 2 asl.library supports the two most common type of requesters:

  * File requesters for choosing a file name in a load or save operation

  * Font requesters for choosing a font in a text operation

