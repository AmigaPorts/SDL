# graphics.library/CloseMonitor



   NAME
	CloseMonitor -- close a [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24) (V36)

   SYNOPSIS
	error = CloseMonitor( monitor_spec )
	d0                    a0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CloseMonitor( struct [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24) * );

   FUNCTION
	Relinquish access to a [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24).

   INPUTS
	monitor_spec - a pointer to a [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24) opened via [OpenMonitor()](../Includes_and_Autodocs_3._guide/node0309.html),
	or NULL.

   RESULTS
	error - FALSE if [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24) closed uneventfully.
	        TRUE if [MonitorSpec](../Includes_and_Autodocs_3._guide/node05D3.html#line24) could not be closed.

   BUGS

   SEE ALSO
	[OpenMonitor()](../Includes_and_Autodocs_3._guide/node0309.html)

