# exec.library/InitCode



   NAME
	InitCode - initialize resident code modules (internal function)

   SYNOPSIS
	InitCode(startClass, version)
		 D0          D1

	void InitCode(ULONG,ULONG);

   FUNCTION
	(This function may be ignored by application programmers)

	Call [InitResident()](../Includes_and_Autodocs_3._guide/node0216.html) for all resident modules in the ResModules array
	with the given startClass and with versions equal or greater than
	that specified.  The segList parameter is passed as zero.

	[Resident](../Includes_and_Autodocs_3._guide/node0643.html#line17) modules are used by the system to pull all its parts
	together at startup.  Modules are initialized in a prioritized order.

	Modules that do not have a startclass should be of priority -120.
	RTF_AFTERDOS modules should start at -100 (working down).

   INPUTS
	startClass - the class of code to be initialized:
		BITDEF RT,COLDSTART,0
		BITDEF RT,SINGLETASK,1	;ExecBase->ThisTask==0 (V36 only)
		BITDEF RT,AFTERDOS,2	;(V36 only)
	version - a major version number

    SEE ALSO
	ResidentTag (RT) structure definition (resident.h)

