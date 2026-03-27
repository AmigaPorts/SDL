# Standard File Structure / Single Purpose Files


A single purpose IFF file is for normal "document" and "archive" storage.
This is in contrast with "scrap files" (see below) and temporary backing
storage (non-interchange files).

The external file type (or filename extension, depending on the host file
system) indicates the file's contents.  It's generally the [FORM](../Devices_Manual_guide/node01C7.html#line52) type of
the data contained, hence the restrictions on FORM type IDs.

Programmers and users may pick an "intended use" type as the filename
extension to make it easy to filter for the relevant files in a filename
requester.  This is actually a "subclass" or "subtype" that conveniently
separates files of the same [FORM](../Devices_Manual_guide/node01C7.html#line52) type that have different uses.  Programs
cannot demand conformity to its expected subtypes without overly
restricting data interchange since they cannot know about the subtypes to
be used by future programs that users will want to exchange data with.

Issue: How to generate 3-letter MS-DOS extensions from 4-letter [FORM](../Devices_Manual_guide/node01C7.html#line52) type
IDs?

Most single purpose files will be a single [FORM](../Devices_Manual_guide/node01C7.html#line52) (perhaps a composite FORM
like a musical score containing nested FORMs like musical instrument
descriptions). If it's a [LIST](../Devices_Manual_guide/node01CA.html#line49) or a [CAT](../Devices_Manual_guide/node01CA.html#line2) , programs should skip over
unrecognized objects to read the recognized ones or the first recognized
one.  Then a program that can read a single purpose file can read
something out of a "scrap file", too.

