---
title: datatypes.library/--background--
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-background
functions: []
libraries: []
---

# datatypes.library/--background--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   PURPOSE
	The datatypes.library provides transparent data handling
	abilities to applications.  Application developers can register
	their data format with datatypes.library and provide a class
	library for handling their data within other applications.

   OVERVIEW

	* [Object](autodocs-3.5/include-intuition-classusr-h.md) Oriented

	datatypes.library implementation is object oriented, using the
	boopsi functions of Intuition.  Each data class is implemented
	as a shared system library.

	* Embedded Objects

	datatypes.library provides the ability to embed different object
	types within an application.  For example, an application can
	embed an picture object or even an AmigaGuide document browser
	within their application's window.  Objects can also be embedded
	within other objects.

	* Gadget-like

	Embedded objects are actually boopsi gadgets.  That means that
	input handling is done on Intuition's task.  Time intensive
	operations, such as layout when the window size changes, are
	off-loaded to a sub-process.  Printing, clipboard operations,
	file read/write are also off-loaded to a separate process on an
	as-needed basis.

	* Trigger Methods

	Sometimes it is necessary for an application to provide
	additional controls for navigating through an object.  For
	example, with an AmigaGuide object it is necessary to have
	controls for "Contents", "Index", "Browse >", "Browse <".  Each
	class implements a method that returns the trigger methods, and
	the appropriate labels, that a class supports.

	* [Format](autodocs-3.5/dos-library-format-2.md) Conversion

	As long as the objects are sub-classes of the same class, data
	from one format can be written out as another format.  For
	example, it is possible to read in an ILBM file and write out a
	JPEG file, since both data types are sub-classes of PICTURE.

	* Future Compatible

	Each class implements a method that returns the supported
	methods within a class.  This way an application can ask an
	object if it is capable of any particular method, such as
	DTM_WRITE for example.

	* Data Type Detection

	datatypes.library provides the ability to examine a file or
	the clipboard to determine what type of data it contains.

