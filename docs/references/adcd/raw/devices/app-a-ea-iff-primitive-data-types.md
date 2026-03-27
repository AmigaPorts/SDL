# App.A EA IFF/ Primitive Data Types


Atomic components such as integers and characters that are interpretable
directly by the CPU are specified in one format for all processors.  We
chose a format that's the same as used by the Motorola MC68000 processor
[M68000 16/32-Bit Microprocessor Programmer's Reference Manual].  The high
byte and high word of a number are stored first.

N.B.: Part 3 dictates the format for "primitive" data types where-and
only where-used in the overall file structure.  The number of such
occurrences of dictated formats will be small enough that the costs of
conversion, storage, and management of processor-specific files would far
exceed the costs of conversion during I/O by "foreign" programs.  A
particular data chunk may be specified with a different format for its
internal primitive types or with processor or environment specific
variants if necessary to optimize local usage.  Since that hurts data
interchange, it's not recommended.  (Cf. Designing New Data Sections, in
Part 4.)

 [Alignment](../Devices_Manual_guide/node01D8.html)   [Characters](../Devices_Manual_guide/node01DA.html)   [Type IDs](../Devices_Manual_guide/node01DC.html)   [Strings](../Devices_Manual_guide/node01DE.html)           [Links](../Devices_Manual_guide/node01E0.html) 
 [Numbers](../Devices_Manual_guide/node01D9.html)     [Dates](../Devices_Manual_guide/node01DB.html)        [Chunks](../Devices_Manual_guide/node01DD.html)     [Data Properties](../Devices_Manual_guide/node01DF.html)   [File References](../Devices_Manual_guide/node01E1.html) 

