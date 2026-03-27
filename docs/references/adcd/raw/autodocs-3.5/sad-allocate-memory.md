# SAD/ALLOCATE_MEMORY



 ALLOCATE MEMORY

 Command:	$AF $0A
 Data:		$qq $rr $ss $tt $hh $ii $jj $kk

 [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a chunk of memory that is <$qqrrsstt> bytes in size.  Note
 that this call is only safe when SAD is in $3F prompting mode (called
 from [Debug()](../Includes_and_Autodocs_3._guide/node01FF.html)) and even then may be unsafe if the system is in bad shape.
 (You are debugging after all)  The returned address will be available to
 you until you release it.  (It is obtained via a call to [AllocVec()](../Includes_and_Autodocs_3._guide/node01EB.html))  The
 type of memory allocated is <$hhiijjkk>.  Note that the allocation may
 fail. In that case, the address returned will be $00000000.

 Command ACK:	$00 $0A
 Command DONE:	$1F $0A $ww $xx $yy $zz

