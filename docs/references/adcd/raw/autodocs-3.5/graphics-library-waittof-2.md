# graphics.library/WaitTOF



   NAME

```c
       WaitTOF -- [Wait](../Includes_and_Autodocs_3._guide/node0246.html) for the top of the next video frame.
```
   SYNOPSIS

```c
       WaitTOF()
```
	void WaitTOF( void );

   FUNCTION

```c
       [Wait](../Includes_and_Autodocs_3._guide/node0246.html)  for vertical blank to occur and all vertical blank
       interrupt routines to complete before returning to caller.
```
   INPUTS

       none
   RESULT
	Places this task on the TOF wait queue. When the vertical blank
	interrupt comes around, the interrupt service routine will fire off
	signals to all the tasks doing WaitTOF. The highest priority task
	ready will get to run then.

   BUGS

   SEE ALSO
	[exec.library/Wait()](../Includes_and_Autodocs_3._guide/node0246.html) [exec.library/Signal()](../Includes_and_Autodocs_3._guide/node023D.html)

