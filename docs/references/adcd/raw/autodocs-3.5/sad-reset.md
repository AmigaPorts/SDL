# SAD/RESET



 RESET - Reset the computer...

 Command:	$AF $10
 Data:		$FF $FF $FF $FF

 This command will reset the computer.  the $FFFFFFFF value is there
 mainly to prevent false reset.  This command will only be ACK'ed as
 the computer will be reset afterwards...

 Command will be ACK'ed when received.
 Command ACK:	$00 $10

