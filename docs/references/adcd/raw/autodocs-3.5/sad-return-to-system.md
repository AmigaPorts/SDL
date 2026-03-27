# SAD/RETURN_TO_SYSTEM



 RETURN TO SYSTEM

 Command:	$AF $08
 Data:		$00 $00 $00 $00

 This command will return <exit> from SAD back to whatever started it.
 The 4 $00 are required as a "safty" to this command.  The command
 will be ACK'ed only as it will have lost control of the system.

 Command ACK:	$00 $08

