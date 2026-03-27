# I-43: Callback Hooks


by David Junod


The callback features of Release 2 provide a standard means for
applications to extend the functionality of libraries, devices, and
their applications.  This standard makes it easy for the operating
system to use custom modules from different high level programming
languages as part of the operating system.  For example, the layers
library, which takes care of treating a display as a series of layered
regions, allows an application to attach a pattern function to a
display layer.  Instead of filling in the background of a layer with
the background color, the layers library calls the custom pattern
function which fills in the layer display with a custom background
pattern.

 [Callback Hook Functions and Structures](../AmigaMail_Vol2_guide/node0051.html) 
 [Simple Callback Hook Usage](../AmigaMail_Vol2_guide/node0052.html) 

