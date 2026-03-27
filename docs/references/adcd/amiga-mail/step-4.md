---
title: Step 4
manual: amiga-mail
chapter: amiga-mail
section: step-4
functions: []
libraries: []
---

# Step 4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Setting a scaling engine's current typeface involves the SetInfoA()
(or SetInfo()) function and the Level 0 tags from
<diskfont/diskfonttag.h>.  The SetInfoA() function takes two
parameters, a pointer to the GlyphEngine structure, and a tag list of
level 0 outline tags.  The Level 0 tags act as commands for a scaling
engine, some of which are for setting scaling engine parameters (with
SetInfo() or SetInfoA()), and some of which are for querying
information from a scaling engine (with ObtainInfo() or
ObtainInfoA()).

Two tags set a scaling engine's current typeface: OT_OTagPath and
OT_TagList.  The OT_OTagPath tag points to the full path name of a
typeface's otag file (for example, fonts:CGTimes.otag).  The
OT_OTagList tag points to the tag list created in step 2 above.

