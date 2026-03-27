# amiga.lib/ArgArrayInit



   NAME
	ArgArrayInit -- allocate and initialize a tooltype array. (V36)

   SYNOPSIS
	ttypes = ArgArrayInit(argc,argv);

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) **ArgArrayInit(LONG,[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) **);

   FUNCTION
	This function returns a null-terminated array of strings
	suitable for sending to [icon.library/FindToolType()](../Includes_and_Autodocs_3._guide/node0349.html). This array will
	be the ToolTypes array of the program's icon, if it was started from
	Workbench. It will just be 'argv' if the program was started from
	a shell.

	Pass ArgArrayInit() your startup arguments received by main().

	ArgArrayInit() requires that icon.library be open (even if the caller
	was started from a shell, so that the function [FindToolType()](../Includes_and_Autodocs_3._guide/node0349.html) can be
	used) and may call [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html), so clean up is necessary when
	the strings are no longer needed. The function [ArgArrayDone()](../Includes_and_Autodocs_3._guide/node001E.html) does
	just that.

   INPUTS
	argc - the number of arguments in argv, 0 when started from Workbench
	argv - an array of pointers to the program's arguments, or the
	       Workbench startup message when started from WB.

   RESULTS
	ttypes - the initialized argument array or NULL if it could not be
	         allocated

   EXAMPLE
	Use of these routines facilitates the use of ToolTypes or command-
	line arguments to control end-user parameters in Commodities
	applications. For example, a filter used to trap a keystroke for
	popping up a window might be created by something like this:

```c
    		char   *ttypes  = ArgArrayInit(argc, argv);
    		[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74)   *filter = UserFilter(ttypes, "POPWINDOW", "alt f1");

               ... with ...

               [CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *UserFilter(char **tt, char *action_name,
```
				  char *default_descr)
		{
		char *desc;

		    desc = FindToolType(tt,action_name);

		    return(CxFilter((ULONG)(desc? desc: default_descr)));
		}

	In this way the user can assign "alt f2" to the action by
	entering a tooltype in the program's icon of the form:

		POPWINDOW=alt f2

	or by starting the program from the CLI like so:

		myprogram "POPWINDOW=alt f2"

   NOTE
	Your program must open icon.library and set up IconBase before calling
	this routine. In addition IconBase must remain valid until after
	[ArgArrayDone()](../Includes_and_Autodocs_3._guide/node001E.html) has been called!

   SEE ALSO
	[ArgArrayDone()](../Includes_and_Autodocs_3._guide/node001E.html), [ArgString()](../Includes_and_Autodocs_3._guide/node0021.html), [ArgInt()](../Includes_and_Autodocs_3._guide/node0020.html), [icon.library/FindToolType()](../Includes_and_Autodocs_3._guide/node0349.html)

