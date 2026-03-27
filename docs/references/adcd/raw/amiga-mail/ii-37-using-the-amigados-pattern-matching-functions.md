# II-37: Using the AmigaDOS Pattern Matching Functions


by Ewout Walraven


One of the additions made to dos.library for release 2.0 is a series of
functions to do standard pattern matching.  Using a set of standard string
matching tokens, any application can use these functions to test if a
particular string matches a pattern.  The Amiga OS uses these functions
for processing file name strings for its new directory scanning functions.

These functions can be used in every circumstance where you would like to
enable the user to enter a pattern to indicate more than one target
string.  Using these functions not only makes it unnecessary to implement
your own pattern matching routines, but by using the familiar DOS pattern
tokens in your application, it is easier for the user to learn how to use
your application.

 [Patterns](../AmigaMail_Vol2_guide/node0069.html)      [Parsing](../AmigaMail_Vol2_guide/node006A.html)      [Matching](../AmigaMail_Vol2_guide/node006B.html) 

