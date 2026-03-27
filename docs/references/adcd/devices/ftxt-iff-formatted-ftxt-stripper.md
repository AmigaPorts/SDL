---
title: FTXT IFF Formatted / FTXT Stripper
manual: devices
chapter: devices
section: ftxt-iff-formatted-ftxt-stripper
functions: []
libraries: []
---

# FTXT IFF Formatted / FTXT Stripper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An FTXT reader program can read the text and ignore all formatting and
structural information in a document [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) that uses [FORMs FTXT](devices/ftxt-iff-formatted-text-introduction.md) for the
leaf nodes.  This amounts to stripping a document down to a stream of
plain text. It would do this by skipping over all chunks except FTXT.[CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md)
(CHRS chunks found inside a [FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md)) and within the FTXT.CHRS chunks
skipping all control characters and control sequences.  ([Appendix C](devices/ftxt-iff-formatted-appendix-c-iso-ansi-control-sequences.md)
diagrams this text scanner.) It may also read FTXT.[FONS](devices/standard-data-and-property-chunks-property-chunk-fons.md) chunks to find a
description for font 1.

Here's a Pascal-ish program for an [FTXT](devices/ftxt-iff-formatted-text-introduction.md) stripper.  Given a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) (a
document of some kind), it scans for all FTXT.[CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md) chunks.  This would
likely be applied to the first FORM in an IFF file.

  PROCEDURE ReadFORM4CHRS();    {Read an IFF FORM for FTXT.CHRS chunks.}

```c
    BEGIN
    IF the FORM's subtype = "FTXT"
        THEN ReadFTXT4CHRS()
    ELSE WHILE something left to read in the FORM
       DO BEGIN
          read the next chunk header;
          CASE the chunk's ID OF
               "LIST", "CAT ": ReadCAT4CHRS();
               "FORM": ReadFORM4CHRS();
                OTHERWISE skip the chunk's body;
          END
       END
    END;
```
  {Read a LIST or CAT for all FTXT.CHRS chunks.}
  PROCEDURE ReadCAT4CHRS();

```c
    BEGIN
    WHILE something left to read in the LIST or CAT
    DO BEGIN
       read the next chunk header;
       CASE the chunk's ID OF
             "LIST", "CAT ": ReadCAT4CHRS();
             "FORM": ReadFORM4CHRS();
             "PROP": IF we're reading a LIST AND the PROP's subtype = "FTXT"
                    THEN read the PROP for "FONS" chunks;
             OTHERWISE error--malformed IFF file;
          END
       END
    END;
```
  PROCEDURE ReadFTXT4CHRS();    {Read a FORM FTXT for CHRS chunks.}



```c
    BEGIN
    WHILE something left to read in the FORM FTXT
    DO BEGIN
       read the next chunk header;
       CASE the chunk's ID OF
          "CHRS": ReadCHRS();
          "FONS": BEGIN
                   read the chunk's contents into a FontSpecifier variable;
                   IF the font specifier's id = 1
                   THEN use this font;
                  END;
            OTHERWISE skip the chunk's body;
        END
      END
    END;
```
  {Read an FTXT.CHRS. Skip all control sequences and unused control chars.}
  PROCEDURE ReadCHRS();


```c
    BEGIN
    WHILE something left to read in the CHRS chunk
    DO
       CASE read the next character OF
          LF:  start a new output line;
          ESC: SkipControl([' '..'/'], ['0'..'~']);
          IN [' '..'~'], IN [NBSP..'ÿ']: output the character;
          SS2, SS3: ; {Just handle the following G0 character directly,
                      ignoring the shift to G2 or G3.}
          CSI: SkipControl([' '..'?'], ['@'..'~']);
            DCS, OSC, PM, APC: SkipControl([' '..'~'] + [NBSP..'ÿ'], [ST]);
       END
    END;
```
  {Skip a control sequence of the format (rSet)* (tSet), i.e., any number of
  characters in the set rSet followed by a character in the set tSet.}
  PROCEDURE SkipControl(rSet, tSet);
  VAR c: CHAR;


```c
    BEGIN
       REPEAT c := read the next character
       UNTIL c NOT IN rSet;

       IF c NOT IN tSet
          THEN put character c back into the input stream;
    END
```
The following program is an optimized version of the above routines
ReadFORM4CHRS and ReadCAT4CHRS for the case where you're ignoring fonts as
well as formatting.  It takes advantage of certain facts of the IFF format
to read a document [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) and its nested FORMs, [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s, and [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s without a
stack. In other words, it's a hack that ignores all fonts and faces to
cheaply get to the plain text of the document.


  {Cheap scan of an IFF FORM for FTXT.CHRS chunks.}
  PROCEDURE ScanFORM4CHRS();
```c
    BEGIN
    IF the document FORM's subtype = "FTXT"
        THEN ReadFTXT4CHRS()
    ELSE WHILE something left to read in the FORM
         DO BEGIN
            read the next chunk header;
```
	    IF it's a group chunk (LIST, FORM, PROP, or CAT)
		THEN read its subtype ID;
	    CASE the chunk's ID OF
		"LIST", "CAT ":;	{NOTE: See explanation below.*}
		"FORM": IF this FORM's subtype = "FTXT"
			    THEN ReadFTXT4CHRS()
			ELSE;	{NOTE: See explanation below.*}
		OTHERWISE skip the chunk's body;
	    END
	END

```c
    END;
```
*Note: This implementation is subtle.  After reading a group header other
than [FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md) it just continues reading.  This amounts to reading all the
chunks inside that group as if they weren't nested in a group.

