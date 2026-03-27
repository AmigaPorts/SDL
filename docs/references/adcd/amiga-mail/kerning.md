---
title: Kerning
manual: amiga-mail
chapter: amiga-mail
section: kerning
functions: []
libraries: []
---

# Kerning

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IntelliFont scaling engine also supports two types of kerning.
One type of kerning is called text kerning, which is for regular
bodies of text.  The other type of kerning is called design kerning,
which is for more obvious displays, like headlines.  The basic
difference is that design kerning is generally more tightly spaced
than text kerning.

Before asking for a kerning pair, an application has to tell the
engine which character pair to kern.  It does this using one of the
SetInfo() functions to set the primary glyph, OT_GlyphCode, and the
secondary glyph code, OT_GlyphCode2.

To ask the scaling engine for a kerning value, use one of the
ObtainInfo() functions with the OT_TextKernPair (for text kerning) or
OT_DesignKernPair (for design kerning) tags.  The engine expects the
value of the kerning tag to be an address where it can store a four
byte long kerning value.  The kerning value is a fixed point binary
fraction of an em square (like the glm_Width field from the GlyphMap
structure).  This value is the distance to remove from the primary
character advance (the glm_Width of OT_GlyphCode) when rendering the
secondary glyph (OT_GlyphCode2) immediately following the primary
glyph.

Unlike other ObtainInfo() tags, the scaling engine does not allocate
any resources when answering queries about kerning values.
Applications do not have to use ReleaseInfo() functions for kerning
queries made with either OT_TextKernPair or OT_DesignKernPair.

