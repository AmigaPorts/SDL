# SAD/WRITE_LONG



 WRITE [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) - [Write](../Includes_and_Autodocs_3._guide/node01D1.html) the given data to the address given

 Command:	$AF $03
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Write](../Includes_and_Autodocs_3._guide/node01D1.html) the long <$qqrrsstt> to address <$wwxxyyzz>

 Command will be ACK'ed when received.
 Command ACK:	$00 $03
 Command DONE:	$1F $03

