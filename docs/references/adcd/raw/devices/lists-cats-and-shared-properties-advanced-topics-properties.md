# LISTs, CATs and Shared Properties (Advanced topics) / Properties for LIST


Optional "properties for [LIST](../Devices_Manual_guide/node01CA.html#line49)" store the origin of the list's contents in
a PROP [chunk](../Devices_Manual_guide/node01DD.html) for the pseudo [FORM](../Devices_Manual_guide/node01C7.html#line52) type "LIST".  They are the properties
originating program "OPGM", processor family "OCPU", computer type "OCMP",
computer serial number or network address "OSN ", and user name "UNAM". In
our imperfect world, these could be called upon to distinguish between
unintended variations of a data format or to work around bugs in
particular originating/receiving program pairs.  Issue: Specify the format
of these properties.

A creation date could also be stored in a property, but let's ask that
file creating, editing, and transporting programs maintain the correct
date in the local file system.  Programs that move files between machine
types are expected to copy across the creation dates.

