---
title: datatypes.library/--rexxhost--
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-rexxhost
functions: []
libraries: []
---

# datatypes.library/--rexxhost--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   HOST INTERFACE
	datatypes.library provides an ARexx function host interface that
	enables ARexx programs to take advantage of the features of data
	types.  The functions provided by the interface are directly
	related to the functions described herein, with the differences
	mostly being in the way they are called.

	The function host library vector is located at offset -30 from
	the library. This is the value you provide to ARexx in the
	AddLib() function call.

   FUNCTIONS
	ExamineDT(FILENAME/A,VARIABLENAME,STEM/S,VAR/S)

   EXAMPLE
	/* datatypes.rexx */
	PARSE ARG fname
	OPTIONS RESULTS

	/* Load the datatypes.library as a function host */
	IF ~SHOW('L','datatypes.library') THEN
	   CALL ADDLIB('datatypes.library',0,-30)

	   IF fname="" THEN DO
	      SAY "Usage:"
	      SAY "  rx datatypes <filename>"
	      EXIT
	   END

	   SAY 'var test'
	   type = ExamineDT(fname,,VAR)
	   SAY type

	   SAY 'stem test'
	   CALL ExamineDT(fname,dtstem.,STEM)

	   SAY '      Disk Key:' dtstem.DiskKey
	   SAY 'Dir Entry Type:' dtstem.DirEntryType
	   SAY '     File Name:' dtstem.FileName
	   SAY '    Protection:' dtstem.Protection
	   SAY '    Entry Type:' dtstem.EntryType
	   SAY '          Size:' dtstem.Size
	   SAY '        Blocks:' dtstem.NumBlocks
	   SAY '          Date:' dtstem.Date
	   SAY '       Comment:' dtstem.Comment
	   SAY '          Type:' dtstem.BaseType
	   SAY '     File Type:' dtstem.DataType
	   SAY '     Base Name:' dtstem.BaseName
	EXIT

