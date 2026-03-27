# SAD/FREE_MEMORY



 FREE MEMORY

 Command:	$AF $0B
 Data:		$ww $xx $yy $zz

 Free the memory allocated with the ALLOCATE MEMORY command.  This command
 has the same restrictions as ALLOCATE MEMORY.  Memory is released by
 calling [FreeVec()](../Includes_and_Autodocs_3._guide/node0212.html) on the address <$wwxxyyzz>

 Command ACK:	$00 $0B
 Command DONE:	$1F $0B

