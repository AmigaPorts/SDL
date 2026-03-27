# SAD/NOP



 NO-OP - Do nothing other than tell SAD you are still there...

 Command:	$AF $00
 Data:		<none>

 This just tells SAD you are still there.  Required so that timeouts do
 not exit SAD while you are not doing anything.

 This command will *NOT* be ACK'ed.  It will just cause the timeout to
 be restarted.

