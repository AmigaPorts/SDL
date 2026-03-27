# dos.library/Cli



   NAME
	Cli -- Returns a pointer to the CLI structure of the process (V36)

   SYNOPSIS
	cli_ptr = Cli()
	D0

	struct [CommandLineInterface](../Includes_and_Autodocs_3._guide/node05D9.html#line313) *Cli(void)

   FUNCTION
	Returns a pointer to the CLI structure of the current process, or NULL
	if the process has no CLI structure.

   RESULT
	cli_ptr - pointer to the CLI structure, or NULL.

   SEE ALSO

