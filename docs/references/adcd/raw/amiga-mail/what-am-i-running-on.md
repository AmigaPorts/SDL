# What Am I Running On?


It is possible for applications to detect if they are running on an
A570 or on a CDTV player.  There is an A570-specific module called
"A690ID".  A title can test to see if this module is present using the
exec.library function FindResident().  If the "A690ID" module is
present, the title is running on an A570-equipped A500.

