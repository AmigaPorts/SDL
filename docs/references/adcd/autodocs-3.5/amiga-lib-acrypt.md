---
title: amiga.lib/ACrypt
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-acrypt
functions: []
libraries: []
---

# amiga.lib/ACrypt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ACrypt -- Encrypt a password

   SYNOPSIS
	newpass = ACrypt( buffer, password, username )

	[UBYTE](autodocs-3.5/include-exec-types-h.md) *ACrypt( [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *) ;

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

	[UBYTE](autodocs-3.5/include-exec-types-h.md) *pw, *getpassword() ;
	[UBYTE](autodocs-3.5/include-exec-types-h.md) *user = "alf"
	[UBYTE](autodocs-3.5/include-exec-types-h.md) *newpass ;
	[UBYTE](autodocs-3.5/include-exec-types-h.md) buffer[16] ;         /* size >= 12 */

	pw = getpassword() ;   /* your own function */

	if((newpass = ACrypt(buffer, pw, user)) != NULL)
	{
		printf("pw = %sn", newpass) ; /* newpass = &buffer[0] */
	}
	else
	{
		printf("ACrypt failedn") ;
	}

