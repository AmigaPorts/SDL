# SAD/READ_ARRAY



 READ ARRAY - [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a range of bytes

 Command:	$AF $0F
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a range of bytes from address <$wwxxyyzz> for <$qqrrsstt> bytes
 Will return that number of bytes...

 Command will be ACK'ed when received.
 Command ACK:	$00 $0F
 Command DONE:	$1F $0F $uu [$uu ...]

