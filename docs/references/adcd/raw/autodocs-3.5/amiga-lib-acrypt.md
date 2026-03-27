# amiga.lib/ACrypt



   NAME
	ACrypt -- Encrypt a password

   SYNOPSIS
	newpass = ACrypt( buffer, password, username )

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *ACrypt( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *) ;

   FUNCTION
	This function takes a buffer of at least 12 characters in length,
	an unencrypted password and the user's name (as known to the host
	system) and returns an encrypted password in the passed buffer.
	This is a one-way encryption. Normally, the user's encrypted
	password is stored in a file for future password comparison.

   INPUTS
	buffer     - a pointer to a buffer at least 12 bytes in length.
	password   - a pointer to an unencrypted password string.
	username   - a pointer to the user's name.

   RESULT
	newpass    - a pointer to the passed buffer if successful, NULL
	             upon failure. The encrypted password placed in the
	             buffer will be be eleven (11) characters in length
	             and will be NULL-terminated.

   EXAMPLE

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *pw, *getpassword() ;
	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *user = "alf"
	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *newpass ;
	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) buffer[16] ;         /* size >= 12 */

	pw = getpassword() ;   /* your own function */

	if((newpass = ACrypt(buffer, pw, user)) != NULL)
	{
		printf("pw = %sn", newpass) ; /* newpass = &buffer[0] */
	}
	else
	{
		printf("ACrypt failedn") ;
	}

