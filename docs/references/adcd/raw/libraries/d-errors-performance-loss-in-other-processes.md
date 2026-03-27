# D / Errors / Performance Loss in Other Processes


This is often caused by a one program doing one or more of the following:
busy waiting or polling; running at a higher priority; doing lengthy
[Forbid()](../Libraries_Manual_guide/node02C2.html#line9)s, [Disable()](../Libraries_Manual_guide/node02C3.html#line6)s, or interrupts.

