# printer.device/--background--



The printer.device gots a lot of new features with V44:

	- It is now possible to print hi- and true-color bitmaps
	- Planar bitmaps are read faster
	- Much more stable if wrong parameters for [PRD_DUMPRPORT](../Includes_and_Autodocs_3._guide/node050C.html) are used
	- A lot of new features for printer drivers are supported.

	Creating a driver for printer.device now gets much easier: the driver
	does not have to scale the bitmap anymore and can use its own
	algorithms for nearly everything (color conversion, color correction,
	all dither methods, anti aliasing). The driver is now run in a
	DOS process instead of a exec task so loading preferences or saving
	the output to a file is not longer a multithreading task.

	The driver gives more information for the preferences user interface
	(names of dither algorithms, names of shading algorithms, information
	about density interpretation) and for the printing itself (left and
	top border on paper, more page formats).

	Drivers can have its own preferences which can be edited and
	stored from every application. Driver can also have its own
	preferences editor (like PrinterPS).

