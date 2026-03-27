# SAD/READ_WORD



 READ WORD - [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a word from the given address		(V40 SAD)

 Command:	$AF $05
 Data:		$ww $xx $yy $zz

 [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a word from address <$wwxxyyzz>  Returns <$qqrr> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $05
 Command DONE:	$1F $05 $qq $rr

 BUGS
	This command does not return correct values in pre-V40 EXEC.

