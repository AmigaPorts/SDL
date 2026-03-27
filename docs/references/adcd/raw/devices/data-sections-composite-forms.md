# Data Sections / Composite FORMs


A [FORM](../Devices_Manual_guide/node01C7.html#line52) [chunk](../Devices_Manual_guide/node01DD.html) inside a FORM is a full-fledged data section.  This means you
can build a composite object such as a multi-frame animation sequence by
nesting available picture FORMs and sound effect FORMs.  You can insert
additional [chunk](../Devices_Manual_guide/node01DD.html)s with information like frame rate and frame count.

Using composite [FORM](../Devices_Manual_guide/node01C7.html#line52)s, you leverage on existing programs that create and
edit the component FORMs.  Those editors may even look into your composite
object to copy out its type of component.  Such editors are not allowed to
replace their component objects within your composite object.  That's
because the IFF standard lets you specify consistency requirements for the
composite FORM such as maintaining a count or a directory of the
components.  Only programs that are written to uphold the rules of your
FORM type may create or modify such FORMs.

Therefore, in designing a program that creates composite objects, you are
strongly requested to provide a facility for your users to import and
export the nested [FORM](../Devices_Manual_guide/node01C7.html#line52)s.  Import and export could move the data through a
clipboard or a file.

Here are several existing [FORM](../Devices_Manual_guide/node01C7.html#line52) types and rules for defining new ones:

 [FTXT](../Devices_Manual_guide/node01E5.html)      [ILBM](../Devices_Manual_guide/node01E6.html)      [PICs](../Devices_Manual_guide/node01E7.html)      [Other Macintosh Resource Types](../Devices_Manual_guide/node01E8.html) 

