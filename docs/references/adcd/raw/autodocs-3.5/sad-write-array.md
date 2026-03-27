# SAD/WRITE_ARRAY



 WRITE ARRAY - [Write](../Includes_and_Autodocs_3._guide/node01D1.html) a range of bytes

 Command:	$AF $0E
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Write](../Includes_and_Autodocs_3._guide/node01D1.html) a range of bytes to address <$wwxxyyzz> for <$qqrrsstt> bytes
 After the computer sends the ACK, you must then send the byte stream...

 Command will be ACK'ed when received.
 Command ACK:	$00 $0E
 Command DONE:	$1F $0E

