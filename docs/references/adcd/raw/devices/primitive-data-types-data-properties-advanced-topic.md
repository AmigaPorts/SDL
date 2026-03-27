# Primitive Data Types / Data Properties (advanced topic)


Data properties specify attributes for following (non-property) [chunk](../Devices_Manual_guide/node01DD.html).  A
data property essentially says "identifier = value", for example "XY =
(10, 200)", telling something about following chunks.  Properties may only
appear inside data sections ("[FORM](../Devices_Manual_guide/node01C7.html#line52)" chunks, cf. Data Sections) and
property sections ("[PROP](../Devices_Manual_guide/node01CA.html#line49)" chunks, cf. Group PROP).

The form of a data property is a type of [Chunk](../Devices_Manual_guide/node01C7.html).  The ckID is a property
name as well as a property type.  The ckSize should be small since data
properties are intended to be accumulated in RAM when reading a file.
(256 bytes is a reasonable upper bound.)  Syntactically:

	Property	::= Chunk

When designing a data object, use properties to describe context
information like the size of an image, even if they don't vary in your
program.  Other programs will need this information.

Think of property settings as assignments to variables in a programming
language.  Multiple assignments are redundant and local assignments
temporarily override global assignments.  The order of assignments doesn't
matter as long as they precede the affected [chunk](../Devices_Manual_guide/node01DD.html).  (Cf. [LIST](../Devices_Manual_guide/node01CA.html#line49)s, CATs, and
Shared Properties.)

Each object type ([FORM](../Devices_Manual_guide/node01C7.html#line52) type) is a local name space for property IDs.
Think of a "[CMAP](../Devices_Manual_guide/node01B0.html)" property in a "FORM [ILBM](../Devices_Manual_guide/node01AC.html)" as the qualified ID
"ILBM.[CMAP](../Devices_Manual_guide/node01B0.html)".  A "CMAP" inside some other type of [FORM](../Devices_Manual_guide/node01C7.html#line52) may not have the
same meaning.  Property IDs specified when an object type is designed (and
therefore known to all clients) are called "standard" while specialized
ones added later are "nonstandard".

