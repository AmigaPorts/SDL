# SAD/TURN_OFF_SINGLE



 TURN OFF SINGLE STEPPING

 Command:	$AF $0D
 Data:		$ww $xx $yy $zz

 This command will turn off SAD single stepping mode.  You need to pass
 to it the address returned from the call to turn on single stepping mode.

 Command ACK:	$00 $0D
 Command DONE:	$1F $0D

