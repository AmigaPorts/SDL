# SAD/READ_LONG



 READ [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) - [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a long from the given address

 Command:	$AF $06
 Data:		$ww $xx $yy $zz

 [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a long from address <$wwxxyyzz>  Returns <$qqrrsstt> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $06
 Command DONE:	$1F $06 $qq $rr $ss $tt

