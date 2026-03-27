# SAD/WRITE_BYTE



 WRITE [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) - [Write](../Includes_and_Autodocs_3._guide/node01D1.html) the given data to the address given	(V40 SAD)

 Command:	$AF $01
 Data:		$ww $xx $yy $zz $qq

 [Write](../Includes_and_Autodocs_3._guide/node01D1.html) the byte <$qq> to address <$wwxxyyzz>

 Command will be ACK'ed when received.
 Command ACK:	$00 $01
 Command DONE:	$1F $01

 BUGS
	This command does not exists in pre-V40 EXEC.
	This command can be emulated with the [WRITE_ARRAY](../Includes_and_Autodocs_3._guide/node0257.html) command with
	a length of 1.

