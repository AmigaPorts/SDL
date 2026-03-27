# SAD/READ_BYTE



 READ [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) - [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a byte from the given address

 Command:	$AF $04
 Data:		$ww $xx $yy $zz

 [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a byte from address <$wwxxyyzz>  Returns <$qq> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $04
 Command DONE:	$1F $04 $qq

