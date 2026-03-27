# exec.library/SumLibrary



   NAME
	SumLibrary -- compute and check the checksum on a library

   SYNOPSIS
	SumLibrary(library)
		   A1

	void SumLibrary(struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *);

   FUNCTION
	SumLibrary computes a new checksum on a library.  It can also be
	used to check an old checksum.	If an old checksum does not match,
	and the library has not been marked as changed, then the system
	will call [Alert()](../Includes_and_Autodocs_3._guide/node01E3.html).

	This call could also be periodically made by some future
	system-checking task.

   INPUTS
	library - a pointer to the library to be changed

   NOTE
	An alert will occur if the checksum fails.

   SEE ALSO
	[SetFunction()](../Includes_and_Autodocs_3._guide/node0238.html)

